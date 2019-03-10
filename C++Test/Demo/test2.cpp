#include<iostream>

using namespace std;

int* f(int* x) {
	(*x)++;
	return x;
}

void g(int& x, int& y) {
	x++;
	y = x;
}

int h(int& x) {
	x++;
	return x;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	g(a, b);
	std::cout<<*f(&c)<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<h(a)<<std::endl;
}
