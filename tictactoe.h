#pragma once
#include "GameBase.h"
#include <string>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <sstream>
#include "Common.h"
#include "pieces.h"
#include <vector>

/*
*
pieces.h
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeffrey Mao, jeff.m@wustl.edu
class defintion for tictactoe which derives from GameBase
*/

class tictactoe : public GameBase {
public:
	tictactoe();
	~tictactoe() {};
	virtual bool done();
	friend ostream& operator<<(ostream& out, const tictactoe& t);
	virtual bool draw();
	virtual int turn();
	void print() override;
	vector<string> moves;
private:
	game_pieces X;
	game_pieces O;
};
