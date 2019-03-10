CUR_DIR = /home/huyang/MyDemo/C++Test/XmlTest/LibXMLParseXML
LIBXML_DIR = /home/huyang/MyDemo/C++Test/externals/libxml2/include
LOG_DIR = /home/huyang/MyDemo/C++Test/LogConfig

SRC = ${wildcard ${CUR_DIR}/*.cpp}
INC = -I${LIBXML_DIR} \
        -I${CUR_DIR} \
        -I${LOG_DIR}
        
OBJ = ${patsubst %.cpp, %.o, ${SRC}}

TARGET = xmlTest
CC = g++

${TARGET}: ${OBJ}
	${CC} ${OBJ} -o $@ -lxml2
	
$(OBJ) : %.o : %.cpp
	${CC} ${INC} -c $< -o $@ -std=c++11 -w

clean:
	rm -f ${OBJ} *.o *.gch *.user ${TARGET}
