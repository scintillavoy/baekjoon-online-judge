#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    unordered_set<int> s;
    int N;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        s.insert(num);
    }

    int M;
    cin >> M;
    while (M--) {
        int num;
        cin >> num;
        cout << (s.count(num) ? 1 : 0) << ' ';
    }
    return 0;
}
