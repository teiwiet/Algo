#include <iostream>
#include <vector>
using namespace std;

struct MyStack {
  int cap;
  int top;
  int *arr;

  MyStack(int c) {
    cap = c;
    arr = new int[cap];
    top = -1;
  }

  void push(int x) {
    top++;
    arr[top] = x;
  }

  int pop() {
    int res = arr[top];
    top--;
    return res;
  }

  int peek() { 
      return arr[top]; 
  }

  int size() { 
      return top + 1; 
  }

  bool isEmpty() {
      return top == -1; 
  }
};

struct MyStack2 {
    vector<int> v;

    void push(int x) {
      v.push_back(x); 
  }

    int size(){
        return v.size();
    }

    int peek(){
        return v.back();
    }
};

int main() {
  MyStack st1(5);
  cout << st1.size() << endl;
}
