#pragma once
#include <iostream>
#include <math.h>
#include "Node.h"

using namespace std;

template<typename T>
struct Stiva
{

private:

	Node<T>* head = NULL;

public:

	void push(T data) {

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

	int peek() {

		return head->getData();

	}

	int pop() {

		head = head->getNext();
		return head->getData();

	}

	bool contains(T data) {

		Node<int>* aux = head;

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

	Node<T>* getHead() {
		return head;
	}

	int ctPar() {

		Node<T>* aux = head;

		int ct = 0;

		while (aux!=NULL)
		{
			if (aux->getData() % 2 == 0) ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	int ctImpar() {

		Node<T>* aux = head;

		int ct = 0;

		while (aux!=NULL)
		{
			if (aux->getData() % 2 == 1) ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	int maxim(int dim) {

		Node<T>* aux = head;
		int maxi = -1;
		while (aux!=NULL)
		{
			if (aux->getData() > maxi) maxi = aux->getData();

			aux = aux->getNext();
		}

		return maxi;
	}

	int minim(int dim) {

		Node<T>* aux = head;

		int mini = 9999;

		while (aux!=NULL)
		{
			if (aux->getData() < mini) mini = aux->getData();

			aux = aux->getNext();
		}

		return mini;
	}

	int mediaAritmetica(int dim) {

		Node<T>* aux = head;

		int s = 0;

		for (int i = 0; i < dim; i++) {
			s += aux->getData();
			aux=aux->getNext();
		}

		return s / dim;
	}

	int ctMaiMareMedia(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > mediaAritmetica(dim)) ct++;
			aux = aux->getNext();
		}

		return ct;
	}

	bool verificareDiferit(int dim, int nr) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {
			
			if (aux->getData() == nr) return true;

			aux = aux->getNext();
		}

		return false;
	}

	int generareNr(int dim) {

		for (int i = 1; i <= 10000; i++) {
			for (int j = 0; j <= 1000; j++) {
				int nr = i * pow(10, 9) + i * j * 23 * j + 25;

				if (verificareDiferit(dim, nr) == 0) return nr;

			}
		}


	}

	bool prim(int nr) {

		if (nr == 0 || nr == 1) return false;

		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0) return false;

		return true;
	}

	int ctPrime(int dim) {
		
		Node<T>* aux = head;

		int ct = 0;
		for (int i = 0; i < dim; i++) {
			if(prim(aux->getData())) ct++;
				aux = aux->getNext();
		}

		return ct;
	}

	bool patratPerfect(int nr) {
		if (sqrt(nr) == (int)sqrt(nr)) return true;
		return false;
	}

	int contor(int nr) {

		int ct = 0;

		while (nr!=0)
		{
			ct++;
			nr /= 10;
		}

		return ct;
	}

	void afisarePatratPerfect(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			int nr = 0;

			nr = aux->getData();

			if(contor(nr)>2)
				nr = nr / pow(10, contor(nr )/ 2);

			if (patratPerfect(nr)) cout << aux->getData() << " ";

			aux = aux->getNext();
		}

	}

	int factorial(int dim) {

		Node<T>* aux = head;

		int fact = 1;

		for (int i = 1; i <= dim; i++) fact *= i;

		return fact;
	}

	void dividFactorialul(int dim, int fact) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			if (fact % aux->getData() == 0) cout << aux->getData() << " ";

			aux = aux->getNext();
		}
	}



};




