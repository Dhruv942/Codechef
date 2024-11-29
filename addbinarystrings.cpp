//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
           int n = s1.size() - 1;
    int m = s2.size() - 1;
    
    string ans = "";
    char carry = '0'; // Carry should be a single character ('0' or '1')
    
    // Add while both strings have digits
    while (n >= 0 && m >= 0) {
        if (s1[n] == '1' && s2[m] == '1' && carry == '0') {
            ans += '0';
            carry = '1';
        } 
        else if (s1[n] == '1' && s2[m] == '1' && carry == '1') {
            ans += '1';
            carry = '1';
        } 
        else if ((s1[n] == '1' && s2[m] == '0' && carry == '0') || 
                 (s1[n] == '0' && s2[m] == '1' && carry == '0')) {
            ans += '1';
            carry = '0';
        } 
        else if ((s1[n] == '1' && s2[m] == '0' && carry == '1') || 
                 (s1[n] == '0' && s2[m] == '1' && carry == '1')) {
            ans += '0';
            carry = '1';
        } 
        else if (s1[n] == '0' && s2[m] == '0' && carry == '0') {
            ans += '0';
            carry = '0';
        } 
        else if (s1[n] == '0' && s2[m] == '0' && carry == '1') {
            ans += '1';
            carry = '0';
        }
        n--;
        m--;
    }

    // Process remaining digits of s1
    while (n >= 0) {
        if (s1[n] == '1' && carry == '0') {
            ans += '1';
            carry = '0';
        } 
        else if (s1[n] == '1' && carry == '1') {
            ans += '0';
            carry = '1';
        } 
        else if (s1[n] == '0' && carry == '0') {
            ans += '0';
            carry = '0';
        } 
        else if (s1[n] == '0' && carry == '1') {
            ans += '1';
            carry = '0';
        }
        n--;
    }

    // Process remaining digits of s2
    while (m >= 0) {
        if (s2[m] == '1' && carry == '0') {
            ans += '1';
            carry = '0';
        } 
        else if (s2[m] == '1' && carry == '1') {
            ans += '0';
            carry = '1';
        } 
        else if (s2[m] == '0' && carry == '0') {
            ans += '0';
            carry = '0';
        } 
        else if (s2[m] == '0' && carry == '1') {
            ans += '1';
            carry = '0';
        }
        m--;
    }

    // If there is a carry left
    if (carry == '1') {
        ans += '1';
    }
    int p=-1;
    // Reverse the result to get the final binary sum
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        if(ans[i]=='0'){
            p = i;
        }
        else{
            break;
        }
    }
    if(p!=-1){
        ans = ans.substr(p+1);
    }
    
    return ans;


    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
