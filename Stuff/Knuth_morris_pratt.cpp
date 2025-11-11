#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PreKmp(const string &X, vector<int> &kmpNext) {
    int m = X.size();
    kmpNext.assign(m, 0);

    int len = 0;  
    int i = 1;
    while (i < m) {
        if (X[i] == X[len]) {
            len++;
            kmpNext[i] = len;
            i++;
        } else {
            if (len != 0)
                len = kmpNext[len - 1];
            else {
                kmpNext[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPsearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> kmpNext;
    vector<int> positions;

    PreKmp(pattern, kmpNext);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                positions.push_back(i - j);
                j = kmpNext[j - 1];
            }
        } else {
            if (j != 0)
                j = kmpNext[j - 1];
            else
                i++;
        }
    }
    return positions;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    vector<int> pos = KMPsearch(text, pattern);
    cout << "Vi tri xuat hien cua pattern trong text: ";
    for (int p : pos)
        cout << p << " ";
    cout << endl;
    return 0;
}
