#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 
        int prices[2 * n]; 

        for (int i = 0; i < 2 * n; i++) {
            cin >> prices[i];
        }

        map<int, int> priceCount;
        bool isValid = true;

        for (int i = 0; i < 2 * n; i++) {
            priceCount[prices[i]]++;
            if (priceCount[prices[i]] > 2) {
                isValid = false; 
                break;
            }
        }
        if (isValid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
