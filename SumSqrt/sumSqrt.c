#include <math.h>

double sumSqrtC(int *arr, int len)
{
    double somme_terme = 0;
    for (int i = 0; i < len; i++)
    {
        somme_terme += sqrt(arr[i]);
    }

    return somme_terme;
}
