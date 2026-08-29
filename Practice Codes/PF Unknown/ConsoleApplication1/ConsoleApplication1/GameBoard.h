#ifndef GAMEBOARD_H
#define GAMEBOARD_H
enum GameStatus {WIN, DRAW, IN_PROGRESS};
enum PlayerTurn { FIRST_PLAYER=1, SECOND_PLAYER =2};
//enum Symbols {FIRST_PLAYER_SYMBOL, SECOND_PLAYER_SYMBOL};
class GameBoard
{
public:
	char data[3][3];
	GameBoard();
	void displayBoard();
	bool isValidPosition(char);
	bool isAlreadyMarked(char);
	void markBoard(char pos, char symbol);
	int getValidMovesCount();
	GameStatus getGameStatus();
};
#endif