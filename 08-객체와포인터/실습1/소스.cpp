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
		cout << "������ ȣ�� " << name << endl; 
	}
	~Sample() { 
		cout << "�Ҹ��� ȣ�� " << name << endl; 
		delete name;
	}
	void printCount(const char* str = "�������� count = ") { cout << str << count << endl; }
};
int Sample::count = 0;
void main() {
	Sample a("sample");
	//Sample b(a);
	a.printCount("��ü a�� �������� count = ");
}