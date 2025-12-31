#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    insertionSort(A, n);
    auto end = high_resolution_clock::now();

    cout << "Insertion Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
