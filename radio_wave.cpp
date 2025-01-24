#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1) Sort the city positions
    sort(a.begin(), a.end());

    // -------------------------
    // Part 1: Coverage for each city in O(n log n)
    // -------------------------
    for (int i = 0; i < n; ++i) {
        long long tower = a[i];
        long long left = tower - d;
        long long right = tower + d;

        // Lower bound: first city >= left
        int leftIdx = int(lower_bound(a.begin(), a.end(), left) - a.begin());
        // Upper bound: first city > right
        int rightIdx = int(upper_bound(a.begin(), a.end(), right) - a.begin());

        int coverage = rightIdx - leftIdx; // number of cities in [left, right]
        cout << coverage << "\n";
    }

    // -------------------------
    // Part 2: Maximum coverage (and a best center) in O(n)
    // -------------------------
    // We want the largest number of cities that fit inside an interval of length 2*d.
    

    int maxCoverage = 0;

    int i = 0;
    for (int j = 0; end < n; ++j) {
        // Shrink from the left if the window is too large
        while (a[j] - a[i] > 2LL * d) {
            i++;
        }
        int coverage = j - i + 1;
        if (coverage > maxCoverage) {
            maxCoverage = coverage;
        }
    }

    // Print maximum coverage
    cout << maxCoverage << "\n";
   

    return 0;
}

