/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
*/

class Node{
public:
    int i;
    int j;
    int val;
    Node(int newX, int newY, int newVal){
        i = newX;
        j = newY;
        val = newVal;
    }
};

class Comparator{
public:
    bool operator() (const Node& node1, const Node& node2){
        return node1.val > node2.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<pair<int, int>, int> added; //Stores whether or not a particular index has been seen.
        //Minheap to store nodes in order of value
        priority_queue<Node, vector<Node>, Comparator > minHeap;

        //Add element [0][0] to the heap
        minHeap.push(Node(0, 0, matrix[0][0]));

        //Add elements to the heap such that the smallest element in the matrix
        //which hasn't already been popped is always in the heap at the start of the loop.
        //Each time we loop, we pop the smallest node so that after k iterations, the
        //node at the top of the heap stores the kth smallest element.
        for(int i = 1; i < k; i++){
            Node cur = minHeap.top();
            minHeap.pop();
            if(cur.i < matrix.size()-1){ //Check for matrix bounds
            	//check if element to the right has already been seen
                if(added[make_pair(cur.i + 1, cur.j)] == 0){ 
                	//If not, mark it as seen and push it to the heap.
                    added[make_pair(cur.i+1, cur.j)]++;
                    minHeap.push(Node(cur.i+1, cur.j, matrix[cur.i+1][cur.j]));
                }
            }
            if(cur.j < matrix.size()-1){
                if(added[make_pair(cur.i, cur.j+1)] == 0){
                    added[make_pair(cur.i, cur.j+1)]++;
                    minHeap.push(Node(cur.i, cur.j+1, matrix[cur.i][cur.j+1]));
                }
            }
            
        }
        return minHeap.top().val;  
    }
};
