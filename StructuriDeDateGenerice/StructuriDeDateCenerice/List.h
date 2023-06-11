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




};








