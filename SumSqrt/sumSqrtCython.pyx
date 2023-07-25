# cython: language_level=3
import numpy as np
cimport numpy as np

cpdef double sumSqrtCython(int[:] x):
    return np.sum(np.sqrt(x))
