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

    vector<int> a(n);
    
    // Reading city positions
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the city positions to apply binary search
    sort(a.begin(), a.end());

    // First part: Efficiently count cities covered by a tower at each city position
    for (int i = 0; i < n; ++i) {
        // Using binary search to find the range of cities covered by the tower
        int left = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
        int right = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin();
        
        int count = right - left; // Number of cities within range
        cout << count << "\n";
    }

    // Second part: Find the tower position with maximum coverage using sliding window
    int maxCoverage = 0;
    int bestCenter = 0;

    // Sliding window approach: for each city, calculate the number of cities within the range of d
    int i = 0; // Left pointer for the sliding window
    for (int center = a[0] - d; center <= a[n-1] + d; ++center) {
        // Move the left pointer to maintain the valid window range
        while (i < n && a[i] < center - d) {
            i++;
        }

        // Count how many cities are within the range [center - d, center + d]
        int count = 0;
        for (int j = i; j < n && a[j] <= center + d; ++j) {
            count++;
        }

        // Update maximum coverage and best center
        if (count > maxCoverage) {
            maxCoverage = count;
            bestCenter = center;
        }
    }

    cout << maxCoverage << "\n";

    return 0;
}

