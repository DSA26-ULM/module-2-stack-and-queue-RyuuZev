#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int A[MAX];
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    Queue q;
    init(&q);

    int current_sum = 0;

    for (int i = 0; i < k; i++) {
        enqueue(&q, A[i]);
        current_sum += A[i];
    }
    cout << current_sum;

    for (int i = k; i < n; i++) {
        int keluar = front(&q);
        dequeue(&q);
        
        enqueue(&q, A[i]);
        current_sum = current_sum - keluar + A[i];

        cout << " " << current_sum;
    }

    cout << endl;
    return 0;
}