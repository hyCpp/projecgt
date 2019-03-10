package com.example;

import android.view.*;
import android.util.*;
import android.content.*;
import android.graphics.*;

/**
 * OsciView displays an oscilloscope showing the audio wave.
 * 
 * @author Nuance Communications
 *
 */
public class OsciView extends View {
	private short[] audioData=null;
	private int waveColor=Color.argb(255, 0, 255, 0);
	private int disabledColor=Color.argb(255, 0xC0, 0xC0, 0xC0);
	private int viewWidth=0;
	private int viewHeight=0;
	private int step=0;
	private Paint paint=null;
	private int mid=0;
	
	public OsciView(Context context) {
		super(context);
	}
	
	public OsciView(Context context, AttributeSet attrs) {
		super(context, attrs);
		
		paint=new Paint();
		paint.setStyle(Paint.Style.FILL);
		paint.setStrokeWidth(0);
		paint.setColor(isEnabled() ? waveColor : disabledColor);
	}
		
	public void setAudioData(short[] data) {
		audioData=data;
		
		if ( audioData != null && viewWidth > 0 ) {
			step=(int) (65535.0*(float)audioData.length/(float)viewWidth);
		}
		
		invalidate();
	}
	
	@Override
	public void onDraw(Canvas canvas) {
		super.onDraw(canvas);
		
		float[] pixels=new float[viewWidth*2];
		int pos=0;
		
		for ( int i=0, x=0; x < viewWidth; i+=2, x++ ) {
			pixels[i]=x;
				
			if ( audioData == null )
				pixels[i+1]=mid;
			else
			{
				int sample=(int)audioData[(int)pos>>16];
				pixels[i+1]=mid-((sample*viewHeight) >> 16);
				pos+=step;
			}
		}
		
		canvas.drawPoints(pixels, paint);
	}
	
	@Override
	protected void onSizeChanged (int w, int h, int oldw, int oldh) {
		viewWidth=w;
		viewHeight=h;
		
		mid=viewHeight/2;
		super.onSizeChanged(w, h, oldw, oldh);
	}
}
