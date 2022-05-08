#include <iostream>		// 표준 입출력
#include <iomanip>		// 입출력 조작자 (특정한 형식으로 출력)
#include <fstream>		// 파일 입출력
#include <string>
using namespace std;	// std라는 namespace에 있는 것을 사용한다고 표시

void main() {
	/*
	int x, y;
	cout << "두 정수 입력: ";
	cin >> x >> y;
	cout << " x=" << x << " y=" << y
		<< " x+y=" << x + y << endl;	// endl: 한 라인으로 출력
	*/

	/*
	int x = 1, y = 2;
	char s[100];
	ofstream f1("tmp.txt");				// 저장을 위한 파일 열기
	if (f1) {							// 파일이 정상적으로 열렸으면
		f1 << x << " " << y << endl;	// 파일로 int값 저장
		f1 << "Game Over !\n\n";		// 파일로 문자열 저장
	}
	f1.close();							// 파일 닫기

	ifstream f2("tmp.txt");				// 읽기를 위한 파일 열기
	if (f2) {							// 파일 열렸으면
		f2 >> x >> y;					// 파일에서 x y 읽기
		f2 >> s;						// 파일에서 문자열 읽기 (>>는 공백을 문자열 끝으로 인식)
		cout << " x=" << x << " y=" << y << endl;
		cout << s << endl;
	}
	f2.close();
	*/

	string s1, s2 = "Game";
	s1.size(), s2.size();				// 문자열의 길이: 0, 5
	s1 = s2 + ' ' + "Over";				// 문자열 연결
	if (s1 == "Game Over")
		cout << s1 << "가 맞습니다\n";
	cout << s1.find("Over") << endl;	// 문자열 처음부터 "Over"검색, 위치 반환, 없으면 string::npos 또는 -1 반환
	cout << s1.find("e", 4) << endl;	// 4번 위치부터 e 검색, 위치 반환
	cout << s1[0] << endl;				// 0번째 요소 (G)
	cout << s1.substr(5, 4) << endl;	// s1[5]부터 시작하는 길이 4의 문자열 추출
	printf("s1 = %s\n", s1.c_str());	// string에서 문자 배열 주소(char*) 추출
	getline(cin, s1);					// 표준 입력에서 '\n'로 끝나는 한 줄 입력
	cout << s1 << endl;

}