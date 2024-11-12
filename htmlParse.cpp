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

  ifstream inFile("Document.html");
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }
  string token;
  while (inFile.is_open()) {
    inFile >> token;
    if (token == "</html>") { // Ending Token, so stop.
      break;
    } else if (token.substr(2) == "</") {
      cout << token << " " << endl;
    } else if (token.substr(1) == "<") {
      cout << token << " " << endl;
    } else {
      cout << token << " ";
    }
  }

  cout << "END PROGRAM.";
}
