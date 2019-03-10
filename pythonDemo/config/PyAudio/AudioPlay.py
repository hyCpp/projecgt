import pyaudio
import wave
import sys

CHUNK = 1024

def playAudio(path):
	print("playing begin ...")
	wf = wave.open(path, 'rb')
	p = pyaudio.PyAudio()
	stream = p.open(format = p.get_format_from_width(wf.getsampwidth()), 
				channels = wf.getnchannels(),
				rate = wf.getframerate(),
				output = True)
                
	data = wf.readframes(CHUNK)
    
	while data != '':
		stream.write(data)
		data = wf.readframes(CHUNK)
    	
	stream.stop_stream()
	stream.close()
	p.terminate()
	print("playing end ...")


if __name__ == '__main__':
    path = sys.argv[1]
    print(path)
    playAudio(path)

