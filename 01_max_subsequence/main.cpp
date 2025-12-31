#include <iostream>
#include <vector>
#include "../common/timer.h"
#include "../common/utils.h"

using namespace std;

int maxSubSum1(const vector<int>&);
int maxSubSum2(const vector<int>&);
int maxSubSum3(const vector<int>&, int, int);
int maxSubSum4(const vector<int>&);

int main() {
    vector<int> data = generateArray(2000);

    Timer t1;
    cout << "O(n^3): " << maxSubSum1(data)
         << " | Time: " << t1.elapsedMilliseconds() << " ms\n";

    Timer t2;
    cout << "O(n^2): " << maxSubSum2(data)
         << " | Time: " << t2.elapsedMilliseconds() << " ms\n";

    Timer t3;
    cout << "O(n log n): " << maxSubSum3(data, 0, data.size() - 1)
         << " | Time: " << t3.elapsedMilliseconds() << " ms\n";

    Timer t4;
    cout << "O(n): " << maxSubSum4(data)
         << " | Time: " << t4.elapsedMilliseconds() << " ms\n";

    return 0;
}
