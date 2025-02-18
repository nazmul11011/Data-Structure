#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &x : a) cin >> x;

        // Step 1: Handle the case where there's only one element
        if (n == 1) {
            cout << "1 1\n";
            continue;
        }

        // Step 2: Check if all elements are the same
        bool all_same = true;
        for (long long i = 1; i < n; ++i) {
            if (a[i] != a[0]) {
                all_same = false;
                break;
            }
        }

        if (all_same) {
            // If all elements are the same, no need to remove anything
            cout << "0\n";
        } else {
            // Step 3: Find the first and last indices of distinct elements
            long long first_distinct = -1, last_distinct = -1;
            unordered_set<long long> seen;

            // Find the first distinct element
            for (long long i = 0; i < n; ++i) {
                if (seen.find(a[i]) == seen.end()) {
                    first_distinct = i + 1; // Convert to 1-based index
                    seen.insert(a[i]);
                }
            }

            // Clear the set and find the last distinct element
            seen.clear();
            for (long long i = n - 1; i >= 0; --i) {
                if (seen.find(a[i]) == seen.end()) {
                    last_distinct = i + 1; // Convert to 1-based index
                    seen.insert(a[i]);
                }
            }

            // Step 4: Output the result
            cout << last_distinct << " " << first_distinct << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}