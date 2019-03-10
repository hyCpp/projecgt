TARGET   := oa-center
CXX      := g++ -std=gnu++11
LDFLAGS  := -fpic
CFLAGS   := -g -Wall -fpic

USER      =    NAME
DEFS      =    -D $(USER)=1
CUR_DIR   =    $(shell pwd)
LIB_DIR   =    $(CUR_DIR)/external
LOG_DIR   =    $(CUR_DIR)/LogConfig
PUGI_DIR  =    $(LIB_DIR)/pugixml
CURL_DIR  =    $(LIB_DIR)/curl
JSON_DIR  =    $(LIB_DIR)/json
SHARE_LIB =    $(LIB_DIR)

SRC = ${wildcard ${CUR_DIR}/*.cpp}  \
	${wildcard ${LOG_DIR}/*.cpp}  \
	${wildcard ${PUGI_DIR}/*.cpp} \
	${wildcard ${CURL_DIR}/*.cpp} \
	${wildcard ${JSON_DIR}/*.cpp} \
			
INC = -I${LIB_DIR}  \
      -I${LOG_DIR}  \
      -I${CURL_DIR} \
      -I${JSON_DIR} \
      -I${PUGI_DIR} \
	      
OBJ = ${patsubst %.cpp, %.o, ${SRC}}

${TARGET}: ${OBJ}
	${CXX} ${LDFLAGS}  ${OBJ} -o $@ -lcurl 

$(OBJ) : %.o : %.cpp
	${CXX} -c ${CFLAGS} ${INC} ${DEFS} -c $< -o $@

.PHONY : clean

clean:
	rm -f  *.o *.gch *~
	
