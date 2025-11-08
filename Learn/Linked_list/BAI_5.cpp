#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

//Tạo node mới
Node* createNode(int value) {
    Node* p = new Node{value, nullptr};
    return p;
}

//Thêm node vào đầu danh sách
void insertHead(Node*& head, int value) {
    Node* p = createNode(value);
    p->next = head;
    head = p;
}

//Thêm node sau node có giá trị key
void insertAfter(Node* head, int key, int value) {
    Node* cur = head;
    while (cur) {
        if (cur->data == key) {
            Node* p = createNode(value);
            p->next = cur->next;
            cur->next = p;
            return;
        }
        cur = cur->next;
    }
}

//Xóa node theo giá trị key
void deleteNode(Node*& head, int key) {
    if (!head) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = head;
    Node* cur = head->next;
    while (cur) {
        if (cur->data == key) {
            prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

//Tìm node theo giá trị
Node* search(Node* head, int key) {
    Node* cur = head;
    while (cur) {
        if (cur->data == key)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

//Sửa giá trị của node
void updateNode(Node* head, int oldValue, int newValue) {
    Node* n = search(head, oldValue);
    if (n) n->data = newValue;
}

//Sắp xếp danh sách tăng dần (bubble sort)
void sortList(Node* head) {
    if (!head) return;
    for (Node* i = head; i->next; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->data > j->data)
                swap(i->data, j->data);
        }
    }
}

//Hiển thị danh sách
void display(Node* head) {
    if (!head) {
        cout << "Danh sach rong\n";
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;

    insertHead(head, 10);
    insertHead(head, 20);
    insertHead(head, 30);

    insertAfter(head, 20, 15);
    updateNode(head, 15, 25);
    sortList(head);
    deleteNode(head, 20);

    display(head);

    return 0;
}
