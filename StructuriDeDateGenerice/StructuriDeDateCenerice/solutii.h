#pragma once
#include "List.h"
#include "Coada.h"
#include "Stiva.h"
#include <fstream>

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



//STIVE && COZI	
Coada<int> coada;
Stiva<int> stiva;

/*Se dă un șir cu n elemente, numere naturale. Determinați diferența în valoare absolută dintre numărul de valori 
pare din șir și numărul de valori impare din șir.
Ex:
5
15 245 28 33 11 se afiseaza 3
*/
void solutia11() {

	int dim = 5, v[100] = { 15, 245, 28, 33, 11 };

	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	int ctPar = stiva.ctPar();
	int ctImpar = stiva.ctImpar();

	if (ctPar > ctImpar)
		cout << stiva.ctPar() - stiva.ctImpar();
	else cout << stiva.ctImpar() - stiva.ctPar();


}

/*Se citește un vector cu n elemente, numere naturale. Să se înlocuiască ultimul element prim din vector 
cu 0, apoi să se afișeze vectorul.
Ex:
5
7 4 9 6 2 se afiseaza 7 4 9 6 0
*/
void solutia12() {

	int dim = 5, v[100] = { 7, 4, 9, 6, 2 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.inlocuireUltimPrim(dim);
	coada.afisare();

}

/*Se citește un vector cu n elemente, numere naturale. Să se înlocuiască fiecare element prim din vector cu 
0, apoi să se afișeze vectorul.
Ex:
5
7 4 9 6 2 se afiseaza 0 4 9 6 0
*/
void solutia13() {

	int dim = 5, v[100] = { 7, 4, 9, 6, 2 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.inlocuirePrim(dim);
	coada.afisare();
}

/*Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele vectorului în următoarea 
ordine: primul, ultimul, al doilea, penultimul, etc.
Ex:
5
2 9 1 5 8 se afiseaza 2 8 9 5 1
*/
void solutia14() {

	int dim = 5, v[100] = { 2, 9, 1, 5, 8 };

	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.afisarePrimUltim(dim);
}

/*Calculaţi valoarea minimă minim și valoarea maximă maxim a valorilor elementelor vectorului.
Ex:
5
8 2 9 4 5 se afiseaza 2 9
*/
void solutia15() {

	int dim = 5, v[100] = { 8, 2, 9, 4, 5 };

	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	cout << stiva.maxim(dim) << " " << stiva.minim(dim) << " ";
}

/*Să se determine indicele maximului şi cel al minimului valorilor elementelor unui vector.
Ex:
5
8 7 9 2 5 se afiseaza 4 3
*/
void solutia16() {

	int dim = 5, v[100] = { 8, 7, 9, 2, 5 };
	for (int i = 0; i < dim; i++) coada.enqueue(v[i]);

	cout<<coada.pozMaxi(dim)+1 << " "<< coada.pozMini(dim)+1;
}

/*Se citește un vector cu n elemente, numere naturale. Să se determine câte elemente ale vectorului sunt 
egale cu diferența dintre cea mai mare și cea mai mică valoare din vector.
Ex:
5
7 7 9 2 4 se afiseaza 2
*/
void solutia17() {

	int dim = 5, v[100] = { 7, 7, 9, 2, 4 };
	for (int i = 0; i < dim; i++) {
		coada.enqueue(v[i]);
		stiva.push(v[i]);
	}

	int dif = stiva.maxim(dim) - stiva.minim(dim);
	cout << coada.ctDif(dim,dif);
}

/*Se citește un vector cu n elemente, numere naturale distincte. Să se afișeze elementele cuprinse între 
elementul cu valoarea minimă și cel cu valoare maximă din vector, inclusiv acestea.
Ex:
5
7 9 6 2 8
se afiseaza 9 6 2
*/
void solutia18() {

	int dim = 5, v[100] = { 7, 9, 6, 2, 8 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	int pozmaxi = coada.pozMaxi(dim);
	int pozmini = coada.pozMini(dim);
	if (pozmaxi < pozmini) {
		int aux = pozmaxi;
		pozmaxi = pozmini;
		pozmini = aux;
	}
	//cout << pozmini << " " << pozmaxi;

	coada.afisareInterval(dim,pozmini,pozmaxi);

}

/*Se citește un vector cu n elemente, numere naturale. Să se determine suma valorilor elementelor cuprinse
între primul și ultimul element par al vectorului, inclusiv acestea.
Ex:
5
7 6 1 2 8
se afiseaza 17
*/
void solutia19() {

	int dim = 5, v[100] = { 7, 6, 1, 2, 8 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);
	int pozprimul = coada.pozPrimuPar(dim);
	int pozultim = coada.pozUltimPar(dim);
	cout << coada.sumaInterval(dim,pozprimul,pozultim);
}

/*Se dă un vector cu n numere naturale. Să se determine câte dintre elemente au valoarea strict mai mare decât 
media aritmetică a elementelor vectorului.
Ex:
5
5 0 2 1 4 se afiseaza 2
*/
void solutia20() {

	int dim = 5, v[100] = { 5, 0, 2, 1, 4 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	int media = stiva.mediaAritmetica(dim);
	//cout << media;

	cout<<stiva.ctMaiMareMedia(dim);
}

/*Moş Crăciun s-a dus la Polul Nord Shopping City să cumpere n cadouri pentru copiii din întreaga lume. 
Fiecare cadou avea un cod de bare pentru identificarea produsului, corespunzător unui număr format din 
nouă cifre, prima cifră fiind nenulă. La plecare şi-a amintit că-i promisese unui copil isteţ un cadou 
special, care să fie diferit de toate celelalte. Moş Crăciun vă roagă să găsiţi un cadou care să aibă 
codul de bare diferit de toate celelalte.
Ex:
4
123456789 987654321 112345567 200000001
se afiseaza 412345678
*/
void solutia21() {

	int dim = 4, v[100] = { 1000000025, 987654321, 112345567, 200000001 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);
	
	cout << stiva.generareNr(dim);

}

/*La liceul nostru sunt m clase, fiecare având n elevi. Pentru fiecare elev se cunoaşte talentul artistic, 
exprimat printr-un număr natural. Să se determine cea mai mare valoare pe care o are talentul artistic al
elevilor, notată cu MAX şi numărul CNT de clase din liceu în care există elevi care au talent maxim.
Ex:
5 4
1 5 3 5
4 4 6 1
6 3 6 2
1 4 1 4
6 5 6 2
se afiseaza 6 3
*/
void solutia22() {

	int m = 5, n = 4;
	int maxi = -10;

	ifstream f("numere.txt");

	f >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int nr = 0;
			f >> nr;
			if (nr > maxi) maxi = nr;

		}
	}

	f.close();
	n = m = 0;
	ifstream g("numere.txt");
	g >> m >> n;
	int ct = 0;

	for (int i = 0; i < m; i++) {
		int semn = 0;
		for (int j = 0; j < n; j++) {
			int nr = 0;
			g >> nr;
			if (maxi == nr && semn == 0) {
				ct++;
				semn = 1;
			}
		}
	}

	cout << maxi << " " << ct;

}

/*Se dă un șir a1, a2, …, an de numere întregi. Se dau de asemenea numerele întregi x și k. Să se determine:
a) Cea mai din stânga poziție p din șir cu a[p] = x
b) Cea mai din dreapta poziție q din șir cu a[q] = x
c) Poziția r a celei de-a k-a apariții a lui x în șir.
Ex:
12
2
4
5
-7
2
3
2
5
7
2
3
4
2
3
se afiseaza 
1 
10 
7
*/
void solutia23() {

	int dim = 0;

	ifstream f("pb23.txt");

	f >> dim;

	for (int i = 0; i < dim; i++) {
		int nr = 0;
		f >> nr;
		coada.enqueue(nr);
	}

	int x, k;

	f >> x >> k;

	cout << coada.primulX(dim,x) << endl;
	cout << coada.ultimulX(dim, x) << endl;
	cout << coada.pozR(dim, k,x) << endl;

}

/*Prietenul vostru Turing va cere din nou ajutorul! Acesta isi doreste un calculator cuantic pentru a calcula o suma 
colosala, imposibila pentru orice om. Momentan nu dispune de resursele materiale si financiare pentru a lucra la nivel
cuantic asa ca va cere ajutorul vostru in sarcina sa.
Ex:
5
3 2
5 6 0
1 1
7
5 3
7 0 4 0 4
4 2
2 7 3 4
3 3
1000000000 1000000000 999999997
se afiseaza : 
11
7
15
16
2999999997
*/
void solutia24() {

	int dim;

	ifstream f("pb24.txt");

	f >> dim;

		int s=0;
	for (int i = 0; i < dim; i++) {

		int n, k;

		f >> n >> k;

		s = 0;
		for (int j = 0; j < n; j++) {
			int nr;
			f >> nr;
			s = nr + s;
			if (i == 4) {
				cout << nr << endl;
				cout << "suma: " << s << endl;
			}
		
		}
		//cout << s << endl;

	}


}

/*Se dau două şiruri cu elemente numere naturale. Determinaţi câte dintre elementele primului şir sunt mai 
mari decât toate elementele celui de-al doilea şir.
Ex:
5
7 8 10 1 9
6
1 3 6 2 7 3
se afiseaza 3
*/
void solutia25() {

	int dim = 0, dim1 = 0;

	ifstream f("pb25.txt");

	f >> dim;

	for (int i = 0; i < dim; i++) {
		int nr;
		f >> nr;
		coada.enqueue(nr);
	}

	f >> dim1;

	Coada<int> coada1;

	for (int i = 0; i < dim1; i++) {
		int nr;
		f >> nr;
		coada1.enqueue(nr);
	}

	int maxi = coada1.maximum(dim);

	cout << coada.ctMaiMare(dim, maxi);

}

/*Dându-se un șir cu n elemente numere naturale, să se construiască pentru fiecare element din șir câte un tabel
al claselor de resturi asociat prin înmulțire dacă indicelele elementului este impar, respectiv prin adunare 
dacă indicele elementului este par.
Ex:
3
2 4 3
se afiseaza 
0 1
1 0
0 0 0 0
0 1 2 3
0 2 0 2
0 3 2 1
0 1 2
1 2 0
2 0 1
*/
void solutia26() {

	int dim=0;

	ifstream f("pb26.txt");

	for (int i = 0; i < dim; i++) {
		int nr = 0;
		f >> nr;
coada.enqueue(nr);
	}
		

	coada.afisareTabeleRest(dim);

}

/*Calculaţi valoarea maxima maxim a celor n numere date şi numărul nrmax de apariţii ale acestei valori în şir.
ex:
5
5 3 2 4 5 se afiseaza 5 2
*/
void solutia27() {

	int dim;

	ifstream f("pb27.txt");

	f >> dim;

	for (int i = 0; i < dim; i++) {
		int nr;
		f >> nr;
		stiva.push(nr);
	}

	cout << stiva.maxim(dim) << " ";
}

/*Să se determine câte elemente din şir sunt egale cu ultimul element al acestuia.
Ex:
5
5 3 2 4 5 se afiseaza 2
*/
void solutia28() {

	int dim = 0;

	ifstream f("pb28.txt");
	f >> dim;
	for (int i = 0; i < dim; i++) {
		int nr;
		f >> nr;
		coada.enqueue(nr);
	}

	int ultimNr = coada.ultimulNr();
	//cout << ultimNr;
	cout << coada.ctNr(dim, ultimNr);
}

/*Să se determine câte elemente din şir sunt numere prime.
Ex:
5
25 17 2 10 13 se afiseaza 3
*/
void solutia29() {

	int dim = 0;

	ifstream f("pb29.txt");

	f >> dim;

	for (int i = 0; i < dim; i++) {
		int nr = 0;
		f >> nr;
		stiva.push(nr);
	}

	cout << stiva.ctPrime(dim);

}
