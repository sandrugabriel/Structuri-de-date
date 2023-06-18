#pragma once
#include <iostream>
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

};




