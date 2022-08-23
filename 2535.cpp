#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    static bool compare(const Student &a, const Student &b);
    int countryNum;
    int studentNum;
    int score;
};

bool Student::compare(const Student &a, const Student &b) {
    return a.score > b.score;
}

int main() {
    int N;
    cin >> N;
    vector<Student> vec(N);
    for (auto &x : vec) {
        cin >> x.countryNum >> x.studentNum >> x.score;
    }
    sort(vec.begin(), vec.end(), Student::compare);
    cout << vec[0].countryNum << ' ' << vec[0].studentNum << '\n';
    cout << vec[1].countryNum << ' ' << vec[1].studentNum << '\n';
    int idx = 2;
    while (vec[0].countryNum == vec[1].countryNum
            && vec[0].countryNum == vec[idx].countryNum) {
        ++idx;
    }
    cout << vec[idx].countryNum << ' ' << vec[idx].studentNum << '\n';
    return 0;
}
