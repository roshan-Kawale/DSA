// sort 0,1,2 i/p:[0,2,1,2,0,0,1] o/p:[0,0,0,1,1,2,2]

#include <iostream>
using namespace std;

int main()
{
    int a[] = {0, 2, 1, 2, 0, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int left = 0, mid = 0, right = n - 1;
    while (mid <= right)
    {
        if (a[mid] == 0)
        {
            swap(a[left], a[mid]);
            left++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid] , a[right]);
            right--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}