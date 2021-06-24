#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int DaLiJeProst(int broj) {
	if (broj <= 1) {
		return 0;
	}

	for (int i = 2; i < broj; i++) {
		if (broj % i == 0) {
			return 0;
		}

	}

	return 1;
}
void najduziPodniz(int niz[], int duzinaniza) {

	int trenutni;
	int prethnodni;

	int brojac = 0;

	int max = 0;

	int maxPodniz[100];
	int duzinaPodniza = 0;

	int pomocniniz[100];
	int duzinapomocneg = 0;


	for (int i = 1; i < duzinaniza; i++) {

		prethnodni = niz[i - 1];
		trenutni = niz[i];


		if (prethnodni == trenutni) {
			brojac++;

			if (brojac == 1) {
				pomocniniz[duzinapomocneg++] = trenutni;
			}

			pomocniniz[duzinapomocneg++] = trenutni;

			if (duzinapomocneg > duzinaPodniza) {
				duzinaPodniza = duzinapomocneg;

				for (int i = 0; i < duzinapomocneg; i++) {
					maxPodniz[i] = pomocniniz[i];
				}

			}

		}
		else {
			duzinapomocneg = 0;
			brojac = 0;
		}

	}

	ispisiniz(maxPodniz, duzinaPodniza);


}
void ispisiniz(int niz[] , int duzinanniza  )

{
	for (int i = 0; i < duzinanniza;i++) {
		printf("%d \t", niz[i]); 


}

}
void unestiteelementeuniz() {

	int n; 
	printf("unesite koliko elemenata zelite u nizu"); 
	scanf("%d", &n);

		int niz[100]; 
	for (int i = 0; i < n; i++) {
		printf("unesite %d. elemet niza ",i+1); 
		scanf("%d", &niz[i]);  

	}
	printf("\n"); 
	ispisiniz(niz, n);    
}

void dodajelnaKRAJ(int nekiniz[], int *duzinaniza, int novibroj) {
	
	
	nekiniz[*duzinaniza] = novibroj; 
	(*duzinaniza)++; 

}

void dodajeNAPOCETAK(int nekiniz[], int *duzinaniza, int novibroj) {
	
	for (int i = *duzinaniza; i >= 1; i--) {
		nekiniz[i] = nekiniz[i - 1];



	}(*duzinaniza)++; 
	nekiniz[0] = novibroj; 


}
void dodajELNAPOZICIJU(int nekiniz[], int* duzinaniza, int novibroj, int pozicija) {

	for (int i = *duzinaniza; i >= pozicija;i--) {
		nekiniz[i] = nekiniz[i - 1];
	}
	(*duzinaniza)++;
	nekiniz[pozicija - 1] = novibroj;
}
void izbacujeelementSAPOCETKA(int nekiniz[], int* duzinaniza) {

	for (int i = 0; i < *duzinaniza; i++) {
		nekiniz[i] = nekiniz[i + 1];
	
	}(*duzinaniza)--; 




}

