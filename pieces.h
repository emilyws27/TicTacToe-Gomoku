#pragma once
#include <string>

/*
*
pieces.h
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeffrey Mao, jeff.m@wustl.edu
a struct for game pieces; each piece has a name a value (either b or w)
*/

struct game_pieces {
	game_pieces();

	game_pieces(std::string name, std::string appearance);

	std::string name;
	std::string appearance;
};

