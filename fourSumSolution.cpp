/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are
such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
*/

class Solution {
public:
    //Returns number of tuples that satisfy the four-sum requirement
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int total = 0;
        map<int, int> subSum; 
        for(auto x:A){
            for(auto y:B){
                //For each sum A[x] + B[y], increment the count of the corresponding map entry
                subSum[x+y]++;
            }
        }
        //Map now stores all sums between A and B along with a count of how many times they occured.
        for(auto v:C){
            for(auto w:D){
                //If the negative of the sum of C[v] and D[w] is in the map, this is a valid tuple.
                if(subSum.find(-(v+w)) != subSum.end()){
                    //Increment by the number of times the sum appears in the map.
                    total += subSum[-(v+w)];
                }
            }
        }
        return total;
    }
};