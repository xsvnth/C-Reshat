#include <stdio.h>

int valid_sudoku(char b[9][10])
{
	int row[9][10] = {0};
	int col[9][10] = {0};
	int box[9][10] = {0};
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c = b[i][j];
			if (c < '1' || c > '9')
				continue;
			int n = c - '0';
			int box_id = (i / 3) * 3 + (j / 3);
			if (row[i][n] || col[j][n] || box[box_id][n])
				return 0;
			row[i][n] = 1;
			col[j][n] = 1;
			box[box_id][n] = 1;
		}
	}
	return 1;
}

int main(void)
{
	char board[9][10] = {
		"534678912",
		"672195348",
		"198342567",
		"859761423",
		"426853791",
		"713924856",
		"961537284",
		"287419635",
		"345286179"
	};

	if (valid_sudoku(board))
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
