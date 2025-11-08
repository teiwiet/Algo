#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string X;
        cin >> X;
        int n = X.size();
        int i = n - 1;
        while (i >= 0 && X[i] == '1') {
            X[i] = '0';
            i--;
        }
        if (i >= 0) X[i] = '1'; 
        cout << X << '\n';
    }
    return 0;
}

