#pragma once
#include "GameBase.h"

/*
*
GameBase.h
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeffrey Mao, jeff.m@wustl.edu
Contains the class definition for the Gomoku game which derives from the GameBase class.

*/

class Gomoku : public GameBase {
public:
	Gomoku();
	~Gomoku() {};
	friend ostream& operator<<(ostream& out, const Gomoku& t);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	void print() override;
private:
	game_pieces B; 
	game_pieces W;
};

ostream& operator<<(ostream& out, const Gomoku& t);