// Initializare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Lista.h"
#include "Masina.h"

int main()
{

	List lista;

	Masina masina1("test1", "4", 300000, 8000);
	Masina masina2("test2", "6", 100000, 11000);
	Masina masina3("test3", "Model X", 20000, 80000);
	Masina masina4("test4", "seria 3", 250000, 12000);
	Masina masina5("test5", "test5", 2500, 102000);
	Masina masina6("test6", "test6", 2500, 102000);


	lista.addStart(masina1);//3
	lista.addStart(masina2);//2
	lista.addStart(masina3);//1
	lista.addStart(masina4);//0


	Node* it = lista.getHead();
	it = it->getNext()->getNext();
//	cout << it->getData().getMarca();

	lista.addEnd(masina5);

	lista.addPoz(masina6, 0);

	lista.stergereaPrimElement();
	lista.stergereUltim();

//	lista.stergerePoz(1);

//	lista.setPoz(1, it);

	//cout << lista.getPoz(3).getMarca()<< endl;
//	lista.setPoz(1, masina1);
	int dim =lista.size();
	//cout <<dim;
//	lista.crescator(dim);
//	lista.afisare();
	cout << lista.maxiPret(dim);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
