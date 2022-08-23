#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;
    vector<vector<int>> c(X.size() + 1, vector<int>(Y.size() + 1));
    for (int i = 1; i <= X.size(); ++i) {
        for (int j = 1; j <= Y.size(); ++j) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
            } else {
                c[i][j] = c[i][j-1];
            }
        }
    }

    cout << c[X.size()][Y.size()] << '\n';
    return 0;
}
