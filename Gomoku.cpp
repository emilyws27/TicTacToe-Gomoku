#include "Gomoku.h"
#include "Common.h"
#include <iomanip>

/*
Lab4.cpp
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeff Mao, jeff.m@wustl.edu
Functions to play the Gomoku game
*/

using namespace std;

Gomoku::Gomoku() : B(game_pieces("B", "B")), W(game_pieces("W", "W")) {
	//constructor for a gomoku board; makes a 20x20 board with empty spaces
	game_pieces gomoku_board[gomoku_board_dim][gomoku_board_dim];		//enum
	longest_string = 2;
	for (int i = 0; i < gomoku_board_dim; i++) {
		for (int j = 0; j < gomoku_board_dim; j++) {
			game_pieces blank = game_pieces();
			gomoku_board[i][j] = blank;
		}
	}
}

ostream& operator<<(ostream& out, const Gomoku& g) {
/*
	* prints board to screen from ostream 
	* Parameters-
	*ostream, game object
	*
	* Returns-
	* the ostream obj
*/
	for (int i = 19; i >= 0; i--) {

		cout << i;
		for (int j = 0; j < 10; j++) {
			out << g.gomoku_board[i][j].appearance << " ";
		}
		for (int j = 10; j <= 19; j++) {
			out << g.gomoku_board[i][j].appearance << " ";
			out << setw(g.longest_string);	//9 changing width
		}

		out << endl;
	}
	for (int i = 0; i <= 19; i++) {
		cout << " " << i;
	}
	cout << endl;
	return out;
}

void Gomoku::print() {
	//prints board to console
	cout << *this << endl;
}

bool Gomoku::done() {
	/*
	* checks if a player has won and therefore game should end
	*
	* Returns-
	* true if player has won
	*/
	for (int i = 1; i < gomoku_board_dim; i++) {
		int num_in_a_row = 0;
		for (int j = 1; j < gomoku_board_dim; j++) {	//checks for 5 in a row horizontal
			if (gomoku_board[i][j].appearance == gomoku_board[i][j + 1].appearance && gomoku_board[i][j].appearance != " ") {
				num_in_a_row++;
			}
			if (num_in_a_row == 4) {
				cout << "horizontal" << endl;
				return true;
			}
		}
	}
	for (int i = 1; i < gomoku_board_dim; i++) {
		int num_in_a_row = 0;
		for (int j = 1; j < gomoku_board_dim; j++) {	//checks for 5 in a row vertical 
			if (gomoku_board[j][i].appearance == gomoku_board[j + 1][i].appearance && gomoku_board[j][i].appearance != " ") {
				num_in_a_row++;
			}

			if (num_in_a_row == 4) {
				cout << "vertical" << endl;
				return true;
			}
		}
	}
	int num_in_a_row = 0;
	for (int i = 1; i <= gomoku_board_dim-5; i++) {
		for (int j = 1; j <= gomoku_board_dim-5; j++) {	//checks for 5 in a row diagonal bottom left to top right
			num_in_a_row = 0;
			for (int z = 0; z <= 4; z++) {
				if (gomoku_board[j][i].appearance == gomoku_board[j + z][i + z].appearance && gomoku_board[j][i].appearance != " ") {
					++num_in_a_row;
				}
				if (num_in_a_row == 5) {
					cout << "diagonal bottom left" << endl;
					return true;
				}
			}

		}
	}
	for (int i = 1; i <= gomoku_board_dim-5; i++) {//checks for 5 in a row diagonal top left to bottom right
		for (int j = gomoku_board_dim-1; j >= 5; j--) {
			num_in_a_row = 0;
			for (int z = 0; z <= 4; z++) {
				if (gomoku_board[i][j].appearance == gomoku_board[i + z][j - z].appearance && gomoku_board[i][j].appearance != " ") {
					++num_in_a_row;
				}
				if (num_in_a_row == 5) {
					cout << "diagonal top left" << endl;
					return true;
				}
			}

		}
	}
	return false;
}

