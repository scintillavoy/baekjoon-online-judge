#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        int price_max = 0;
        string name_max;
        for (int j = 0; j < p; ++j) {
            int price;
            string name;
            cin >> price >> name;
            if (price > price_max) {
                price_max = price;
                name_max = name;
            }
        }
        cout << name_max << '\n';
    }
    return 0;
}
