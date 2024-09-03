//Sum of Digits of String After Convert : s is a string and k is iteration for the sum operations

#include <iostream>
using namespace std;

int sumDigits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int getLucky(string s, int k)
{
    int sum = 0;
    for (auto it : s)
    {
        int value = it - 'a' + 1;
        if (value >= 10)
        {
            sum += value % 10 + value / 10;
        }
        else
            sum = sum + value;
    }

    k--; // since I did the sum once;
    while (k-- && sum >= 10)
    { // furthur trasformations starts here
        sum = sumDigits(sum);
    }
    return sum;
}

int main()
{
    string s = "string";
    int k=2;
    cout<<getLucky(s,k)<<endl;
}