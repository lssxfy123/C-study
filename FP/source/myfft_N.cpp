/*
 * myfft_N.cpp
 *
 * Code generation for function 'myfft_N'
 *
 * C source code generated on: Thu Jan 09 19:13:14 2014
 *
 */

/* Include files */
#include "../include/rt_nonfinite.h"
#include "../include/myfft_N.h"
#include "../include/MT_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void eml_fft(const emxArray_real_T *x, uint32_T n, emxArray_creal_T *y);
static real_T rt_hypotd_snf(real_T u0, real_T u1);

/* Function Definitions */
static void eml_fft(const emxArray_real_T *x, uint32_T n, emxArray_creal_T *y)
{
  int32_T iDelta2;
  int32_T nd2;
  uint32_T ju;
  int32_T nRows;
  emxArray_real_T *costab1q;
  int32_T nRowsM1;
  int32_T ixDelta;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T lastChan;
  real_T e;
  int32_T k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int32_T b_n;
  int32_T n2;
  int32_T ix;
  int32_T chanStart;
  int32_T i;
  uint32_T c_n;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T iheight;
  int32_T ihi;
  real_T twid_im;
  iDelta2 = y->size[0];
  y->size[0] = (int32_T)n;
  emxEnsureCapacity((emxArray__common *)y, iDelta2, (int32_T)sizeof(creal_T));
  if (n > (uint32_T)x->size[0]) {
    nd2 = y->size[0];
    iDelta2 = y->size[0];
    y->size[0] = nd2;
    emxEnsureCapacity((emxArray__common *)y, iDelta2, (int32_T)sizeof(creal_T));
    nd2--;
    for (iDelta2 = 0; iDelta2 <= nd2; iDelta2++) {
      y->data[iDelta2].re = 0.0;
      y->data[iDelta2].im = 0.0;
    }
  }

  if (x->size[0] == 0) {
  } else {
    ju = n;
    if (ju > 2147483647U) {
      ju = 2147483647U;
    }

    nRows = (int32_T)ju;
    if (x->size[0] > nRows) {
      nd2 = nRows;
    } else {
      nd2 = x->size[0];
    }

    b_emxInit_real_T(&costab1q, 2);
    nRowsM1 = nd2 - 1;
    ixDelta = x->size[0] - nRowsM1;
    if (1 >= ixDelta) {
      ixDelta = 1;
    }

    nRowsD2 = nRows / 2;
    nRowsD4 = nRowsD2 / 2;
    lastChan = nRows * (x->size[0] / x->size[0] - 1);
    e = 6.2831853071795862 / (real_T)nRows;
    iDelta2 = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = nRowsD4 + 1;
    emxEnsureCapacity((emxArray__common *)costab1q, iDelta2, (int32_T)sizeof
                      (real_T));
    costab1q->data[0] = 1.0;
    nd2 = nRowsD4 / 2;
    for (k = 1; k <= nd2; k++) {
      costab1q->data[k] = cos(e * (real_T)k);
    }

    for (k = nd2 + 1; k <= nRowsD4 - 1; k++) {
      costab1q->data[k] = sin(e * (real_T)(nRowsD4 - k));
    }

    b_emxInit_real_T(&costab, 2);
    b_emxInit_real_T(&sintab, 2);
    costab1q->data[nRowsD4] = 0.0;
    b_n = costab1q->size[1] - 1;
    n2 = b_n << 1;
    nd2 = n2 + 1;
    iDelta2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2;
    emxEnsureCapacity((emxArray__common *)costab, iDelta2, (int32_T)sizeof
                      (real_T));
    iDelta2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2;
    emxEnsureCapacity((emxArray__common *)sintab, iDelta2, (int32_T)sizeof
                      (real_T));
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= b_n; k++) {
      costab->data[k] = costab1q->data[k];
      sintab->data[k] = -costab1q->data[b_n - k];
    }

    for (k = b_n + 1; k <= n2; k++) {
      costab->data[k] = -costab1q->data[n2 - k];
      sintab->data[k] = -costab1q->data[k - b_n];
    }

    emxFree_real_T(&costab1q);
    ix = 0;
    chanStart = 0;
    while ((nRows > 0) && (chanStart <= lastChan)) {
      ju = 0U;
      nd2 = chanStart;
      for (i = 1; i <= nRowsM1; i++) {
        y->data[nd2].re = x->data[ix];
        y->data[nd2].im = 0.0;
        c_n = n;
        tst = TRUE;
        while (tst) {
          c_n >>= 1U;
          ju ^= c_n;
          tst = ((int32_T)(ju & c_n) == 0);
        }

        nd2 = chanStart + (int32_T)ju;
        ix++;
      }

      y->data[nd2].re = x->data[ix];
      y->data[nd2].im = 0.0;
      ix += ixDelta;
      nd2 = chanStart + nRows;
      if (nRows > 1) {
        for (i = chanStart; i <= nd2 - 2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      n2 = 2;
      iDelta2 = 4;
      k = nRowsD4;
      iheight = 1 + ((nRowsD4 - 1) << 2);
      while (k > 0) {
        i = chanStart;
        ihi = chanStart + iheight;
        while (i < ihi) {
          nd2 = i + n2;
          temp_re = y->data[nd2].re;
          temp_im = y->data[nd2].im;
          y->data[i + n2].re = y->data[i].re - y->data[nd2].re;
          y->data[i + n2].im = y->data[i].im - y->data[nd2].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
          i += iDelta2;
        }

        nd2 = chanStart + 1;
        for (b_n = k; b_n < nRowsD2; b_n += k) {
          e = costab->data[b_n];
          twid_im = sintab->data[b_n];
          i = nd2;
          ihi = nd2 + iheight;
          while (i < ihi) {
            temp_re = e * y->data[i + n2].re - twid_im * y->data[i + n2].im;
            temp_im = e * y->data[i + n2].im + twid_im * y->data[i + n2].re;
            y->data[i + n2].re = y->data[i].re - temp_re;
            y->data[i + n2].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += iDelta2;
          }

          nd2++;
        }

        k /= 2;
        n2 = iDelta2;
        iDelta2 <<= 1;
        iheight -= n2;
      }

      chanStart += nRows;
    }

    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

static real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (rtIsNaN(y)) {
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

void myfft_N(const emxArray_real_T *signal, int32_T N, emxArray_real_T *y)
{
  emxArray_real_T *b_signal;
  int32_T i0;
  int32_T loop_ub;
  emxArray_creal_T *b_y;
  emxArray_creal_T *b_y1;
  uint32_T uv0[2];
  emxInit_real_T(&b_signal, 1);
  i0 = b_signal->size[0];
  b_signal->size[0] = signal->size[1];
  emxEnsureCapacity((emxArray__common *)b_signal, i0, (int32_T)sizeof(real_T));
  loop_ub = signal->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_signal->data[i0] = signal->data[i0];
  }

  emxInit_creal_T(&b_y, 2);
  b_emxInit_creal_T(&b_y1, 1);
  i0 = N;
  if (i0 < 0) {
    i0 = 0;
  }

  eml_fft(b_signal, (uint32_T)i0, b_y1);
  i0 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(creal_T));
  loop_ub = b_y1->size[0];
  i0 = b_y->size[0] * b_y->size[1];
  b_y->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(creal_T));
  emxFree_real_T(&b_signal);
  loop_ub = b_y1->size[0] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_y->data[i0] = b_y1->data[i0];
  }

  emxFree_creal_T(&b_y1);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)b_y->size[i0];
  }

  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T));
  for (loop_ub = 0; loop_ub <= b_y->size[1] - 1; loop_ub++) {
    y->data[loop_ub] = rt_hypotd_snf(fabs(b_y->data[loop_ub].re), fabs(b_y->
      data[loop_ub].im));
  }

  emxFree_creal_T(&b_y);
}

/* End of code generation (myfft_N.cpp) */
