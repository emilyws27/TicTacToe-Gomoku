#include "Common.h"
#include <iostream>
/*
Common.cpp
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeff Mao, jeff.m@wustl.edu
Contains the usage message function which details how to run the program
*/
int usage_message(char* name)
{
	std::cout << "usage:" << name << " <Game>" << std::endl; //outputs the helpful message telling user to include the name of the program which is the prameter name and then to also include the textfile.txt
	return Inc_cmdargs; //returns the outcome for incorrect number of command line arguments
}