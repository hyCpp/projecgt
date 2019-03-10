CUR_DIR = /home/huyang/myTest/C++Test/Thread_communication

DEFS = -D TEST_RECV=1

COMMON_DIR =      $(CUR_DIR)/common
LINUX_DIR  =      $(CUR_DIR)/implement
TEST_DIR   =      $(CUR_DIR)/ThreadTest
		
SRC =   ${wildcard ${COMMON_DIR}/*.cpp} \
	${wildcard ${TEST_DIR}/*.cpp} \
	${wildcard ${LINUX_DIR}/*.cpp} \
	${wildcard ${CUR_DIR}/*.cpp}

INC = -I${COMMON_DIR} \
      -I${TEST_DIR} \
      -I${LINUX_DIR}
      
OBJ = ${patsubst %.cpp, %.o, ${SRC}}

TARGET = main
CC = g++

${TARGET}: ${OBJ}
	${CC} ${OBJ} -o $@ -lpthread

$(OBJ) : %.o : %.cpp
	${CC} ${INC} ${DEFS} -c $< -o $@

clean:
	rm -f ${OBJ} *.o *~ ${TARGET}
