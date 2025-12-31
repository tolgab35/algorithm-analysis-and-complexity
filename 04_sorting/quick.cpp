#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    quickSort(A, 0, n - 1);
    auto end = high_resolution_clock::now();

    cout << "Quick Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
