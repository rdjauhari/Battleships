/* BATTLESHIPS
print an 8x8 board fully filled with ships
	B - battleship length 4 (x1)
	C - cruiser length 3 (x2)
	S - cargo ship length 2 (x5)
	_ - submarine length 1 (x10)

	total ships = 18

	**ships can only be placed VERTICALLY
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//variables
const int size_of_board = 8;
char game_board[size_of_board][size_of_board];
int x_coord = 0;
int y_coord = 0;

void print_board() {
	//printing board to display
	for (int ycol = 0; ycol < size_of_board; ycol++) {
		for (int xrow = 0; xrow < size_of_board; xrow++) {
			cout << game_board[xrow][ycol];
			if (xrow == size_of_board - 1) {
				cout << endl;
			}
		}
	}
}

int random_x_coordinate() {
	//generating random x coordinate to place ships
	x_coord = rand() % 8;
	return x_coord;
}

int random_y_coordinate() {
	//generating random x coordinate to place ships
	y_coord = rand() % 8;
	return y_coord;
}

int main() {
	for (int number_of_boards = 0; number_of_boards < 100; number_of_boards++) {
		int x = 0;
		int y = 0;

		//char game_board[size_of_board][size_of_board] = { '\0' };

		char marker_battleship = 'B';
		int number_of_battleships = 1;
		int length_of_battleship = 4;

		char marker_cruiser = 'C';
		int number_of_cruisers = 2;
		int length_of_cruiser = 3;

		char marker_cargo = 'S';
		int number_of_cargo = 5;
		int length_of_cargo = 2;

		char marker_sub = '_';
		int number_of_subs = 10;
		int length_of_sub = 1;

		//placing battleships
		while (number_of_battleships != 0) {
			int counter_check = 0;
			int counter_place = 0;
			x = random_x_coordinate();
			y = random_y_coordinate();
			int y_temp = y;

			if (x > 7) {
				//re-generate an x coordinate
				x = random_x_coordinate();
			}
			else if (y > 7) {
				//re-generate a y-coordinate
				y = random_y_coordinate();
			}
			else {
				while (counter_check < length_of_battleship) {
					//checking if the length of the ship fits on the board
					if (y_temp > 7) {
						y = random_y_coordinate();
						y_temp = y;
						counter_check = 0;
					}
					else {
						counter_check++;
						y_temp++;
					}
				}
				while (counter_place < length_of_battleship) {
					//placing 
					game_board[x][y] = marker_battleship;
					y++;
					counter_place++;
				}
				number_of_battleships--;
			}
		}

		//placing cruisers
		while (number_of_cruisers != 0) {
			int counter_check = 0;
			int counter_place = 0;
			x = random_x_coordinate();
			y = random_y_coordinate();
			int y_temp = y;


			if (x > 7) {
				//re-generate an x coordinate
				x = random_x_coordinate();
			}
			else if (y > 7) {
				//re-generate a y-coordinate
				y = random_y_coordinate();
			}
			else {
				while (counter_check < length_of_cruiser) {
					if (y_temp > 7) {
						//checking if the length of the ship fits on the board
						y = random_y_coordinate();
						y_temp = y;
						counter_check = 0;
					}
					else if (game_board[x][y_temp] == marker_battleship || game_board[x][y_temp] == marker_cruiser) {
						//checking if there is already a ship there
						x = random_x_coordinate();
						y = random_y_coordinate();
						y_temp = y;
						counter_check = 0;
					}
					else {
						counter_check++;
						y_temp++;
					}
				}
				while (counter_place < length_of_cruiser) {
					//placing 
					game_board[x][y] = marker_cruiser;
					y++;
					counter_place++;
				}
				number_of_cruisers--;
			}
		}

		//placing cargo ships
		while (number_of_cargo != 0) {
			int counter_check = 0;
			int counter_place = 0;
			x = random_x_coordinate();
			y = random_y_coordinate();
			int y_temp = y;

			if (x > 7) {
				//re-generate an x coordinate
				x = random_x_coordinate();
			}
			else if (y > 7) {
				//re-generate a y-coordinate
				y = random_y_coordinate();
			}
			else {
				while (counter_check < length_of_cargo) {
					if (y_temp > 7) {
						//checking if the length of the ship fits on the board
						y = random_y_coordinate();
						counter_check = 0;
						y_temp = y;
					}
					else if (game_board[x][y_temp] == marker_battleship || game_board[x][y_temp] == marker_cruiser || game_board[x][y_temp] == marker_cargo) {
						//checking if there is already a ship there
						x = random_x_coordinate();
						y = random_y_coordinate();
						counter_check = 0;
						y_temp = y;
					}
					else {
						counter_check++;
						y_temp++;
					}
				}
				while (counter_place < length_of_cargo) {
					//placing 
					game_board[x][y] = marker_cargo;
					y++;
					counter_place++;
				}
				number_of_cargo--;
			}
		}

		//placing subs
		while (number_of_subs != 0) {
			int counter_check = 0;
			int counter_place = 0;
			x = random_x_coordinate();
			y = random_y_coordinate();
			int y_temp = y;

			if (x > 7) {
				//re-generate an x coordinate
				x = random_x_coordinate();
			}
			else if (y > 7) {
				//re-generate a y-coordinate
				y = random_y_coordinate();
			}
			else if (game_board[x][y_temp] == marker_battleship || game_board[x][y_temp] == marker_cruiser || game_board[x][y_temp] == marker_cargo || game_board[x][y_temp] == marker_sub) {
				//checking if there is already a ship there
				x = random_x_coordinate();
				y = random_y_coordinate();
			}
			else {
				while (counter_place < length_of_sub) {
					//placing 
					game_board[x][y] = marker_sub;
					y++;
					counter_place++;
				}
				number_of_subs--;
			}
		}
		print_board();
		cout << endl;

		//reinitializing gameboard
		for (int a = 0; a < size_of_board; a++) {
			for (int b = 0; b < size_of_board; b++) {
				game_board[a][b] = ' ';
			}
		}
	}
	return 0;
}