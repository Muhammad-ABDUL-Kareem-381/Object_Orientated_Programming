#include <iostream>
#include "TicTacToeGameProject.h"
#include "GameBoard.h"
using namespace std;
GameBoard board;
PlayerTurn currentPlayer = FIRST_PLAYER;
char cellNumber;
char currentPlayerSymbol;
void TicTacToe::playGame()
{
	char currentSymbol;
	char player1Symbol = selectPlayer1Symbol();
	char player2Symbol = selectPlayer2Symbol(player1Symbol);
	while ( board.getGameStatus() == IN_PROGRESS )
	{
		board.displayBoard();
		currentSymbol = (currentPlayer == FIRST_PLAYER) ? player1Symbol : player2Symbol;
		getTurn(currentSymbol);
		getDecision(player1Symbol, player2Symbol);
		currentPlayer = changePlayer(currentPlayer);
	}
}
char selectPlayer1Symbol()
{
	char symbol;
	bool validSymbolSt;
	do
	{
		cout << "Enter Player 1 Symbol: ";
		cin >> symbol;
		validSymbolSt = validSymbol(symbol);
		if (!validSymbolSt)
			cout << "Not A Valid Symbol\n";
	}
	while (!validSymbolSt);
	return symbol;
}
bool validSymbol(char symbol)
{
	if ((symbol >= '1') && (symbol <= '9'))
		return false;
	else
		return true;
}
char selectPlayer2Symbol(char player1Symbol)
{
	char symbol;
	bool validSymbolSt;
	do
	{
		cout << "Enter Player 2 Symbol: ";
		cin >> symbol;
		validSymbolSt = validSymbol(symbol);
		if ((!validSymbolSt) || (symbol == player1Symbol))
			cout << "Not a valid Symbol\n";
	} while ((!validSymbolSt) || (symbol == player1Symbol));
	return symbol;
}
void getTurn(char player1Symbol)
{
	int cellNumber;
	bool validMoveSt = false;
	do
	{
		cout << "\nPlayer " << currentPlayer << " Turn: Enter Position: ";
		cin >> cellNumber;
		if (board.isValidPosition(cellNumber) && ! board.isAlreadyMarked(cellNumber))
		{
			board.markBoard(cellNumber, player1Symbol);
			validMoveSt = true;
		}
	}
	while (!validMoveSt);
}
void getDecision(char player1Symbol, char player2Symbol)
{
	if (board.getGameStatus() == WIN)
	{
		board.displayBoard();
		cout << "\nGame Won by Player : " << currentPlayer << '\n';
	}
	else if (board.getGameStatus() == DRAW)
	{
		cout << "\nGame DrawX\n";
	}
	else
	{
		currentPlayerSymbol = (currentPlayer == FIRST_PLAYER ? player2Symbol : player1Symbol);
		currentPlayer = changePlayer(currentPlayer);
	}
}
PlayerTurn	changePlayer(PlayerTurn currentPlayer)
{
	return (currentPlayer == FIRST_PLAYER ) ? SECOND_PLAYER : FIRST_PLAYER;
}
