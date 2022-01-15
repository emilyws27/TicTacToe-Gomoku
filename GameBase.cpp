#include "GameBase.h"
#include "Common.h"
#include "tictactoe.h"
#include "Gomoku.h"
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <algorithm>

/*
tic-tac-toe.cpp
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeff Mao, jeff.m@wustl.edu
Contains the main functions that are common to both the TicTacToe game and Gomoku game
*/

using namespace std;


GameBase::GameBase() : turns(1), longest_string(0) {
	//constructor; creates the gameboard and sets each space to empty

	game_pieces board[board_rows][board_columns];
	for (int i = 0; i < board_rows; i++) {
		for (int j = 0; j < board_columns; j++) {
			game_pieces blank = game_pieces();
			board[i][j] = blank;
		}
	}
}

int GameBase::prompt(unsigned int& a, unsigned int& b)
{
	/*
	* prompts user to insert correctly formatted coordinates and calls function repeatedly if not correct format.
	* Parameters-
	* x and y coords
	* string argument_format: what the command line args should look like	*
	*
	* Returns-
	* Success value
	*/

	string coordinate;
	cout << "Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0" << endl;
	cin >> coordinate;
	if (coordinate == "quit") {
		cout << "you have quit" << endl;
		return user_quit;
	}
	else {
		replace(coordinate.begin(), coordinate.end(), ',', ' ');
		istringstream iss(coordinate);
		if (iss >> a && iss >> b) {
			return coord_extraction_success;
		}
		cout << "you have inputted the coordinates improperly ";
		return prompt(a, b);
	}
}

int GameBase::play() {
/*
	* sees whether the game should continue, is done, or is quit,
	*
	* Returns-
	* Success value
*/
	if (done() == true)
	{
		if (turns % 2 == 0)
		{
			cout << "Player 1 won the game (O for TicTacToe, B for Gomoku)";
			return success;
		}
		else
		{
			cout << "Player 2 won the game (X for TicTacToe, W for Gomoku)";
			return success;
		}
	}
	else if (draw() == true)
	{
		cout << "There were: " << turns - 1 << " turns and there are no winning moves remaining, game is a draw" << endl;
		return game_draw;
	}
	else if (turn() == turn_userquit)
	{
		cout << "There were " << turns - 1 << " turns" << endl;	
		return play_userquit;
	}
	return play();
}

GameBase* GameBase::choose(int x, char* arr[]) {
	/*
	* creates either tiktaktoe obj or gomoku obj depending on args
	*
	* Returns-
	* GameBase object
	*/
	GameBase* gb = nullptr;
	if (x == correct_number_args && strcmp(arr[input_string], "TicTacToe") == 0) {
		gb = new tictactoe();
		return gb;
	}
	else if (x == correct_number_args && strcmp(arr[input_string], "Gomoku") == 0) {
		gb = new Gomoku();
		return gb;
	}
	return gb;
}

