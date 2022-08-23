#include <iostream>
#include <bitset>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    bitset<33554432> check;
    int num;
    while (cin >> num) {
        if (!check[num]) {
            check.set(num);
            cout << num << ' ';
        }
    }
    return 0;
}
