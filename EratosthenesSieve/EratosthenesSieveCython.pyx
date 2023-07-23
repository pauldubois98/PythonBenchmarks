
def EratosthenesSievePython(int n):
    cdef list nbs = [True] * (n+1)
    nbs[0] = False
    nbs[1] = False

    cdef int i, j
    for i in range(2, int(n**0.5)+1):
        if nbs[i]:
            for j in range(i*i, n+1, i):
                nbs[j] = False

    return [i for i in range(n+1) if nbs[i]]

