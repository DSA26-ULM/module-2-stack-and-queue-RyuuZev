#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    // Membaca n dan k [cite: 60, 63]
    if (!(cin >> n >> k)) return 0;

    int A[MAX];
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Membaca elemen array 
    }

    Queue q;
    init(&q);

    int current_sum = 0;

    // 1. Hitung jendela pertama (k elemen pertama) 
    for (int i = 0; i < k; i++) {
        enqueue(&q, A[i]);
        current_sum += A[i];
    }
    cout << current_sum;

    // 2. Geser jendela ke kanan [cite: 48, 49]
    for (int i = k; i < n; i++) {
        // Keluarkan yang paling depan, masukkan yang baru 
        int keluar = front(&q);
        dequeue(&q);
        
        enqueue(&q, A[i]);
        current_sum = current_sum - keluar + A[i];

        // Cetak dengan spasi sesuai format 
        cout << " " << current_sum;
    }

    cout << endl;
    return 0;
}