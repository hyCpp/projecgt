#include<iostream>

using namespace std;

class integer {
	int i;
	integer* This() { return this; }
	
pubilc:
	integer(long I = 0):i(I) {
	}
	
	const integer& operator+(const integer& a) {
		std::cout<<"+integer\n";
		return a;
	}
	
	const integer operator-(const integer& a) {
		std::cout<<"-integer\n";
		return integer(-a.i);
	}
	
	const integer operator~(const integer& a) {
		std::cout<<"~integer\n";
		return integer(~a.i);
	}
	
	integer* operator&(const integer& a) {
		std::cout<<"&integer\n";
		return a.This();
	}
	
	int operator!(const integer& a) {
		std::cout<<"!integer\n";
		return !a.i;
	}
	
	const integer& operator++(const integer& a) {
		std::cout<<"++integer\n";
		a.i++;
		return a;
	}
	
	const integer operator++(integer& a, int) {
		std::cout<<"integer++\n";
		integer r(a.i);
		a.i++;
		return r;
	}
};

void f(integer a) {
	+a;
	-a;
	~a;
	integer* ip = &a;
    !a;
    ++a;
    a++;
}

int main() {
	integer a;
	f(a);
}
