#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;
	Jugador::Jugador(string Nombre, string User, string Password, int Score) { 
		setNombre(Nombre);
		setUser(User);
		setPassword(Password);
		setScore(Score);
	}
	void Jugador::setNombre(string a) {
		this->Nombre = a;
	}
	void Jugador::setUser(string a) {
		this->User = a;
	}
	void Jugador::setPassword(string a) {
		this->Password = a;
	}
	void Jugador::setScore(int a) {
		this->Score = a;
	}
	string Jugador::getNombre() {
		return this->Nombre;
	}
	string Jugador::getUser() {
		return this->User;
	}
	string Jugador::getPassword() {
		return this->Password;
	}
	int Jugador::getScore() {
		return this->Score;
	}
