#include <iostream>
using namespace std;

int Sum(int A[], int N) {
    if (N == 1)
        return A[0];

    int localSum = Sum(A, N - 1);

    return localSum + A[N - 1];
}

int main() {
    int A[] = {1, 2, 3, 4};
    int N = 4;
    cout << "Sum: " << Sum(A, N) << endl;
    return 0;
}
