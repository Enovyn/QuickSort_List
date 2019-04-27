#ifndef LIST.H
#define LIST.H

#include <iostream>

class liste{
private:
int value;
liste* next;

public:
liste(int nmbr){
  value = nmbr;
  next = NULL;
}

liste(int nmbr, liste* n){
  value = nmbr;
  next = n;
}

int giveValue(){
  return value;
}

liste* giveNext(){
  return next;
}

void setNext(liste* n){
  next = n;
}

void printValue(){
  printf("%d ", value);
  if(next != NULL){
      next->printValue();
  }
}
};

#endif
