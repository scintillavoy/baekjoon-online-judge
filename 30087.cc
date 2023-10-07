#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<string, string> seminars{
      {"Algorithm", "204"},
      {"DataAnalysis", "207"},
      {"ArtificialIntelligence", "302"},
      {"CyberSecurity", "B101"},
      {"Network", "303"},
      {"Startup", "501"},
      {"TestStrategy", "105"},
  };
  while (N--) {
    string seminar;
    cin >> seminar;
    cout << seminars[seminar] << '\n';
  }
  return 0;
}
