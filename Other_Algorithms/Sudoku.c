#include <stdio.h>
int sudoku[9][9];
int check(int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != y && sudoku[x][i] == sudoku[x][y])
			return 0;
		if (i != x && sudoku[i][y] == sudoku[x][y])
			return 0;
	}
	for (int i = (x / 3) * 3; i < (x / 3 + 1) * 3; i++)
		for (int j = (y / 3) * 3; j < (y / 3 + 1) * 3; j++)
			if (i != x && j != y && sudoku[i][j] == sudoku[x][y])
				return 0;
	return 1;
}

void trace(int x, int y)
{
	if (x == 9)
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d ", sudoku[i][j]);
			printf("\n");
		}
	else
	{
		if (sudoku[x][y] == 0)
			for (int i = 1; i <= 9; i++)
			{
				sudoku[x][y] = i;
				if (check(x, y))
					trace(x + (y + 1) / 9, (y + 1) % 9);
				sudoku[x][y] = 0;
			}
		else
			trace(x + (y + 1) / 9, (y + 1) % 9);
	}
}

int main(void)
{
	freopen("data.in", "r", stdin);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &sudoku[i][j]);		// 1 ~ 9, and 0
	trace(0, 0);
	return 0;
}
