#include "PQ.h"

int main() {
  PQ p;

  //printf("%d", p.getVal(0));
  time_t t;
  srand((unsigned) time(&t));
  for(int i = 0 ; i < 100; i++ ) {
    p.insert(rand() % 100);
  }
  
  p.print();
  printf("%d\n", p.remove());
  /*for(int i = 0; i < 100; i++){
    printf("%d is it in order: %d\n", p.remove(), p.checkTree());
    if(p.checkTree() == false)
    {
      printf("Tree is not in correct order\n");
      break;
    }
  }*/
  /*p.print();
  printf("%d\n", p.size());
  printf("%d\n", p.checkTree());
  printf("%d\n", p.getParent(14));
  printf("%d\n", p.getVal(6)<p.getVal(14));*/
}