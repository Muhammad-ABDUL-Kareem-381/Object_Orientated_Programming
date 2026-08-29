#include<iostream>
#include "TicTacToeGameProject.h"
#include "GameBoard.h"
using namespace std;
GameBoard::GameBoard()
{
	for (int i = 0; i <=2 ; i++)
	{
		for (int j = 0; j <= 2; j++)
			GameBoard::data [i] [j] = (i) * 3+ (j+1) + '0';
	}
}
void GameBoard::displayBoard()
{
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << GameBoard::data[i][j] << ' ';
		}
		cout << '\n';
	}
}
int GameBoard::getValidMovesCount()
{
	int validMovesCnt = 0;
	for (int i = 0; i < 9; i++)
	{
		if (GameBoard::data[0][i] !=  (i + 1) + '0')
		{
			validMovesCnt++;
		}
	}
	return validMovesCnt;
}
GameStatus GameBoard::getGameStatus()
{
	if ( getValidMovesCount() == 0)
		return IN_PROGRESS;
	for (int i = 0; i < 3; i++)
	{
		if ((GameBoard::data[0][i] == GameBoard::data[1][i]) && (GameBoard::data[0][i] == GameBoard::data[2][i]) )
		{
			return WIN;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if ((GameBoard::data[i][0] == GameBoard::data[i][1]) && (GameBoard::data[i][0] == GameBoard::data[i][2]))
			return WIN;
	}
	if ((GameBoard::data[0][0] == GameBoard::data[1][1]) && (GameBoard::data[0][0] == GameBoard::data[2][2]))
		return WIN;
	if ((GameBoard::data[0][2] == GameBoard::data[1][1]) && (GameBoard::data[0][2] == GameBoard::data[2][0]))
		return WIN;
	int validMovesCnt = getValidMovesCount();
	if (validMovesCnt < 9)
		return IN_PROGRESS;
	else
		return DRAW;
}
bool GameBoard::isValidPosition(char pos)
{
	if (pos > 0 && pos <= 9)
	{
		return true;
	}
	else
	{
		cout << "\t Invalid Index Entered!";
		return false;
	}
	//return pos > 0 && pos <= 9 ? true: false;
}
bool GameBoard::isAlreadyMarked(char pos)
{
	return (GameBoard::data[0][pos - 1] > '0' && GameBoard::data[0][pos - 1]) <= '9' ? false : true;
}
void GameBoard::markBoard (char pos, char symbol)
{
	pos--;
	int i, j;
	i =pos/3;
	j = pos % 3;
	cout << '[' << i << ']';
	cout << ' ' << '[' << j << ']';
	GameBoard::data[i][j] = symbol;
}





