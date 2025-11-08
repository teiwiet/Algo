#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = newNode->prev = nullptr;
    return newNode;
}

// Thêm node vào đầu danh sách
void insertHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
        return;
    }
    Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

// Thêm node vào cuối danh sách
void insertTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
        return;
    }
    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// Thêm node vào vị trí bất kỳ (1-based)
void insertAt(Node*& head, int pos, int value) {
    if (!head || pos <= 1) {
        insertHead(head, value);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == head) {
        insertTail(head, value);
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Xóa node tại vị trí bất kỳ (1-based)
void deleteAt(Node*& head, int pos) {
    if (!head) return;
    Node* temp = head;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    if (pos == 1) {
        Node* tail = head->prev;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete temp;
        return;
    }

    int count = 1;
    while (temp->next != head && count < pos) {
        temp = temp->next;
        count++;
    }

    if (count < pos) return; 
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Tìm node tại vị trí bất kỳ
Node* findAt(Node* head, int pos) {
    if (!head) return nullptr;
    Node* temp = head;
    int count = 1;
    do {
        if (count == pos) return temp;
        temp = temp->next;
        count++;
    } while (temp != head);
    return nullptr;
}

// Sửa đổi thông tin của node tại vị trí pos
void updateAt(Node* head, int pos, int newValue) {
    Node* temp = findAt(head, pos);
    if (temp) temp->data = newValue;
}

// Hiển thị danh sách
void display(Node* head) {
    if (!head) {
        cout << "Danh sach rong.\n";
        return;
    }
    Node* temp = head;
    cout << "Danh sach: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Sắp xếp danh sách tăng dần
void sortList(Node* head) {
    if (!head) return;
    Node* i = head;
    do {
        Node* j = i->next;
        while (j != head) {
            if (i->data > j->data)
                swap(i->data, j->data);
            j = j->next;
        }
        i = i->next;
    } while (i->next != head);
}

int main() {
    Node* head = nullptr;

    insertTail(head, 10);
    insertTail(head, 30);
    insertTail(head, 50);
    insertHead(head, 5);
    insertAt(head, 3, 20);

    cout << "Sau khi chen cac node:\n";
    display(head);

    deleteAt(head, 2);
    cout << "Sau khi xoa node thu 2:\n";
    display(head);

    updateAt(head, 3, 100);
    cout << "Sau khi sua node thu 3:\n";
    display(head);

    sortList(head);
    cout << "Sau khi sap xep tang dan:\n";
    display(head);
    return 0;
}
