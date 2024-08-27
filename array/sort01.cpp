// sort 0,1 i/p:[0,1,1,0,0,1] o/p:[0,0,0,1,1,1]

#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 1, 1, 0, 0, 0, 1, 0, 0};
    int n = sizeof(a) / sizeof(a[0]);
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (a[i] == 1 & a[j] == 0)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (a[i] == 0)
        {
            i++;
        }
        if (a[j] == 1)
        {
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}