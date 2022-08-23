#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string arr[5][5] = {{"***", "***", "***", "***", "***"},
                        {"*.*", "*.*", "*..", "*.*", "*.."},
                        {"***", "***", "*..", "*.*", "***"},
                        {"*.*", "*.*", "*..", "*.*", "*.."},
                        {"*.*", "***", "***", "***", "***"}};
    int N;
    cin >> N;
    vector<string> vec(5);
    while (N--) {
        char c;
        cin >> c;
        for (int i = 0; i < 5; ++i) {
            vec[i].append(arr[i][c-'A']);
        }
    }
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
