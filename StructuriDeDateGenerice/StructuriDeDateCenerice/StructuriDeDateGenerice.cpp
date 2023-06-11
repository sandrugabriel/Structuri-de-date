#include "List.h"


void afisareMasini(List<Masina> list) {

	Node<Masina>* it = list.getHead();

	while (it != NULL)
	{
		cout << it->getData().descriere()<<endl;
		it = it->getNext();
	}

}

void afisarePersoane(List<Persoana> list) {

	Node<Persoana>* it = list.getHead();

	while (it != NULL)
	{
		cout << it->getData().descriere() << endl;
		it = it->getNext();
	}



}

int main()
{

	List<Masina> list;

	Masina data1(1, "test1", "test1", 12000, 30000);
	Masina data2(2, "test2", "test2", 12000, 30000);
	Masina data3(3, "test3", "test3", 12000, 30000);
	Masina data4(4, "test4", "test4", 12000, 30000);
	Masina data5(5, "test5", "test5", 12000, 30000);


	list.addStart(data1);
	list.addStart(data2);
	list.addStart(data3);
	list.addStart(data4);
	list.addStart(data5);

	//afisareMasini(list);
  
	List<Persoana> listPerosana;

	Persoana pers1(1, "pers1", 17);
	Persoana pers2(2, "pers2", 17);
	Persoana pers3(3, "pers3", 17);
	Persoana pers4(4, "pers4", 17);
	Persoana pers5(5, "pers5", 17);
	Persoana pers6(6, "pers6", 17);


	listPerosana.addStart(pers1);
	listPerosana.addStart(pers2);
	listPerosana.addStart(pers3);
	listPerosana.addStart(pers4);
	listPerosana.addStart(pers5);


	listPerosana.addEnd(pers5);
	listPerosana.addPoz(pers6, 3);

	listPerosana.stergerePrimul();
	listPerosana.stergereUltimul();
	listPerosana.stergerePoz(3);

	cout<<listPerosana.size()<<endl;

	afisarePersoane(listPerosana);


}