#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> price(n);
        for (auto &x : price) {
            cin >> x;
        }
        sort(price.begin(), price.end(), greater<int>());
        int discount = 0;
        for (int i = 2; i < price.size(); i += 3) {
            discount += price[i];
        }
        cout << discount << '\n';
    }
    return 0;
}
