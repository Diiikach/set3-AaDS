#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

size_t DROPS = 2000000;

class circle {
private:
    double X, Y, R;
public:
    circle(double x, double y, double r) : X(x), Y(y), R(r) {};
    circle() {};

    int belongs(double x, double y) {
        if (pow(x - X, 2) + pow(y - Y, 2) <= R * R) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main() {
    #ifdef TEST
        cin >> DROPS;
    #endif
    vector<circle> circles(3);
    double maxiH = -100, maxiW = -100;
    double miniH = 100, miniW = 100;
    for (int i = 0; i < 3; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        circles[i] = circle{x, y, r};
        maxiH = max(maxiH, y + r);
        miniH = min(miniH, y - r);

        maxiW = max(maxiW, x + r);
        miniW = min(miniW, x - r);
    }
    uniform_real_distribution<> width(miniW, maxiW);
    uniform_real_distribution<> height(miniH, maxiH);
    double Srec = (maxiW - miniW) * (maxiH - miniH);
    size_t hits = 0;
    for (int _ = 0; _ < DROPS; _++) {
        double x = width(rng), y = height(rng);
        int c = 0;
        for (auto circle : circles) {
            c += (int) circle.belongs(x, y);
        }
        if (c == 3) {
            hits++;
        }
    }
    if (Srec == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout  << fixed << (double) hits / (double) DROPS * Srec << endl;
}