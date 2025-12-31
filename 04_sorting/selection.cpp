#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min])
                min = j;
        swap(A[i], A[min]);
    }
}

int main() {
    int A[] = {5, 3, 8, 4, 2};
    int n = 5;

    auto start = high_resolution_clock::now();
    selectionSort(A, n);
    auto end = high_resolution_clock::now();

    cout << "Selection Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;
    return 0;
}
