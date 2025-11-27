#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void init() {
    front = rear = -1;
}

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (rear == MAX - 1);
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    q[rear] = data;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Menghapus: " << q[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Isi Queue: ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main() {
    int pilih, nilai;
    init();

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Tampilkan\n4. Keluar\nPilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(nilai);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while (pilih != 4);

    return 0;
}
