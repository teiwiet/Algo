
#include <iostream>
using namespace std;

#define MAX 100

struct PriorityQueue {
    int data[MAX];
    int size;
};

// Khởi tạo hàng đợi ưu tiên
void init(PriorityQueue &pq) { 
    pq.size = 0; 
}

// Kiểm tra rỗng
bool isEmpty(PriorityQueue pq) { 
    return pq.size == 0; 
}

// Kiểm tra đầy
bool isFull(PriorityQueue pq) { 
    return pq.size == MAX; 
}

// Thêm phần tử và sắp xếp theo độ ưu tiên (bé hơn -> ưu tiên hơn)
void enqueue(PriorityQueue &pq, int x) {
    if (isFull(pq)) {
        cout << "Hang doi uu tien day!\n";
        return;
    }
    int i = pq.size - 1;
    while (i >= 0 && pq.data[i] > x) {
        pq.data[i + 1] = pq.data[i];
        i--;
    }
    pq.data[i + 1] = x;
    pq.size++;
}

// Lấy phần tử có ưu tiên cao nhất
int dequeue(PriorityQueue &pq) {
    if (isEmpty(pq)) {
        cout << "Hang doi uu tien rong!\n";
        return -1;
    }
    return pq.data[--pq.size];
}

// Xem phần tử có ưu tiên cao nhất
int front(PriorityQueue pq) {
    if (isEmpty(pq)) return -1;
    return pq.data[pq.size - 1];
}

int main() {
    PriorityQueue pq;
    init(pq);
    enqueue(pq, 30);
    enqueue(pq, 10);
    enqueue(pq, 20);
    cout << "Phan tu uu tien cao nhat: " << front(pq) << endl;
    cout << "Lay ra: " << dequeue(pq) << endl;
    cout << "Phan tu uu tien cao moi: " << front(pq) << endl;
    return 0;
}
