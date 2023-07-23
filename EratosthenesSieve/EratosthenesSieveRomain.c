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
    double limit = sqrt(n);

    // Initialize the array with true everywhere except for 0 and 1
    nbs[0] = nbs[1] = false;
    for (i = 2; i <= n; i++)
    {
        nbs[i] = true;
    }

    // Apply the Sieve of Eratosthenes algorithm
    for (i = 2; i <= limit; i++)
    {
        if (nbs[i])
        {
            for (j = i * i; j <= n; j += i)
            {
                if (nbs[j])
                {
                    nbs[j] = false;
                    count++; // how many numbers are not prime
                }
            }
        }
    }

    // Allocate memory for the array of primes
    int *primes = (int *)malloc((n + 1 - count - 2) * sizeof(int));

    // Store the prime numbers in the 'primes' array
    int index = 0;
    for (i = 2; i <= n; i++)
    {
        if (nbs[i])
        {
            primes[index++] = i;
        }
    }

    // Free the memory used by the 'nbs' array
    free(nbs);

    Result result;
    result.primes = primes;
    result.size = n - count;

    return result;
}