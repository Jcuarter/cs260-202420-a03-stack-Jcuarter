//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>

#include "Stack.h"

using namespace std;

int main()
{
  ifstream inFile("Document.html");
  string taco;
  while (inFile.is_open()) {
    if (!inFile.is_open()) {
      cout << "Error opening file" << endl;
      return 1;
    } else {
      inFile >> taco;
      cout << taco;
    }
  }

  cout << "-----------------------Section 1----------------------" << endl;
  Stack<int> test;
  cout << "Empty?: " << test.isEmpty() << endl;
  test.push(6);
  cout << test.peek() << endl;
  test.push(3);
  cout << test.peek() << endl;
  test.push(163);
  cout << test.peek() << endl;
  test.pop();
  cout << test.peek() << endl;
  cout << "Empty?: " << test.isEmpty() << endl;
  for (int i = 0; i < 50; i++) {
    test.push(rand());
  }
  cout << endl << "Normal Direction: " << endl;
  test.print();
  cout << "Reverse Direction: " << endl;
  test.reversePrint();

  cout << "-----------------------Section 2----------------------" << endl;

  // test;

  cout << "END PROGRAM.";
}
