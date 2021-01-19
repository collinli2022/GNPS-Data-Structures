// Collin Li
// Data Structures H
// 9/15/2020
// Classwork 4a
/*
Create an enumerated type to keep
track of the pieces on a chessboard
(ROOK, KNIGHT, etc. but EMPTY
is also an option). Then declare a 2-
dimensional array that represents the
board itself (the type is the name of
your enum). Fill the board.
*/

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum PIECES {EMPTY, PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING};

// Prints the board (duh)
void printBoard(PIECES board [8][8]) {
	for (int i = 0; i < 8; i++) { // loop thru rows
		for (int j = 0; j < 8; j++) { // loop thru col	
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// Start of the program
int main() {
	// White Square on Right.. Black on Left
	PIECES board[8][8];
	// Set up board with empty
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {	
			board[i][j] = EMPTY;
		}
	}
	// Set up ends
	for (int i = 0; i < 2; i++) {
		board[i*7][0] = ROOK;
		board[i*7][1] = KNIGHT;
		board[i*7][2] = BISHOP;
		board[i*7][3] = QUEEN;
		board[i*7][4] = KING;
		board[i*7][5] = BISHOP;
		board[i*7][6] = KNIGHT;
		board[i*7][7] = ROOK;
	}
	// Set up pawns
	for (int i = 1; i < 10; i = i+5) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = PAWN;
		}
 	}
	// print the board
	printBoard(board);
	
	return 0;
}
