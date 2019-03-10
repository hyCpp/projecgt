CXX        := g++ -std=gnu++11
CFLAGS     := -Wall -g -fPIC
LDFLAGS    := -shared -fpic
SOURCE     := $(wildcard *.cpp)
SHARE_LIB  := pugixml.so

all:$(SHARE_LIB)

$(SHARE_LIB) : $(SOURCE)
		$(CXX) $(LDFLAGS) $^ -o $(SHARE_LIB)
		
.PHONY:
		clean

clean:
	rm *.so *.o -rf
