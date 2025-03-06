#include <iostream>
#include "stack.h"
using namespace std;


int main()
{
  Stack<int> s;
  s.push(3);
  s.push(5);
  s.push(8);
  s.push(9);

  cout << "stack elements are: " << endl;

  while(!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}