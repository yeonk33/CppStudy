#include "Matrix.h"
int findMaxPixel(int** a, int rows, int cols) {		// 최대값 찾는 함수
	int max = a[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (max < a[i][j]) max = a[i][j];
	return max;
}
void main() {
	Matrix u(3, 6);
	u.setRand();		// 난수 행렬을 만들어서
	u.print(" U = ");
	cout << "Max Pixel Value = "
		<< findMaxPixel(u.Data(), u.Rows(), u.Cols())	// 최대값 찾아서 출력
		<< endl;
}
// 행(ㅡ, row) 열(|, column)