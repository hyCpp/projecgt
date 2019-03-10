import socket

PORT = 48888

def socketClient(ip):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((ip, PORT))
	
	while 1:
		msg = raw_input('>>:')
		if len(msg) == 0 : continue
		s.send(msg)
		
		back = s.recv(1024)
		print(back)
	
	s.close
