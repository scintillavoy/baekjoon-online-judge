#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    string B1, B2;
    cin >> B1 >> B2;
    bitset<60> product(stoull(B1, 0, 2) * stoull(B2, 0, 2));
    int idx;
    for (idx = 59; idx >= 0 && !product[idx]; --idx);
    if (idx < 0) {
        cout << 0;
    } else {
        for (int i = idx; i >= 0; --i) {
            cout << product[i];
        }
    }
    cout << '\n';
    return 0;
}
