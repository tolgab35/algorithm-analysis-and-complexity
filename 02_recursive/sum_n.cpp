#include <iostream>
using namespace std;

int Sum(int n) {
    if (n == 1)
        return 1;

    int partialSum = Sum(n - 1);

    return partialSum + n;
}

int main() {
    int x = 0;
    x = Sum(4);
    cout << "Sum: " << x << endl;
    return 0;
}
