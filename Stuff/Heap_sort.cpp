#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &A, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(vector<int> &A) {
    int n = A.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]); 
        heapify(A, i, 0); 
    }
}

int main() {
    vector<int> A = {9, 7, 12, 8, 6, 5};
    for (int x : A) cout << x << " ";
    cout << endl;
    heapSort(A);
    for (int x : A) cout << x << " ";
    cout << endl;
    return 0;
}
