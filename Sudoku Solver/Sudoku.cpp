#include "Sudoku.h"


sudoku::sudoku()
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0;  col < 9; col++)
		{
			grid[row][col] = 0;
		}
	}
}

sudoku::sudoku(int g[9][9])
{
	initializeSudokuGrid(g);
}

bool sudoku::solveSudoku(int r, int c)
{
	int row = r, col = c;
	if (findEmptyGridSlot(row, col))
	{
		for (int num = 1; num <= 9; num++)
		{
			if (canPlaceNum(row, col, num))
			{
				grid[row][col] = num;
				if (solveSudoku(row, col)) //recursive
					return true;
				grid[row][col] = 0;
			}
		}
		return false;
	}
	else
	{
		cout << "The solution is:" << endl;
		cout << endl;
		sudoku::printSudokuGrid();
		return true;
	}
}

void sudoku::initializeSudokuGrid()
{

}

void sudoku::initializeSudokuGrid(int g[9][9])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			grid[row][col] = g[row][col];
		}
	}
}

void sudoku::printSudokuGrid()
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			cout << grid[row][col] << "     ";
		}
		cout << endl;
	}
}

bool sudoku::findEmptyGridSlot(int& row, int& col)
{
	if (grid[row][col] == 0)
		return true;
	else if(col < 8 && row <=8)
	{
		col++;
			if (findEmptyGridSlot(row, col))
			return true;
	}
	else if (col >= 8 && row < 8)
	{
		row++;
		col = 0;
		if (findEmptyGridSlot(row, col))
			return true;
	}
		return false;
}

bool sudoku::canPlaceNum(int row, int col, int num)
{

	for (int i = 0; i <= 8; i += 3) //traversing rows 0, 3, 6
	{
		for (int j = 0; j <= 8; j += 3) //traversing colums 0, 3, 6
		{
			if (row >= i && row <= i+2 && col >= j && col <= j + 2) //finding given coordinate's subsection
			{
				if (numAlreadyInBox(i, j, num))
					return false;
				else if (!numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) && grid[row][col] == 0) //check if num can be placed in subsection.
					return true;
				else
					return false;
			}
		}
	}
		return false;
}

bool sudoku::numAlreadyInRow(int row, int num)
{
	for (int i = 0; i <= 8; i++)
	{
		if (grid[row][i] == num)
			return true;
	}

	return false;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
	for (int j = 0; j <= 8; j++)
	{
		if (grid[j][col] == num)
			return true;
	}

	return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[smallGridRow+i][smallGridCol+j] == num)
				return true;
		}
	}
	return false;
}
