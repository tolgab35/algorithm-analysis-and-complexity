#include <iostream>
using namespace std;

const int MAXN = 100;
int H[MAXN];
int N = 0;

int findMin() {
    if (N == 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return H[1];
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= N && H[left] < H[smallest])
        smallest = left;
    if (right <= N && H[right] < H[smallest])
        smallest = right;

    if (smallest != i) {
        swap(H[i], H[smallest]);
        heapify(smallest);
    }
}

void insertHeap(int key) {
    if (N >= MAXN - 1) {
        cout << "Heap overflow!" << endl;
        return;
    }

    N++;
    int i = N;
    H[i] = key;

    while (i > 1 && H[i / 2] > H[i]) {
        swap(H[i], H[i / 2]);
        i = i / 2;
    }
}

int deleteMin() {
    if (N == 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int minVal = H[1];
    H[1] = H[N];
    N--;
    heapify(1);
    return minVal;
}

void buildHeap() {
    for (int i = N / 2; i >= 1; i--)
        heapify(i);
}

void decreaseKey(int pos, int delta) {
    H[pos] -= delta;
    while (pos > 1 && H[pos / 2] > H[pos]) {
        swap(H[pos], H[pos / 2]);
        pos /= 2;
    }
}

void increaseKey(int pos, int delta) {
    H[pos] += delta;
    heapify(pos);
}

void deleteKey(int pos) {
    H[pos] = H[N];
    N--;
    heapify(pos);
}

void mergeHeaps(int H2[], int size2) {
    for (int i = 1; i <= size2; i++) {
        H[++N] = H2[i];
    }
    buildHeap();
}
