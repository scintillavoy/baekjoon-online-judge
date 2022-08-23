#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    // input
    int N, K;
    cin >> N >> K;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> vec;
    string str;
    getline(cin, str);

    // compute
    for (string::size_type from = 0, to = str.find(',');;
        from = to + 1, to = str.find(',', from)) {
        vec.push_back(stoi(str.substr(from, to - from)));
        if (to == string::npos) {
            break;
        }
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < vec.size() - 1; ++j) {
            vec[j] = vec[j + 1] - vec[j];
        }
        vec.pop_back();
    }

    // output
    cout << vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        cout << ',' << vec[i];
    }
    return 0;
}