bool Gomoku::draw() {
	/*
	* checks whether there are possible winning moves remaining in game
	*
	* Returns-
	* true if the game is over (ends in a draw), false if winning moves left to be made
	*/
	if (turns == 361) {
		cout << "there are no empty spaces remaining." << endl;
		return true;
	}

	for (int i = 1; i < gomoku_board_dim; i++) {
		int num_in_a_row = 0;
		for (int j = 1; j < gomoku_board_dim; j++) {	//checks for 5 in a row horizontal
			if (gomoku_board[i][j].appearance == gomoku_board[i][j + 1].appearance || gomoku_board[i][j].appearance == " ") {
				num_in_a_row++;
			}
			if (num_in_a_row == 5) {
				cout << "valid moves left to make" << endl;
				return false;
			}
		}
	}
	for (int i = 1; i < gomoku_board_dim; i++) {
		int num_in_a_row = 0;
		for (int j = 1; j < gomoku_board_dim; j++) {	//checks for 5 in a row vertical 
			if (gomoku_board[j][i].appearance == gomoku_board[j + 1][i].appearance || gomoku_board[j][i].appearance == " ") {
				num_in_a_row++;
			}
			if (num_in_a_row == 5) {
				cout << "valid moves left to make" << endl;
				return false;
			}
		}
	}
	int num_in_a_row = 0;
	for (int i = 1; i <= gomoku_board_dim-5; i++) {
		for (int j = 1; j <= gomoku_board_dim-5; j++) {	//checks for 5 in a row diagonal bottom left to top right
			num_in_a_row = 0;
			for (int z = 0; z <= 4; z++) {
				if (gomoku_board[j][i].appearance == gomoku_board[j + z][i + z].appearance || gomoku_board[j][i].appearance == " ") {
					++num_in_a_row;
				}
				if (num_in_a_row == 5) {
					cout << "valid moves left to make" << endl;
					return false;
				}
			}

		}
	}

	for (int i = 1; i <= gomoku_board_dim-4; i++) {//checks for 5 in a row diagonal top left to bottom right
		for (int j = gomoku_board_dim-1; j >= 5; j--) {
			num_in_a_row = 0;
			for (int z = 0; z <= 4; z++) {
				if (gomoku_board[i][j].appearance == gomoku_board[i + z][j - z].appearance || gomoku_board[i][j].appearance == " ") {
					++num_in_a_row;
				}
				if (num_in_a_row == 5) {
					cout << "valid moves left to make" << endl;
					return false;
				}
			}

		}
	}
	cout << "spaces remain on the board, but there are no winning moves remaining." << endl;
	return true;
}

int Gomoku::turn() {
	/*
	* handles each player's turn; calls other functions to faciliate turn
	*
	* Returns-
	* success value
	*/
	unsigned int x, y;
	if (turns == 1)
	{
		cout << *this << endl;	//question 16 
		cout << "Player B Goes first" << endl;
	}
	if (prompt(x, y) != user_quit) {
		if (turns % 2 == 1) {		//even is player W, odd is player B
			cout << endl << "Next Move is Player B" << endl;
			if (gomoku_board[y][x].appearance == " " && x >= cord1 && x <= 19 && y >= cord1 && y <= 19) //within the boundaries of a valid spot and the spot is empty
			{
				gomoku_board[y][x] = B;
				cout << *this << endl;
				cout << "Player B Played: " << x << ", " << y << "; " << endl << endl;
				turns++;
				return valid_value;
			}
			else
			{
				cout << "Cannot move there, try again" << endl;
				return turn();
			}
		}
		else
		{
			cout << endl << "Next Move is Player W" << endl;
			if (gomoku_board[y][x].appearance == " " && x >= cord1 && x <= 19 && y >= cord1 && y <= 19) //within the boundaries of a valid spot and the spot is empty
			{
				gomoku_board[y][x] = W;
				cout << *this << endl;
				cout << "Player W Played: " << x << ", " << y << "; " << endl << endl;	
				turns++;
				return valid_value;
			}
			else
			{
				cout << "Cannot move there, try again" << endl;
				return turn();
			}
		}
	}
	else {
		return turn_userquit;
	}
}