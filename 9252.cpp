#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printLCS(const vector<vector<int>> &b, const string &X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 1) {
        printLCS(b, X, i-1, j-1);
        cout << X[i-1];
    } else if (b[i][j] == 2) {
        printLCS(b, X, i-1, j);
    } else {
        printLCS(b, X, i, j-1);
    }
}

int main() {
    string X, Y;
    cin >> X >> Y;
    vector<vector<int>> c(X.size() + 1, vector<int>(Y.size() + 1)), b(c);
    for (int i = 1; i <= X.size(); ++i) {
        for (int j = 1; j <= Y.size(); ++j) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }

    cout << c[X.size()][Y.size()] << '\n';
    printLCS(b, X, X.size(), Y.size());
    return 0;
}
