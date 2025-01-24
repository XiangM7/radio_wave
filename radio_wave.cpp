#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
   

    int left = 0, right = 0; 
    for (int i = 0; i < n; i++) 
    {
        long long minVal = a[i] - d;
        long long maxVal = a[i] + d;

        // Advance 'left' so that it's the first index where a[left] >= minVal
        while (left < n && a[left] < minVal) 
        {
            left++;
        }
        // Advance 'right' so that it's the first index where a[right] > maxVal
        while (right < n && a[right] <= maxVal) 
        {
            right++;
        }
        int coverage = right - left;
        
        cout << coverage << "\n";
    }
    
    // Part 2: Maximum coverage (and a best center) in O(n)
    int maxCoverage = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) 
    {
        // Shrink from the left if the window is too large
        while (a[j] - a[i] >  2 * d) 
        {
            i++;
        }
        int coverage = j - i + 1;
        if (coverage > maxCoverage) 
        {
            maxCoverage = coverage;
        }
    }
    cout << maxCoverage << "\n";
   

    return 0;
}


