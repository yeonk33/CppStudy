//int** alloc2DInt(int rows, int cols) {
//	int** mat = new int* [rows];		// ������ ������ ������ �迭 (**)
//	for (int i = 0; i < rows; i++)
//		mat[i] = new int [cols];		// �� ��(��)�� �����͸� ������ �迭
//	return mat;
//}
//// ��(��, row) ��(|, column)
//
//void free2DInt(int** mat, int rows, int cols = 0) {
//	for (int i = 0; i < rows; i++)
//		delete[] mat[i];
//	delete[] mat;
//}