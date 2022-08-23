#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int happy = 0, sad = 0;
    for (int i = 0; (i = str.find(":-)", i)) != string::npos; ++happy, ++i);
    for (int i = 0; (i = str.find(":-(", i)) != string::npos; ++sad, ++i);
    if (happy == 0 && sad == 0) {
        cout << "none";
    } else if (happy > sad) {
        cout << "happy";
    } else if (happy < sad) {
        cout << "sad";
    } else {
        cout << "unsure";
    }
    return 0;
}
