#include<iostream>
using namespace std;
#include <vector>
void combsum(int num[], int len, vector<int>& ds, int freq[])
{
	if (ds.size() == len)
	{
		for (auto it : ds)
		{
			cout << it;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		
		if (freq[i] == 0)
		{
			ds.push_back(num[i]);
			freq[i] = 1;

			combsum(num, len, ds, freq);
			ds.pop_back();
			freq[i] = 0;
		}
		
		//combsum(num, len, ds, index + 1, freq);

	}
}



int main() {

	int num[] = { 1, 2, 3 };

	vector<int> ds;
	int freq[sizeof(num) / sizeof(num[0])] = { 0 };
	combsum(num, sizeof(num) / sizeof(num[0]),ds,freq);
	getchar();

}