#include <iostream>
using namespace std;

int digitSum(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return digitSum(sum);
}

int main() {
    int x = digitSum(9875);
    cout << "Digit Sum: " << x << endl;
    return 0;
}
