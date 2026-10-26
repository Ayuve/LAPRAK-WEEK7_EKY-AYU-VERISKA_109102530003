#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX;
}

// mengembalikan false (tanpa mengubah stack) jika stack penuh
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

// mengembalikan false (tanpa mengubah stack) jika stack kosong
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

// menampilkan isi stack mulai dari TOP
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

// membalik isi stack dengan satu stack bantu (hanya lewat push dan pop).
// Semua elemen di-pop dari S lalu di-push ke stack bantu, sehingga
// stack bantu berisi urutan terbalik. Stack bantu kemudian menjadi isi S.
void balikStack(Stack &S) {
    Stack bantu;
    createStack(bantu);
    int x;
    while (!isEmpty(S)) {
        pop(S, x);
        push(bantu, x);
    }
    S = bantu;
}
