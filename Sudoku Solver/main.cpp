#include "pch.h"
#include <iostream>
#include "sudoku.h"

int main()
{

	int randomGrid[9][9] = { 
								{8,0,0,0,0,0,0,0,0},
								{0,0,3,6,0,0,0,0,0},
								{0,7,0,0,9,0,2,0,0},
								{0,5,0,0,0,7,0,0,0},
								{0,0,0,0,4,5,7,0,0},
								{0,0,0,1,0,0,0,3,0},
								{0,0,1,0,0,0,0,6,8},
								{0,0,8,5,0,0,0,1,0},
								{0,9,0,0,0,0,4,0,0}
							};
	sudoku mySudoku(randomGrid);

	cout << "The sudoku is:" << endl;
	cout << endl;
	mySudoku.printSudokuGrid();
	cout << endl;
	cout << endl;
	
	if (!mySudoku.solveSudoku(0, 0))
		cout << "No solution. Sudoku is NOT possible to solve.";
	

	return 0;
}


/*sample sudoku grid
								{0,0,0,0,8,0,0,0,0},
								{8,0,9,0,7,1,0,2,0},
								{4,0,3,5,0,0,0,0,1},
								{0,0,0,1,0,0,0,0,7},
								{0,0,2,0,3,4,0,8,0},
								{7,3,0,0,0,9,0,0,4},
								{9,0,0,0,0,0,7,0,2},
								{0,0,8,2,0,5,0,9,0},
								{1,0,0,0,4,0,3,0,0}}
								*/