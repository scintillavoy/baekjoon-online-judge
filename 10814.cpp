#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<vector<string>> vec(200);
    int N;
    cin >> N;
    while (N--) {
        int age;
        string name;
        cin >> age >> name;
        vec[age-1].push_back(name);
    }
    for (int i = 0; i < vec.size(); ++i) {
        for (auto const &x : vec[i]) {
            cout << i + 1 << ' ' << x << '\n';
        }
    }
    return 0;
}
