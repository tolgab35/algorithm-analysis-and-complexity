#include <iostream>
using namespace std;

double Power(double a, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    return a * Power(a, n - 1);
}

int main() {
    double x = Power(3, 4);
    cout << "Power: " << x << endl;
    return 0;
}
