#include <iostream>
using namespace std;

extern int H[];
extern int N;

int findMin();
void insertHeap(int key);
int deleteMin();
void buildHeap();
void decreaseKey(int pos, int delta);
void increaseKey(int pos, int delta);
void deleteKey(int pos);
void mergeHeaps(int H2[], int size2);

int main() {
    insertHeap(10);
    insertHeap(4);
    insertHeap(15);
    insertHeap(20);
    insertHeap(0);

    cout << "Minimum element: " << findMin() << endl;

    deleteMin();
    cout << "Minimum after deleteMin: " << findMin() << endl;

    decreaseKey(3, 10);
    cout << "Minimum after decreaseKey: " << findMin() << endl;

    increaseKey(2, 5);
    cout << "Minimum after increaseKey: " << findMin() << endl;

    deleteKey(2);
    cout << "Minimum after deleteKey: " << findMin() << endl;

    int H2[] = {0, 7, 3, 9};
    mergeHeaps(H2, 3);

    cout << "Minimum after merge: " << findMin() << endl;

    return 0;
}
