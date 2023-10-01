#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int start = 1;
    int amplitude = 3;
    int displacement = 1;
    int floater = 1;
    while (start <= n) 
    {
        for (int i = 0; i < floater && start <= n; i++)
        {
            cout << start++ << " ";
        }
        cout << endl;
        floater += displacement;
        if (floater < 1)
        {
            displacement = 1;
            floater = 2;
            ++amplitude;
        }
        else if (floater >= amplitude)
        {
            displacement = -1;
            floater -= 2;
        }
    }
}
