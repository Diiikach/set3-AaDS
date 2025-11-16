#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

struct fraq {
    unsigned num;
    unsigned denom;

    bool operator<(const fraq& other) const {
        unsigned l = denom * other.denom;
        return num * (l/denom) < other.num * (l/other.denom);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<fraq> fraqs(n);
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        int pos = cur.find('/');
        unsigned firstNum = 0, secondNum = 0;
        for (int p = 0; p < pos; p++) {
            firstNum *= 10;
            firstNum += cur[p] - '0';
        }
        for (int p = pos + 1; p < cur.size(); p++) {
            secondNum *= 10;
            secondNum += cur[p] - '0';
        }
        fraqs[i] = {firstNum, secondNum};
    }
    stable_sort(fraqs.begin(), fraqs.end());
    for (auto[a, b] : fraqs) {
        cout << a << '/' << b << ' ';
    }
    cout << endl;
}