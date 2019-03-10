#include"../struct/Stack/Nested.h"
#include"string.cpp"
#include<fstream>
#include<iostream>

using namespace std;

class StringList : public stack {

public:
	void push(String* str) {
		stack::push(str);
	}
	
	String* peek() {
		return (String*)stack::peek();
	}
	
	String* pop() {
		return (String*)stack::pop();
	}
};

int main() {
	ifstream file("../struct/Stack/huyang.txt");
	const int bufsize = 100;
	char buf[bufsize];
	StringList textlines;
	while(file.getline(buf, bufsize)) {
		textlines.push(String::make(buf));
	}
	
	String* s;
	
	while ((s = textlines.pop()) != 0) {
		std::cout<<*s<<std::endl;
	}
}
