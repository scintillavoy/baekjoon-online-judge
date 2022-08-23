#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(const string &name, const int &korean, 
            const int &english, const int &math)
            : name(name), korean(korean), english(english), math(math) {}
    static bool compare(const Student &a, const Student &b);
    string name;
    int korean = 0;
    int english = 0;
    int math = 0;
};

bool Student::compare(const Student &a, const Student &b) {
    if (a.korean != b.korean) {
        return a.korean > b.korean;
    } else if (a.english != b.english) {
        return a.english < b.english;
    } else if (a.math != b.math) {
        return a.math > b.math;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int N;
    cin >> N;
    vector<Student> vec;
    for (int i = 0; i < N; ++i) {
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        vec.emplace_back(name, korean, english, math);
    }
    sort(vec.begin(), vec.end(), Student::compare);
    for (auto const &x : vec) {
        cout << x.name << '\n';
    }
    return 0;
}
