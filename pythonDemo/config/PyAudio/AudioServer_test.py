import socket
import commands

PORT = 48888
Host = '192.168.40.36'
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((Host,PORT))
s.listen(3)

while 1:
	conn,addr=s.accept()
	print'Connected by', addr
	while 1:
		msg = conn.recv(1024)
		if len(msg) == 0 : break
		print(msg)
		if msg == 'client ok':
			conn.send('server ok')
		if msg == 'playBegin':
			print 'apptool start vr'
		if msg == 'playEnd':
			print 'apptool stop vr'
			conn.send('record begin')
			
		
	conn.close()
s.close()
