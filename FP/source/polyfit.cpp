/*
 * polyfit.cpp
 *
 * Code generation for function 'polyfit'
 *
 * C source code generated on: Thu Oct 24 16:14:05 2013
 *
 */

/* Include files */
#include "../include/rt_nonfinite.h"
#include "../include/DataFit.h"
#include "../include/polyfit.h"
#include "../include/MT_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real_T eml_matlab_zlarfg(int32_T n, real_T *alpha1, emxArray_real_T *x,
  int32_T ix0);
static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y, real_T *rankR);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static real_T rt_hypotd_snf(real_T u0, real_T u1);

/* Function Definitions */
static real_T eml_matlab_zlarfg(int32_T n, real_T *alpha1, emxArray_real_T *x,
  int32_T ix0)
{
  real_T tau;
  int32_T nm1;
  real_T xnorm;
  int32_T knt;
  real_T d0;
  tau = 0.0;
  if (n <= 0) {
  } else {
    nm1 = n - 1;
    xnorm = eml_xnrm2(nm1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(fabs(*alpha1), xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          eml_xscal(nm1, 9.9792015476736E+291, x, ix0);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = eml_xnrm2(nm1, x, ix0);
        xnorm = rt_hypotd_snf(fabs(*alpha1), xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        d0 = 1.0 / (*alpha1 - xnorm);
        eml_xscal(nm1, d0, x, ix0);
        for (nm1 = 1; nm1 <= knt; nm1++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        d0 = 1.0 / (*alpha1 - xnorm);
        eml_xscal(nm1, d0, x, ix0);
        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y, real_T *rankR)
{
  emxArray_real_T *b_A;
  real_T smax;
  real_T s;
  int32_T mn;
  int32_T i0;
  int32_T yk;
  emxArray_real_T *tau;
  int32_T m;
  int32_T n;
  int32_T b_mn;
  int32_T b_n;
  emxArray_int32_T *jpvt;
  int32_T k;
  emxArray_real_T *work;
  emxArray_real_T *vn1;
  emxArray_real_T *vn2;
  int32_T nmi;
  int32_T i;
  int32_T i_i;
  int32_T mmi;
  int32_T mmip1;
  int32_T ix;
  int32_T iy;
  int32_T i_ip1;
  int32_T lastc;
  boolean_T exitg3;
  int32_T exitg2;
  real_T y;
  real_T t;
  boolean_T exitg1;
  uint32_T unnamed_idx_0;
  emxInit_real_T(&b_A, 2);
  smax = (real_T)A->size[0];
  s = (real_T)A->size[1];
  if (smax <= s) {
    s = smax;
  }

  mn = (int32_T)s - 1;
  i0 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, i0, (int32_T)sizeof(real_T));
  yk = A->size[0] * A->size[1] - 1;
  for (i0 = 0; i0 <= yk; i0++) {
    b_A->data[i0] = A->data[i0];
  }

  b_emxInit_real_T(&tau, 1);
  m = A->size[0];
  n = A->size[1];
  if (m <= n) {
    b_mn = m;
  } else {
    b_mn = n;
  }

  i0 = tau->size[0];
  tau->size[0] = b_mn;
  emxEnsureCapacity((emxArray__common *)tau, i0, (int32_T)sizeof(real_T));
  if (n < 1) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T(&jpvt, 2);
  i0 = jpvt->size[0] * jpvt->size[1];
  jpvt->size[0] = 1;
  jpvt->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)jpvt, i0, (int32_T)sizeof(int32_T));
  if (b_n > 0) {
    jpvt->data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      jpvt->data[k - 1] = yk;
    }
  }

  if ((A->size[0] == 0) || (A->size[1] == 0)) {
  } else {
    b_emxInit_real_T(&work, 1);
    i0 = work->size[0];
    work->size[0] = n;
    emxEnsureCapacity((emxArray__common *)work, i0, (int32_T)sizeof(real_T));
    yk = n - 1;
    for (i0 = 0; i0 <= yk; i0++) {
      work->data[i0] = 0.0;
    }

    b_emxInit_real_T(&vn1, 1);
    b_emxInit_real_T(&vn2, 1);
    i0 = vn1->size[0];
    vn1->size[0] = n;
    emxEnsureCapacity((emxArray__common *)vn1, i0, (int32_T)sizeof(real_T));
    i0 = vn2->size[0];
    vn2->size[0] = vn1->size[0];
    emxEnsureCapacity((emxArray__common *)vn2, i0, (int32_T)sizeof(real_T));
    k = 1;
    for (nmi = 0; nmi + 1 <= n; nmi++) {
      vn1->data[nmi] = eml_xnrm2(m, A, k);
      vn2->data[nmi] = vn1->data[nmi];
      k += m;
    }

    for (i = 0; i + 1 <= b_mn; i++) {
      i_i = i + i * m;
      nmi = n - i;
      mmi = (m - i) - 1;
      mmip1 = 1 + mmi;
      if (nmi < 1) {
        yk = -1;
      } else {
        yk = 0;
        if (nmi > 1) {
          ix = i;
          smax = fabs(vn1->data[i]);
          for (k = 2; k <= nmi; k++) {
            ix++;
            s = fabs(vn1->data[ix]);
            if (s > smax) {
              yk = k - 1;
              smax = s;
            }
          }
        }
      }

      b_n = i + yk;
      if (b_n + 1 != i + 1) {
        ix = m * b_n;
        iy = m * i;
        for (k = 1; k <= m; k++) {
          smax = b_A->data[ix];
          b_A->data[ix] = b_A->data[iy];
          b_A->data[iy] = smax;
          ix++;
          iy++;
        }

        yk = jpvt->data[b_n];
        jpvt->data[b_n] = jpvt->data[i];
        jpvt->data[i] = yk;
        vn1->data[b_n] = vn1->data[i];
        vn2->data[b_n] = vn2->data[i];
      }

      if (i + 1 < m) {
        s = b_A->data[i_i];
        tau->data[i] = eml_matlab_zlarfg(mmip1, &s, b_A, i_i + 2);
      } else {
        smax = b_A->data[i_i];
        s = b_A->data[i_i];
        b_A->data[i_i] = smax;
        tau->data[i] = 0.0;
      }

      b_A->data[i_i] = s;
      if (i + 1 < n) {
        s = b_A->data[i_i];
        b_A->data[i_i] = 1.0;
        i_ip1 = (i + (i + 1) * m) + 1;
        if (tau->data[i] != 0.0) {
          yk = i_i + mmip1;
          while ((mmip1 > 0) && (b_A->data[yk - 1] == 0.0)) {
            mmip1--;
            yk--;
          }

          lastc = nmi - 1;
          exitg3 = FALSE;
          while ((exitg3 == 0U) && (lastc > 0)) {
            yk = i_ip1 + (lastc - 1) * m;
            k = yk;
            do {
              exitg2 = 0;
              if (k <= (yk + mmip1) - 1) {
                if (b_A->data[k - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  k++;
                }
              } else {
                lastc--;
                exitg2 = 2;
              }
            } while (exitg2 == 0U);

            if (exitg2 == 1U) {
              exitg3 = TRUE;
            }
          }
        } else {
          mmip1 = 0;
          lastc = 0;
        }

        if (mmip1 > 0) {
          if (lastc == 0) {
          } else {
            yk = lastc - 1;
            for (iy = 1; iy <= yk + 1; iy++) {
              work->data[iy - 1] = 0.0;
            }

            iy = 0;
            i0 = i_ip1 + m * yk;
            yk = i_ip1;
            while ((m > 0) && (yk <= i0)) {
              ix = i_i;
              smax = 0.0;
              b_n = yk + mmip1;
              for (k = yk; k <= b_n - 1; k++) {
                smax += b_A->data[k - 1] * b_A->data[ix];
                ix++;
              }

              work->data[iy] += smax;
              iy++;
              yk += m;
            }
          }

          if (-tau->data[i] == 0.0) {
          } else {
            yk = i_ip1 - 1;
            b_n = 0;
            for (nmi = 1; nmi <= lastc; nmi++) {
              if (work->data[b_n] != 0.0) {
                smax = work->data[b_n] * -tau->data[i];
                ix = i_i;
                i0 = mmip1 + yk;
                for (k = yk; k + 1 <= i0; k++) {
                  b_A->data[k] += b_A->data[ix] * smax;
                  ix++;
                }
              }

              b_n++;
              yk += m;
            }
          }
        }

        b_A->data[i_i] = s;
      }

      for (nmi = i + 1; nmi + 1 <= n; nmi++) {
        if (vn1->data[nmi] != 0.0) {
          s = fabs(b_A->data[i + b_A->size[0] * nmi]) / vn1->data[nmi];
          y = s * s;
          s = 1.0 - s * s;
          if (1.0 - y < 0.0) {
            s = 0.0;
          }

          smax = vn1->data[nmi] / vn2->data[nmi];
          if (s * (smax * smax) <= 1.4901161193847656E-8) {
            if (i + 1 < m) {
              yk = (i + m * nmi) + 1;
              y = 0.0;
              if (mmi < 1) {
              } else if (mmi == 1) {
                y = fabs(b_A->data[yk]);
              } else {
                smax = 2.2250738585072014E-308;
                b_n = yk + mmi;
                while (yk + 1 <= b_n) {
                  s = fabs(b_A->data[yk]);
                  if (s > smax) {
                    t = smax / s;
                    y = 1.0 + y * t * t;
                    smax = s;
                  } else {
                    t = s / smax;
                    y += t * t;
                  }

                  yk++;
                }

                y = smax * sqrt(y);
              }

              vn1->data[nmi] = y;
              vn2->data[nmi] = vn1->data[nmi];
            } else {
              vn1->data[nmi] = 0.0;
              vn2->data[nmi] = 0.0;
            }
          } else {
            vn1->data[nmi] *= sqrt(s);
          }
        }
      }
    }

    emxFree_real_T(&vn2);
    emxFree_real_T(&vn1);
    emxFree_real_T(&work);
  }

  *rankR = 0.0;
  if (mn + 1 > 0) {
    k = 0;
    exitg1 = FALSE;
    while ((exitg1 == 0U) && (k <= mn)) {
      smax = (real_T)A->size[0];
      s = (real_T)A->size[1];
      if (smax >= s) {
        s = smax;
      }

      if (fabs(b_A->data[k + b_A->size[0] * k]) <= s * fabs(b_A->data[0]) *
          2.2204460492503131E-16) {
        exitg1 = TRUE;
      } else {
        (*rankR)++;
        k++;
      }
    }
  }

  unnamed_idx_0 = (uint32_T)A->size[1];
  i0 = Y->size[0];
  Y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)Y, i0, (int32_T)sizeof(real_T));
  yk = (int32_T)unnamed_idx_0 - 1;
  for (i0 = 0; i0 <= yk; i0++) {
    Y->data[i0] = 0.0;
  }

  for (nmi = 0; nmi <= mn; nmi++) {
    if (tau->data[nmi] != 0.0) {
      smax = B->data[nmi];
      i0 = A->size[0] + (int32_T)(1.0 - ((1.0 + (real_T)nmi) + 1.0));
      for (i = 0; i <= i0 - 1; i++) {
        unnamed_idx_0 = ((uint32_T)nmi + (uint32_T)i) + 2U;
        smax += b_A->data[((int32_T)unnamed_idx_0 + b_A->size[0] * nmi) - 1] *
          B->data[(int32_T)unnamed_idx_0 - 1];
      }

      smax *= tau->data[nmi];
      if (smax != 0.0) {
        B->data[nmi] -= smax;
        i0 = A->size[0] + (int32_T)(1.0 - ((1.0 + (real_T)nmi) + 1.0));
        for (i = 0; i <= i0 - 1; i++) {
          unnamed_idx_0 = ((uint32_T)nmi + (uint32_T)i) + 2U;
          B->data[(int32_T)unnamed_idx_0 - 1] -= b_A->data[((int32_T)
            unnamed_idx_0 + b_A->size[0] * nmi) - 1] * smax;
        }
      }
    }
  }

  emxFree_real_T(&tau);
  for (i = 0; i <= mn; i++) {
    Y->data[jpvt->data[i] - 1] = B->data[i];
  }

  for (nmi = 0; nmi <= mn; nmi++) {
    yk = mn - nmi;
    Y->data[jpvt->data[yk] - 1] /= b_A->data[yk + b_A->size[0] * yk];
    for (i = 0; i <= yk - 1; i++) {
      Y->data[jpvt->data[i] - 1] -= Y->data[jpvt->data[yk] - 1] * b_A->data[i +
        b_A->size[0] * yk];
    }
  }

  emxFree_int32_T(&jpvt);
  emxFree_real_T(&b_A);
}

