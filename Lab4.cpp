/*
Lab4.cpp
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeff Mao, jeff.m@wustl.edu
Contains the main function which begins the program
*/

#include <iostream>
#include "Common.h"
#include "GameBase.h"
#include "tictactoe.h"
#include "Gomoku.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	/*
	* begins/ends game
	*
	* Returns-
	* success code
	*/

	try {
		GameBase* gb = GameBase::choose(argc, argv);
		shared_ptr<GameBase> sp(gb);
		if (sp == 0) {
			return usage_message(argv[lab4]);
		}
		return gb->play();
		
	}
	catch (bad_alloc) {
		return bad_memory;
	}

}
