#include<iostream>
using namespace std;

class B {
public:
	int b;
	void funa1() {
		cout << "class b" << endl;
	}
	bool operator>(B& obj) {

		return this->b > obj.b;

	}
};
int main() {
	
	
	
	B* b = new B();
	b->b = 100;
	
	B* b1 = new B();
	b1->b = 15;
	cout << (*b > *b1) << endl;

	
	return 0;
}