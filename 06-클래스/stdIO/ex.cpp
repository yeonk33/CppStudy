#include <iostream>		// ǥ�� �����
#include <iomanip>		// ����� ������ (Ư���� �������� ���)
#include <fstream>		// ���� �����
#include <string>
using namespace std;	// std��� namespace�� �ִ� ���� ����Ѵٰ� ǥ��

void main() {
	/*
	int x, y;
	cout << "�� ���� �Է�: ";
	cin >> x >> y;
	cout << " x=" << x << " y=" << y
		<< " x+y=" << x + y << endl;	// endl: �� �������� ���
	*/

	/*
	int x = 1, y = 2;
	char s[100];
	ofstream f1("tmp.txt");				// ������ ���� ���� ����
	if (f1) {							// ������ ���������� ��������
		f1 << x << " " << y << endl;	// ���Ϸ� int�� ����
		f1 << "Game Over !\n\n";		// ���Ϸ� ���ڿ� ����
	}
	f1.close();							// ���� �ݱ�

	ifstream f2("tmp.txt");				// �б⸦ ���� ���� ����
	if (f2) {							// ���� ��������
		f2 >> x >> y;					// ���Ͽ��� x y �б�
		f2 >> s;						// ���Ͽ��� ���ڿ� �б� (>>�� ������ ���ڿ� ������ �ν�)
		cout << " x=" << x << " y=" << y << endl;
		cout << s << endl;
	}
	f2.close();
	*/

	string s1, s2 = "Game";
	s1.size(), s2.size();				// ���ڿ��� ����: 0, 5
	s1 = s2 + ' ' + "Over";				// ���ڿ� ����
	if (s1 == "Game Over")
		cout << s1 << "�� �½��ϴ�\n";
	cout << s1.find("Over") << endl;	// ���ڿ� ó������ "Over"�˻�, ��ġ ��ȯ, ������ string::npos �Ǵ� -1 ��ȯ
	cout << s1.find("e", 4) << endl;	// 4�� ��ġ���� e �˻�, ��ġ ��ȯ
	cout << s1[0] << endl;				// 0��° ��� (G)
	cout << s1.substr(5, 4) << endl;	// s1[5]���� �����ϴ� ���� 4�� ���ڿ� ����
	printf("s1 = %s\n", s1.c_str());	// string���� ���� �迭 �ּ�(char*) ����
	getline(cin, s1);					// ǥ�� �Է¿��� '\n'�� ������ �� �� �Է�
	cout << s1 << endl;

}