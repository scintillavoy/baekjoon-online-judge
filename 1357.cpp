#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    string result = to_string(stoi(X) + stoi(Y));
    reverse(result.begin(), result.end());
    cout << stoi(result);
    return 0;
}
