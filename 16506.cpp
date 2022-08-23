#include <iostream>
#include <bitset>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> codemap = {
        {"ADD",     0},
        {"ADDC",    1},
        {"SUB",     2},
        {"SUBC",    3},
        {"MOV",     4},
        {"MOVC",    5},
        {"AND",     6},
        {"ANDC",    7},
        {"OR",      8},
        {"ORC",     9},
        {"NOT",     10},
        // There is no 11
        {"MULT",    12},
        {"MULTC",   13},
        {"LSFTL",   14},
        {"LSFTLC",  15},
        {"LSFTR",   16},
        {"LSFTRC",  17},
        {"ASFTR",   18},
        {"ASFTRC",  19},
        {"RL",      20},
        {"RLC",     21},
        {"RR",      22},
        {"RRC",     23},
    };
    int N;
    cin >> N;
    while (N--) {
        string opcode;
        int op1, op2, op3;
        cin >> opcode >> op1 >> op2 >> op3;
        bitset<16> bs;
        bs |= codemap[opcode] << 11;
        bs |= op1 << 7;
        bs |= op2 << 4;
        bs |= op3 * (bs[11] ? 1 : 2);
        cout << bs << '\n';
    }
    return 0;
}
