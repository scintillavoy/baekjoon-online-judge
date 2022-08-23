#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X;
    cin >> X;
    cout << (next_permutation(X.begin(), X.end()) ? X : "0");
    return 0;
}
