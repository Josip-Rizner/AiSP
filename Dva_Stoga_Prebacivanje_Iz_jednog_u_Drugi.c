#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct STOG_{
  int x;
  struct STOG_ *next;
}STOG;

void ispis_stoga(STOG *prvi);


STOG* prvi=NULL, *novi=NULL, *prvi2 = NULL;

void S1push(int);
int S1pop(void);
int S1IsEmpty(void);

void S2push(int);
int S2pop(void);
int S2IsEmpty(void);

int main() {
  int counter = 0, x=100;

  S1push(1);
  S1push(2);
  S1push(3);
  S1push(4);
  S1push(5);

  ispis_stoga(prvi);

  while(S1IsEmpty() == 0 ){
    S2push(S1pop());
  }

  //ubacivanje podatka x na drugo mjesto u stogu

  while( S2IsEmpty() == 0){
    if(counter == 1){
      S1push(x);
      counter++;
    }
    else{
      S1push(S2pop());
      counter++;
    }
  }

  ispis_stoga(prvi);


	return 0;
}



void S1push(int x){
  novi = (STOG*)malloc(sizeof(STOG));

  if(novi == NULL){
    printf("Stack overflow");
  }
  else{
    novi->x = x;  
    novi->next = prvi;
    prvi = novi;
  }
} 



int S1pop(void){
  int x;
  if(prvi == NULL){
    printf("Illegal poping");
    return -1;
  }

  x = prvi->x;
  STOG* temp = prvi;
  prvi = prvi->next;
  free(temp); 
  return x;
}

int S1IsEmpty(void){
  if(prvi == NULL){
    return 1;
  }
  return 0;
}


void S2push(int x){
  novi = (STOG*)malloc(sizeof(STOG));

  if(novi == NULL){
    printf("Stack overflow");
  }
  else{
    novi->x = x;  
    novi->next = prvi2;
    prvi2 = novi;
  }
} 



int S2pop(void){
  int x;
  if(prvi2 == NULL){
    printf("Illegal poping");
    return -1;
  }

  x = prvi2->x;
  STOG* temp = prvi2;
  prvi2 = prvi2->next;
  free(temp); 
  return x;
}



int S2IsEmpty(void){
  if(prvi2 == NULL){
    return 1;
  }
  return 0;
}


void ispis_stoga(STOG *prvi){
  STOG *temp = prvi;

  printf("\n");

  while(temp){
    printf("%d\t", temp->x);
    temp = temp->next;
  }
}