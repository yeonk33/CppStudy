#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>	// getch()
using namespace std;

class Hangman {
	string progress[64];	// ��� ���� ���� �׸�
	string problem;			// ����
	string answer;			// ���� ���� �ܾ�
	string guessed;			// ������� ���� ��Ȳ
	int nTries;				// Ʋ�� Ƚ��
	const int maxTries = 7;	// �ִ� ���� Ƚ�� (����)

	void load(const char* filename = "HangmanProgress.txt") {
		ifstream fs(filename);				// ������ ���� ���� ����
		if (fs) {							// ������ ���������� ��������
			getline(fs, progress[0]);		// ù ���� �ּ�
			for (int i = 0; i < 64; i++)
				getline(fs, progress[i]);	// �� �྿ ����
		}
		//fs.close();
	}
	void print() {
		system("cls");
		cout << " <Hangman Game>\n";
		for (int i = 0; i < 8; i++)
			cout << '\t' << progress[nTries * 8 + i] << endl;
		cout << "\n\t" << answer;
		cout << "\n\t" << guessed;
	}
	int countMatched(char ch) {	// ������ ���ڰ� ����� ��ġ�ϴ� ���� ��ȯ
		int matched = 0;
		for (int pos = -1;;) {
			pos = problem.find(ch, pos + 1);
			if (pos < 0) break;
			answer[pos] = ch;
			matched++;
		}
		/*for (int i = 0;; i++) {
			if (problem[i] == ch) {
				matched++;
				answer[i] = ch;
			}			
			if (problem[i] == '\n') break;
		}*/
		return matched;
	}
	void guess() {
		char ch = _getch();	// �� ���� �Է� �ް�
		if (ch >= 'a' && ch <= 'z') {
			int pos = guessed.find(ch);
			if (pos < 0) {				// ���� �������� ���� ����
				guessed[ch - 'a'] = ch;	// �������� ������ ���ڴ� ǥ��
				if (countMatched(ch) == 0) nTries++;	// ����++
			}
		}
	}

public:
	void play(string prob) {
		load();
		problem = prob;
		answer = string(problem.length(), '-');	// ������ ���, ����ܾ� ���̸�ŭ - ǥ��
		guessed = string(24, '.');				// ������ ���, ���ĺ� 24���� ��� .���� ǥ��
		nTries = 0;								// ���� Ƚ�� �ʱ�ȭ
		while (nTries < maxTries && answer != problem) {
			print();
			guess();
		}
		print();	// ���� ���� �� ���� ���
		cout<<"\n\t"<<((nTries == maxTries) ? "����" : "����") << endl;
	}
};