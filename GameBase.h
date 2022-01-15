#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Common.h"
#include "pieces.h"

/*
*
GameBase.h
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeffrey Mao, jeff.m@wustl.edu
Contains the class definition for the GameBase base class.

*/

using namespace std;

class GameBase {
public:
	GameBase();
	~GameBase() {};
	static GameBase* choose(int x, char* arr[]); //decide which game to play
	int play();
protected:
	game_pieces board[board_rows][board_columns]; //come back
	game_pieces gomoku_board[20][20];
	int turns;
	int longest_string;
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int prompt(unsigned int& a, unsigned int& b);
	virtual int turn() = 0;


};


