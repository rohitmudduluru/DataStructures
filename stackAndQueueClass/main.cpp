#include "stack_queue.h"
int main(){
  stack it1;
  queue it2;
  for(int i = 0; i < 1000; i++)
    it1.push(i);
  for(int i = 1; i < 1001; i++)
    printf("%d ", it1.getData(i));
  for(int i = 0; i < 1000; i++)
    printf("%d ", it1.pop());
  for(int i = 0; i < 1000; i++)
    it2.enq(i);
  for(int i = 1; i < 1001; i++)
    printf("%d ", it2.getData(i));
  for(int i = 0; i < 1000; i++)
    printf("%d ", it2.deq());
  
}