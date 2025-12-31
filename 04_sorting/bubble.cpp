#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    bubbleSort(A, n);
    auto end = high_resolution_clock::now();

    cout << "Bubble Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
