//int** alloc2DInt(int rows, int cols) {
//	int** mat = new int* [rows];		// 포인터 변수를 저장할 배열 (**)
//	for (int i = 0; i < rows; i++)
//		mat[i] = new int [cols];		// 각 행(ㅡ)의 데이터를 저장할 배열
//	return mat;
//}
//// 행(ㅡ, row) 열(|, column)
//
//void free2DInt(int** mat, int rows, int cols = 0) {
//	for (int i = 0; i < rows; i++)
//		delete[] mat[i];
//	delete[] mat;
//}