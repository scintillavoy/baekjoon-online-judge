#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> file(N);
    for (auto &x : file) {
        cin >> x;
    }
    int cluster;
    cin >> cluster;
    long long disk = 0;
    for (auto const &x : file) {
        disk += (x + cluster - 1) / cluster * cluster;
    }
    cout << disk;
    return 0;
}
