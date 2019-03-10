#include<iostream>

using namespace std;

void increment(int*& i) {
	i++;
}

int main() 
{
	int* i = 0;
	std::cout<<"i = "<<i<<std::endl;
	increment(i);
	std::cout<<"i = "<<i<<std::endl;
	std::cout<<"i = "<<&i<<std::endl;
}
