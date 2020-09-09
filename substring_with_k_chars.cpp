/*
Find the length of the longest substring T of a given string
(consists of lowercase letters only) such that every character
in T appears no less than k times.
*/

class Solution {
public:
	//Returns the length of the longest valid substring
    int longestSubstring(string s, int k) {
        return recurse(s, 0, s.size()-1, k);
    }
    
    //Returns the length of the longest valid substring within the given bounds
    int recurse(string s, int begin, int end, int k){
    	//Base case - nothing within bounds
        if(begin > end){
            return 0;
        }
        int left, right;
        bool badLetter = false;
        map<char, int> letters;

        //Add all letters to a map, store number of occurances.
        for(int i = begin; i <= end; i++){
            letters[s[i]]++;
        }

        //loop through all letters until we find one that doesn't work -
        for(int i = begin; i <= end; i++){
        	//If letter appears less than k times
            if(letters[s[i]] < k){
                int newBegin, newEnd;
                newBegin = i+1;
                newEnd = i-1;
                i++;
                //If multiple in a row are invalid, we can get rid of them all.
                while(letters[s[i]] < k && i <= end){
                    newBegin++;
                    i++;
                }

                //Recurse on either side of the invalid letters
                left = recurse(s, begin, newEnd, k);
                right = recurse(s, newBegin, end, k);
                badLetter = true;
                break;
                
            }
        }
        //If all letters valid:
        if(!badLetter){
            return end-begin+1;
        }
        else{
        	//return the greater of the two recursive calls.
            return max(left, right);
        }
    }
};