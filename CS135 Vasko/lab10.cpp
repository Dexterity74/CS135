#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_MAP_HEIGHT = 50;
const int MAX_MAP_WIDTH = 50;

// TODO: write missing function prototypes
void shrinkStorm(char [][MAX_MAP_WIDTH], int , int , int , int , int& );
void drop(char [][MAX_MAP_WIDTH], int , int , int );
void load(char [][MAX_MAP_WIDTH], int& , int& , int& , int& , int&);
void render(char [][MAX_MAP_WIDTH], int , int );
int getNumPlayers(char[][MAX_MAP_WIDTH], int, int);

int main() {
	srand(time(0));
	char map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	int height, width;
	int playerCount;
	int eyeR, eyeC;
	int radius;
	char temp;

	load(map, height, width, playerCount, eyeR, eyeC);
	// TODO: call render
    render(map, height, width);
	drop(map, height, width, playerCount);
	radius = width;

	while (playerCount > 1) {
		cout << "Hit enter to continue";
		cin.get(temp);
		shrinkStorm(map, height, width, eyeR, eyeC, radius);
		playerCount = getNumPlayers(map, height, width);
		// TODO: call render
        render(map, height, width);
	}

	return 0;
}

// TODO: write render funciton description
/* Function Description: The void render function sets the 
                         perimeter of the map and outputs the border.
 *
*/
void render(char screenSpace[][MAX_MAP_WIDTH], int rows, int cols) {
	string border;
	border.append(cols + 2, '_');

	cout << border << endl;
	for (int r = 0; r < rows; r++) {
		cout << "|";
		for (int c = 0; c < cols; c++)
			cout << screenSpace[r][c];
		cout << "|\n";
	}
	cout << border << endl;
}

// TODO: write load funciton description
/* Function Description: The void load function sets the height and width for
 *                       each respective map. This function also allows the user
 *                       to select which map they would like to play.
 *                       The second half of this function sets random positions
 *                       for the players.
 *                       The end of this function uses a nested for loop to clear
 *                       the map
 *
*/ 
void load(char map[][MAX_MAP_WIDTH], int& rows, int& cols, int& playerCount, int& eyeR, int& eyeC) {
	const int FL_HEIGHT = 20; // size of Farmland
	const int FL_WIDTH = 40;
	const int BY_HEIGHT = 15; // size of Boneyard
	const int BY_WIDTH = 30;
	const int HP_HEIGHT = 10; // size of Hospital
	const int HP_WIDTH = 20;

	const int FL_PC = 26; // players in Farmland
	const int BY_PC = 15; // players in Boneyard
	const int HP_PC = 10; // players in Hospital

	char marker;
	cout << "Where we droppin bois?\n";
	cout << "[F]armland\n";
	cout << "[B]oneyard\n";
	cout << "[H]ospital\n";
	cout << "Choice: ";
	cin >> marker;
	cin.ignore(256, '\n');

	switch (marker) {
		case 'F': case 'f':
		rows = FL_HEIGHT;
		cols = FL_WIDTH;
		playerCount = FL_PC;
		break;
		case 'B': case 'b':
		rows = BY_HEIGHT;
		cols = BY_WIDTH;
		playerCount = BY_PC;
		break;
		default:
		rows = HP_HEIGHT;
		cols = HP_WIDTH;
		playerCount = HP_PC;
		break;
	}

	eyeR = rand() % rows;
	eyeC = rand() % cols;

	// TODO: clear map
    for(size_t r = 0; r < rows; r++) {
        for(size_t c = 0; c < cols; c++) {
            map[r][c] = ' ';
        }
    }
	
}

// TODO: write getNumPlayers funciton description
/* Function Description: The int getNumPlayers function counts the amount of
 *                       players left to determine when to stop the loop.
 *
*/
// TODO: write getNumPlayers function definition
int getNumPlayers(char map[][MAX_MAP_WIDTH], int rows, int cols) {
    int count = 0;
    for(size_t r = 0; r < rows; r++) {
        for(size_t c = 0; c < cols; c++) {
            if(map[r][c] != ' ' && map[r][c] != '*') {
                count++;
            }
        }
    }
    return count;
}

// TODO: write drop funciton description
/* Function Description: The void drop function drops the player on a specific
 *                       coordinate on the map
*/
void drop(char map[][MAX_MAP_WIDTH], int rows, int cols, int playerCount) {
	char player = 'A';
	int drops = 0;

	while (drops < playerCount) {
		int r = rand() % rows;
		int c = rand() % cols;

		if (map[r][c] == ' ') {
			map[r][c] = player;
			player++;
			drops++;
		}
	}
}

// TODO: write shrinkStorm funciton description
/* Function Description: The void shrinkStorm function solely sets '*' for where the storm
 *                       is and decreases the radius to weave out players
*/ 
void shrinkStorm(char map[][MAX_MAP_WIDTH], int rows, int cols, int eyeR, int eyeC, int& radius) {
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			if (map[r][c] != '*') {
				double distance = sqrt(pow(c - eyeC, 2) + pow(r - eyeR, 2));
				if (distance > radius)
					map[r][c] = '*';
			}
	radius--;
}
