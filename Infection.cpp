#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

char Map[30][40] = {

"#######################################",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#           X                         #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                 X                   #",
"#                                     #",
"#                                     #",
"#                          X          #",
"#                                     #",
"#           X                         #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#                                     #",
"#######################################",

};

bool running = true;
int gamespeed = 100;
int randNum = 0;

int main(int argv, char** argc) {

	while (running) {

		system("cls");

		for (int y=0; y<30; y++) {
			cout << Map[y] << endl;
		}

		for (int y=0; y<30; y++) {
			for (int x=0; x<40; x++) {
				switch (Map[y][x]) {
                    case 'X':
                        randNum = rand() % 4 + 1;

                        switch (randNum) {
                        case 1:
                            if (Map[y-1][x] != '#' && Map[y-1][x] != 'X') {
                                Map[y][x] = ' ';
                                Map[y-1][x] = 'X';
                            }
                            break;

                        case 2:
                            if (Map[y][x+1] != '#' && Map[y][x+1] != 'X') {
                                Map[y][x] = ' ';
                                Map[y][x+1] = 'X';
                            }
                            break;
                        case 3:
                            if (Map[y+1][x] != '#' && Map[y+1][x] != 'X') {
                                Map[y][x] = ' ';
                                Map[y+1][x] = 'X';
                            }
                            break;
                        case 4:
                            if (Map[y][x-1] != '#' && Map[y][x-1] != 'X') {
                                Map[y][x] = ' ';
                                Map[y][x-1] = 'X';
                            }
                            break;
					}
					break;
				}
			}
		}
		randNum = 0;
		Sleep(gamespeed);
	}
	return 0;
}
