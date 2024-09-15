#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pnext;
};
int main() {
	Node* phead = nullptr;
	Node* ptemp = nullptr;
	int a = 1;
	int end = 10;
	while (end) {
		/*Node* pnewnode = new Node;
		pnewnode->data = 10;
		pnewnode->pnext = nullptr;*/
		ptemp = new Node;
		ptemp->pnext = phead;
		ptemp->data = end;
		phead = ptemp;
		end--;
	}
		while (phead!=NULL)
	{
		cout << phead->data << endl;
		phead = phead->pnext;
	}
	cin.get();

}
