#pragma warning(disable : 4996).
#include <iostream>
//#include<cstring>
class String {
private:
	char* res;
	unsigned int len;


public:
	String() :res(nullptr), len(0)
	{

	}
	String(const char* ch) {
		len = strlen(ch);
		res = new char[len + 1];
		strcpy(res, ch);
	}
	String(const String& str) {
		if (str.res != nullptr) {
			len = str.len;
			res = new char[len + 1];
			strcpy(res, str.res);
		}
		
	}
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = res;
			delete[] res;
			len = str.len;
			res = new char[len + 1];
			strcpy(res,str.res);
			delete[] temp;

		}
		return* this;
	}
	unsigned int length() {
		return len;
	}
};




int main() {
	String str1;
	String str2 = "hello";
	String str3 = str1;
	str1 = str2;
	int len = str2.length();
	

	/*cout << str2;
	cin >> str1;*/
	//String str5(str1);
	return 0;
}