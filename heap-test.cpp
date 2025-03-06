#include <iostream>
#include <string>
#include "heap.h"
using namespace std;

int main()
{
  Heap<int> minHeap; // uses default Comparator std::less<int>
  minHeap.push(5);
  minHeap.push(1);
  minHeap.push(3);
  minHeap.push(4);
  minHeap.push(2);

  cout << "minHeap in ascending order: " << endl;
  while(!minHeap.empty())
  {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }
  cout << endl;

  // create a maxHeap
  Heap<int, greater<int>> maxHeap;
  maxHeap.push(5);
  maxHeap.push(1);
  maxHeap.push(3);
  maxHeap.push(4);
  maxHeap.push(2);

  cout << "maxHeap in ascending order: " << endl;
  while(!maxHeap.empty())
  {
    cout << maxHeap.top() << " ";
    maxHeap.pop();
  }
  cout << endl;

  // test heap with strings
  Heap<string> stringHeap;
  stringHeap.push("cherry");
  stringHeap.push("dragonfruit");
  stringHeap.push("banana");
  stringHeap.push("apple");
  stringHeap.push("eggplant");

  cout << "stringHeap in alphabetical order" << endl;
  while(!stringHeap.empty())
  {
    cout << stringHeap.top() << endl;
    stringHeap.pop();
  }
  cout << endl;
  
  return 0;
}