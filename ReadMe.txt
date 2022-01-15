This is a TicTacToe and Gomoku game app that I built in C++ that runs in the console. To run, navigate to the folder in your cmd prompt, and type in Lab4.exe <Game> (either Gomoku or TicTacToe.) From there, follow the prompts.
Test Cases:
---------------------Invalid Move in TicTacToe--------------------------------------------------------------------------------------------------
Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0
1,5

Cannot move there, try again
Moves thus far: (1, 1), (3, 2),
Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------Game Ending in Draw--------------------------------------------------------------------------------------------------------
4
3  X O O
2  O X X
1  O X O
0
 0 1 2 3 4

Player O Played: 2, 3
Next Move is Player X
There were: 9 turns and there are no winning moves remaining, game is a draw
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------Wrong Args/Incorrect Game--------------------------------------------------------------------------------------------------
H:\>H:\332-AGAIN\Labs\test2\Lab4\x64\Debug\Lab4.exe TicTacTo
usage:H:\332-AGAIN\Labs\test2\Lab4\x64\Debug\Lab4.exe <Game>
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------TicTacToe Winner ----------------------------------------------------------------------------------------------------------
4
3  O X
2  O X
1  O
0
 0 1 2 3 4

Player O Played: 1, 3
Next Move is Player X
Player 1 won the game (O for TicTacToe, B for Gomoku)
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------Gomoku Wrong Coods---------------------------------------------------------------------------------------------------------
35,20

Next Move is Player B
Cannot move there, try again
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 0
  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B Goes first
Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------Gomoku Winneer-------------------------------------------------------------------------------------------------------------
6,5

Next Move is Player B
19
18                       W
17
16                                   W
15
14
13            W
12
11
10
 9          W
 8                  W
 7                  W
 6
 5      W     B
 4          B
 3        B B                              W
 2  B B B
 1    B B
 0
  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B Played: 6, 5;

diagonal bottom left
Player 1 won the game (O for TicTacToe, B for Gomoku)
------------------------------------------------------------------------------------------------------------------------------------------------
---------------------Gomoku Quit----------------------------------------------------------------------------------------------------------------
valid moves left to make
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 0
  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B Goes first
Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0
quit
you have quit
There were 0 turns
H:\>echo %errorlevel%
6
