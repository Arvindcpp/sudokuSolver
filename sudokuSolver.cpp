#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>> board)
{
	for(auto a:board)
	{
		for(auto b:a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	
	bool check(vector<vector<char>> board, int r, int c, int val)
	{
			//check row
			for(int i=0; i<9; i++)
			{
				if(board[i][c] == val)
				return false;
			}
			
			//check col
			for(int i=0; i<9; i++)
			{
				if(board[r][i] == val)
				return false;
			}
			//check 3x3
			int x = r - r%3;	int y = c - c%3;
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					if(board[x+i][y+j] == val)
						return false;
				}
			}
			return true;
	}
	
	bool solver(vector<vector<char>>& board, int r, int c)
	{
		if(r == 9)
		return true;
		else if(c == 9)	return solver(board,r+1, 0);
		else if(board[r][c] != '.') return solver(board,r, c+1);
		
		for(char ch = '1'; ch<= '9'; ch++)
		{
			if(check(board, r, c, ch))
			{
				board[r][c] = ch;
				if(solver(board, r, c+1))	return true;
				board[r][c] = '.';
			}
		}
		return false;
	}

    void solveSudoku(vector<vector<char>>& board) {
		solver(board, 0, 0);
	}
};


int main()
{
	vector<vector<char>> board =   					{
									{'5','3','.', '.','7','.', '.','.','.'},
									{'6','.','.', '1','9','5', '.','.','.'},
									{'.','9','8', '.','.','.', '.','6','.'},
									
									{'8','.','.', '.','6','.', '.','.','3'},
									{'4','.','.', '8','.','3', '.','.','1'},
									{'7','.','.', '.','2','.', '.','.','6'},
									
									{'.','6','.', '.','.','.', '2','8','.'},
									{'.','.','.', '4','1','9', '.','.','5'},
									{'.','.','.', '.','8','.', '.','7','9'}
									};

	Solution s1;
	s1.solveSudoku(board);
	print(board);
}
