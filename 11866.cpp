#include <iostream>
#include <list>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    list<int> li;
    for (int i = 1; i <= N; ++i) {
        li.push_back(i);
    }

    auto it = li.begin();
    for (int i = 0; i < M - 1; ++i) {
        ++it;
        if (it == li.end()) {
            it = li.begin();
        }
    }
    cout << '<' << *it;
    it = li.erase(it);
    if (it == li.end()) {
        it = li.begin();
    }

    while (!li.empty()) {
        for (int i = 0; i < M - 1; ++i) {
            ++it;
            if (it == li.end()) {
                it = li.begin();
            }
        }
        cout << ", " << *it;
        it = li.erase(it);
        if (it == li.end()) {
            it = li.begin();
        }
    }
    cout << '>';
    return 0;
}
