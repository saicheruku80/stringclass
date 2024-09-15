#include<iostream>
using namespace std;
#include <vector>
void combsum(int num[], int len, int sum, vector<int>& ds, int internalsum, int i)
{
	if (i == len)
	{
		if (internalsum == sum)
		{
			for (auto it : ds) {
				cout << it;
			}
			cout << endl;
		}
		return;
	}	
		internalsum = internalsum + num[i];
		ds.push_back(num[i]);		
		combsum(num, len, sum, ds, internalsum,i+1);
		internalsum = internalsum-num[i];
		ds.pop_back();
		combsum(num, len, sum, ds, internalsum, i + 1);

}


int main() {

	int num[] = { 1, 2, 3,1,1,4};
	int sum = 3; int internalsum = 0;

	vector<int> ds;
	combsum(num, sizeof(num) / sizeof(num[0]),sum,ds, internalsum,0);
	getchar();
	
}