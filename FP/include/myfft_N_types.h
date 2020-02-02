/*
 * myfft_N_types.h
 *
 * Code generation for function 'myfft_N'
 *
 * C source code generated on: Thu Jan 09 19:13:14 2014
 *
 */

#include"../include/rtwtypes.h"
#ifndef __MYFFT_N_TYPES_H__
#define __MYFFT_N_TYPES_H__

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
typedef struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray__common;
#endif
#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T
typedef struct emxArray_creal_T
{
    creal_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_creal_T;
#endif
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
typedef struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_real_T;
#endif

#endif
/* End of code generation (myfft_N_types.h) */
