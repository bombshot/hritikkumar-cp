#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class Matrix
{
	public:
		vector<vector<int>> mat; 
		int noRows, noColumn;
	public:
		Matrix()
		{
			// do nothing
		}
		Matrix(vector<vector<int>> newMatrix)
		{
			mat = newMatrix;
			noRows = newMatrix.size(),
			noColumn = newMatrix[0].size(); // destructuring
		}
		
		void addTwoMatrices(Matrix *mat2)
		{
			if(noRows != mat2->noRows || noColumn != mat2->noColumn)
			{
				cout<<"WRONG OPERATION!!! IT DOESN't FOLLOW RULES OF NO OF COLUMNS & NO OF ROWS SHOULD BE SAME";
				return;
			}
			vector<vector<int>> matSum = mat;
			for(int rowIndex = 0; rowIndex < noRows; rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < noColumn; colIndex += 1)
				{
					matSum[rowIndex][colIndex] += mat2->mat[rowIndex][colIndex]; // add each value at i,j position
				}
			}
			cout<<"SUM OF MATRICES:"<<endl;
			for(int rowIndex = 0; rowIndex < noRows; rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < noColumn; colIndex += 1)
				{
					cout<<matSum[rowIndex][colIndex]<<" " ;
				}
				cout<<endl;
			}
		}
		
		void mulTwoMatrices(Matrix *mat2)
		{
			if( noColumn != mat2->noRows)
			{
				cout<<"WRONG OPERATION!!! IT DOESN't FOLLOW RULES OF NO OF COLUMNS & NO OF ROWS SHOULD BE SAME";
				return;
			}
			vector<vector<int>> matMul(noRows, vector<int>(mat2->noColumn, 0)); // multiplication matrix
			for(int rowIndex = 0; rowIndex < noRows; rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < (signed) matMul[0].size(); colIndex+=1)
				{
					for(int mat1RowIndexK = 0; mat1RowIndexK < noRows; mat1RowIndexK +=1)
					{
						matMul[rowIndex][colIndex] += mat[rowIndex][mat1RowIndexK] * mat2->mat[mat1RowIndexK][colIndex];
					}
				}
			}
			cout<<"Multiplication OF MATRICES:"<<endl;
			for(int rowIndex = 0; rowIndex < (signed) matMul.size(); rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < (signed) matMul[0].size(); colIndex += 1)
				{
					cout<<matMul[rowIndex][colIndex]<<" " ;
				}
				cout<<endl;
			}
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fast io
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int r, c;
	cin>>r>>c;
	vector<vector<int>> matrix1(r, vector<int>(c));
	for(int rIndex = 0; rIndex < r; rIndex+=1)
	{
		for(int cIndex = 0; cIndex < c; cIndex += 1)
		{
			cin>>matrix1[rIndex][cIndex]; // taking input
		}
	}
	
	Matrix *mat1 = new Matrix(matrix1); // matrix 1
	
	cin>>r>>c; // overrighting the variables 
	vector<vector<int>> matrix2(r, vector<int>(c));
	for(int rIndex = 0; rIndex < r; rIndex+=1)
	{
		for(int cIndex = 0; cIndex < c; cIndex += 1)
		{
			cin>>matrix2[rIndex][cIndex]; // taking input
		}
	}
	
	Matrix *mat2 = new Matrix(matrix2); // matrix 2;
	
	mat1 -> addTwoMatrices(mat2);
	mat1 -> mulTwoMatrices(mat2); 
	
	return 0; // return type is int
}
