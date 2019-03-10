import os, sys

def inputWalk(root):
	for root, dirs, files in os.walk(root):
		for filename in files:
			pathname =  os.path.join(root, filename)
			if not filename.endswith('.mk'):
				continue
			print pathname
			print pathname.split('/')
			read = open(pathname).read()
			contents = unicode(read, 'utf-8')
			print contents
			
			
if __name__ == '__main__':
	if len(sys.argv) < 2:
		sys.exit(1)
		
	inputWalk(sys.argv[1])
		
