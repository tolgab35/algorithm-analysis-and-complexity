#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int getMax(int A[], int n) {
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx) mx = A[i];
    return mx;
}

void countSort(int A[], int n, int exp) {
    int output[n], count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

void radixSort(int A[], int n) {
    int m = getMax(A, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, n, exp);
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    auto start = high_resolution_clock::now();
    radixSort(A, n);
    auto end = high_resolution_clock::now();

    cout << "Radix Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
