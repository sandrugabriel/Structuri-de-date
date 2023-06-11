#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Persoana
{

private:

	int idPersoana;
	string numele;
	int varsta;

public:

	Persoana() {



	}

	Persoana(int id, string nume, int age) {

		idPersoana = id;
		numele = nume;
		varsta = age;

	}

	int getIdPersoana() {
		return idPersoana;
	}

	void setIdPersoana(int id) {
		idPersoana = id;
	}

	string getNumele() {
		return numele;
	}

	void setNumele(string nume) {
		numele = nume;
	}

	int getVarsta() {
		return varsta;
	}

	void setVarsta(int age) {
		varsta = age;
	}

	string descriere() {

		string t;

		t += "Id: " + to_string(idPersoana) + "\n";
		t += "Numele: " + numele + "\n";
		t += "Varsta: " + to_string(varsta) + "\n";

		return t;
	}

};








