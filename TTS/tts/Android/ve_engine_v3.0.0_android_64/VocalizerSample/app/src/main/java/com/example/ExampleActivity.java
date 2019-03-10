package com.example;

import android.app.Activity;
import android.content.Context;
import android.media.AudioManager;
import android.os.Bundle;
import com.nuance.android.vocalizer.*;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Spinner;
import android.speech.tts.TextToSpeech.OnInitListener;
import android.speech.tts.TextToSpeech;

import java.io.IOException;
import java.io.InputStream;
import java.util.Locale;

/**
 * Demonstration activity for the Nuance Vocalizer Expressive Text-to-Speech Engine
 * 
 * @author Nuance Communications
 *
 */
public class ExampleActivity extends Activity implements VocalizerEngineListener, VocalizerSpeechMarkListener,  VocalizerAudioOutputListener {

	private TextToSpeech mSpeech = null;

	/**
	 * The text to speech engine.
	 */
	private VocalizerEngine ttsEngine=null;
	
	/**
	 * The list of available voices that can be used to speak.
	 * @see #updateVoiceList()
	 */
	private VocalizerVoice[] availableVoices=null;

	/**
	 * The various UI components.
	 */
	private EditText textField=null;
	private Button speakButton=null;
	private Button stopButton=null;
	private Button initializeButton=null;
	private Button pauseButton=null;
	private MouthView mouthView=null;
	private OsciView osciView=null;
	private Spinner voiceList=null;
	private Spinner volumeList=null;
	private Spinner rateList=null;
	private Spinner pitchList=null;
	
	/**
	 * Array of possible volumes to be used when speaking.
	 */
	private static int volumeTable[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100};
	
	/**
	 * Array of possible pitch values to be used when speaking.
	 */
	private static int pitchTable[]={50, 70, 90, 100, 110, 120, 140, 160, 170, 200};
	
	/**
	 * Array of possible rates to be used when speaking.
	 */
	private static int rateTable[]={50, 80, 100, 130, 150, 180, 200, 280, 350, 400};
	
	/**
	 * Logcat output tag name
	 */
	private final static String TAG="SAMPLE";
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        textField=(EditText)findViewById(R.id.textField);
        speakButton=(Button)findViewById(R.id.speakButton);
        stopButton=(Button)findViewById(R.id.stopButton);
        initializeButton=(Button)findViewById(R.id.initializeButton);
        pauseButton=(Button)findViewById(R.id.pauseButton);
        voiceList=(Spinner)findViewById(R.id.voiceList);
        volumeList=(Spinner)findViewById(R.id.volumeList);
        rateList=(Spinner)findViewById(R.id.rateList);
        pitchList=(Spinner)findViewById(R.id.pitchList);
        mouthView=(MouthView)findViewById(R.id.mouth);
		osciView=(OsciView)findViewById(R.id.oscilloscope);
        
		// Set the buttons to the default state
        stopButton.setEnabled(false);
        speakButton.setEnabled(false);
        pauseButton.setEnabled(false);
        
        initializeSpeechEngine();

		mSpeech = new TextToSpeech(ExampleActivity.this, new TTSListener());
                
        // Make the volume keys of this activity control the volume keys of the audio stream
        // where the engine will play.
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
        
        speakButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				// Speak the text that has been typed into the text field. Give the text an
				// id so that we are notified when the text begins and is done speaking.
				textField.requestFocus();
				ttsEngine.speak(textField.getText().toString(), false, "text_id");
			}
		});
        
        stopButton.setOnClickListener(new View.OnClickListener() {
        	@Override
			public void onClick(View v) {
        		// Stop the text that is being spoken.
				ttsEngine.stop();
			}
		});
        
        initializeButton.setOnClickListener(new View.OnClickListener() {
        	@Override
			public void onClick(View v) {
				// Initialize or release the Text-to-Speech engine.
				if ( ttsEngine.isInitialized() )
					ttsEngine.release();
				else ttsEngine.initialize();
			}
		});
        
        pauseButton.setOnClickListener(new View.OnClickListener() {
        	@Override
			public void onClick(View v) {
        		// Pause or resume the text to speech engine.
				if ( ttsEngine.isPaused() )
					ttsEngine.resume();
				else ttsEngine.pause();
			}
		});
    }

	public static String readAssetsContext(Context con, String fileName) {
		try {
			InputStream is = con.getAssets().open(fileName);
			int size = is.available();

			byte[] buffer = new byte[size];
			is.read(buffer);
			is.close();
			return new String(buffer, "utf-8");
		} catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}

    private class TTSListener implements OnInitListener {
    	@Override
		public void onInit(int status) {
    		if (status == TextToSpeech.SUCCESS) {
				mSpeech.setLanguage(Locale.ENGLISH);
				mSpeech.setSpeechRate(0.5f);
				mSpeech.setPitch(1.0f);
				mSpeech.setOnUtteranceCompletedListener(new TextToSpeech.OnUtteranceCompletedListener() {
					@Override
					public void onUtteranceCompleted(String s) {

					}
				});
			}
			else {

			}
		}
	}

    /**
     * Called when the activity is being destroyed. Note that Android can call this
     * method even if the activity is not being finished. For example, as a result
     * of a screen rotation the activity will be destroyed and recreated.
     * We need to make sure that the Text-to-Speech engine is released only
     * when the activity is really finishing.
     * 
     * @see #initializeSpeechEngine()
     * @see #onRetainNonConfigurationInstance()
     */
    @Override
    public void onDestroy() {
    	if ( isFinishing() && ttsEngine != null )
    		ttsEngine.release();

		if ( mSpeech != null ) {
			mSpeech.stop();
			mSpeech.shutdown();
			mSpeech = null;
		}
    	
    	super.onDestroy();
    }
    
    /**
     * Loads the voice that is currently selected in the voice list spinner.
     */
    private void loadSelectedVoice() {
		mSpeech.speak("", TextToSpeech.QUEUE_FLUSH, null);
    	if ( availableVoices == null ) {
    		Log.e(TAG, "loadSelectedVoice: no available voices.");
    		return;
    	}
    	
    	int position=voiceList.getSelectedItemPosition();
    	
    	if ( position >= 0 && position < availableVoices.length ) {
    		try {
				if ( ttsEngine.loadVoice(availableVoices[position]) )
					configureSpeechProperties();
			}
			catch(Exception e) {
				Log.e(TAG, "EXCEPTION WHILE TRYING TO LOAD VOICE: " + e);
			}
    	}
    }
    
    /**
     * Updates the Text-to-Speech engine properties (volume, rate and pitch) with
     * the values currently selected in the UI. This method will be called whenever
     * the selection of any of the properties spinners is changed, or when a new
     * voice is loaded.
     */
    private void configureSpeechProperties() {
    	ttsEngine.setSpeechVolume(volumeTable[volumeList.getSelectedItemPosition()]);
    	ttsEngine.setSpeechRate(rateTable[rateList.getSelectedItemPosition()]);
    	ttsEngine.setSpeechPitch(pitchTable[pitchList.getSelectedItemPosition()]);
    }
    
    /**
     * Updates the UI with the values currently set in the Text-to-Speech engine.
     * This method is generally called after initialization to set the UI to the
     * (default) Text-to-Speech engine values.
     */
    private void configureUI() {
	    updateVoiceList();
	    	    
	    configureSpeechControlSpinner(volumeList, volumeTable, ttsEngine.getSpeechVolume(), VocalizerEngine.DEFAULT_VOLUME);
	    configureSpeechControlSpinner(rateList, rateTable, ttsEngine.getSpeechRate(), VocalizerEngine.DEFAULT_RATE);
	    configureSpeechControlSpinner(pitchList, pitchTable, ttsEngine.getSpeechPitch(), VocalizerEngine.DEFAULT_PITCH);
    }
    
    /**
     * Obtains a list of voices that are currently available in the system that can
     * be used by the Text-to-Speech engine.
     * 
     * This method also populates the voice list spinner with all available voices
     * and selects the spinner item that corresponds to the currently used voice (if any)
     */
    public void updateVoiceList() {
	    availableVoices=ttsEngine.getVoiceList();
	    
	    if ( availableVoices != null ) {
	    	VocalizerVoice currentVoice=ttsEngine.getCurrentVoice();
	    	int selectedItem=-1;
	    	int voiceIndex=0;
	    	
	        // Make all the voices available in the voice list
	        ArrayAdapter<String> voiceListAdapter=new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item);
	        for ( VocalizerVoice voice : availableVoices ) {
	        	voiceListAdapter.add(new String(voice.getVoiceName()+" (" + voice.getLanguage() + ")"));
	        	if ( currentVoice != null && currentVoice.equals(voice) )
	        		selectedItem=voiceIndex;
	        	
	        	voiceIndex++;
	        }
	        
	        voiceListAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
	        voiceList.setAdapter(voiceListAdapter);
	        
	        voiceList.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
	        	@Override
	        	public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
	        		// Load the selected voice when the spinner selection changes.
	        		loadSelectedVoice();
	        	}
	        	
	        	@Override
	        	public void onNothingSelected(AdapterView<?> parent) {
	        	}
	        	
			});
	        
	        if ( selectedItem != -1 )
	        	voiceList.setSelection(selectedItem);
	    }
    }  
    
    /**
     * This method will be called when the state of the Text-to-Speech engine changes.
     * The main purpose of this method is to update the contents of the UI according
     * to the current engine state.
     * 
     * Note that when the engine is done initializing the first voice in the list
     * will automatically be loaded by a call to loadSelectedVoice. It is not
     * the default behavior of the Text-to-Speech engine to load any voice upon
     * initialization.
     */
    @Override
    public void onStateChanged(int newState) {
    	String stateStr="";
    	
    	switch (newState) {
    	case VocalizerEngine.STATE_INITIALIZED:
    		stateStr=getString(R.string.state_initialized);
    		stopButton.setEnabled(false);
    		speakButton.setEnabled(false);
    		initializeButton.setText(getString(R.string.release));
    		pauseButton.setEnabled(false);
    		
    		configureUI();
    		loadSelectedVoice();
    		break;
    		
    	case VocalizerEngine.STATE_READY:
    		mouthView.setMark(null);
    		osciView.setAudioData(null);
    		
    		stateStr=getString(R.string.state_ready);
    		stopButton.setEnabled(false);
    		speakButton.setEnabled(true);
    		pauseButton.setEnabled(false);
    		break;
    		
    	case VocalizerEngine.STATE_SPEAKING:
    		stateStr=getString(R.string.state_speaking);
    		stopButton.setEnabled(true);
    		speakButton.setEnabled(true);
    		pauseButton.setEnabled(true);
    		pauseButton.setText(getString(R.string.pause));
    		break;
    		
    	case VocalizerEngine.STATE_PAUSED:
    		stateStr=getString(R.string.state_paused);
    		pauseButton.setText(getString(R.string.resume));
    		break;
    		
    	case VocalizerEngine.STATE_UNINITIALIZED:
    		stateStr=getString(R.string.state_uninitialized);
    		stopButton.setEnabled(false);
    		speakButton.setEnabled(false);
    		pauseButton.setEnabled(false);
    		initializeButton.setText(R.string.initialize);
    		break;
    		
    	default:
           	break;
    	}
    
    	((TextView)findViewById(R.id.state)).setText(stateStr);
    }
    
    /**
     * This method will be called by the Text-to-Speech engine when
     * it begins speaking. Note that in order to be notified one must pass
     * a text id to the speak method.
     */
    @Override
	public void onSpeakElementStarted(String id) {
    	Log.v(TAG, "Started text with id: " + id);
    }
    
    /**
     * This method will be called by the Text-to-Speech engine when
     * it has completed speaking the text. Note that in order to be notified
     * one must pass a text id to the speak method.
     */
    @Override
	public void onSpeakElementCompleted(String id) {
    	Log.v(TAG, "Completed text with id: " + id);
    }
    
    /**
     * This method will be called by the Text-to-Speech engine when a
     * speech mark is received. There are several types of speech marks.
     * This example handles lip position information and word markers
     * within the original text.
     */
    @Override
    public void onSpeechMarkReceived(VocalizerSpeechMark mark) {
    	if ( mark.getType() == VocalizerSpeechMark.VMOBILE_MRK_PHONEME ) {
    		// We have received a new phoneme. Pass the lip information
    		// to the view handling the mouth movements.
    		mouthView.setMark(mark);
    	}
    	else if ( mark.getType() == VocalizerSpeechMark.VMOBILE_MRK_WORD ) {
    		textField.setSelection(mark.getSrcPos(), mark.getSrcPos()+mark.getSrcTextLen());
    		textField.moveCursorToVisibleOffset();
    	}
    }
    
    /**
     * This method will be called by the Text-to-Speech engine as audio
     * samples are generated. This demo application displays the audio data
     * in an oscilloscope.
     */
    @Override
    public void onAudioData(final VocalizerAudioSettings settings, final short[] audioData) {
    	// We have received audio samples. Show them in the oscilloscope.
    	osciView.setAudioData(audioData);
    }
    
    /**
     * This method will be called by the Text-to-Speech engine when the list
     * of available voices changes. This is due to a voice package being
     * installed or removed in the system.
     */
    @Override
	public void onVoiceListChanged() {
		updateVoiceList();
	}
    
    /**
     * Constructs and begins initialization of the Text-to-Speech engine.
     * 
     * This method will be called once during the life time of the activity, but
     * in response of two events: first time creation of the activity (when the
     * activity is first launched) and recreation of the activity (as a result, for example,
     * of a screen rotation).
     * 
     */
    private void initializeSpeechEngine() {
    	// Check if we have a Text-to-Speech engine object from the last session
    	// (activity recreation).
    	ttsEngine=(VocalizerEngine)getLastNonConfigurationInstance();
    	
    	if ( ttsEngine == null ) {
    		// Activity is first created, so create a new Text-to-Speech engine and configure it.
    		
    		// Use the application context to prevent memory leaks when re-using the
    		// Text-to-Speech engine accross activity recreations due to configuration
    		// changes.
    		ttsEngine=new VocalizerEngine(getApplicationContext());
    		
    		// Register this activity as the listener to receive state change events.
        	ttsEngine.setListener(this);
        	
        	// Register this activity to receive speech markers when text is being spoken.
        	ttsEngine.setSpeechMarkListener(this);
        	
        	// Register this activity to receive audio samples.
        	ttsEngine.setAudioOutputListener(this, false);
        	
        	// Begin the initialization of the Text-to-Speech engine. Note that the 
        	// initialization process is asynchronous. onStateChanged will be invoked
        	// once the initialization process is completed.
        	ttsEngine.initialize();
    	}
    	else
    	{
    		// We have an old instance, simply register the new listeners (as the old activity
    		// is already dead), but do not initialize.
        	ttsEngine.setListener(this);
        	ttsEngine.setSpeechMarkListener(this);
        	ttsEngine.setAudioOutputListener(this, false);
        	
        	configureUI();
        	
        	onStateChanged(ttsEngine.getState());
    	}
    }
    
    /**
     * This method will be invoked by the Android framework when the activity is about
     * to be destroyed as a result of a configuration change (for example, the screen rotates)
     * We return the Text-to-Speech engine in order to preserve its state and re-use it
     * when the activity is re-created.
     */
    @Override
    public Object onRetainNonConfigurationInstance () {
    	return ttsEngine;
    }
    
    /**
     * Utility function to populate the contents of a spinner control.
     * 
     * @param list the spinner to populate
     * @param table the array of values
     * @param currentValue the current value that must be selected in the spinner
     * @param defaultValue the default value of the array
     */
    private void configureSpeechControlSpinner(Spinner list, int[] table, int currentValue, int defaultValue) {
    	int selectedIndex=-1;
    	ArrayAdapter<String> listAdapter=new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item);
    	
        for ( int i=0; i < table.length; i++ ) {
        	if ( table[i] == currentValue )
        		selectedIndex=i;
        	
        	listAdapter.add( new String("" + table[i] + ( table[i] == defaultValue ? (" ("+getString(R.string.default_value) + ")") : "") ) );
        }
        
        listAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        list.setAdapter(listAdapter);
        
        list.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
        	@Override
        	public void onItemSelected(AdapterView<?> parent, View view, int position, long id) { 
        		configureSpeechProperties();
        	}
        	
        	@Override
        	public void onNothingSelected(AdapterView<?> parent) {
        	}
		});
        
        if ( selectedIndex != -1 )
        	list.setSelection(selectedIndex);
    }
}