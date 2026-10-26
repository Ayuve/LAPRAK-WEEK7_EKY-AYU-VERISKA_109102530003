#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// menambahkan elemen pada TOP
void push(Stack &S, int x) {
    address P = alokasi(x);
    P->next = S.Top;
    S.Top = P;
}

// mengambil nilai TOP lalu melepas node-nya.
// Jika kosong, mengembalikan false dan stack tidak berubah
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    address P = S.Top;
    x = P->info;
    S.Top = P->next;
    P->next = nullptr;
    dealokasi(P);
    return true;
}

// menampilkan isi stack mulai dari TOP
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "TOP: ";
    address P = S.Top;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// menyisipkan x sehingga urutan menaik dari bawah ke TOP (terbesar di TOP).
// Elemen yang lebih besar dari x dipindah sementara ke stack bantu
// (lewat pop dan push), x di-push, lalu elemen tadi dikembalikan.
// Nilai yang sama dengan x tetap di bawah x sehingga duplikat tersimpan
// sebagai elemen terpisah.
void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);
    int temp;

    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(bantu, temp);
    }
    push(S, x);
    while (!isEmpty(bantu)) {
        pop(bantu, temp);
        push(S, temp);
    }
}

// melepas seluruh node sehingga Top kembali nullptr
void clearStack(Stack &S) {
    int x;
    while (!isEmpty(S)) {
        pop(S, x);
    }
}
