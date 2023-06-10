#pragma once
#include "Nod.h"

using namespace std;

struct List
{

private:
	Node* head = NULL;
public:

	void addStart(Masina  masina) {


		if (head == NULL) {

			head = new Node();

			head->setNext(NULL);
			head->setData(masina);
		}
		else {
			Node* nou = new Node();
			nou->setNext(head);
			nou->setData(masina);
			head = nou;
			
		}
		
    }

	Node* getHead() {
		return head;
	}

	void afisare() {


		Node* aux = head;
		

		while (aux!=NULL)
		{

			cout << aux->getData().descriere();
			aux = aux->getNext();
		}

	}

	void addEnd(Masina masina) {

		if (head == NULL) {

			head = new Node();

			head->setNext(NULL);
			head->setData(masina);
		}
		else {


			Node* aux = head;

			while (aux->getNext() != NULL) {

				aux = aux->getNext();
			}


			Node* nou = new Node();

			nou->setNext(NULL);
			nou->setData(masina);
			aux->setNext(nou);

		}

		
	}

	void addPoz(Masina masina, int poz) {


		if (head == NULL) {

			head = new Node();

			head->setNext(NULL);
			head->setData(masina);
		}
		else
		{

			Node* aux = head;

			int ct = 0;

			if (poz == 0) {
				addStart(masina);
				return;
			}

			while (ct<poz-1)
			{

				aux = aux->getNext();
				ct++;
			}

			if (aux->getNext() == NULL) {

				addEnd(masina);
				return;
			}

			Node* nou = new Node();
			nou->setNext(aux->getNext());
			nou->setData(masina);
			aux->setNext(nou);

		}


	}

	void stergereaPrimElement() {

		head = head->getNext();

	}

	void stergereUltim() {

		Node* aux = head;

		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}

		aux->setNext(NULL);

	}

	void stergerePoz(int poz) {

		Node* aux = head;

		int ct = 0;

		if (poz == 0) {
			stergereaPrimElement();
			return;
		}

		while (ct<poz-1)
		{
			aux = aux->getNext();
			ct++;
		}

		if (aux->getNext() == NULL) {
			stergereUltim();
			return;
		}

		aux->setNext(aux->getNext()->getNext());

	}

	//todo: set pe o anumita pozitie
	//todo: get de pe o anumita pozitie
	//todo: 

	int size() {

		Node* aux = head;
		int ct = 0;
		while (aux->getNext()!=NULL)
		{
			aux = aux->getNext();
			ct++;
		}

		return ct+1;
	}
	
	void setPoz(int poz,Masina masina){
		Node* aux = head;
		int ct = 0;
		while (ct<poz)
		{
			aux = aux->getNext();
			ct++;
		}
		
		aux->setData(masina);

	
	}

	Masina getPoz(int poz) {

		Node* aux = head;

		int ct = 0;

		while (ct<poz)
		{
			aux = aux->getNext();
			ct++;
		}

		return aux->getData();
	}

	void crescator(int dim) {

		Node* head1 = head;

		int semn = 1;

		do {
			semn = 1;
			head1 = head;
			for (int i = 0; i < dim - 1; i++) {

				if (head1->getData().getPret() > head1->getNext()->getData().getPret()) {

					Masina aux = getPoz(i);
					setPoz(i, getPoz(i + 1));
					setPoz(i + 1, aux);
					semn = 0;
				}

				head1 = head1->getNext();
			}

		} while (semn == 0);



	}

	int maxiPret(int dim) {
		Node* aux = head;
		int maxi = -1;

		for (int i = 0; i < dim; i++) {

			if (aux->getData().getPret() > maxi)
				maxi = aux->getData().getPret();

			aux = aux->getNext();
		}

		return maxi;
	}

};




