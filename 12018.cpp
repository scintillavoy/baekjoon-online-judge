#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nthMileage;
    for (int i = 0; i < n; ++i) {
        int P, L;
        cin >> P >> L;
        vector<int> mileage(P);
        for (auto &x : mileage) {
            cin >> x;
        }
        if (P < L) {
            nthMileage.push_back(1);
        } else {
            nth_element(mileage.begin(), mileage.begin() + L - 1,
                mileage.end(), greater<int>());
            nthMileage.push_back(mileage[L - 1]);
        }
    }
    sort(nthMileage.begin(), nthMileage.end());
    int answer;
    for (answer = 0; answer < nthMileage.size(); ++answer) {
        m -= nthMileage[answer];
        if (m < 0) {
            break;
        }
    }
    cout << answer;
    return 0;
}
