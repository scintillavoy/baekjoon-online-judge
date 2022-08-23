#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    string word;
    cin >> word;
    int arr[26] = {0};
    for (auto const &x : word) {
        ++arr[x - 'A'];
    }
    int cnt = 0;
    while (--N) {
        string word2;
        cin >> word2;
        int arr2[26] = {0};
        for (auto const &x : word2) {
            ++arr2[x - 'A'];
        }
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += abs(arr[i] - arr2[i]);
        }
        if (diff <= 1 || (diff == 2 && word.size() == word2.size())) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
