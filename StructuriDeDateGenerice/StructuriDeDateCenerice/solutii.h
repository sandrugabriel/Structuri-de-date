#pragma once
#include "List.h"


List<int> list;

void afisare(List<int> l) {

	Node<int>* aux = list.getHead();

	while (aux!=NULL)
	{
		cout << aux->getData() << " ";
		aux = aux->getNext();
	}

}

/*#509
Să se ordoneze crescător elementele vectorului.
ex:6
8 2 9 4 5 7 
se va afisa 2 4 5 7 8 9*/
void solutia1() {

	int dim = 6, v[100] = { 8, 2, 9, 4 ,5, 7 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	list.crescator(dim);
//	list.setPoz(2, 1234);
	afisare(list);
}

/*#633
Se dă un șir cu n elemente, numere naturale. Determinați diferența în valoare absolută dintre numărul de valori pare din
șir și numărul de valori impare din șir.
Ex:
5
15 245 28 33 11 se va afisa 3
*/
void solutia2() {

	int dim = 5, v[100] = { 15, 245, 28, 33, 11 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	int ctpar = list.ctPar(dim);
	int ctimpar = list.ctImpar(dim);
	if (ctpar > ctimpar) cout << ctpar - ctimpar;
	else  cout << ctimpar - ctpar;

}

/*#4383
Se citește un vector cu n elemente, numere naturale. Să se înlocuiască ultimul element prim din vector cu 0,
apoi să se afișeze vectorul.
Ex:
5
7 4 9 6 2 se afiseaza 7 4 9 6 0*/
void solutia3() {

	int dim = 5, v[100] = { 7, 4 ,9 ,6, 2 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);
	list.setUlitmPrim(dim);
	afisare(list);
}

/*#4382
Se citește un vector cu n elemente, numere naturale. Să se înlocuiască fiecare element prim din vector cu 0,
apoi să se afișeze vectorul.
Ex:
5
7 4 9 6 2
se va afisa 0 4 9 6 0*/
void solutia4() {

	int dim = 5, v[100] = { 7, 4 ,9 ,6, 2 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	list.setPrim(dim);
	afisare(list);


}

/*#486
Să se determine maximul şi minimul valorilor elementelor unui vector.
Ex:
5
7 4 9 6 2
se va afisa 9 2
*/
void solutia5() {

	int dim = 5, v[100] = { 7, 4 ,9 ,6, 2 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.maximum(dim)<< " ";
	cout << list.minimum(dim);

}

/*#546
Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele din vector care sunt multipli ai ultimului element.
Ex:
5
7 4 9 6 2 se va afisa 4 6 2
*/
void solutia6() {

	int dim = 5, v[100] = { 7, 4 ,9 ,6, 2 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	list.afisareMultipli(dim);
}

/*#553
Să se determine indicele maximului şi cel al minimului valorilor elementelor unui vector.
Ex:
5
8 7 9 2 5 se va afisa 3 4
*/
void solutia7() {

	int dim = 5, v[100] = { 8, 7, 9, 2 ,5 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);


	cout << list.pozmaximum(dim) << " ";
	cout << list.pozminimum(dim);

}

/*#547
Se citește un vector cu n elemente, numere naturale. Să se determine câte elemente ale vectorului sunt egale cu
diferența dintre cea mai mare și cea mai mică valoare din vector.
5
7 7 9 2 4 se va afisa 2
*/
void solutia8() {

	int dim = 5, v[100] = { 7, 7 ,9, 2, 4 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	int dif = list.maximum(dim)-list.minimum(dim);
	cout << list.ctNr(dim, dif);
}

/*#490
Se citește un vector cu n elemente, numere naturale distincte. Să se afișeze elementele cuprinse între elementul cu valoarea
minimă și cel cu valoare maximă din vector, inclusiv acestea.
5
7 9 6 2 8 se va afisa 9 6 2*/
void solutia9() {

	int dim = 5, v[100] = { 7, 9, 6, 2, 8 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	int pozmaxi = list.pozmaximum(dim);
	int pozmini = list.pozminimum(dim);
	if (pozmaxi > pozmini) {
		int aux = pozmaxi;
		pozmaxi = pozmini;
		pozmini = aux;
	}

	list.afisareInterval(dim, pozmaxi,pozmini);

}

/*#491
Se citește un vector cu n elemente, numere naturale. Să se determine suma valorilor elementelor cuprinse între primul și
ultimul element par al vectorului, inclusiv acestea.
Ex:
5
7 6 1 2 8
se va afisa 17
*/
void solutia10() {

	int dim = 5, v[100] = { 7, 6, 1, 2, 8 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout<<list.sumaIntervalPare(dim);

}






