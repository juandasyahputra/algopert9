#include <iostream>
using namespace std;

const int MAX = 10;
char q[MAX];
int frontIndex = 0;
int rearIndex = -1;
int countData = 0;

bool isQueueEmpty() {
    return countData == 0;
}

bool isQueueFull() {
    return countData == MAX;
}

void insertChar(char c) {
    if (isQueueFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    rearIndex = (rearIndex + 1) % MAX;
    q[rearIndex] = c;
    countData++;
}

void removeChar() {
    if (isQueueEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Menghapus: " << q[frontIndex] << endl;
    frontIndex = (frontIndex + 1) % MAX;
    countData--;
}

void tampil() {
    if (isQueueEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    
    cout << "Isi Queue: ";
    int idx = frontIndex;
    for (int i = 0; i < countData; i++) {
        cout << q[idx] << " ";
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

int main() {
    // Isi queue
    insertChar('A');
    insertChar('R');
    insertChar('I');
    insertChar('F');

    cout << "Setelah insert A R I F:\n";
    tampil();

    // Hapus 2
    removeChar();
    removeChar();

    cout << "Setelah remove 2 kali:\n";
    tampil();

    return 0;
}
