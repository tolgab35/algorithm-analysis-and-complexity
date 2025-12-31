#include <iostream>
using namespace std;

void TOH(int n, char src, char target, char aux) {
    if (n == 0)
        return;

    TOH(n - 1, src, aux, target);
    cout << "Move disk " << n << " from " << src << " to " << target << endl;
    TOH(n - 1, aux, target, src);
}

int main() {
    TOH(3, 'A', 'C', 'B');
    return 0;
}
