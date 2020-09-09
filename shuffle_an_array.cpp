/*
Randomly shuffle a set of numbers without duplicates.
*/

class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    vector<int> original;

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int* free = new int[original.size()];
        vector<int> shuffled;

        //Set values of free array to equal their position
        for(int i = 0; i < original.size(); i++){
            free[i] = i;
        }

        //Randomly select from the free slots and push the corresponding value onto
        //shuffled vector. Shrink the size of free slot list and adjust
        //the values to reflect which spot was used.
        for(int i = original.size()-1; i >= 0; i--){
            int index = rand() % (i + 1);
            shuffled.push_back(original[free[index]]);
            free[index] = free[i];
        }
        return shuffled;
    }
};