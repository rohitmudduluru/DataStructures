#include "ll.h"

void* ll::addtail(int value)
{
  if (head == NULL)
  {
    list = (node*) malloc(sizeof(node));
    memset(list,0,sizeof(*list));
    head = list;
  }
  else {
    list = tail;
    list = list -> next;
    list = (node*) malloc(sizeof(node));
    memset(list,0,sizeof(*list));
    tail -> next = list;
    list->prev = tail;
  }
  list->data = value;
  tail = list;
  list = head;
  count++;
  return list;
}

void* ll::delete_head()
{
  if (get_count() == 0){}
  else if (get_count() == 1)
  {
    head = NULL;
    list = NULL;
    tail = NULL;
  }
  node* next = head -> next;
  next -> prev = NULL;
  free(head);
  head = next;
  count--;
  return head;
}
void* ll::delete_tail()
{
  if (get_count() == 0){}
  else if (get_count() == 1)
  {
    head = NULL;
    list = NULL;
    tail = NULL;
  }
  node* prev = tail -> prev;
  prev->next = NULL;
  free(tail);
  tail = prev;
  count--;
  return tail;
}

int ll::remove_head()
{
  if (get_count() == 0) return -1;
  int data = head->data;
  if (get_count() == 1)
  {
    head = NULL;
    list = NULL;
    tail = NULL;
    return data;
  }
  else{
  node* next = head -> next;
  next -> prev = NULL;
  head = next;
  count--;
  return data;
  }
}

int ll::remove_tail()
{
  if (get_count() == 0) return -1;
  int data = tail->data;
  if (get_count() == 1)
  {
    head = NULL;
    list = NULL;
    tail = NULL;
    return data;
  }
  else{
  node* prev = tail ->prev;
  prev->next = NULL;
  tail = prev;
  count--;
  return data;
  }
}

int ll::get_count()
{
  return count;
}

int ll::get_data(int c)
{
  node* cur = head;
  if(c > count)
    return 0;
  else{
  for(int i = 0;i < c-1; i++)
    {
      cur = cur->next;
    }
  return cur->data;
  }
}

