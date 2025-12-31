#include <vector>
#include <algorithm>
using namespace std;

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(const vector<int>& a, int left, int mid, int right) {
    int sum = 0, leftSum = 0;
    for (int i = mid; i >= left; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubSum3(const vector<int>& a, int left, int right) {
    if (left == right)
        return max(0, a[left]);

    int mid = (left + right) / 2;

    return max3(
        maxSubSum3(a, left, mid),
        maxSubSum3(a, mid + 1, right),
        maxCrossingSum(a, left, mid, right)
    );
}
