#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

void merge(int* array, int begin, int mid, int end){
    std::cout << "check";
    int newArray[10];
    int begCount = begin;
    int endCount = mid+1;
    for(int i=begin; i <= end; i++){
        if(begCount <= mid && endCount <= end){
            if(array[begCount] < array[endCount]){
                newArray[i] = array[begCount];
                begCount++;
            }
            else{
                newArray[i] = array[endCount];
                endCount++;
            }
        }
        else if(begCount <= mid){
            newArray[i] = array[begCount];
            begCount++;
        }
        else{
            newArray[i] = array[endCount];
            endCount++;
        }
    }
    for(int i = begin; i <= end; i++){
        array[i] = newArray[i];
    }

}

void myMergeSort(int* array, int begin, int end){
    int size = end - begin + 1;
    int mid = begin + size/2 - 1;
    if(size > 1){
        myMergeSort(array, begin, mid);
        myMergeSort(array, begin + mid + 1, end);
    }
    merge(array, begin, mid, end);
}

int main(){
    int myArray[10] = {12, 5, 8, 6, 97, 4, 7, 10, 15, 19};
    myMergeSort(myArray, 0, 9);
    for(int i=0; i<10; i++){
        std:: cout << myArray[i];
    }
}