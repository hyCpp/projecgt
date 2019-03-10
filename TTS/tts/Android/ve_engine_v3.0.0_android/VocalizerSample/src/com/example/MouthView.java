package com.example;

import com.nuance.android.vocalizer.VocalizerSpeechMark;

import android.util.AttributeSet;
import android.view.*;
import android.content.*;
import android.graphics.*;

/**
 * MouthView displays a face that synchronizes the lips with the text spoken by the Text-to-Speech engine.
 * 
 * @author Nuance Communications
 *
 */
public class MouthView extends View {
	private VocalizerSpeechMark mMark=null;
	private Context context=null;
	private Paint facePaint=new Paint();
	private Paint lipPaint=new Paint();
	private Paint eyePaint=new Paint();
	private Paint pupilPaint=new Paint();
	private Paint nosePaint=new Paint();
	private Point leftEdge=new Point();
	private Point rightEdge=new Point();
	private Point topEdge=new Point();
	private Point bottomEdge=new Point();
	private Path path=new Path();
	
	public MouthView(Context context) {
		super(context);
	}
	
	public MouthView(Context context, AttributeSet attrs) {        
		super(context, attrs);
		this.context=context;
	}
	
	@Override
	protected void onSizeChanged (int w, int h, int oldw, int oldh) {
		super.onSizeChanged(w, h, oldw, oldh);
	}
	
	@Override
	protected void onDraw (Canvas canvas) {
		super.onDraw(canvas);
		
		facePaint.setColor(Color.BLUE);
		facePaint.setStyle(Paint.Style.FILL);
		
		lipPaint.setColor(Color.RED);
		lipPaint.setStyle(Paint.Style.FILL);
		
		eyePaint.setColor(Color.WHITE);
		eyePaint.setStyle(Paint.Style.FILL);
		
		pupilPaint.setColor(Color.BLACK);
		pupilPaint.setStyle(Paint.Style.FILL);
		
		nosePaint.setColor(Color.rgb(218, 69, 137));
		nosePaint.setStyle(Paint.Style.FILL);
				
		int width=getWidth();
		int height=getHeight();
		
		int faceRad=Math.max(width, height);

		canvas.drawCircle(width/2, height/2, faceRad/2, facePaint);
		
		int eyeOffset=faceRad/5;
		int eyeRad=faceRad/6;
		
		canvas.drawCircle((width/2)-eyeOffset, (faceRad/2)-eyeOffset, eyeRad, eyePaint);
		canvas.drawCircle((width/2)+eyeOffset, (faceRad/2)-eyeOffset, eyeRad, eyePaint);
		
		canvas.drawCircle((width/2)-eyeOffset, (faceRad/2)-eyeOffset, eyeRad*4/6, pupilPaint);
		canvas.drawCircle((width/2)+eyeOffset, (faceRad/2)-eyeOffset, eyeRad*4/6, pupilPaint);
		
		int noseOffset=faceRad/20;
		int noseRad=faceRad/10;
		
		canvas.drawCircle((width/2), (faceRad/2)+noseOffset, noseRad, nosePaint);
		
		int mouthWidth=mMark == null ? 150 : mMark.getMouthWidth();
		int mouthHeight=mMark == null ? 50 : mMark.getMouthHeight();
		int mouthUpturn=mMark == null ? 200 : mMark.getMouthUpturn();
		
		leftEdge.x=scale(255-(mouthWidth-20), faceRad/2);
		leftEdge.y=height/2;
		
		rightEdge.x=width-scale(255-(mouthWidth-20), faceRad/2);
		rightEdge.y=height/2;
		
		topEdge.x=width/2;
		topEdge.y=scale(255-(mouthHeight/5), faceRad/2);
		
		bottomEdge.x=width/2;
		bottomEdge.y=height-scale(255-(mouthHeight/2), faceRad/2);
		
		int mouthOffset=(faceRad/5)+scale(mouthUpturn, 10);
		
		path.reset();
		path.moveTo(leftEdge.x, leftEdge.y+mouthOffset);
		path.lineTo(topEdge.x, topEdge.y+mouthOffset);
		path.lineTo(rightEdge.x, rightEdge.y+mouthOffset);
		path.lineTo(bottomEdge.x, bottomEdge.y+mouthOffset);
		path.close();
		
		canvas.drawPath(path, lipPaint);
	}
	
	private int scale(int value, int width) {
		return (width*Math.max(value, 0))/255;
	}
	
	public void setMark(VocalizerSpeechMark mark) {
		if ( mark != null && mark.getMouthWidth() == 0 && mark.getMouthHeight() == 0 && mark.getMouthUpturn() == 0 )
			return; // Ignore 
		
		mMark=mark;
		invalidate();
	}
	
	@Override
	protected void onMeasure (int widthMeasureSpec, int heightMeasureSpec) {
		int dip=70;
		
		float density = context.getResources().getDisplayMetrics().density; 
		final int minHeight = (int) (dip*density + 0.5f);
		final int minWidth = (int) (dip*density + 0.5f);
		
		setMeasuredDimension(minWidth, minHeight);
	}
}
