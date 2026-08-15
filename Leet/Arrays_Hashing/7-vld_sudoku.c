#include <stdio.h>

int	vld_sudoku(char **b)
{
	int row[9][10] = {0};
	int col[9][10] = {0};
	int box[9][10] = {0};
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c = b[i][j];
			if (c < '1' && c > 9)
				continue;
			int n = c - '0';
			int box_id = (i/3) * 3 + (j/3);
			if (row[i][n] || col[j][n] || box[box_id][n])
				return (0);
			row[i][n] = 1;
			col[j][n] = 1;
			box[box_id][n] = 1;
		}
	}
	return (1);
}

int	main()
{
	char *board[10] = {
	"123456789",
	"234567891",
	"345678912",
	"456789123",
	"567891234",
	"678912345",
	"789123456",
	"891234567",
	"912345678",};
	if (vld_sudoku(board))
		printf("true\n");
	else
		printf("false\n");
	return(0);
}
