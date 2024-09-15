#include<iostream>
using namespace std;
template <typename T>
class uniqueptr
{
private:
	T* res;
public:
	uniqueptr(T* a = nullptr) :res(a)
	{
		cout << "constructor\n";
	}
	uniqueptr(const uniqueptr<T>& ptr) = delete;
	uniqueptr& operator=(const uniqueptr<T>& ptr) = delete;

	uniqueptr(uniqueptr<T>&& ptr)
	{
		res = ptr.res;
		ptr.res = nullptr;
	}
	uniqueptr& operator=(uniqueptr<T>&& ptr)
	{
		if (this != &ptr)
		{
			if (res)
			{
				delete res;
			}
			res = ptr.res;
			ptr.res = nullptr;
		}
		return *this;
	}
	T*operator->() {
		return res;
	}
	T& operator*() {
		return *res;
	}
	T* get() {
		return res;
	}
	void reset(T* newres=nullptr) {
		if (res) {
			delete res;
		}
		res = newres;
	}
	~uniqueptr() {
		cout << "destructor\n";
		if (res) {
			delete res;
			res = nullptr;
		}
	}
};



int main() {
	uniqueptr<int>ptr1(new int(2));
	//uniqueptr<int>ptr2(ptr1);
	//uniqueptr<int>ptr3 = ptr1;
	uniqueptr<int>ptr4(new int(60));
	//ptr4 = ptr1;
	uniqueptr<int>pt(new int(50));
	uniqueptr<int>ptr3 = std::move(ptr1);
	ptr4 = std::move(pt);

	//ptr1->fun();
	//cout << *ptr1;
	ptr1.get();
	ptr1.reset(new int(30));

	return 0;
}