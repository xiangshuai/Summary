#include "searchMatrix.h"
#include "searchRange.h"
int main() {
	//vector<vector<int>> mat(2, vector<int>(3, 0));
	//mat[0][0] = 1;
	//mat[0][1] = 3;
	//mat[0][2] = 5;
	//mat[1][0] = 3;
	//mat[1][1] = 11;
	//mat[1][2] = 16;
	//Solution sl;
	//sl.searchMatrix(mat, 3);
	int a[6] = {9,10,100,101,1002,10203};
	vector<int> A(a, a+6);
	SRSolution srsl;
	srsl.searchRange(A, 10203);
}

