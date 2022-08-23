#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string in, out;
    cin >> in;
    for (int i = in.size() - 3; i >= 0; i -= 3) {
        out.push_back(4*(in[i]-'0') + 2*(in[i+1]-'0') + in[i+2]);
    }
    if (in.size() % 3 == 1) {
        out.push_back(in[0]);
    } else if (in.size() % 3 == 2) {
        out.push_back(2*(in[0]-'0') + in[1]);
    }
    reverse(out.begin(), out.end());
    cout << out;
    return 0;
}
