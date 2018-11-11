#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int Partition(vector<int>& collection, int l, int r) {
    int m = (r + l) / 2;
    swap(collection[m], collection[r]);
    int a = collection[r];
    int last = r;
    r -= 1;
    while (l <= r) {
        while (l < last && collection[l] <= a) {
            l += 1;
        }
        while (collection[r] > a) {
            r -= 1;
        }
        if (l >= r) {
            break;
        }
        swap(collection[l], collection[r]);
    }
    swap(collection[l], collection[last]);
    return l;
}

// Function for finding k-ordered element
// Passing vector by value to evade changing the original one
int FindKOrder(vector<int> collection, int k) {
    int l = 0;
    int r = collection.size() - 1;
    while (l <= r) {
        int index = Partition(collection, l, r);    
        if (index == k) {
            return collection[index];
        } else if (k < index) {
            r = index - 1;
        } else {
            l = index + 1;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    assert(n != 0);
    int k;
    cin >> k;
    vector<int> collection(n);
    for (size_t i = 0; i < n; i++) {
        cin >> collection[i];
    }    
    int answer = FindKOrder(collection, k);
    cout << answer << endl;
    return 0;
}



