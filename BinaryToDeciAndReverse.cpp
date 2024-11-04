#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string decToBinary(int n)
{
    string str = "";
    while (n > 0)
    {
        int x = n % 2;
        n = n / 2;
        str = str + to_string(x);
    }
    reverse(str.begin(), str.end());
    return str;
}
int BinaryToDec(string str)
{
    int binary = 0;
    int power = 0;
    while (str.size() > 0)
    {
        int x;
        if (str[str.size() - 1] == '1')
            x = 1;
        else
            x = 0;
        binary = binary + x * pow(2, power);
        power += 1;
        str.pop_back();
    }
    return binary;
}

int main()
{
    cout << decToBinary(50);
    cout << BinaryToDec("110010");
    return 0;
}