#include <ncurses.h>
#include <vector>
#include <string>
#include "Jugador.h"

using namespace std;
int Menu(vector<string>);
int* show(int**, int, int);
int* showChar(char**, int, int);
int** SetGame(int, int, int);
string getString();
int ListarVector(vector<Jugador*>* vList);
void Game();

int main (){
	initscr();
	vector<string> MenuItems;
	vector<Jugador*>* vJugadores = new vector<Jugador*>();
	MenuItems.push_back("Agregar nuevo Jugador");
	MenuItems.push_back("Eliminar Jugador");
	MenuItems.push_back("Modificar Jugador");
	MenuItems.push_back("Highscores");
	MenuItems.push_back("Jugar");
	MenuItems.push_back("Salir");
	int op = 0;
	while (op != 5) {
		op = Menu(MenuItems);
		switch (op) {
			case 0: {
				clear();
				addstr("Ingrese Nombre: \n");
				string Nombre = getString();
				Jugador* J = new Jugador(Nombre, "", "", 0);
				vJugadores->push_back(J);
			} break;
			case 1: {
			
			} break;
			case 2: {

			} break;
			case 3: {
				ListarVector(vJugadores);
			} break;
			case 4: {
				Game();
			} break;
		}
	}

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
int* showChar(char** Tabla, int Xlength, int Ylength) {
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
				string p = "";
				p+= Tabla[i][j];
				addstr(p.c_str());
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
int** setGame(int Minas, int Y, int X) {
	int** Matriz = new int*[9];
	for (int i = 0;i<9;i++) {
		Matriz[i] = new int[9];
	}
	for (int i = 0;i<Y;i++) {
		for (int j = 0;j<X;j++) {
			Matriz[i][j] = 0;
		}
	}
	for (int i = 0;i<Minas;i++) {
		int v1 = rand() % Y;
		int v2 = rand() % X;  
		Matriz[v1][v2] = -1;
	}
	for (int i = 1;i<Y;i++) {
		for (int j = 1;j<X;j++) {
			if (Matriz[i][j] == -1) {
				if (Matriz[i+1][j]!=-1) {
					Matriz[i+1][j]++;
				}
				if (Matriz[i-1][j]!=-1) {
					Matriz[i-1][j]++;
				}
				if (Matriz[i][j+1]!=-1) {
					Matriz[i][j+1]++;
				}
				if (Matriz[i][j-1]!=-1) {
					Matriz[i][j-1]++;
				}
				if (Matriz[i+1][j+1]!=-1) {
					Matriz[i+1][j+1]++;
				}
				if (Matriz[i+1][j-1]!=-1) {
					Matriz[i+1][j-1]++;
				}
				if (Matriz[i-1][j+1]!=-1) {
					Matriz[i-1][j+1]++;
				}
				if (Matriz[i-1][j-1]!=-1) {
					Matriz[i-1][j-1]++;
				}
			}
		}
	}
	return Matriz;
}
void recursiva(int** numeros, char** show, int y, int x){
	if(numeros[y][x]!=0){
		show[y][x] = numeros[y][x]+48;
		return;
	} else{
		if(numeros[y][x]==0){
			show[y][x] = numeros[y][x]+48;
			if(numeros[y+1][x]==0){
				show[y+1][x]=numeros[y+1][x]+48;
				return recursiva(numeros, show, y+1, x);
			}
			if(numeros[y-1][x]==0){

				show[y-1][x]= numeros[y-1][x]+48;
				return recursiva(numeros, show, y-1, x );
			}
			if(numeros[y-1][x-1]==0){
				show[y-1][x-1] = numeros[y-1][x-1]+48;
				return recursiva(numeros, show, y-1, x-1);
			}
			if(numeros[y+1][x+1]==0){
				show[y+1][x+1] = numeros[y+1][x+1]+48;
				return recursiva(numeros, show, y+1, x+1);
			}
			if(numeros[y-1][x+1]==0){
				show[y-1][x+1]= numeros[y-1][x+1]+48;
				return recursiva(numeros, show, y-1, x+1);
			}
			if(numeros[y+1][x-1]==0){
				show[y+1][x-1] = numeros[y+1][x-1]+48;
				return recursiva(numeros, show, y+1, x-1);
			}
			if(numeros[y][x-1]==0){
				show[y][x-1] = numeros[y][x-1]+48;
				return recursiva(numeros, show, y, x-1);
			}
			if(numeros[y][x+1]==0){
				show[y][x+1] = numeros[y][x+1]+48;
				return recursiva(numeros, show, y, x+1);
			}
		}
		
	}
	

}
string getString() {
	string Nombre;
	noecho();
	int ch = '0';
	int i = 0;
	while (ch != '\n') {
		ch = getch();
		//127 == BS
		if (ch==127) {
			Nombre.erase(Nombre.length()-1);
		} else {
			Nombre.push_back(ch);
		}
		clear();
		addstr(Nombre.c_str());
	}
	Nombre.erase(Nombre.length()-1);
	if (Nombre.size()==0) {
		return "NoString";
	} else {
		return Nombre;
	}

}

void Game() {
	int* XY;
	int** MatrizNum = setGame(10, 9, 9);
	char** Matriz = new char*[9];
	for (int i = 0;i<9;i++) {
		Matriz[i] = new char[9];
	}
	for (int i = 0;i<9;i++) {
		for (int j = 0;j<9;j++) {
			Matriz[i][j] = '_';
		}
	}
	show(MatrizNum, 9, 9);
	bool NotLose = true;
	while (NotLose) {
		XY = showChar(Matriz, 9, 9);
		int x = XY[0];
		int y = XY[1];
		Matriz[y][x] = (MatrizNum[y][x]+48);
		if (MatrizNum[y][x]==-1) {
			NotLose = false;
			Matriz[y][x] = 'X';
		}
		if (MatrizNum[y][x]==0) {
			//recursiva(MatrizNum, Matriz, y, x);		
		}
	}
	showChar(Matriz, 9, 9);
	addstr("\n Oficialmente perdio :P");
	delete[] XY;
	getch();
}
int ListarVector(vector<Jugador*>* vList) {
	int op = 0;
	int ch = 0;
	while (ch != '\n') {
		clear();
		for (int i = 0;i<vList->size();i++) {
			addstr(vList->at(i)->getNombre().c_str());
			addstr(" Score: ");
			addstr(to_string(vList->at(i)->getScore()).c_str());
			if (op == i) {
				addstr(" <-");
			}
			addstr("\n");
			addstr("\n");
		}		
		ch = getch();
		//Key Down == 66
		if (ch == 66) {
			op++;
			if (op >= vList->size()) {
				op = 0;
			}
		}
		//Key Down == 65
		if (ch == 65) {
			op--;
			if (op < 0) {
				op = vList->size();
			}
		}
	}	
	return op;
}

