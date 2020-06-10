#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

typedef struct STOG_{
  int x;
  struct STOG_ *next;
}STOG;


STOG* prvi=NULL, *novi=NULL;

int stog[MAX];
int sp=-1;

void push(int);
int pop(void);
int povrhF(int, int);

//za PP

void pushPP(int);
int popPP(void);



int main() {
  int x=30;
  int povrh = 0, povrhPP=0, a, b, n, m, rez;
  time_t t1, t2, t3, t4, t5, t6;

  a=x;
  b=x/2;  

  //Rekurzivno
  t1 = clock();

  rez = povrhF(a, b);

  t2 = clock();
  printf("%d\n", rez);

  //Stog pomocu niza
  t3 = clock();

  push(a);
  push(b);

  do{
    m=pop();
    n=pop();

    if(m==n || m==0){
      povrh++;
    }
    else{
      push(n-1);
      push(m-1);
      push(n-1);
      push(m);
    }

  }while(sp>=0);

  t4 = clock();
  printf("%d\n", povrh);

  //Stog pomocu PP-a
  t5 = clock();
  pushPP(a);
  pushPP(b);

  do{
    m=popPP();
    n=popPP();

    if(m==n || m==0){
      povrhPP++;
    }
    else{
      pushPP(n-1);
      pushPP(m-1);
      pushPP(n-1);
      pushPP(m);
    }

  }while(prvi != NULL);
  t6 = clock();
  printf("%d\n", povrhPP);


  printf("Rekurzivno: %ld us\n",t2-t1);
  printf("Sa stogom(Nizovi): %ld us\n", t4-t3);
  printf("Sa stogom(Povezani popisi): %ld us\n", t6-t5);

	return 0;
}





int povrhF(int a, int b){
  if(a==b || b==0){
    return 1;
  }
  return povrhF(a-1, b-1) + povrhF(a-1, b); 
}

void push(int broj){

  if(sp == (MAX-1)){
    printf("Stack Overflow\n");
  }

  else{
    sp=sp+1;
    stog[sp] = broj;
  }
}

int pop(void){

  int x;

  if(sp == -1){
    printf("Stack Underflow\n");
    return -1;
  }
  else{
    x = stog[sp];
    //printf("%d\n",stog[sp]);
    sp=sp-1;
    return x;  
  }
}

void pushPP(int x){
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

int popPP(void){
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