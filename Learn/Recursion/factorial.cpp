#include<iostream>
using namespace std;
int factorialPrint(int n){
    if(n==0){
        return 1;
    }
    return n*factorialPrint(n-1);
}

int main(){
    factorialPrint(4);
}
