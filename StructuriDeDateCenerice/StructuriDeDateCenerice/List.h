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



};








