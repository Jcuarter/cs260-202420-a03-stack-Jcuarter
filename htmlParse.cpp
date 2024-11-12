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

int checkToken(string token)
{
  if (token == "</html>") {
    return 0; // Ending
  } else if ((token.substr(0, 2) == "</")
             and token.substr((token.size() - 1)) == ">") {
    return 1; // Close Tag
  } else if ((token.substr(0, 1) == "<")) {
    return 2; // Open Tag
  } else {
    return 3; // Text, Unused, but I feel I should add it.
  }
}

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
  Stack<string> tags;
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }
  string token;
  while (inFile.is_open()) {
    inFile >> token;

    if (checkToken(token) == 0) { // Ending Token, so stop.
      tags.pop();
      break;
    } else if (checkToken(token) == 1) { // Closing Tag.
      if (tags.peek().substr(1) != token.substr(2)) {
        cout << "ERROR: BAD ENDING TAG." << endl;
        cout << token << " DOES NOT CLOSE " << tags.peek();
        // Error Only Shows Up While Popping, So can be late(?).
        // Idk, I think it's fine honestly.
        break;
      }
      tags.pop();
    } else if (checkToken(token) == 2) { // Open Tag.
      tags.push(token);
    } else { // Word.
      tags.reversePrint();
      cout << token << endl;
    }
  }
  if (tags.isEmpty()) {
    cout << "ERROR: OPEN TAG LEFTOVER." << endl;
    cout << tags.peek() << " WAS NOT CLOSED." << endl;
  }

  delete &tags;
  cout << "END PROGRAM.";
}
