#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> deq(N);
    for (int i = 0; i < N; ++i) {
        deq[i] = i + 1;
    }
    while (deq.size() > 1) {
        cout << deq.front() << ' ';
        deq.pop_front();
        deq.push_back(deq.front());
        deq.pop_front();
    }
    cout << deq.front();
    return 0;
}
