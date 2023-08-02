//implementation of stack?

#include <iostream>

using namespace std;

// Define the stack data structure.
struct Stack {
  int data;
  Stack *next;
};

// Create a new stack.
Stack *createStack() {
  Stack *newStack = new Stack;
  newStack->data = 0;
  newStack->next = NULL;

  return newStack;
}

// Push an item onto the stack.
void push(Stack *stack, int item) {
  Stack *newNode = new Stack;
  newNode->data = item;
  newNode->next = stack->next;

  stack->next = newNode;
}

// Pop an item off the stack.
int pop(Stack *stack) {
  int item = stack->next->data;
  Stack *temp = stack->next;

  stack->next = stack->next->next;

  delete temp;

  return item;
}

// Check if the stack is empty.
bool isEmpty(Stack *stack) {
  if (stack->next == NULL) {
    return true;
  } else {
    return false;
  }
}

// Print the contents of the stack.
void printStack(Stack *stack) {
  Stack *current = stack->next;

  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }

  cout << endl;
}

int main() {
  // Create a new stack.
  Stack *stack = createStack();

  // Push some items onto the stack.
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  // Print the contents of the stack.
  printStack(stack);

  // Pop an item off the stack.
  int item = pop(stack);

  // Print the item that was popped.
  cout << "The item that was popped is: " << item << endl;

  // Check if the stack is empty.
  if (isEmpty(stack)){
    cout<<"satck is empty";
  }
  else{
    cout<<"Stack is not empty";
  }

}