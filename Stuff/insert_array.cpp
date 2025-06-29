#include<iostream>
using namespace std;

void inputArray(int a[],int n){
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
}

void outputArray(int a[],int n){
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
}

void insertArray(int a[],int &n,int idx,int value){
    int pos = idx-1;
    for(int i = n-1;i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos] = value;
    n++;
}

int main(){
    int n;
    cin >> n;
    int a[100];
    inputArray(a,n);
    insertArray(a,n,2,10);
    outputArray(a,n);
}
