#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void countingSort(int A[], int n, int k) {
    int C[k + 1] = {0};
    for (int i = 0; i < n; i++) C[A[i]]++;
    int idx = 0;
    for (int i = 0; i <= k; i++)
        while (C[i]--)
            A[idx++] = i;
}

int main() {
    int A[] = {1, 4, 1, 2, 7, 5, 2};
    int n = 7;

    auto start = high_resolution_clock::now();
    countingSort(A, n, 9);
    auto end = high_resolution_clock::now();

    cout << "Counting Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
