/*
 * DataFit.cpp
 *
 * Code generation for function 'DataFit'
 *
 * C source code generated on: Thu Oct 24 16:14:05 2013
 *
 */

/* Include files */
#include "../include/rt_nonfinite.h"
#include "../include/DataFit.h"
#include "../include/polyfit.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void DataFit(const emxArray_real_T *x, const emxArray_real_T *y, real_T n,
             emxArray_real_T *C)
{
  polyfit(x, y, n, C);
}

/* End of code generation (DataFit.cpp) */
