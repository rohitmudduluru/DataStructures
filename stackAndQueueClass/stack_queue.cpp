#include "stack_queue.h"

void stack::push(int n) { stlist.addtail(n); }
int stack::pop() { return stlist.remove_tail(); }
int stack::getCount() { return stlist.get_count(); }
int stack::getData(int n) { return stlist.get_data(n); }

void queue::enq(int n) { qulist.addtail(n); }
int queue::deq() { return qulist.remove_head(); }
int queue::getCount() { return qulist.get_count(); }
int queue::getData(int n) { return qulist.get_data(n); }