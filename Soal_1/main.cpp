#include "stack.h"

int main()
{
    Stack S;
    createStack(S);

    int pilihan;
    do {
        cout << endl;
        cout << "===== MENU STACK =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -1;
        }

        if (pilihan == 1) {
            int x;
            cout << "Masukkan bilangan: ";
            if (!(cin >> x)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Input bukan bilangan bulat" << endl;
            } else if (push(S, x)) {
                cout << x << " berhasil di-push" << endl;
            } else {
                cout << "Stack penuh, push ditolak" << endl;
            }
        } else if (pilihan == 2) {
            int x;
            if (pop(S, x)) {
                cout << "Nilai yang di-pop: " << x << endl;
            } else {
                cout << "Stack kosong, pop ditolak" << endl;
            }
        } else if (pilihan == 3) {
            printInfo(S);
        } else if (pilihan == 4) {
            if (isEmpty(S)) {
                cout << "Stack kosong, tidak ada yang dibalik" << endl;
            } else {
                balikStack(S);
                cout << "Stack berhasil dibalik" << endl;
                printInfo(S);
            }
        } else if (pilihan == 0) {
            cout << "Program selesai" << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
