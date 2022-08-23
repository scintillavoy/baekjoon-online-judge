#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int X;
    cin >> X;
    vector<int> vec = {64};
    while (accumulate(vec.cbegin(), vec.cend(), 0) > X) {
        int back = vec.back();
        vec.pop_back();
        vec.push_back(back / 2);
        if (accumulate(vec.cbegin(), vec.cend(), 0) < X) {
            vec.push_back(back / 2);
        }
    }
    cout << vec.size();
    return 0;
}