int  FREKVENCJIJIA(int nekiniz[], int duzinaniza, int nekibroj) {
	int brojac = 0; 
	for (int i = 0; i < duzinaniza;i++) {

		if (nekiniz[i] == nekibroj)brojac++;
	}return brojac; 


}
void sorirajniz(int nekiniz[], int dutinanita) {
	int j;
	for (int i = 0; i < dutinanita - 1; i++) {
		for (j = i + 1; j < dutinanita; j++) {
			if (nekiniz[i] > nekiniz[j]) {
				int cuva = nekiniz[i];
				nekiniz[i] = nekiniz[j];
				nekiniz[j] = cuva;


			}

		}



	}
}
int daLIJENIZRASTUCI(int nekiniz[], int duzinaniza) {
	for (int i = 0; i < duzinaniza - 1;i++) {
		int j = i + 1;
		if (nekiniz[i] > nekiniz[j]) {
			return 0;
		}
	}return 1; 


}
void preseknizova(int niz1[], int duzina1, int niz2[], int duzina2, int nizrazlika[], int *duzinarazlike) {
	for (int i = 0; i < duzina1; i++) {
		int sampojednom = FREKVENCJIJIA(niz1, i+1, niz1[i]); 
		if (sampojednom == 1) {
			int frekvencijaudrgom = FREKVENCJIJIA(niz2, duzina2, niz1[i]); 
			if (frekvencijaudrgom!=0 ) {
				dodajelnaKRAJ(nizrazlika, duzinarazlike, niz1[i]); 
			
			}
			

		}
	
	}


}
void razlikaNizovaMarcetaEdition(int niz1[], int duzina1, int niz2[], int duzina2, int nizrazlika[], int* duzinarazlike) {
	for (int i = 0; i < duzina1; i++) {
		int prviput = FREKVENCJIJIA(niz1, i + 1, niz1[i]); 
		if (prviput == 1) {
			int frekUDrugom = FREKVENCJIJIA(niz2, duzina2, niz1[i]);  
			if (frekUDrugom == 0) {
				dodajelnaKRAJ(nizrazlika,&*duzinarazlike, niz1[i]); 
			}
		}
}
	ispisiniz(nizrazlika, *duzinarazlike); 

}
void unijaNizovaMarcetaEdition(int niz1[], int duzina1, int niz2[], int duzina2, int nizrazlika[], int* duzinarazlike) {
	for (int i = 0; i < duzina1;i++) {
		int samojednom = FREKVENCJIJIA(niz1, i + 1, niz1[i]); 
		if (samojednom == 1) {
			int frekUDrugom = FREKVENCJIJIA(niz2, duzina2, niz1[i]); 
			if (frekUDrugom == 0) {
				dodajelnaKRAJ(nizrazlika, &*duzinarazlike, niz1[i]); 
			}
			
		}
		
	}
	for (int j = 0;j < duzina2;j++) {
		int jednomdrugiNiz = FREKVENCJIJIA(niz2, j + 1, niz2[j]);
		if (jednomdrugiNiz == 1) {
			dodajelnaKRAJ(nizrazlika, &*duzinarazlike, niz2[j]);
		}
	}
	ispisiniz(nizrazlika, *duzinarazlike);

}
int dalijePALINDROM(int niz[], int n) {
	for (int i = 0; i < n / 2; i++) {
		if (niz[i] != niz[n - (i + 1)]){
			return 0;
		}

	}return 1;





}
void ubaciSORTIRANO(int vecsortiranniz[], int* duzinaniza, int novibroj) {
	
	if (*duzinaniza == 0) {
		dodajelnaKRAJ(vecsortiranniz, duzinaniza, novibroj);
	}
	if (vecsortiranniz[0] > novibroj)dodajeNAPOCETAK(vecsortiranniz, duzinaniza, novibroj); 
	if (vecsortiranniz[(*duzinaniza) - 1] < novibroj)dodajelnaKRAJ(vecsortiranniz, duzinaniza, novibroj);
	
	for (int i = 0; i < (*duzinaniza)-1;i++) {
		int j = i + 1; 

			if (vecsortiranniz[i]<novibroj && vecsortiranniz[j]>novibroj) {
				dodajELNAPOZICIJU(vecsortiranniz, duzinaniza, novibroj, j + 1);
			
			
		
		}
	
	}







}


