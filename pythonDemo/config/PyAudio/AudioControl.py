


import AudioPlay
import AudioWrite
import sys
import socket

if len(sys.argv) < 2:
    print("recording a wave file.\n\nUsage: %s filename.wav" % sys.argv[0])
    sys.exit(-1)
    
WAVE_OUTPUT_FILENAME = sys.argv[1] + ".wav"

PORT = 48888

def getHostIp():
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		s.connect(('8.8.8.8', 80))
		ip = s.getsockname()[0]
	finally:
		s.close()
	return ip

def socketClient(ip):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((ip, PORT))
	s.send('client ok')
	back = s.recv(1024)
	if back == 'server ok':
		while 1:
			s.send('playBegin')
			AudioPlay.playAudio(WAVE_OUTPUT_FILENAME)
			s.send('playEnd')
			
			back = s.recv(1024)
			if back == 'record begin':
				AudioWrite.writeAudio(WAVE_OUTPUT_FILENAME, 3)
	s.close

if __name__ == '__main__':
	socketClient(getHostIp())
