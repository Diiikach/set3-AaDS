#include <iostream>
#include <vector>
#include <random>
#include <bitset>
#include <chrono>


using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

vector<char> getRandomVector(int n) {
    vector<char> result(n);
    for (int i = 0; i < n; i++) {
        char vals[] = {0, 1};
        result[i] = vals[rng() % 2];
    }
    return result;
}

vector<char> mulMatrixVector(vector<vector<char>>& M, vector<char>& r) {
    int n = M.size();
    vector<char> result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += M[i][j] * r[j];
            result[i] %= 2;
        }
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> A(n, vector<char> (n)), B(A), C(A);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ceil((double) n / 4); j++) {
            char num;
            cin >> num;
            if (isdigit(num)) {
                num -= '0';
            } else {
                num -= 'A';
                num += 10;
            }
            bitset<4> representation(num);
            for (int p = 0; p < 4 && p + j * 4 < n; p++) {
                A[i][p + j * 4] = representation[3 - p];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ceil((double) n / 4); j++) {
            char num;
            cin >> num;
            if (isdigit(num)) {
                num -= '0';
            } else {
                num -= 'A';
                num += 10;
            }
            bitset<4> representation(num);
            for (int p = 0; p < 4 && p + j * 4 < n; p++) {
                B[i][p + j * 4] = representation[3 - p];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ceil((double) n / 4); j++) {
            char num;
            cin >> num;
            if (isdigit(num)) {
                num -= '0';
            } else {
                num -= 'A';
                num += 10;
            }
            bitset<4> representation(num);
            for (int p = 0; p < 4 && p + j * 4 < n; p++) {
                C[i][p + j * 4] = representation[3 - p];
            }
        }
    }
    for (int k = 0; k < 10; k++) {
        vector<char> v = getRandomVector(n);
        auto f = mulMatrixVector(B, v);
        if (mulMatrixVector(A,  f) == mulMatrixVector(C, v)) {
            continue;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;   
}