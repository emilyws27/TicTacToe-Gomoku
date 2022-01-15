#pragma once

/*
* 
Common.h
Emily Sheehan, e.sheehan@wustl.edu; Michael Treiber, m.treiber@wustl.edu; Jeffrey Mao, jeff.m@wustl.edu
Contains all the enums/number substitutions

*/

enum board { board_rows = 5,
			 board_columns = 5, 
			 cord3 = 3,
			 cord2 = 2,
			 cord1 = 1, 
			 gomoku_board_dim = 20};

enum results { success = 0,
			   user_quit = 1,
			   coord_extraction_success = 2,
			   turn_userquit = 3,
			   valid_value = 4,
			   game_draw = 5,
			   play_userquit = 6,
			   Inc_cmdargs = 7,
			   bad_memory = 8 };

enum cmdargs { lab4 = 0,
			   input_string = 1,
			   correct_number_args = 2 };

int usage_message(char* name);
