#include <iostream>
#include <vector>
using namespace std;

int a[(int)1e5 + 5];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Number of cities covered if the tower is placed at city a[i]
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        int left = a[i] - d, right = a[i] + d;
        for (int j = 0; j < n; ++j) {
            if (a[j] >= left && a[j] <= right) {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    // Maximum number of cities that can be covered by a single tower
    int ans = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && a[j] <= a[i] + d) {
            j++;
        }
        ans = max(ans, j - i);
    }
    cout << ans << '\n';

    return 0;
}
