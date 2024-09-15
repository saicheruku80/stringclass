//#include<iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* pnext;
//};
//int main() {
//	Node* ptemp = nullptr;
//	Node* phead = nullptr;
//	int end = 10;
//	int i = 1;
//	
//
//	while (i != end+1) 
//	{
//		Node* pnewnode = new Node;
//		pnewnode->data = i;
//		pnewnode->pnext = nullptr;
//		if (phead == nullptr) {
//			phead = pnewnode;
//		}
//		else {
//			ptemp = phead;
//			while (ptemp->pnext!=nullptr) {
//				ptemp = ptemp->pnext;
//			}
//			ptemp->pnext = pnewnode;
//		}
//		i++;
//	}
//
//	while (phead!=NULL)
//	{
//		cout << phead->data << endl;
//		phead = phead->pnext;
//	}
//	cin.get();
//}

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
