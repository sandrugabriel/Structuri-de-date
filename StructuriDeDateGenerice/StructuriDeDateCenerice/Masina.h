#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Masina
{

private:
	int idMasina;
	string marca;
	string model;
	int km;
	int pret;

public:

	Masina() {



	}

	Masina(int id, string marca1, string model1, int km1, int pret1) {

		idMasina = id;
		marca = marca1;
		model = model1;
		km = km1;
		pret = pret1;
	}

	int getIdmasina() {
		return idMasina;
	}

	void setIdMasina(int id) {
		idMasina = id;
	}

	string getMarca() {
		return marca;
	}

	void setMarca(string m) {
		marca = m;
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

	void setKm(int km1) {
		km = km1;
	}

	int getPret() {
		return pret;
	}
	
	void setPret(int pret1) {
		pret = pret1;
	}

	string descriere() {
		string t;

		t += "Id: " + to_string(idMasina) + "\n";
		t += "Marca: " + marca + "\n";
		t += "Model: " + model + "\n";
		t += "Km: " + to_string(km) + "\n";
		t += "Pret: " + to_string(pret) + "\n";

		return t;
	}

};



