#include <iostream>
using namespace std;

struct avl_node {
    int data;
    avl_node* left;
    avl_node* right;
};

class avlTree {
public:
    avl_node* root;

    avlTree() { root = NULL; }

    // trả lại độ cao của cây avl
    int height(avl_node* node) {
        if (node == NULL) return 0;
        int hL = height(node->left);
        int hR = height(node->right);
        return (hL > hR ? hL : hR) + 1;
    }

    // trả lại chỉ số cân bằng của cây avl
    int diff(avl_node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    // thao tác quay phải phải
    avl_node* rr_rotation(avl_node* parent) {
        avl_node* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }

    // thao tác quay trái trái
    avl_node* ll_rotation(avl_node* parent) {
        avl_node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    // thao tác quay trái phải
    avl_node* lr_rotation(avl_node* parent) {
        avl_node* temp = parent->left;
        parent->left = rr_rotation(temp);
        return ll_rotation(parent);
    }

    // thao tác quay phải trái
    avl_node* rl_rotation(avl_node* parent) {
        avl_node* temp = parent->right;
        parent->right = ll_rotation(temp);
        return rr_rotation(parent);
    }

    // cân bằng lại cây
    avl_node* balance(avl_node* node) {
        int b = diff(node);
        if (b > 1) {
            if (diff(node->left) > 0)
                node = ll_rotation(node);
            else
                node = lr_rotation(node);
        } else if (b < -1) {
            if (diff(node->right) < 0)
                node = rr_rotation(node);
            else
                node = rl_rotation(node);
        }
        return node;
    }

    // thêm node vào cây avl
    avl_node* insert(avl_node* root, int value) {
        if (root == NULL) {
            root = new avl_node;
            root->data = value;
            root->left = root->right = NULL;
            return root;
        }
        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        return balance(root);
    }

    // thao tác hiển thị cây
    void display(avl_node* ptr, int level) {
        if (ptr == NULL) return;
        display(ptr->right, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << ptr->data << endl;
        display(ptr->left, level + 1);
    }

    // duyệt giữa
    void inorder(avl_node* tree) {
        if (tree == NULL) return;
        inorder(tree->left);
        cout << tree->data << " ";
        inorder(tree->right);
    }

    // duyệt trước
    void preorder(avl_node* tree) {
        if (tree == NULL) return;
        cout << tree->data << " ";
        preorder(tree->left);
        preorder(tree->right);
    }

    // duyệt sau
    void postorder(avl_node* tree) {
        if (tree == NULL) return;
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << " ";
    }
};

int main() {
    avlTree tree;
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 35);
    tree.root = tree.insert(tree.root, 50);

    tree.display(tree.root, 0);
}
