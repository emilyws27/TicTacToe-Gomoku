#include "tictactoe.h"
#include <iostream>
#include <vector>
#include "Common.h"
#include "pieces.h"
#include <string>

/*
tictactoe.cpp
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeff Mao, jeff.m@wustl.edu
Contains the usage message function which details how to run the program
*/

using namespace std;


//override virtual void print question 10-11
void tictactoe::print() {
	cout << *this << endl;
}



tictactoe::tictactoe() : X(game_pieces("X", "X")), O(game_pieces("O", "O")) {
	//constructor; creates game board with empty spaces

	vector<string> moves;
	game_pieces board[board_rows][board_columns];
	for (int i = 0; i < board_rows; i++) {
		for (int j = 0; j < board_columns; j++) {
			game_pieces blank = game_pieces();
			board[i][j] = blank;
		}
	}
}

ostream& operator<<(ostream& out, const tictactoe& t) {
	/*
	* prints board to screen from ostream
	* Parameters-
	*ostream, game object
	*
	* Returns-
	* the ostream obj
	*/
	
	for (int i = board_rows - 1; i >= 0; i--) {
		cout.width(t.longest_string);	//9 changing width
		cout << i;
		for (int j = 0; j <= board_columns - 1; j++) {
			out << t.board[i][j].appearance << " ";
		}
		out << endl;
	}
	cout << " " << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
	return out;
}

bool tictactoe::done() {
	/*
	* checks if a player has won and therefore game should end
	*
	* Returns-
	* true if player has won
	*/
	if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord3][cord2].appearance && board[cord3][cord1].appearance == board[cord3][cord3].appearance)
	{ //horizontal 3 in a row top
		return true;
	}
	else if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord2][cord1].appearance && board[cord3][cord1].appearance == board[cord1][cord1].appearance)
	{ //vertical 3 left
		return true;
	}
	else if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord2][cord2].appearance && board[cord3][cord1].appearance == board[cord1][cord3].appearance)
	{ //diagnoal top left to bottom right
		return true;
	}
	else if (board[cord3][cord3].appearance != " " && board[cord3][cord3].appearance == board[cord2][cord2].appearance && board[cord3][cord3].appearance == board[cord1][cord1].appearance)
	{ //diagnoal top right to bottom left
		return true;
	}
	else if (board[cord3][cord3].appearance != " " && board[cord3][cord3].appearance == board[cord2][cord3].appearance && board[cord3][cord3].appearance == board[cord1][cord3].appearance)
	{ //right vertical
		return true;
	}
	else if (board[cord1][cord1].appearance != " " && board[cord1][cord1].appearance == board[cord1][cord2].appearance && board[cord1][cord1].appearance == board[cord1][cord3].appearance)
	{ //bottom horizontal
		return true;
	}
	else if (board[cord2][cord1].appearance != " " && board[cord2][cord1].appearance == board[cord2][cord2].appearance && board[cord2][cord1].appearance == board[cord2][cord3].appearance)
	{ //middle Horizontal
		return true;
	}
	else if (board[cord3][cord2].appearance != " " && board[cord3][cord2].appearance == board[cord2][cord2].appearance && board[cord3][cord2].appearance == board[cord1][cord2].appearance)
	{ //middle vertical
		return true;
	}

	return false; //nobody is a winner

}

bool tictactoe::draw() {
	/*
	*sees if there are any valid moves left to be made in the game
	* 
	* Returns-
	* false if no piece at space, true otherwise
	*/
	if (done())
	{
		return false;
	}
	else if (turns != 10) //create another case for when there are no moves left, create member variable for turns increment turns after each turn and when turns hits 9 then no moves left
	{
		return false;
	}

	return true;
}



//prints out the initial empty game board and says which player is going first. Then it calls on prompt and as long as user doesn't quit and the coordinate is a valid spot it will replace that empty spot with an X or O and print out the board and where the player moved
//To switch between players I usde an odd and even system for a member variable turns and if the user chose a spot that doesn't work, an appropriate message is returned
int tictactoe::turn() {
	cout << "Moves thus far: ";
	for (string player_move : moves) {
		cout << '(' << player_move << "), ";
	}
	cout << endl;
	unsigned int x, y;
	if (turns == 1)
	{
		cout << *this << endl;	//question 16 
		cout << "Player O Goes first" << endl;
	}
	if (prompt(x, y) != user_quit) {
		if (turns % 2 == 1) {		//even is player X, odd is player O
			cout << endl;
			if (board[y][x].appearance == " " && x >= cord1 && x <= cord3 && y >= cord1 && y <= cord3) //within the boundaries of a valid spot and the spot is empty
			{
				string player = to_string(x) + ", " + to_string(y);
				moves.push_back(player);

				board[y][x] = O;
				cout << *this << endl;
				cout << "Player O Played: " << x << ", " << y << endl << "Next Move is Player X" << endl;
				turns++;
				return valid_value;
			}
				cout << "Cannot move there, try again" << endl;
				return turn();
			
		}
		
			cout << endl;
			if (board[y][x].appearance == " " && x >= cord1 && x <= cord3 && y >= cord1 && y <= cord3) //within the boundaries of a valid spot and the spot is empty
			{
				string player = to_string(x) + ", " + to_string(y);
				moves.push_back(player);
				board[y][x] = X;
				cout << *this << endl;
				cout << "Player X Played: " << x << ", " << y << "; " << endl << "Next Move is Player O " << endl;
				turns++;
				return valid_value;
			}
			else
			{
				cout << "Cannot move there, try again" << endl << endl;
				return turn();
			}
		
	}
	return turn_userquit;
}






