#pragma once
#include <iostream>
#include <string>
using namespace std;
class Jugador {
	private: 
		string Nombre;
		string User;
		string Password;
		int Score;
	public: 
		Jugador(string, string, string, int);
		void  setNombre(string);
		void  setUser(string);
		void  setPassword(string);
		void  setScore(int);
		string getNombre();
		string getUser();
		string getPassword();
		int getScore();
};
