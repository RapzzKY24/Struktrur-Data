#ifndef STACK_H
#define STACK_H

const int NMAX = 20;

struct Stack
{
   int data[NMAX];
   int top;
};

void createStack(Stack* s);
void push(Stack* s,int x);
int pop(Stack* s);
void printInfo(const Stack s);
void balikStack(Stack* s);
void pushAscending(Stack *s, int x);
void getInputStream(Stack* s);


#endif