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
        cout << count << " ";
    }

    // Find the maximum number of cities a tower can cover
    int maxCoverage = 0;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        // Count how many cities are covered by a tower placed at a[i]
        for (int j = 0; j < n; ++j) {
            if (abs(a[j] - a[i]) <= d) {  // Checking the distance between the cities
                count++;
            }
        }
        maxCoverage = max(maxCoverage, count);  // Updating the maximum coverage
    }
    
    cout << maxCoverage << '\n';

    return 0;
}
