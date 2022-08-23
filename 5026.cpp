#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        if (str == "P=NP") {
            cout << "skipped\n";
        } else {
            auto pos = str.find('+');
            cout << stoi(str.substr(0, pos)) + stoi(str.substr(pos+1)) << '\n';
        }
    }
    return 0;
}
