#include<iostream>
#include<set>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;
int bruteforce(string& s,int maxsize) {
	for (int i = 0; i < s.length(); i++) {
	
		set<char>subset;
		for (int  j = i; j < s.length(); j++) {
			if (subset.find(s[j]) == subset.end()) {
				subset.insert(s[j]);
			}
			else
			{
				maxsize = max(int(subset.size()), maxsize);
				subset.clear();
			}
			
		}
	}
	return maxsize;
}
int mapmethod(string& s, int maxsize) {
	vector<int>mpp(256, -1);
	int left=0, right = 0;
	int n = (int)s.length();
	int len = 0;
	while (right < n) {
		if (mpp[s[right]]!=-1) {
			left = max(mpp[s[right]] + 1, left);
		}
		mpp[s[right]] = right;
		len = max(len, right - left + 1);
		right++;
	}
	return len;
}
pair<int,string> twopointer(string& s, int maxsize) 
{
	int len = (int)s.length();
	int start = 0;
	int l = 0, j = 0;
	string longsub = "";
	unordered_set<char>set;
	for (j; j < len; j++) {
		if (set.find(s[j]) != set.end()) {
			while (l < j && set.find(s[j])!=set.end()) {
				set.erase(s[l]);
				l++;
				
			}

		}

		set.insert(s[j]);
		/*maxsize = max(j - l + 1, maxsize);
		start = l;*/

		if (j - l + 1 > maxsize) {
			maxsize = j - l + 1;
			start = l;
		}
		
		//longsub= s.substr(start, maxsize);

	}
	return { maxsize,s.substr(start, maxsize)};
}
int main() {
	int maxsize = 0;
	string s = "ccadbzfyabcmdd";
	int sublen = bruteforce(s, maxsize);
	cout << sublen << endl;
}
//	//int msplen = mapmethod(s, maxsize);
//	pair<int, string> result = twopointer(s,maxsize);
//cout << sublen <<endl;
//	//cout << msplen << endl;
//	cout << result.first << endl;
//	cout << result.second << endl;
//	
//
//
//}
// 
//#include <iostream>
//#include <unordered_set>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//pair<int, string> twopointer(string& s) {
//    int len = s.length();
//    int l = 0, maxsize = 0;
//    int start_index = 0;
//    unordered_set<char> set;
//
//    for (int j = 0; j < len; j++) {
//        if (set.find(s[j]) != set.end()) {
//            while (l < j && set.find(s[j]) != set.end()) {
//                set.erase(s[l]);
//                l++;
//            }
//        }
//
//        set.insert(s[j]);
//        if (j - l + 1 > maxsize) {
//            maxsize = j - l + 1;
//            start_index = l;
//        }
//    }
//
//    string longest_substring = s.substr(start_index, maxsize);
//    return { maxsize, longest_substring };
//}
//
//int main() {
//    string s = "ccadbzfyabcmdd";
//    pair<int, string> result = twopointer(s);
//    cout << "The length of the longest substring without repeating characters is: " << result.first << endl;
//    cout << "The longest substring without repeating characters is: \"" << result.second << "\"" << endl;
//    return 0;
//}
