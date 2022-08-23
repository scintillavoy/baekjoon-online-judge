#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> D(N);
    for (auto &x : D) {
        cin >> x;
    }
    sort(D.begin(), D.end());
    
    int price = A, calorie = C;
    while ((double) calorie / price < (double) D.back() / B) {
        price += B;
        calorie += D.back();
        D.pop_back();
    }

    cout << calorie / price;
    return 0;
}
