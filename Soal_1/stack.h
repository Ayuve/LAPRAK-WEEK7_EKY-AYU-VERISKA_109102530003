#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

#define MAX 20

// Stack array: data disimpan pada indeks 1..20
// Top = 0 -> kosong, Top = 20 -> penuh
struct Stack {
    int info[MAX + 1];
    int Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif // STACK_H_INCLUDED
