# include<iostream>
using namespace std;

int getPivot (int arr[] , int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int start = 0;
    int end = n-1;
    int mid = start + (end - start) / 2;
    while (start < end) {
        if(arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int  arr[7] = {3,6,7,8,11,1,2};
    cout<<"Pivot is "<<getPivot(arr , 7)<<endl;

}