#include<string.h>
#include<iostream>
#include<fstream> <fstream> 
class String {
	char* s;
	String(const char* sp) {
		s = new char[strlen(sp) + 1];
		strcpy(s, sp);
	}
	
	String(const String&);
	void operator=(String&);

public:
	friend String* makeString(const char* sp) {
		return new String(sp);
	} 
	
	static String* make(const char* sp) {
		return new String(sp);
	}
	
	~String() {
		delete s;
	}
	
	operator char*() const {
		return s;
	}
	
	char* str() const {
		return s;
	}
	
	friend ostream& operator<<(ostream& os, const String& sp) {
		return os<<sp.s;
	}
};
