// @hritikkumar

#include<bits/stdc++.h> // al header files

#define endl '\n'

using namespace std; //namespace created as std 

void backtracking(int**, int , int , int , long long int &, int);

long long int calculateNoOfWays(int);
int ittr = 0;
int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt" ,"r", stdin); 
	freopen("output.txt" , "w", stdout); 
	#endif
	
	int n;
	cin>>n;
	
	long long int ans = calculateNoOfWays(n); 
	cout<<ans<<endl;
	
	
	cout<<"ITR: "<<ittr<<endl;
	return 0; //return type is int
}
/*
 * This is 6 X 6 board
							________________________
						->|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_|
							|_|_||_|_||_|_||_|_||_|_||_|_| <-
	*/
	
void backtracking(int **a ,int n, int i, int j , long long int &ans, int cells)
{
	if( i< 0 || j < 0 || i > n-1 || j > n-1 || a[i][j] == 1 )
		return;
	
	a[i][j] = 1;
	cells +=1;
	 if(i== n-1 && j==n-1 &&  cells == n*n)
	{
		cells +=1;
		a[i][j] = 1;
		cout<<i<<" +++ "<<j<<endl;
		ans++;
		a[i][j] = 0;
		return;
	}
	cout<<endl;
	for(int row=0;row<n;row++)
	{
		for(int col=0; col < n; col++)
		{
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
	ittr++;
	cout<<endl;
	backtracking(a, n, i-1, j, ans , cells);
	backtracking(a, n, i, j-1, ans, cells );
	backtracking(a, n, i+1, j, ans, cells );
	backtracking(a, n, i, j+1, ans, cells);
	a[i][j] = 0;
}
long long int calculateNoOfWays(int n)
{
	int** board = new int*[n];
	for(int i=0;i<n;i++) board[i] = new int[n];
	
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) board[i][j] = 0;
	// 0 mean not visited and 1 means that It has been visited!
	long long int ans = 0;
	int cellTouch = 0;
	backtracking(board, n, 0, 0, ans, cellTouch);
	return ans; //return type is long long int
}
