#include <bits/stdc++.h>
using namespace std;

void square(int n, int m);
void triangle(int n);
void invertedTriangle(int n);

int main()
{
    // square(3, 3);
    // triangle(3);
    invertedTriangle(4);
    return 0;
}

void square(int n = 3, int m = 3)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << count++ << " ";
        cout << endl;
    }
    return;
}

void triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void invertedTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = i; j < n; j++)
            cout << i+1;
        cout << endl;
    }
}