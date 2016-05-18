Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int row[9],col[9];
		
		for(int i = 0; i < 9; i++)
		{
			memset(row,0,sizeof(int)*9);
			memset(col,0,sizeof(int)*9);
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.')
				{
					if(row[board[i][j]-'1'] > 0)return false;
					else row[board[i][j]-'1']++;
				}
				if(board[j][i] != '.')
				{
					if(col[board[j][i]-'1'] > 0)return false;
					else col[board[j][i]-'1']++;
				}
			}
		}

		for(int i = 0; i < 9; i+=3)
			for(int j = 0; j < 9; j+=3)
			{
				memset(row,0,sizeof(int)*9);
				for(int a = 0; a < 3; a++)
					for(int b= 0; b < 3; b++)
						if(board[i+a][j+b] != '.')
						{
							if(row[board[i+a][j+b]-'1']>0)return false;
							else row[board[i+a][j+b]-'1']++;
						}
			}
        return true;
}