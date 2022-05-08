#include <iostream>
using namespace std;
class Sample {
	const char* name;
public:
	static int count;
	Sample(){}
	Sample(const char* name) {
		name = new char[5];
		this->name = name;
		cout << "생성자 호출 " << name << endl; 
	}
	~Sample() { 
		cout << "소멸자 호출 " << name << endl; 
		delete name;
	}
	void printCount(const char* str = "정적변수 count = ") { cout << str << count << endl; }
};
int Sample::count = 0;
void main() {
	Sample a("sample");
	//Sample b(a);
	a.printCount("객체 a의 정적변수 count = ");
}