static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = fabs(x->data[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x->data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  emxArray_real_T *b_x;
  int32_T i1;
  int32_T k;
  emxInit_real_T(&b_x, 2);
  i1 = (ix0 + n) - 1;
  for (k = ix0; k <= i1; k++) {
    x->data[k - 1] *= a;
  }

  emxFree_real_T(&b_x);
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

void polyfit(const emxArray_real_T *x, const emxArray_real_T *y, real_T n,
             emxArray_real_T *p)
{
  emxArray_real_T *V;
  int32_T unnamed_idx_0;
  int32_T j;
  real_T b_j;
  emxArray_real_T *b_y;
  emxArray_real_T *p1;
  real_T rr;
  emxInit_real_T(&V, 2);
  unnamed_idx_0 = x->size[1];
  j = V->size[0] * V->size[1];
  V->size[0] = unnamed_idx_0;
  V->size[1] = (int32_T)(n + 1.0);
  emxEnsureCapacity((emxArray__common *)V, j, (int32_T)sizeof(real_T));
  if ((V->size[0] == 0) || (V->size[1] == 0)) {
  } else {
    for (unnamed_idx_0 = 0; unnamed_idx_0 <= x->size[1] - 1; unnamed_idx_0++) {
      V->data[unnamed_idx_0 + V->size[0] * ((int32_T)(n + 1.0) - 1)] = 1.0;
    }

    if (n < 1.0) {
    } else {
      for (unnamed_idx_0 = 0; unnamed_idx_0 <= x->size[1] - 1; unnamed_idx_0++)
      {
        V->data[unnamed_idx_0 + V->size[0] * ((int32_T)n - 1)] = x->
          data[unnamed_idx_0];
      }

      for (j = 0; j <= (int32_T)-(1.0 + (-1.0 - (n - 1.0))) - 1; j++) {
        b_j = (n - 1.0) + -(real_T)j;
        for (unnamed_idx_0 = 0; unnamed_idx_0 <= x->size[1] - 1; unnamed_idx_0++)
        {
          V->data[unnamed_idx_0 + V->size[0] * ((int32_T)b_j - 1)] = x->
            data[unnamed_idx_0] * V->data[unnamed_idx_0 + V->size[0] * ((int32_T)
            (b_j + 1.0) - 1)];
        }
      }
    }
  }

  b_emxInit_real_T(&b_y, 1);
  j = b_y->size[0];
  b_y->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)b_y, j, (int32_T)sizeof(real_T));
  unnamed_idx_0 = y->size[1] - 1;
  for (j = 0; j <= unnamed_idx_0; j++) {
    b_y->data[j] = y->data[j];
  }

  b_emxInit_real_T(&p1, 1);
  eml_qrsolve(V, b_y, p1, &rr);
  emxFree_real_T(&b_y);
  emxFree_real_T(&V);
  j = p->size[0] * p->size[1];
  p->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)p, j, (int32_T)sizeof(real_T));
  unnamed_idx_0 = p1->size[0];
  j = p->size[0] * p->size[1];
  p->size[1] = unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)p, j, (int32_T)sizeof(real_T));
  unnamed_idx_0 = p1->size[0] - 1;
  for (j = 0; j <= unnamed_idx_0; j++) {
    p->data[j] = p1->data[j];
  }

  emxFree_real_T(&p1);
}

/* End of code generation (polyfit.cpp) */
