#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    int *primes;
    int size;
} Result;

Result EratosthenesSieveC(int n)
{
    bool *nbs = (bool *)malloc((n + 1) * sizeof(bool));
    int i, j, count = 0;

    // Initialize the array with 'true'
    for (i = 0; i <= n; i++)
    {
        nbs[i] = true;
    }

    nbs[0] = nbs[1] = false;

    // Apply the Sieve of Eratosthenes algorithm
    for (i = 2; i <= sqrt(n); i++)
    {
        if (nbs[i])
        {
            for (j = i * i; j <= n; j += i)
            {
                nbs[j] = false;
            }
        }
    }

    // Count the number of primes found
    for (i = 0; i <= n; i++)
    {
        if (nbs[i])
        {
            count++;
        }
    }

    // Allocate memory for the array of primes
    int *primes = (int *)malloc(count * sizeof(int));

    // Store the prime numbers in the 'primes' array
    int index = 0;
    for (i = 0; i <= n; i++)
    {
        if (nbs[i])
        {
            primes[index] = i;
            index++;
        }
    }

    // Free the memory used by the 'nbs' array
    free(nbs);

    Result result;
    result.primes = primes;
    result.size = count;

    return result;
}