void pozicijaNiza(int niz[], int duzinaniza, int x) { //ovo nije za ispit to sam se zajebavao nesto

	if (FREKVENCJIJIA(niz, duzinaniza, x) == 1) {
		printf("ima ga samo jednom u nizu "); 

	}
	
	if (FREKVENCJIJIA(niz, duzinaniza, x) > 1) {
		
		int prvi; 
		int poslednji; 
		
		
		
		for (int i = 0; i < duzinaniza;i++) {
			if (FREKVENCJIJIA(niz, i + 1, x) == 1) {
				printf("\nprva pozicija x je %d", i + 1);
			}

			if (niz[i] == x) {
				poslednji = i;
		
			}
		}


		printf(" \n poslednja pozicija je %d", poslednji + 1); 
	}




}



 /*void etfSortiraj(int duzina, int niz[]) {

	int pomocni[100]; 
	int duzinapomocneg= 0 ; 

	int pomocnizaindexe[100]; 
	int duzinaindexa = 0; 
	for (int i = 0; i < duzina;i++) {
		if (niz[i] < 0) { // negativni

			dodajelnaKRAJ(pomocnizaindexe, &duzinaindexa, i);

			dodajeNAPOCETAK(pomocni, &duzinapomocneg, niz[i]);
			sorirajniz(pomocni, duzinapomocneg);


		}
	}
	
	
		for (int j = 0; j < duzinaindexa;j++) {
			
			    int x = 0; 
				int cuva; 
				niz[pomocnizaindexe[j]] = cuva;
				niz[pomocnizaindexe[j]] = pomocni[j]; 
				

				//ovo je index na kome se nalazio prvi negativan broj
	
		
	}
		
	

	
	ispisiniz(pomocnizaindexe, duzinaindexa); printf("\n ");
	ispisiniz(pomocni,duzinapomocneg );
	printf("\n "); 
	ispisiniz(niz,duzina); 




}
*/





	int main() {
		
		int nizneki[100] = { 1,-2,-5,3,3};
		int nneki = 5; 

	
		
		pozicijaNiza(nizneki, nneki, 3); 
		printf("\n");
		int niz[100] = { 2,3,4,5,6 };
		int n = 5; 
		int niz2[100] = { 7,8,8,2,4,3,4 }; 
		int n2 = 7; 
		int nizrazlika[100];
		int duzinarazlike = 0;
		printf("%d \n", 25 % 4);
		printf("%d \n", FREKVENCJIJIA(niz, 5, 2)); 

		ubaciSORTIRANO(niz, &n, 69); 

	printf("da li je taj niz sortiran %d",daLIJENIZRASTUCI(niz,n));

		printf("el koji sam dodao na prvu piziciju je ");  
		dodajELNAPOZICIJU(niz, &n, 69, 1); 
		ispisiniz(niz, n); 

		printf("%d", duzinarazlike); 
		printf("\n  soritano ubacivanje u prazan niz je "); 
		ubaciSORTIRANO(nizrazlika, &duzinarazlike, 15); 
		ispisiniz(nizrazlika, duzinarazlike);
		printf("\n %d",duzinarazlike);

		ubaciSORTIRANO(niz, &n, 3); 
		printf("\n sortiano ubacivanje je  :  ");
		ispisiniz(niz, n); 
		printf("da li je palindrom  %d \n", dalijePALINDROM(niz, n)); 
		/*preseknizova(niz,n, niz2, n2, nizrazlika, &duzinarazlike); 
		printf("preseknizova nizova je \n"); */
		ispisiniz(nizrazlika, duzinarazlike); 
		printf("\n\n");

		printf("\n\n");
		printf("unija nizova je \n");
		int niz5[100] = { 2,3,4,5,6 };
		int n5 = 5;
		int niz6[100] = { 7,8,8,2,4,3,4 };
		int n6 = 7;
		int nizrazlika5[100];
		int duzinarazlike5 = 0;
		

		unijaNizovaMarcetaEdition(niz5, n5, niz6, n6, nizrazlika5, &duzinarazlike5); 
		printf("\n\n");
		
		
		printf("\n\n");
		int poziija; 

  
		printf("%d", daLIJENIZRASTUCI(niz, n)); 
		sorirajniz(niz, n); 
		ispisiniz(niz, n); 

		unestiteelementeuniz();  
	


































































	/*
	printf("marceta kralj");
	//apsolutna vrednost //
	int x = -22;
	x = abs(x);
	printf(" \n %d \n", x);

	int visinakepeca = 144;
	visinakepeca = sqrt(visinakepeca);
	printf("\n %d", visinakepeca);

	int gorimodstepeni = 16;
	gorimodstepeni = pow(gorimodstepeni, 2);
	printf("\n %d", gorimodstepeni);

	float zaokruzime = 123.444;
	zaokruzime = ceil(zaokruzime);
	printf("\n %f", zaokruzime);

	float zaokruzinamanji = 22.33232323213;
	zaokruzinamanji = floor(zaokruzinamanji);
	printf("\n %f", zaokruzinamanji);

	int broj;
	printf("unesi cetvorocifreni broj ");
	scanf("%d", &broj);
	printf("%d", broj);

	int hiljade = broj / 1000;
	printf("\n %d", hiljade);
	int stotine = (broj - (hiljade * 1000)) / 100;
	printf("\n %d", stotine);
	int desetine = ((broj - (hiljade * 1000)) - (stotine * 100)) / 10;
	printf(" \n desetine su %d", desetine);

	int jedinice = ((broj - (hiljade * 1000)) - (stotine * 100)) - (desetine * 10);
	printf("\n jedninice su %d", jedinice);
	int proizvod = hiljade * stotine * desetine * jedinice;
	printf("\n \n PROIZVOD CIFARA CETFOROCIFRENOG BROJA %d je %d", broj, proizvod);


	srand(time(NULL));

	int br1, br2;


	br1 = rand() % 10 + 1;
	br2 = rand() % 10 + 1;

	printf("random brojevi su %d i %d", br1, br2);
	int donjagranica, gornjagranica;
	printf(" unesi interval koji zelis unesi prvo donju granicu ");
	scanf("%d", &donjagranica);
	printf("unesi sad gornju granicu intervala ");
	scanf("%d", &gornjagranica);
	int slucajanbroj = rand() % ((gornjagranica - donjagranica + 1) + donjagranica);



	int unetibroj;
	printf("unesi trocifreni broj lesino");
	scanf("%d", &unetibroj);
	printf("uneso si broj %d", unetibroj);



	int sto = unetibroj / 100;
	printf("sto je %d", sto);
	int deset = (unetibroj - (sto * 100)) / 10;
	printf("deset je %d", deset);
	int jedan = (unetibroj - (sto * 100)) - (deset * 10);
	printf("jedan je %d", jedan);

	if ((deset * deset * deset + sto * sto * sto + jedan * jedan * jedan) == unetibroj) {
		printf("broj %d jsete amstrongov broj ", unetibroj);
	}
	
	int number;
	printf("unesi broj od koga hoces da ispise zvezdice ");  
	scanf("%d", &number);  

	for (int i = 1;i <= number;i++){
		for (int j = 0;j < i;j++) {
			printf(".!.");
		}
		printf("\n");
	}

	int br; 
	printf("unesi broj od koga hoces da vidis broj cifara \n"); 
	scanf("%d", &br); 
	int brojacc = 0; 
	while (br !=0) {
		brojacc++; 
		br = br / 10;
	}
	printf("broj cifara broja koji si uneo je %d \n", brojacc); 
	int br2; 
	printf("unesi broj od koga bi hteo da vidis prvu i poslednju cifru "); 
	scanf("%d", &br2); 

	 int poslednji = br2 % 10;  

	while (br2 >= 10 ) {
		br2 = br2 / 10; 
	
	
	}printf("prva cifra je %d a poslednja cifra je %d", br2, poslednji); 

	int br3; 
	printf("unesi bilo koji broj i dobices zbir njegovich cifara"); 
	scanf("%d", &br3);

	int proizvod = 1; 
	while (br3!=0) {
	
		int zadnji = br3 % 10;  
		proizvod = proizvod* zadnji; 
		br3 = br3 / 10; 

	}printf("proizvod svih cifara broja koji si uneo je %d", proizvod);  
	
int br4 =1 ; 
printf("unesite brojeve od kojih hocete artimeticku sredinu "); 
int suma = 0; 
int brojac = 0; 

do {
	scanf("%d", &br4);
	brojac++;
	suma = suma + br4;
} while (br4 != 0); 
printf("\n brojac je %d", brojac); 
float sredina = (float) suma / brojac;  
printf("aritmeticka sredina unetih brojebva je %d", sredina); 
*/















	system("pause"); 
	return 0;  
}







