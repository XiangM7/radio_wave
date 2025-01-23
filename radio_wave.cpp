#include <iostream>
using namespace std;

int a[(int)1e5 + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;
    
    // Reading city positions
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Calculate the number of cities covered by a tower at each city position
    for (int i = 0; i < n; ++i) {
        int count = 0;
        
        // Count how many cities are covered by a tower placed at a[i]
        for (int j = 0; j < n; ++j) {
            if (abs(a[j] - a[i]) <= d) {  // Checking the distance between the cities
                count++;
            }
        }
        cout << count << "\n";
    }

   int maxCoverage = 0;
    int bestCenter = 0;

    int i = 0; // Start of the sliding window
    for (int center = a[0] - d; center <= a[n-1] + d; ++center) {
        // Adjust the start of the window to keep within range [center - d, center + d]
        while (i < n && a[i] < center - d) {
            i++;
        }

        // Count how many cities are within range [center - d, center + d]
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

    cout<< maxCoverage << "\n";

    return 0;
}
