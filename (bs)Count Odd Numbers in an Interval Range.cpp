//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=study-plan&id=programming-skills-i

class Solution {
public:

    int countOdds(int low, int high) {
        
     return (high + 1) / 2 - (low / 2);

    }
};
