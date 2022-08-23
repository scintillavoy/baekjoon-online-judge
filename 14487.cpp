#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, maxCost = 0;
    while (n--) {
        int cost;
        cin >> cost;
        sum += cost;
        if (maxCost < cost) {
            maxCost = cost;
        }
    }
    sum -= maxCost;
    cout << sum;
    return 0;
}
