#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Masina
{
	
private:
	string marca;
	string model;
	int km;
	int pret;

public:

	Masina() {

	}
	Masina(string mar, string mod, int km1, int pret1) {

		marca = mar;
		model = mod;
		km = km1;
		pret = pret1;

	}

	string getMarca() {
		return marca;
	}

	void setMarce(string n) {
		marca = n;
	}

	string getModel() {
		return model;
	}

	void setModel(string m) {
		model = m;
	}

	int getKm() {
		return km;
	}

	void setKm(int k) {
		km = k;
	}

	int getPret() {
		return pret;
	}

	void setPret(int p) {
		pret = p;
	}

	string descriere() {

		string text = "";

		text += "Marca: " + marca + "\n";
		text += "Model: " + model + "\n";
		text += "Km: " + to_string(km) + "\n";
		text += "Pret: " + to_string(pret) + "\n\n\n";

		return text;
	}

};











