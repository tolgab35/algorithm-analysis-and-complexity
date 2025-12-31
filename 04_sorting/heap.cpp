#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void heapify(int A[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    heapSort(A, n);
    auto end = high_resolution_clock::now();

    cout << "Heap Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
