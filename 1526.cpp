#include <iostream>
#include <string>
using namespace std;

// mode: increase (true) or decrease (false) GMS
void computeGMS(string &GMS, int idx, bool mode) {
    char a, b;
    if (mode) {
        a = '4', b = '7';
    } else {
        a = '7', b = '4';
    }
    if (GMS[idx] == a) {
        GMS[idx] = b;
    } else if (GMS[idx] == b) {
        GMS[idx] = a;
        if (idx == 0) {
            if (mode) {
                GMS.push_back(a);
            } else {
                GMS.pop_back();
            }
        } else {
            computeGMS(GMS, idx - 1, mode);
        }
    }
}

int main() {
    string N, GMS;
    cin >> N;
    if (N.size() == 1) {
        GMS = "4";
    } else {
        GMS = string(N.size() - 1, '7');
    }
    while (GMS.size() < N.size() || (GMS.size() == N.size() && GMS < N)) {
        computeGMS(GMS, GMS.size() - 1, true);
    }
    if (GMS.size() > N.size() || (GMS.size() == N.size() && GMS > N)) {
        computeGMS(GMS, GMS.size() - 1, false);
    }
    cout << GMS;
    return 0;
}
