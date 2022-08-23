#include <iostream>
#include <random>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec(45);
    iota(vec.begin(), vec.end(), 1);
    random_device rd;
    mt19937 gen(rd());
    shuffle(vec.begin(), vec.end(), gen);
    for (int i = 0; i < 6; ++i) {
        cout << vec[i] << ' ';
    }
    return 0;
}
