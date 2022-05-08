#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
// ��(��, row) ��(|, column)
class Matrix {
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {	// ������
		mat = new int* [rows];
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];
	}
	~Matrix() {								// �Ҹ���
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i];			// �� �� �޸� ��ȯ
			delete[] mat;					// �� �޸� ��ȯ
		}
	}
	int& elem(int x, int y) { return mat[y][x]; }	// �����ڸ� ��ȯ, l-value�� ��� ����
	int Rows() { return rows; }		// �� ��ȯ
	int Cols() { return cols; }		// �� ��ȯ
	int** Data() { return mat; };	// mat ��ȯ  �ܺο��� ���ϰ� ����Ϸ��� �����
	void print(const char* str = "Mat") {
		cout << str << " " << rows << "x" << cols << endl;	// �� by �� ������� ���
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << setw(4) << mat[i][j];	// �� ���
			cout << "\n";
		}
	}
	void setRand(int val = 100) {					// ���� ��� ����
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mat[i][j] = (rand() % val);
		}
	}

};