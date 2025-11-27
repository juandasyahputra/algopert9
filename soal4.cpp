#include <iostream>
using namespace std;

struct Pelanggan {
    int nomor;
    int waktu;
};

const int MAX = 20;
Pelanggan q[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int nomor, int waktu) {
    if (isFull()) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear++;

    q[rear].nomor = nomor;
    q[rear].waktu = waktu;

    cout << "Pelanggan " << nomor << " masuk antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Tidak ada pelanggan.\n";
        return;
    }
    cout << "Melayani pelanggan " << q[front].nomor
         << " (" << q[front].waktu << " detik)\n";

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void tampil() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\nPelanggan menunggu:\n";
    for (int i = front; i <= rear; i++)
        cout << "- No." << q[i].nomor << " (" << q[i].waktu << " detik)\n";
}

int jumlah() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

int main() {
    int pilih, nomor = 1, waktu;

    do {
        cout << "\n=== MENU KASIR ===\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Layani pelanggan\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Jumlah pelanggan\n";
        cout << "5. Keluar\nPilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan waktu pelayanan: ";
                cin >> waktu;
                enqueue(nomor++, waktu);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampil();
                break;
            case 4:
                cout << "Jumlah pelanggan: " << jumlah() << endl;
                break;
        }
    } while (pilih != 5);

    return 0;
}
