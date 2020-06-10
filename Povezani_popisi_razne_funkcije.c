#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Cvor{
  int x;
  struct Cvor *next;
}cvor;

cvor* napravi_popis(void);
void ubaci_izmedu(cvor *glava, int x, int y, int z);
void ispis_popisa(cvor *glava);
void ubaci_cvor(cvor* glava, int n);
cvor * ubaci(cvor *glava);
void prolaz(cvor *glava);
int uzlazno_sortiran(cvor *glava);
// 1-je, 0-nije

void dodaj_na_kraj_rekurzivno(cvor *glava, int n);

int main() {

  cvor *head;

  head = napravi_popis();
  prolaz(head);
  ispis_popisa(head);
  printf("\n%d", uzlazno_sortiran(head));

  dodaj_na_kraj_rekurzivno(head, 99);
  //ubaci_izmedu(head, 4, 6, 10);
  ispis_popisa(head);
 
	return 0;
}



cvor* napravi_popis(void){
  int flag_ = 0, n=1;
  cvor *temp=NULL, *glava=NULL;
  while(n != 0){

    printf("Unesi n: ");
    scanf("%d", &n);

    if(flag_ == 0){
      glava = (cvor*)malloc(sizeof(cvor));
      glava->x = n;
      flag_ = 1; 
      temp = glava;
    }
    else{
      temp->next = (cvor*)malloc(sizeof(cvor));
      temp = temp->next;
      temp->x = n;
    } 
  }

  temp->next = NULL;
  return glava;
}


void ubaci_izmedu(cvor *glava, int x, int y, int z){
  cvor *temp1= glava;

  while(temp1->next){
    if(temp1->x == x && temp1->next->x == y){
      ubaci_cvor(temp1, z);
    }
    temp1 = temp1->next;
  }
}

cvor * ubaci(cvor *glava){
  cvor *temp = glava;

  while(temp->next){
    ubaci_cvor(temp, temp->x - temp->next->x);
    temp = temp->next->next;
  }
  
  return glava;
}



void ubaci_cvor(cvor* glava, int n){

  cvor *novi = (cvor*)malloc(sizeof(cvor));
      novi->next = glava->next;
      novi->x = n;
      glava->next = novi;
}


void ispis_popisa(cvor *glava){
  cvor *temp = glava;

  printf("\n");

  while(temp){
    printf("%d\t", temp->x);
    temp = temp->next;
  }
}



void prolaz(cvor *glava){
  if(glava == NULL){
    return;
  }
  prolaz(glava->next);
}




int uzlazno_sortiran(cvor *glava){
  cvor *temp = glava;

  while(temp->next){
    if(temp->x > temp->next->x){
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}


void dodaj_na_kraj_rekurzivno(cvor *glava, int n){
  if(glava->next == NULL){
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->x = n;
    novi->next = NULL;
    glava->next = novi;
    return;
  }
  dodaj_na_kraj_rekurzivno(glava->next, n);
}