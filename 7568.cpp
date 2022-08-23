#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > vec;
    for (int i = 0; i < N; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        vec.push_back(p);
    }
    for (auto const &x : vec) {
        int rank = 1;
        for (auto const &y : vec) {
            if (x.first < y.first && x.second < y.second) {
                ++rank;
            }
        }
        cout << rank << ' ';
    }
    return 0;
}
