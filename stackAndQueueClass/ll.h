#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
node *prev;
int data;
node *next;
};

class ll{
int count = 0;
public:
node *head = NULL, *tail = NULL, *list = NULL;
void* addtail(int value);
void* delete_head();
void* delete_tail();
int remove_head();
int remove_tail();
int get_count();
int get_data(int count);
};