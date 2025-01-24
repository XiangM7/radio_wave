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
        long long towerPos = a[i];
        long long leftRange = towerPos - d;
        long long rightRange = towerPos + d;

        // Lower bound: first city >= leftRange
        int leftIdx = int(lower_bound(a.begin(), a.end(), leftRange) - a.begin());
        // Upper bound: first city > rightRange
        int rightIdx = int(upper_bound(a.begin(), a.end(), rightRange) - a.begin());

        int coverage = rightIdx - leftIdx; // number of cities in [leftRange, rightRange]
        cout << coverage << "\n";
    }

    // -------------------------
    // Part 2: Maximum coverage (and a best center) in O(n)
    // -------------------------
    // We want the largest number of cities that fit inside an interval of length 2*d.
    // a[end] - a[start] <= 2*d. Move end and adjust start with a two-pointer technique.

    int maxCoverage = 0;

    int start = 0;
    for (int end = 0; end < n; ++end) {
        // Shrink from the left if the window is too large
        while (a[end] - a[start] > 2LL * d) {
            start++;
        }
        int coverage = end - start + 1;
        if (coverage > maxCoverage) {
            maxCoverage = coverage;
            // For all cities in [start..end], they fit inside an interval of length 2*d.
            // A valid center can be anywhere in [a[end]-d, a[start]+d].
            // We'll choose one possible center (for example, a[start] + d).
        }
    }

    // Print maximum coverage
    cout << maxCoverage << "\n";
    // If you need the actual center, you can also print bestCenter, e.g.:
    // cout << bestCenter << "\n";

    return 0;
}

