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

	int primulX(int dim, int x) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() == x) return i + 1;

			aux = aux->getNext();
		}

		return -1;
	}

	int ultimulX(int dim,int x){
	
		Node<T>* aux = head;


		for (int i = 0; i < dim; i++) {

			int ct = 0;
			Node<T>* nou = head;
			while (ct<dim-1-i)
			{
				nou = nou->getNext();
				ct++;
			}

			if (nou->getData() == x) return ct + 1;
		}
	
	
		return -1;
	}

	int pozR(int dim, int k, int x) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == x) ct++;

			if (k == ct) return i + 1;

			aux = aux->getNext();
		}

		return -1;
	}

	int maximum(int dim) {

		Node<T>* aux = head;
		int maxi = -10;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > maxi) maxi = aux->getData();
			aux = aux->getNext();
		}

		return maxi;
	}

	int ctMaiMare(int dim, int maxi) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			//cout << aux->getData() << " "<<maxi << endl;
			if (aux->getData() > maxi) {
				ct++;
			}
			aux = aux->getNext();
		}

		return ct;
	}
	
	void afisareTabeleRest(int dim) {

		Node<T>* aux = head;

		for (int k = 0; k < dim; k++) {

			if (k % 2 == 0) {

				for (int i = 0; i < aux->getData(); i++) {
					for (int j = 0; j < aux->getData(); j++) {
						cout << (i + j) % aux->getData()<< " ";
					}
					cout << endl;
				}

			}
			else
			{
				for (int i = 0; i < aux->getData(); i++) {
					for (int j = 0; j < aux->getData(); j++) {
						cout << (i * j) % aux->getData()<< " ";
					}
					cout << endl;
				}

			}

			aux = aux->getNext();
		}


	}

	int ultimulNr() {

		Node<T>* aux = head;

		while (aux->getNext() !=NULL)
		{
			aux = aux->getNext();
		}

		return aux->getData();
	}

	int ctNr(int dim, int nr) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == nr) ct++;
			aux = aux->getNext();
		}

		return ct;
	}

	void afisareSumMaxiPerechi(int dim) {

		Node<T>* aux = head;

		int pozI, pozJ;

		int sumMAxi = -10;

		for (int i = 0; i < dim/2; i++) {

			int nr1 = aux->getData();
			int nr2 = 0, ct = 0;
			Node<T>* nou = head;
			while (ct < dim - 1 - i)
			{
				ct++;
				nou = nou->getNext();
			}

			nr2 = nou->getData();

			if (nr1 + nr2 >= sumMAxi) {
				sumMAxi = nr1 + nr2;
				pozI = i;
				pozJ = ct;
			}

			aux = aux->getNext();
		}

		cout << sumMAxi << " " << pozI << " " << pozJ;
	}

	void afisareSumaN(int dim) {


		for (int i = 0; i < dim; i++) {

			Node<T>* aux = head;
			int suma = 0;
			for (int j = 0; j < dim - i; j++) {
				
				suma += aux->getData();
				aux = aux->getNext();
			}
			cout << suma << endl;
		}


	}

	void setPoz(int nr, int poz) {

		int ct = 0;

		Node<T>* aux = head;

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


		int semn = 1;

		do {

			Node<T>* aux = head;
			semn = 1;
			for (int i = 0; i < dim - 1; i++) {
				if (aux->getData() > aux->getNext()->getData()) {

					int a = getPoz(i);
					setPoz(getPoz(i+1), i);
					setPoz(a, i+1);
					semn = 0;
				}

				aux = aux->getNext();
			}

		} while (semn == 0);

	}

	int pozPrimSortat(int dim) {

		Node<T>* aux = head;

		int primulNr = aux->getData();

		crescator(dim);
		aux = head;
		for (int i = 0; i < dim; i++) {

			if (aux->getData() == primulNr) return i + 1;
			aux = aux->getNext();
		}


	}
	
	bool palindrom(int nr) {

		int t = 0,aux=nr;

		while (nr!=0)
		{
			int c = nr % 10;
			t = t * 10 + c;
			nr /= 10;
		}

		if (aux == t) return true;
		return false;
	}







};