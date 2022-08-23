#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> A, B;
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int num, cnt = sizeA + sizeB;
    while (sizeA--) {
        cin >> num;
        A.insert(num);
    }
    while (sizeB--) {
        cin >> num;
        B.insert(num);
    }

    for (auto const &x : A) {
        if (B.count(x)) {
            cnt -= 2;
        }
    }
    cout << cnt;
    return 0;
}
