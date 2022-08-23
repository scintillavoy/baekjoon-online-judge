#include <cstdio>
#include <vector>
using namespace std;

bool checkParity(vector<int> &vec) {
    bool parity = false;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > vec.size()) {
            continue;
        }
        bool cycle = false;
        for (int j = vec[i] - 1; i != j; j = vec[j] - 1 - vec.size()) {
            cycle = !cycle;
            vec[j] += vec.size();
        }
        vec[i] += vec.size();
        if (cycle) {
            parity = !parity;
        }
    }
    return parity;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A(n), B(n);
    for (auto &x : A) {
        scanf("%d", &x);
    }
    for (auto &x : B) {
        scanf("%d", &x);
    }
    printf("%sossible\n", checkParity(A) == checkParity(B) ? "P" : "Imp");
    return 0;
}
