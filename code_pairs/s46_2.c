#include <stdio.h>
 
int binarySearch(int arr[], int target, int size){
    
    // arr[] it is in decreasing order
    
    int start=0, end=size-1, mid;
    
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==target){
            return mid+1;
        } else if(arr[mid]>target){
            // target is smaller from element at mid => search target in the right half
            end=mid-1;
        } else{
            start = mid+1;
        }
    }
    
    // target was not present in the arr[], now end<start and arr[end]>arr[start], start is just larger from target
    return start;
}
 
void insertionSort(int arr[], int size, int p){
    int index;  // index is the position for the element p in the array arr[]
    if(p>=arr[size-1]){
        // p is the largest element, it should be in the beginning
        index = size;
    } else if(p<=arr[0]){
        // p is the smallest element, it should be in the end
        index=0;
    } else {
        index = binarySearch(arr,p,size);
    }
    
    // shift the elements
    for(int i=size; i>index; i--) arr[i]=arr[i-1];
    arr[index] = p;
}
 
int main(){
    int tasks;
    scanf("%d", &tasks);
    
    int t,p,arr[tasks], size=0;
    while(tasks--){
        scanf("%d", &t);
        switch(t){
            case 1:
                scanf("%d", &p); // take the input - bug difficulty
                if(size==0){
                    // inserting the first element
                    arr[0]=p;
                } else{
                    // perform insertion sort to maintain the decreasing order of arr[]
                    insertionSort(arr,size,p);
                }
                size++; // adding an element increases the size of arr[]
                break;
            case 2:
                if(size<3) printf("Not enough enemies\n");
                // this is for ascending order
                else printf("%d\n", arr[size-size/3]);
        }
    }
    return 0;
}