# ConwaysGameOfLife
This project simulates Conway's Game of Life

BACKGROUND:
The Game of Life is a cellular automaton created by John Conway. It is an example of a zero-player game, where each step is completely determined by the current state of the board.  The idea is that populations require a certain size in order to thrive, and can expand if they are large enough, but cannot become so dense that they overtax their local resources.  An infinite grid is impractical to simulate, so we will use a grid that wraps around, so that the top row and bottom row are neighbors, as are the left and right sides.


SEMANTICS:
a. Life is played on an infinite, two-dimensional grid of square cells. Each cell has eight neighbors,
which are the cells that share a side or a corner with it.

b. At any time, each cell is either populated or unpopulated.

c. If a cell is populated at time t but has fewer than two populated neighbors or more than three populated neighbors, it will be unpopulated at time t + 1.

d. If a cell is unpopulated at time t but has exactly three populated neighbors, it will be populated at time t + 1.


INPUT FORMAT:
The input file has two parts. The first line contains two integers, h and w, indicating the height and width of the board, respectively.  The following h lines describe the board.  A populated cell is indicated by an asterisk (*) and an unpopulated cell by a period (.)

The following is an example of a sample input board.txt:
5 5
.....
..*..
..*..
..*..
.....

The second part of the input in the command line, which describes the number of iterations the board should go through.  The complete input would appear as follows:

./life 3 board.txt
("3" can be replaced with any number and board.txt with the name of the txt file containing the initial board)

OUTPUT FORMAT:
The output is another board displaying the 
