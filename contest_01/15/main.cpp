#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string; 
    getline(cin, string);
    int stringLength = string.size(),
        count = 1,
        compressedStringLength = stringLength,
        index = 0; 
    int* array = new int[stringLength];
    for (int i = 0; i < stringLength - 1; i++)
    {
        for (int j = i + 1; j <= stringLength; j++)
        {
            if (string[i] == string[j])
            {
                count++;
                compressedStringLength--;
            }
            else
            {
                array[index] = count;
                index++;
                count = 1;
                i = j;
            }
        }
    }

    for (int i = 0, a = 0; a < compressedStringLength; i += array[a], a++)
    {
        if (array[a] == 1)
        {
            cout << string[i];
        }
        else
        {
            cout << string[i] << array[a];
        }
    }
    cout << endl;

    delete[] array;
}
