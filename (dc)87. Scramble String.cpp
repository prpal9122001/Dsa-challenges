//https://leetcode.com/problems/scramble-string/submissions/924957375/

class Solution {
public:
//for storing already solved problems
    unordered_map<string,bool> mp;
    
    
    bool isScramble(string s1, string s2) {
        //base cases
        
        int n = s1.size();
        
        //if both string are not equal in size
        if(s2.size()!=n)
            return false;
        
        //if both string are equal
        if(s1==s2)
         return true;   
        
            
        
        //if code is reached to this condition then following this are sure:
        //1. size of both string is equal
        //2.  string are not equal
        //so size is equal (where size==1) and they are not equal then obviously false
        //example 'a' and 'b' size is equal ,string are not equal
        if(n==1)
            return false;
        
        string key = s1+" "+s2;
        
		//check if this problem has already been solved
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        //for every iteration it can two condition 
        //1.we should proceed without swapping
        //2.we should swap before looking next
        for(int i=1;i<n;i++)
        {

            //ex of without swap: gr|eat and rg|eat
            bool withoutswap = (
                //left part of first and second string
                isScramble(s1.substr(0,i),s2.substr(0,i)) 
                
                &&
                
                //right part of first and second string;
                isScramble(s1.substr(i),s2.substr(i))
                );
            
            
            
            //if without swap give us right answer then we do not need 
            //to call the recursion withswap
            if(withoutswap)
                return true;
            
            //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"
            bool withswap = (
                //left part of first and right part of second 
                isScramble(s1.substr(0,i),s2.substr(n-i)) 
                
                &&
                
                //right part of first and left part of second
                isScramble(s1.substr(i),s2.substr(0,n-i)) 
                );
            
            
            
            //if withswap give us right answer then we return true
            //otherwise the for loop do it work
            if(withswap)
                return true;
            //we are not returning false in else case 
            //because we want to check further cases with the for loop
        }
        
        
        return mp[key] = false;
        
    }
};

/*SUMMARY*/
//The isScramble() function takes two strings s1 and s2 as input and returns a boolean value indicating if s1 can be scrambled into s2.
//The function uses an unordered_map mp to store already solved problems and avoids solving them again.
//The function first checks if the lengths of s1 and s2 are equal. If not, it returns false. 
//If they are equal, it checks if both strings are the same, in which case it returns true.
//If both strings are of length 1 and not the same, it returns false.
//For each iteration of the for loop, the function checks whether it should proceed without swapping or swap before looking at the next value.
//It does this by breaking s1 and s2 into two parts at index i. It then calls isScramble() recursively with the two left parts and the two right parts of the substrings s1 and s2. 
//If isScramble() returns true for both the left and right parts, it either proceeds without swapping or swaps the left and right parts of s2 and checks again. 
//If it finds a correct solution, it returns true. If it reaches the end of the for loop, it returns false.
