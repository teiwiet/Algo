#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

// Khởi tạo hàng đợi
void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

// Kiểm tra rỗng
bool isEmpty(Queue q) {
    return q.rear < q.front;
}

// Kiểm tra đầy
bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

// Thêm phần tử
void enqueue(Queue &q, int x) {
    if (isFull(q))
        cout << "Hang doi day!\n";
    else
        q.data[++q.rear] = x;
}

// Xóa phần tử
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!\n";
        return -1;
    }
    return q.data[q.front++];
}

// Xem phần tử đầu
int front(Queue q) {
    if (isEmpty(q)) return -1;
    return q.data[q.front];
}

int main() {
    Queue q;
    init(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    cout << "Phan tu dau: " << front(q) << endl;
    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Phan tu dau moi: " << front(q) << endl;
    return 0;
}
