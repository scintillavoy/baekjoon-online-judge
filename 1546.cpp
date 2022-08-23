#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, in;
    vector<int> score;
    cin >> n;
    for (; n > 0; --n) {
        cin >> in;
        score.push_back(in);
    }

    int max = *max_element(score.begin(), score.end());
    double average = 0;
    for (auto const &x : score) {
        average += (double) x / max * 100;
    }
    average /= score.size();
    cout.precision(4);
    cout.setf(ios::showpoint);
    cout << average;

    return 0;
}
