#pragma once
#include "Node.h"

template<typename T>
struct Coada
{

private:
	Node<T>* head = NULL;

public:

	Node<T>* getHead() {
		return head;
	}

	void enqueue(T data) {

		if (head == NULL) {
			head = new Node<T>();
			head->setNext(NULL);
			head->setData(data);

		}
		else
		{
			Node<T>* nou = new Node<T>();
			Node<T>* aux = head;

			while (aux->getNext()!=NULL)
			{

				aux = aux->getNext();

			}

			nou->setData(data);
			nou->setNext(NULL);
			aux->setNext(nou);

		}

	}

	int dequeue() {

		Node<T>* aux = head;

		while (aux->getNext()->getNext()!=NULL)
		{
			aux = aux->getNext();
		}
		int nr = aux->getNext()->getData();
		aux->setNext(NULL);
		return nr;
	}

	int peek() {

		Node<T>* aux = head;

		while (aux->getNext()!=NULL)
		{
			aux = aux->getNext();
		}

		return aux->getData();
	}

	bool contains(T data) {

		Node<T>* aux = head;

		while (aux!=NULL)
		{
			if (aux->getData() == data) return true;
			aux = aux->getNext();
		}

		return false;
	}

	void clear() {

		while (head!=NULL)
		{
			head = head->getNext();
		}

	}

	void afisare() {

		Node<T>* aux = head;

		while (aux!=NULL)
		{

			cout << aux->getData() << " ";
			aux = aux->getNext();

		}

	}

	bool prim(int nr) {

		if (nr == 0 || nr == 1) return false;

		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0) return false;

		return true;
	}

	void inlocuireUltimPrim(int dim) {

		for (int i = 0; i < dim; i++) {

			Node<T>* aux = head;
			int ct =0;

			while (ct<dim-i-1)
			{
				ct++;
				aux = aux->getNext();
			}

			if (prim(aux->getData())) {
				aux->setData(0);
				return;
			}
		}


	}

	void inlocuirePrim(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			if (prim(aux->getData())) aux->setData(0);

			aux = aux->getNext();
		}

	}

	void afisarePrimUltim(int dim) {

		Node<T>* aux = head;
		int d = 0;
		for (int i = 0; i < dim; i+=2) {

			if (i % 2 == 0) {

				cout << aux->getData() << " ";

				aux = aux->getNext();

				if (d < dim/2) {


					int ct = 0;

					Node<T>* aux1 = head;

					while (ct < dim - d - 1)
					{
						ct++;
						aux1 = aux1->getNext();
					}

					cout << aux1->getData() << " ";
				}

				d++;
			}

		}



	}

	int pozMaxi(int dim) {

		Node<T>* aux = head;
		int maxi = -1,poz=0;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() > maxi) {
				maxi = aux->getData();
				poz = i;
			}
			aux = aux->getNext();
		}

		return poz;
	}

	int pozMini(int dim) {

		Node<T>* aux = head;

		int mini = 999, poz = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() < mini) {
				mini = aux->getData();
				poz = i;
			}
			aux = aux->getNext();
		}

		return poz;
	}

	int ctDif(int dim, int dif) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {

			if (dif == aux->getData()) ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	void afisareInterval(int dim, int pozmini, int pozmaxi) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			if (pozmini <= i && i <= pozmaxi) cout << aux->getData() << " ";

			aux = aux->getNext();
		}

		
	}

	int pozPrimuPar(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() % 2 == 0) return i;
			aux = aux->getNext();
		}

		return -1;
	}

	int pozUltimPar(int dim) {


		for (int i = 0; i < dim; i++) {

			Node<T>* aux = head;

			int ct = 0;

			while (ct<dim-1-i)
			{
				ct++;
				aux = aux->getNext();
			}

			if (aux->getData() % 2 == 0) return ct;
		}


	}

	int sumaInterval(int dim, int poz1, int poz2) {

		Node<T>* aux = head;

		int s = 0;

		for (int i = 0; i < dim; i++) {
			if (poz1 <= i && i <= poz2) s += aux->getData();
			aux = aux->getNext();
		}

		return s;
	}

};