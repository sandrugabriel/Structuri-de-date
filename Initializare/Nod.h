#pragma once
#include "Masina.h"


using namespace std;


struct Node {

private:

	Node* next;
	Masina data;

public:

	Node(){

	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* n) {
		next = n;
	}

	Masina getData() {
		return data;
	}

	void setData(Masina a) {
		data = a;
	}

};












