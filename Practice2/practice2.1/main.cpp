#include <math.h>

bool is_prime(int number)
{
    for (int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }

    return true;
}
