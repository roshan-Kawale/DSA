//binary search 

#include<iostream>
using namespace std;

int binarySearch(int arr[] , int n , int key) {
    int start = 0 , end = n-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key ) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    int even[8] = {2,4,6,8,10,12,16,18};
    int odd[5] = {1,2,3,4,5};
    int evenIdx = binarySearch(even , 8 , 12);
    cout<<"Index of 12 is "<< evenIdx <<endl;
    int oddIdx = binarySearch(odd , 5 , 3);
    cout<<"Index of 3 is "<< oddIdx <<endl;

}