#include <iostream>
using namespace std;

int linearSearchForward(int A[], int N, int key) {
    int i = 0;

    while (i < N) {
        if (A[i] == key)
            break;
        i++;
    }

    if (i < N)
        return i;
    else
        return -1;
}

int main() {
    int A[] = {9, 4, 10, 1, 20, 12, 3};
    int N = 7;

    cout << linearSearchForward(A, N, 12) << endl;
    cout << linearSearchForward(A, N, 77) << endl;
    return 0;
}
