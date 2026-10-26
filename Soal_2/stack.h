#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Node *address;

struct Node {
    int info;
    address next;
};

// Stack hanya menyimpan pointer Top. Kosong jika Top = nullptr
struct Stack {
    address Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
address alokasi(int x);
void dealokasi(address &P);
void push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif // STACK_H_INCLUDED
