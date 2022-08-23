#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string convert(int input) {
    static string arr[10] = {"zero", "one", "two", "three", "four",
                             "five", "six", "seven", "eight", "nine"};
    string inputStr = to_string(input), output;
    for (auto const &x : inputStr) {
        output.push_back(' ');
        output.append(arr[x - '0']);
    }
    return output;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec;
    for (int i = N; i <= M; ++i) {
        vec.push_back(i);
    }
    sort(vec.begin(), vec.end(), [](const int &a, const int &b) {
        return convert(a) < convert(b);
    });
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ' ';
        if ((i + 1) % 10 == 0) {
            cout << '\n';
        }
    }
    return 0;
}
