#include <iostream>
using namespace std;

const int MAX = 5;
int q[MAX];
int front = 0, rear = 0, countData = 0;

bool isFull() {
    return countData == MAX;
}

bool isEmpty() {
    return countData == 0;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    q[rear] = data;
    rear = (rear + 1) % MAX;
    countData++;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Menghapus: " << q[front] << endl;
    front = (front + 1) % MAX;
    countData--;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Isi Circular Queue: ";
    int idx = front;
    for (int i = 0; i < countData; i++) {
        cout << q[idx] << " ";
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

int main() {
    // isi sampai penuh
    for (int i = 1; i <= 5; i++) enqueue(i);

    // hapus 3
    dequeue();
    dequeue();
    dequeue();

    // isi 2 data baru
    enqueue(99);
    enqueue(100);

    cout << "Front di index: " << front << endl;
    cout << "Rear di index: " << rear << endl;

    display();

    return 0;
}
