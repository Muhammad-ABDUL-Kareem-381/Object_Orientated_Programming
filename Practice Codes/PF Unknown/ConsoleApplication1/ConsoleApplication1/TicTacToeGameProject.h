#include "GameBoard.h"
#ifndef TICTACTOEGAMEPROJECT_H
#define TICTACTOEGAMEPROJECT_H
class TicTacToe
{
public:
	void playGame();
};
char selectPlayer1Symbol();
bool validSymbol(char symbol);
char selectPlayer2Symbol(char player1Symbol);
void getTurn(char player1Symbol);
void getDecision(char player1Symbol, char player2Symbol);
PlayerTurn	changePlayer(PlayerTurn currentPlayer);
#endif
