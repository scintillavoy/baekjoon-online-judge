#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--) {
        vector<int> vec;
        string str;
        getline(cin, str);
        istringstream iss(str);
        int num;
        while (iss >> num) {
            vec.push_back(num);
        }
        int maxGCD = 0;
        for (int i = 0; i < vec.size() - 1; ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                if (maxGCD < gcd(vec[i], vec[j])) {
                    maxGCD = gcd(vec[i], vec[j]);
                }
            }
        }
        cout << maxGCD << '\n';
    }
    return 0;
}
