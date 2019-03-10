#include<iostream>

using namespace std;

class widget {

	void f(int) const { std::cout<<"widget::f()\n";}
	void g(int) const { std::cout<<"widget::g()\n";}
	void h(int) const { std::cout<<"widget::h()\n";}
	void j(int) const { std::cout<<"widget::j()\n";}
	enum { count = 4 };
	void (widget::*fptr[count])(int) const;

public:
	widget() {
		fptr[0] = &widget::f;
		fptr[1] = &widget::g;
		fptr[2] = &widget::h;
		fptr[3] = &widget::j;
	}
	
	void select(int i, int j) {
		if (i < 0 || i >= count) {
			return;
		}
		(this->*fptr[i])(j);
	}
	
	int Count() {
		return count;
	}
};

int main() {
	widget w;
	for (int i = 0; i < w.Count(); i++) {
		w.select(i, 47);
	}
}
