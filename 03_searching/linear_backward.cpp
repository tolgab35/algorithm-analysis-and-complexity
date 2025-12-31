#include <iostream>
using namespace std;

int linearSearchBackward(int A[], int N, int key) {
    int i = N - 1;

    while (i >= 0) {
        if (A[i] == key)
            return i;
        i--;
    }

    return -1;
}

int main() {
    int A[] = {9, 4, 10, 1, 20, 12, 3};
    int N = 7;

    cout << linearSearchBackward(A, N, 12) << endl;
    cout << linearSearchBackward(A, N, 77) << endl;
    return 0;
}
