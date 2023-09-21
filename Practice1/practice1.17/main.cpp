#include <iostream>
using namespace std;

int calculateResidualWater(int arrayLength, int blockLevels[])
{
    int water = 0;
    int level = 0;
    int left = 0;
    int right = arrayLength - 1;

    while (left < right)
    {
        if (blockLevels[left] < blockLevels[right])
        {
            level = max(blockLevels[left], level);
            water += level - blockLevels[left];
            left++;
        }
        else
        {
            level = max(blockLevels[right], level);
            water += level - blockLevels[right];
            right--;
        }
    }

    return water;
}

int main()
{
    int arrayLength;
    cin >> arrayLength;
    int *blockLevels = new int[arrayLength];
    
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> blockLevels[i];
    }

    cout << calculateResidualWater(arrayLength, blockLevels) << endl;

    delete[] blockLevels;
}
