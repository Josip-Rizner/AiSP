#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popuniPolje(int *polje, int n);
void ispis(int *polje, int n);
void swap(int *a, int *b);


void bubbleSort(int *polje, int n);
void selectionSort(int polje[], int n);
void quickSort(int polje[], int low, int high);
int partition(int polje[], int low, int high);


int sekvencijalnoPretrazivanje(int *polje, int n, int broj);
int binarnoPretrazivanje(int *polje, int low,int high, int broj);
int binarnoRekurzivnoPretrazivanje(int polje[], int low, int high, int broj);


int main() {
	/* Napravi i popuni polje */


	int n=500, *polje;
	polje = (int*)malloc(sizeof(int)*n);

  time_t t1, t2;

	popuniPolje(polje, n);
	ispis(polje, n);

	
	//bubbleSort(polje, n);
	//selectionSort(polje, n);
	quickSort(polje, 0, n-1);
	
	ispis(polje, n);
	
	printf("Broj %d se nalazi na %d mjestu (sek).\n", 536, sekvencijalnoPretrazivanje(polje, n, 536));
	printf("Broj %d se nalazi na %d mjestu (bin).\n", 536, binarnoPretrazivanje(polje, 0, n-1, 536));
	printf("Broj %d se nalazi na %d mjestu (binRek).\n", 536, binarnoRekurzivnoPretrazivanje(polje, 0, n - 1, 536));


	getch();
	return 0;
}

void ispis(int *polje, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", polje[i]);
	}

	printf("\n\n\n\n\n");
}

void popuniPolje(int *polje, int n) {
	int i;
	for (i = 0; i < n; i++) {
		polje[i] = rand() % 1001;
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



	/*SORTIRANJA*/

void bubbleSort(int *polje, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (polje[j] > polje[j + 1]) {
				swap(&polje[j], &polje[j + 1]);
			}
		}
	}
}

void selectionSort(int polje[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{		  
		min = i;
		for (j = i + 1; j < n; j++) {
			if (polje[j] < polje[min]) {
				min = j;
			}
		}
		swap(&polje[min], &polje[i]);
	}
}

				/*Quicksort*/
void quickSort(int polje[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(polje, low, high);
		quickSort(polje, low, pi - 1);
		quickSort(polje, pi + 1, high);
	}
}

int partition(int polje[], int low, int high)
{
	//printf("\n %d ---- %d\n", low, high);
	int pivot = polje[high];  
	int i = (low-1);  

	for (int j = low; j <= high - 1; j++)
	{
		if (polje[j] < pivot)
		{
			i++;   
			//printf("%d %d      ", polje[i], polje[j]);
			swap(&polje[i], &polje[j]);
		}
	}
	//printf("\n\n");
	swap(&polje[i + 1], &polje[high]);
	//printf("%d %d", polje[i + 1], polje[high]);
	return (i + 1);
}



	/*PRETRAŽIVANJA*/

int sekvencijalnoPretrazivanje(int *polje, int n, int broj) {
	int i;

	for (i = 0; i < n; i++) {
		if (polje[i] == broj) {
			return i;
		}
	}
	return -1;
}

int binarnoPretrazivanje(int *polje, int low, int high,  int broj) {
	while (low <= high) {
		int m = low + (high - low) / 2;

		if (polje[m] == broj) {
			return m;
		}

		if (polje[m] < broj) {
			low = m + 1;
		}
		
		else {
			high = m - 1;
		}
	}

	return -1;
}

int binarnoRekurzivnoPretrazivanje(int polje[], int low, int high, int broj)
{
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (polje[mid] == broj)
			return mid;

		if (polje[mid] > broj)
			return binarnoRekurzivnoPretrazivanje(polje, low, mid - 1, broj);

		return binarnoRekurzivnoPretrazivanje(polje, mid + 1, high, broj);
	}

	return -1;
}