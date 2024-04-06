#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Node{
Node* prev;
char c;
int freq;
Node* left;
Node* right;
};

class PQ{
  int n = 0;
  int *arr;
  void increaseSpace();
  int maxSize = 100;
  public:
  PQ();
  PQ(const int userSize ,int arr[]);
  int size();
  int getChild(int n, bool l);
  int getParent(int n);
  int getVal(int index);
  int totalRows();
  int getRow(int index);
  void insert(int val);
  int remove();
  bool checkTree();
  void print();
};