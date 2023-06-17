#pragma once
#include "Node.h"

template<typename T>

struct List
{

private:
	Node<T>* head = NULL;

public:

	Node<T>* getHead() {
		return head;
	}

	void addStart(T data) {

		if (head == NULL) {
			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);
		}
		else {

			Node<T>* nou = new Node<T>();

			nou->setNext(head);
			nou->setData(data);
			head = nou;

		}


	}

	void addEnd(T data) {

		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);

		}
		else
		{

			Node<T>* aux = head;

			while (aux->getNext() != NULL)
			{
				aux = aux->getNext();
			}

			Node<T>* nou = new Node<T>();

			nou->setData(data);
			nou->setNext(NULL);
			aux->setNext(nou);
		}


	}

	void addPoz(T data, int poz) {

		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);

		}
		else
		{
			Node<T>* aux = head;
			int ct = 0;
			while (ct < poz)
			{
				ct++;
				aux = aux->getNext();
			}

			Node<T>* nou = new Node<T>();

			nou->setData(data);
			nou->setNext(aux->getNext());
			aux->setNext(nou);



		}



	}

	void stergerePrimul() {
		head = head->getNext();
	}

	void stergereUltimul() {

		Node<T>* aux = head;

		while (aux->getNext()->getNext()!=NULL)
		{
			aux = aux->getNext();
		}

		aux->setNext(NULL);

	}

	void stergerePoz(int poz) {

		int ct = 0;
		Node<T>* aux = head;

		if (poz == 0) {
			stergerePrimul();
		}

		while (ct<poz-1)
		{
			ct++;
			aux = aux->getNext();
		}

		if (aux->getNext() == NULL) {
			stergereUltimul();
		}

		aux->setNext(aux->getNext()->getNext());

	}

	int size() {

		Node<T>* aux = head;
		int ct = 0;

		while (aux!=NULL)
		{
			aux = aux->getNext();
			ct++;
		}


		return ct;
	}

	void setPoz(int poz, int nr) {

		Node<T>* aux = head;

		int ct = 0;
		while (ct<poz)
		{
			ct++;
			aux = aux->getNext();
		}
	
		aux->setData(nr);
	}

	int getPoz(int poz) {

		Node<T>* aux = head;

		int ct = 0;

		while (ct<poz)
		{
			ct++;
			aux = aux->getNext();
		}

		return aux->getData();
	}

	void crescator(int dim) {

		Node<T>* aux = head;

		int semn = 0;

		do {
			semn = 1;
			aux = head;
			for (int i = 0; i < dim - 1; i++) {
				if (aux->getData() > aux->getNext()->getData()) {
					int aux = getPoz(i);
					setPoz(i, getPoz(i+1));
					setPoz(i + 1, aux);
					semn = 0;
				}

				aux = aux->getNext();
			}
		} while (semn == 0);



	}

	int ctPar(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() % 2 == 0)
				ct++;
			aux = aux->getNext();
		}

		return ct;	
	}

	int ctImpar(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() % 2 == 1)
				ct++;
			aux = aux->getNext();
		}

		return ct;
	}

	bool prim(int nr) {

		if (nr == 0 || nr == 1) {
			return false;
		}

		for (int i = 2; i <= nr / 2; i++) {
			if (nr % i == 0) return false;
		}

		return true;
	}

	void setUlitmPrim(int dim) {

		Node<T>* aux = head;

		for (int i = dim - 1; i >= 0; i--) {
			aux = head;

			int ct = 0;
			while (ct < i)
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
	
	void setPrim(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i <dim; i++) {

			if (prim(aux->getData())) {
				aux->setData(0);
			}
			aux = aux->getNext();
		}
	}

	int maximum(int dim) {

		int maxi = -1;

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > maxi)
				maxi = aux->getData();
			aux = aux->getNext();
		}
		return maxi;
	}

	int minimum(int dim) {

		int mini = 99999;

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() < mini)
				mini = aux->getData();
			aux = aux->getNext();
		}
		return mini;
	}

	int ultimNr(int dim) {
		
		Node<T>* aux = head;

		for (int i = 0; i < dim - 1; i++)
			aux = aux->getNext();

		return aux->getData();
	}

	void afisareMultipli(int dim) {

		Node<T>* aux = head;
		int ultim = ultimNr(dim);

		for (int i = 0; i < dim; i++) {
			if (aux->getData() % ultim == 0)
				cout << aux->getData() << " ";
			aux = aux->getNext();
		}

	}

	int pozmaximum(int dim) {

		int maxi = -1;
		int poz = 0;
		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > maxi) {
				maxi = aux->getData(); 
				poz = i;
			}
			aux = aux->getNext();
		}
		return poz+1;
	}

	int pozminimum(int dim) {

		int mini = 99999;
		int poz = 0;
		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() < mini) {
				mini = aux->getData(); 
				poz = i;
			}
				
			aux = aux->getNext();
		}
		return poz+1;
	}

	int ctNr(int dim, int dif) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == dif) ct++;
			aux = aux->getNext();
		}

		return ct;
	}

	void afisareInterval(int dim, int pozmaxi, int pozmini) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			if (i >= pozmaxi-1 && i <= pozmini-1) {
				cout << aux->getData() << " ";
			}
			aux = aux->getNext();
		}

	}

	int pozPrimulPar(int dim) {

		Node<T>* aux = head;


		for (int i = 0; i < dim; i++) {
			if (aux->getData() % 2 == 0) return i;
			aux = aux->getNext();
		}

		return -1;
	}

	int pozUltimPar(int dim) {

		Node<T>* aux = head;


		for (int i = dim-1; i >= 0; i--) {
			aux = head;
			int ct = 0;
			while (ct<i)
			{
				ct++;
				aux = aux->getNext();
			}
			if (aux->getData() % 2 == 0) return i;
			aux = aux->getNext();
		}

		return -1;
	}

	int sumaIntervalPare(int dim) {

		Node<T>* aux = head;

		int s = 0;

		for (int i = 0; i < dim; i++) {
			if (i >= pozPrimulPar(dim) && i <= pozUltimPar(dim))
				s+=aux->getData();
			aux = aux->getNext();
		}


		return s;
	}

	int mediaAritmetica(int dim) {

		Node<T>* aux = head;

		int s = 0;

		for (int i = 0; i < dim; i++) {
			s += aux->getData(); 
			aux = aux->getNext();
		}

		return s / dim;
	}

	int ctMaiMareMedia(int dim) {

		Node<T>* aux = head;

		int media = mediaAritmetica(dim);
		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > media) ct++;
			aux = aux->getNext();
		}

		return ct;
	}
	
	int ctPerechiCifZeci(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			Node<T>* nou = head;
			int ct1 = 0;
			while (ct1 < i - 1)
			{
				ct1++;
				nou = nou->getNext();
			}

			for (int j = i; j < dim; j++) {
				if (aux->getData() / 10 % 10 == nou->getData() / 10 % 10)
					ct++;
				nou = nou->getNext();
			}
			aux = aux->getNext();
		}

		return ct / 2;
	}
};








