//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::cout;
using std::endl;

// Turn loops off for the duration of this file.
// You are to use recursion for any repetition.
// Make sure to do any other includes before these defines.
#define for DONOTUSETHIS
#define while DONOTUSETHIS
#define goto DONOTUSETHIS

/**
 * @brief List node for AddressLinkedList
 */
template<class T>
struct StackNode {
  T data;
  StackNode* next;

  StackNode();
  StackNode(const T& value);
};

/**
 * @brief Stack based on a linked list
 */
template<class T>
class Stack {
private:
  StackNode<T>* top;

public:
  /**
   * @brief Construct empty stack
   */
  Stack();

  /**
   * @brief Copy constructor
   *
   * Implement if you need it, otherwise not required
   * Declared to prevent default shallow copy
   */
  Stack(const Stack<T>& other);

  /**
   * @brief Assignment Operator
   *
   * Implement if you need it, otherwise not required
   * Declared to prevent default shallow copy
   */
  Stack<T>& operator=(const Stack<T>& other);

  /**
   * @brief Destructor
   */
  ~Stack();

  /**
   * @brief Check if stack is empty
   * @return true if nothing in stack, false otherwise
   */
  bool isEmpty() const;

  /**
   * @brief Add item to stack
   * @param value Item to push a copy of onto the stack
   */
  void push(const T& item);

  /**
   * @brief Remove and return top item from stack
   * @return Item that was at the top of the stack
   * Can throw exception/blow up with assertion if currently empty
   */
  T pop();

  T popAll();

  /**
   * @brief Return a copy of the top item on the stack (without removing it)
   * @return Item that is at the top of the stack
   */
  T peek() const;

  /**
   * @brief Output the stack in order to cout
   */
  void print() const;

  void printHelper(const StackNode<T>* node) const;

  /**
   * @brief Output the stack in reverse order to cout
   */
  void reversePrint() const;

  void reversePrintHelper(const StackNode<T>* node) const;
};

//--------------------------------------------------------------------
// StackNode implementations
//--------------------------------------------------------------------

template<class T>
StackNode<T>::StackNode()
{
  next = nullptr;
  data = T(); // data will be default initialized
}

template<class T>
StackNode<T>::StackNode(const T& value): data(value)
{
  next = nullptr;
  // data = T(value);
}

//--------------------------------------------------------------------
// Stack Implementations
//--------------------------------------------------------------------

template<class T>
Stack<T>::Stack()
{
  top = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
  delete top;
  // if (top->next == nullptr) {
  //   delete top;
  // } else {
  //   delete pop();
  // }

  return;
}

template<class T>
bool Stack<T>::isEmpty() const
{
  return top == nullptr;
}

template<class T>
void Stack<T>::push(const T& item)
{
  StackNode<T>* input = new StackNode<T>(item);
  input->next = top;
  top = input;
}

template<class T>
T Stack<T>::pop()
{
  if (top == nullptr) {
    throw;
  } else {
    T temp = top->data;
    StackNode<T>* deleted = top;
    top = top->next;
    delete deleted;
    return temp;
  }
}

template<class T>
T Stack<T>::popAll()
{
  if (top == nullptr) {
    throw;
  } else {
    T temp = top->data;
    StackNode<T>* deleted = top;
    top = top->next;
    delete deleted;
    return temp;
  }
}

template<class T>
T Stack<T>::peek() const
{
  return top->data;
}

template<class T>
void Stack<T>::print() const
{
  printHelper(top);
  // cout << endl << endl;
  return;
}

template<class T>
void Stack<T>::printHelper(const StackNode<T>* node) const
{
  if (node == nullptr) {
    return;
  }
  cout << (node->data) << " ";
  printHelper(node->next);
  return;
}

template<class T>
void Stack<T>::reversePrint() const
{
  reversePrintHelper(top);
  // cout << endl << endl;
  return;
}

template<class T>
void Stack<T>::reversePrintHelper(const StackNode<T>* node) const
{
  if (node == nullptr) {
    return;
  }
  reversePrintHelper(node->next);
  cout << (node->data) << " ";
  if (node == nullptr) {
    return;
  }
}

//--------------------------------------------------------------------
// All your code before here
//--------------------------------------------------------------------
// Turn loops back on.
// Otherwise whatever file includes this will not be able to use them.
#undef for
#undef while
#undef goto

#endif // STACK_H
