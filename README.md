# sudokuSolver

There are functions
1) check() -> To check if the value we are trying to insert in available or not
2) solver() ->performs backtracking

check()
checks given row, col and 3X3 grid for given value, if either of them goes false, control comes out of the loop
else returns true, implying that this value is a possibility.

solver()


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
  
  as shown above, following are some default conditions we need to take care of before we go on into the main loop
  i)if row becomes 9, this means that all the previous ones were correct so that sudoku must be solved. return true
  ii)if col becomes 9, means col reached the end and need to go into the next row.
  iii)if we find some number that wasnt a number we return next column
  
  Now, onto the main loop,
  we run a loop from 1 to 9 and check if any one of them is true. If its true, then we fill the given row and col with the given value and check further down the             line, calling the function again in recursive way, if this solver was false, we reset the value and continue the for loop.
