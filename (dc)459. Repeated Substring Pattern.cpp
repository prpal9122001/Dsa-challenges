//https://leetcode.com/problems/repeated-substring-pattern/description/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
              // Check for possible factors of n that can be lengths of substrings
        for(int i = 1; i <=n/2 ; ++i){
            if(n % i == 0){
                string sub = s.substr(0,i);// Extract the potential substring
                string reconstructed = "";
                // Reconstruct the original string using the potential substring
                for(int j = 0; j<n/i ; ++j){
                    reconstructed+=sub;
                }
                if(reconstructed == s){
                    return true; // Found a repeated substring pattern
                }
            }
        }
        return false;// No repeated substring pattern found
    }
};
