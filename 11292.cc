#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }

    vector<string> students;
    double max_height = 0;
    while (N--) {
      string student;
      double height;
      cin >> student >> height;
      if (height > max_height) {
        max_height = height;
        students = {student};
      } else if (height == max_height) {
        students.push_back(student);
      }
    }

    for (auto &x : students) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
