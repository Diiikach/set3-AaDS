#include <iostream>
#include <vector>

using namespace std;

int left(int i ) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void heapify(vector<int>& A, int i) {
    // аналог шифта вниз
    while (2 * i + 1 < A.size()) {
        int l = left(i);
        int r = right(i);
        int u = (r < A.size() && A[r] > A[l] ? r : l);
        if (A[u] < A[i]) {
            break;
        }
        swap(A[u], A[i]);
        i = u;
    }
}

int parent(int i) {
    if (i == 0) {
        return 0;
    } else {
        return (i - 1) / 2;
    }
}

void heapifyUp(vector<int>& A, int i) {
    while (i > 0 && A[i] > A[parent(i)]) {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

vector<int> buildMaxHeap(vector<int>& A) {
    vector<int> H = A;
    for (int i = 1; i < A.size(); i++) {
        heapifyUp(H, i);
    }
    return H;
}

void removeTop(vector<int>& H) {
    if (H.size() == 0) {
        cout << "Error, empty heap" << endl;
        exit(-1);
    }
    swap(H[H.size() - 1], H[0]);
    H.pop_back();
    heapify(H, 0);
}

int getTop(vector<int>& H) {
    if (H.size() == 0) {
        cout << "Error, empty heap" << endl;
        exit(-1);
    }
    return H[0];
}

void heapSort(vector<int>& A) {
    vector<int> H = buildMaxHeap(A);
    for (int i = A.size() - 1; i >= 0; i--) {
        A[i] = getTop(H);
        removeTop(H);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    heapSort(A);
    for (auto el : A) {
        cout << el << ' ';
    }
    cout << endl;
}