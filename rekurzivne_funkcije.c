#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int parni = 0;

int brojZnamenaka(int n);
int brojParnihZnamenaka(int n);
int u_binarno(int n);
int zbroj_znamenaka(int n);
int bin_u_dec(int n);

int main() {

  

  printf("%d\n", brojZnamenaka(5555));
  printf("%d\n", brojParnihZnamenaka(122));
  printf("%d\n", u_binarno(33));
  printf("%d\n", zbroj_znamenaka(12345));
  printf("%d\n", bin_u_dec(100001));
  
	//getch();
	return 0;
}

int brojZnamenaka(int n){
  n=n/10;
  if(n==0){
    return 1;
  }

  return 1 + brojZnamenaka(n);
}



int brojParnihZnamenaka(int n){
  //printf("%d\n", n);

  if(n%2 == 0 && n!=0){
    return 1 + brojParnihZnamenaka(n/10);
  }
  if(n%2 != 0 && n!=0){
    return brojParnihZnamenaka(n/10);
  }

  if(n==0){
    return 0;
  }
  
}

int u_binarno(int n) 
{ 
    if(n==0){
      return 0;
    }  
    else{
      return (n%2 + 10* u_binarno(n/2)); 
    }
} 

int zbroj_znamenaka(int n){
  if(n==0){
    return 0;
  }

  return n%10 + zbroj_znamenaka(n/10);
}


int bin_u_dec(int n){
  if(n==0){
    return 0;
  }
  return n%2 + 2*bin_u_dec(n/10);
}