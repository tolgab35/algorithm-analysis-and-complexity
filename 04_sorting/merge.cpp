#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void merge(int A[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = A[l + i];
    for (int j = 0; j < n2; j++) R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        A[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    mergeSort(A, 0, n - 1);
    auto end = high_resolution_clock::now();

    cout << "Merge Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
