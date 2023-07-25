# cython: language_level=3
import numpy as np
cimport numpy as np

cpdef double cython_sum_sqrt(int[:] x):
    return np.sum(np.sqrt(x))
