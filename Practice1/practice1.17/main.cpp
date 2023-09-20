#include <iostream>
using namespace std;

int arrayLength;
int* blocks;
int waterBlocks = 0;

void calculateResidualWater(int height)
{
	int temp = -1;
	for (int i = 0; i < arrayLength; i++)
	{
		if (blocks[i] >= height)
		{
			if (temp != -1)
			{
				waterBlocks += temp;
			}
			temp = 0;
		}
		else if (temp != -1) 
		{
			temp++;
		}
	}
}

int main()
{
	int max = 0;

	cin >> arrayLength;
	blocks = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		cin >> blocks[i];
		if (blocks[i] > max)
		{
			max = blocks[i];
		}
	}

	int height = 2;
	while (height < max + 1)
	{
		calculateResidualWater(height);
		height++;
	}
	cout << waterBlocks;
}
