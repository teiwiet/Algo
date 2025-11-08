#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node *front, *rear;
};

// Khởi tạo hàng đợi
void init(Queue &q) { 
    q.front = q.rear = nullptr; 
}

// Kiểm tra rỗng
bool isEmpty(Queue q) { 
    return q.front == nullptr; 
}

// Thêm phần tử vào cuối hàng đợi
void enqueue(Queue &q, int x) {
    Node* p = new Node{x, nullptr};
    if (isEmpty(q))
        q.front = q.rear = p;
    else {
        q.rear->next = p;
        q.rear = p;
    }
}

// Lấy phần tử đầu hàng đợi
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!\n";
        return -1;
    }
    Node* p = q.front;
    int x = p->data;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete p;
    return x;
}

// Trả về phần tử đầu hàng đợi 
int front(Queue q) {
    if (isEmpty(q)) return -1;
    return q.front->data;
}

int main() {
    Queue q;
    init(q);
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    cout << "Phan tu dau: " << front(q) << endl;
    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Phan tu dau moi: " << front(q) << endl;
    return 0;
}
