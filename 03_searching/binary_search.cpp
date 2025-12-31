#include <iostream>
using namespace std;

int BinarySearch(int A[], int N, int key) {
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (A[middle] == key)
            return middle;
        else if (key < A[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}

int main() {
    int A[] = {3, 8, 10, 11, 20, 50, 55, 60, 65, 70};
    int N = 10;

    cout << BinarySearch(A, N, 55) << endl;
    cout << BinarySearch(A, N, 77) << endl;
    return 0;
}
