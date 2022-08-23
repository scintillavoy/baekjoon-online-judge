#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Color {
public:
    Color(const string &name, const int &R, const int &G, const int &B)
        : name(name), R(R), G(G), B(B) {}
    string name;
    int R, G, B;
};

int main() {
    Color webColor[16] = {{"White", 255, 255, 255},
                          {"Silver", 192, 192, 192},
                          {"Gray", 128, 128, 128},
                          {"Black", 0, 0, 0},
                          {"Red", 255, 0, 0},
                          {"Maroon", 128, 0, 0},
                          {"Yellow", 255, 255, 0},
                          {"Olive", 128, 128, 0},
                          {"Lime", 0, 255, 0},
                          {"Green", 0, 128, 0},
                          {"Aqua", 0, 255, 255},
                          {"Teal", 0, 128, 128},
                          {"Blue", 0, 0, 255},
                          {"Navy", 0, 0, 128},
                          {"Fuchsia", 255, 0, 255},
                          {"Purple", 128, 0, 128}};
    int r, g, b;
    while (cin >> r >> g >> b) {
        if (r == -1 && g == -1 && b == -1) {
            break;
        }
        string closestColor;
        int minDist = numeric_limits<int>::max();
        for (auto const &x : webColor) {
            int dist = (x.R-r)*(x.R-r) + (x.G-g)*(x.G-g) + (x.B-b)*(x.B-b);
            if (minDist > dist) {
                minDist = dist;
                closestColor = x.name;
            }
        }
        cout << closestColor << '\n';
    }
    return 0;
}
