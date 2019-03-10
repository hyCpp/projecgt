import pyaudio
import wave

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 2
RATE = 16000
RECORD_SECONDS = 3

def writeAudio(fileName, time):
    p = pyaudio.PyAudio()
    stream = p.open(format = FORMAT,
                channels = CHANNELS,
                rate = RATE,
                input = True,
                frames_per_buffer = CHUNK)

    print("recording begin ...")
    frames = []  
    for i in range(0, int(RATE / CHUNK * time)):
        data = stream.read(CHUNK)
        frames.append(data) 

    print("recording end ...")

    stream.stop_stream()
    stream.close()
    p.terminate()  

    wf = wave.open(fileName, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(p.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frames))
    wf.close()           	

if __name__ == '__main__':
    writeAudio("Yes.wav", 2)