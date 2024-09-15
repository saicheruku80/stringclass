#include<iostream>
using namespace std;
#include <vector>
void combsum(int num[], int len, vector<int>& ds, int i)
{
	if (i == len)
	{
			for (auto it : ds) 
			{
				cout << it;
			}
			cout << endl;
		return;
	}


	ds.push_back(num[i]);
	combsum(num, len, ds, i + 1);
	ds.pop_back();
	combsum(num, len, ds, i + 1);

}



int main() {

	int num[] = { 1, 2, 3};


	vector<int> ds;
	combsum(num, sizeof(num) / sizeof(num[0]), ds, 0);
	getchar();

}