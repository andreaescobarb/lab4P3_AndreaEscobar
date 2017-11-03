#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;
//int Menu();
int main () {
	initscr();
	vector<string> MenuItems;
	/*MenuItems.push_back("Agregar nuevo Jugador");
	MenuItems.push_back("Eliminar nuevo Jugador");
	MenuItems.push_back("Modificar nuevo Jugador");
	MenuItems.push_back("Highscores");
	MenuItems.push_back("Jugar");*/
	endwin();	
	return 0;
}
/*int Menu(vector<string> vec) {
	int op = 0;
	int ch = 0;
	while (ch != '\n') {
		clear();
		addstr("mover con flechitas \n Seleccionar con Enter\n");
		for (int i = 0;i<vec.size();i++) {
			addstr(vec.at(i).c_str());
			if (op == i) {
				addstr(" <-");
			}
			addstr("\n");
		}		
		ch = getch();
		//Key Down == 66
		if (ch == 66) {
			op++;
			if (op >= vec.size()) {
				op = 0;
			}
		}
		//Key UP == 65
		if (ch == 65) {
			op--;
			if (op < 0) {
				op = vec.size()-1;
			}
		}
	}	
	refresh();
	return op;
}*/


