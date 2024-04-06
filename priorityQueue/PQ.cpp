#include "PQ.h"

PQ::PQ()
{
  arr = (int*)malloc(sizeof(int)*maxSize);
}

PQ::PQ(int userSize, int *userArr)
{
  arr = (int*)malloc(sizeof(int)*maxSize);
  for(int i = 0; i < userSize; i++)
    {
      insert(userArr[i]);
    }
}

int PQ::size()
{
  return n;
}

int PQ::getChild(int parent, bool right)
{
  int child;
  if(!right)
    child = parent*2 + 1;
  else
    child = parent*2 + 2;
  if(child >= n)
  {
    //printf("\nChild Requested out of Range\n");
    return -1;
  }
  return child;
}

int PQ::getParent(int child)
{
  if(child <= 0)
  {
    //printf("\nIndex Requested out of Range\n");
    return -1;
  }
  return (child-1)/2;
}

int PQ::getVal(int index)
{
  if(index >= n)
  {
    //printf("\nIndex Requested out of Range\n");
    return -1;
  }
  return arr[index];
}

int PQ::totalRows()
{
  int ct = 0;
  for(int i = 1; i <= n; ct++)
      i *= 2;
  return ct-1;
}

int PQ::getRow(int index)
{
  int ct = 0;
  for(int i = 1; i <= index; ct++)
      i *= 2;
  return ct-1;
}

void PQ::increaseSpace()
{
  int *temp;
  maxSize *= 2;
  temp = (int*)realloc(arr, sizeof(int)*maxSize);
  arr = temp;
}

void PQ::insert(int val)
{
  bool keepSwapping = true;
  int curr = n;
  if(n == maxSize)
  {
    increaseSpace();
  }
  arr[curr] = val;
  while(keepSwapping)
    {
      if(arr[getParent(curr)] <= arr[curr] || getParent(curr) < 0)
      {
        keepSwapping = false;
      }
      else if(arr[curr] < arr[getParent(curr)])
      {
        int temp = arr[curr];
        arr[curr] = arr[getParent(curr)];
        arr[getParent(curr)] = temp;
        curr = getParent(curr);
      }
    }
  n++;
}

int PQ::remove()
{
  int ret = arr[0];
  if(n == 0)
  {
    return -1;
    //printf( "\nPriority queue has no more elements to delete\n");
    
  }
  else{
  int index = 0;
  int temp = arr[index];
  bool keepSwapping = true;
  arr[index] = arr[n-1];
  arr[n-1] = temp;
  n--;
  while(keepSwapping)
    {
      if(getChild(index, 0) == -1 || getChild(index, 1) == -1)
      {
        if(getChild(index, 0) > -1)
        {
          if(arr[index] > arr[getChild(index, false)])
          {
            temp = arr[index];
            arr[index] = arr[getChild(index, false)];
            arr[getChild(index, false)] = temp;
            index = getChild(index, false);
          }
        }
        keepSwapping = false;
      }
      
      if(arr[index] > arr[getChild(index, false)] && arr[index] > arr[getChild(index, true)])
      {
        bool whichSwap;
        
        if(arr[getChild(index, 0)] < arr[getChild(index, 1)])
          whichSwap = 0;
        else
          whichSwap = 1;
        
        temp = arr[index];
        arr[index] = arr[getChild(index, whichSwap)];
        arr[getChild(index, whichSwap)] = temp;
        index = getChild(index, whichSwap);
      }
        
      else if(arr[index] > arr[getChild(index, false)])
      {
        temp = arr[index];
        arr[index] = arr[getChild(index, false)];
        arr[getChild(index, false)] = temp;
        index = getChild(index, false);
      }

      else if(arr[index] > arr[getChild(index, true)])
      {
        temp = arr[index];
        arr[index] = arr[getChild(index, true)];
        arr[getChild(index, true)] = temp;
        index = getChild(index, true);
      }

      else
        keepSwapping = false;
    }
  }
  return ret;
}

void PQ::print()
  {
    for(int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
    printf("\n");
    if(checkTree())
    {
      printf("Tree is in correct order\n");
    }
    else
      printf("Tree is not in correct order\n");
  }
bool PQ::checkTree()
{
  for(int i = 1; i < n; i++)
    {
      if(arr[i] < arr[getParent(i)])
        return false;
    }
  return true;
}
