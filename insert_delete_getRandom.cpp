/*
Design a data structure that supports all following operations in average O(1) time.

 

insert(val): Inserts an item val to the set if not already present.

remove(val): Removes an item val from the set if present.

getRandom: Returns a random element from current set of elements
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        vecSet.push_back(1);
        index = 1;
        size = 0;
    }
    
    map<int, int> mapSet; //Key is the value of element, value is the position it takes in vecSet.
    vector<int> vecSet; //Vector of all elements.
    int index; //Stores the index of the next available slot to be added to the vector
    int size; //Stores the number of elements currently in the structure

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mapSet[val] == 0){
            mapSet[val] = index;
            vecSet.push_back(val);
            index++;
            size++;
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	//If value is not in the data structure
        if(mapSet[val] == 0){
            return false;
        }
    	//Store the vector position of the value to be deleted.
        int swap = mapSet[val];
        //Erase the element from the map
        mapSet[val] = 0;
        index--;
        //Swap the deleted value with the value at the back of the vector. Update map.
        if(swap != size){
            vecSet[swap] = vecSet.back();
            mapSet[vecSet.back()] = swap;
        }
        size--; //Update size variable
        vecSet.pop_back(); //Remove the deleted element from the back of the vector
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = (rand() % size) + 1;
        return vecSet[random];
    }
};
