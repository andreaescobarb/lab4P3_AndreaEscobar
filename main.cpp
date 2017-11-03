#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;
int Menu(vector<string>);
int* show(int**, int, int);
int main (){
	initscr();
	vector<string> MenuItems;
	MenuItems.push_back("Agregar nuevo Jugador");
	MenuItems.push_back("Eliminar nuevo Jugador");
	MenuItems.push_back("Modificar nuevo Jugador");
	MenuItems.push_back("Highscores");
	MenuItems.push_back("Jugar");
	int op =0;
	op = Menu(MenuItems);
	endwin();	
	return 0;
}
int Menu(vector<string> vec) {
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
}
int* show(int** Tabla, int Xlength, int Ylength) {
	//Se le ingresa la matriz, y las longitudes de la tabla
	//Devuelve un arreglo, la posicion [0] es la pos. X, la posicion [1] es el Y
	int* XY = new int[2];	
	char ch = '.';
	int x = 0;
	int y = 0;
	while (ch !='\n') {	
		clear();
		for (int i = 0;i<Ylength;i++) {
			for (int j = 0;j<Xlength;j++) {
				addstr((to_string(Tabla[i][j])+" ").c_str());
			}
			addstr("\n");
		}
		addstr(("x: "+to_string(x)+"\n").c_str());
		addstr(("y: "+to_string(y)+"\n").c_str());
		ch = getch();
		//Key Down == 66
		if (ch == 66) {
			y++;
			if (y >= Ylength) {
				y = 0;
			}
		}
		//Key UP == 65
		if (ch == 65) {
			y--;
			if (y < 0) {
				y = 7;
			}
		}
		//Key Left == 68
		if (ch == 68) {
			x--;
			if (x < 0) {
				x = 7;
			}
		}
		//Key Right == 67
		if (ch == 67) {
			x++;
			if (x >= Xlength) {
				x = 0;
			}
		}
	}
	XY[0] = x;
	XY[1] = y;
	return XY;
}


