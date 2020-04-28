/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactSVM.c
 *
 * Code generation for function 'CompactSVM'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EP_vs_PKS.h"
#include "CompactSVM.h"
#include "Clasificador_diferencial_EP_vs_PKS_emxutil.h"

/* Function Definitions */
void CompactSVM_normalize(const double obj_Mu[3], const double obj_Sigma[3],
  emxArray_real_T *X)
{
  emxArray_real_T *a;
  int i0;
  int csz_idx_0;
  int k;
  int bcoef;
  int szc;
  int acoef;
  int b_acoef;
  int tmp_data[3];
  emxArray_real_T *c;
  int b_tmp_data[3];
  int ia;
  int ib;
  int b_szc;
  emxInit_real_T(&a, 2);
  i0 = a->size[0] * a->size[1];
  a->size[0] = X->size[0];
  a->size[1] = 3;
  emxEnsureCapacity_real_T1(a, i0);
  csz_idx_0 = X->size[0] * X->size[1];
  for (i0 = 0; i0 < csz_idx_0; i0++) {
    a->data[i0] = X->data[i0];
  }

  csz_idx_0 = X->size[0];
  i0 = X->size[0] * X->size[1];
  X->size[0] = csz_idx_0;
  X->size[1] = 3;
  emxEnsureCapacity_real_T1(X, i0);
  if (X->size[0] != 0) {
    for (k = 0; k < 3; k++) {
      szc = X->size[0];
      acoef = (a->size[0] != 1);
      for (csz_idx_0 = 0; csz_idx_0 < szc; csz_idx_0++) {
        X->data[csz_idx_0 + X->size[0] * k] = a->data[acoef * csz_idx_0 +
          a->size[0] * k] - obj_Mu[k];
      }
    }
  }

  emxFree_real_T(&a);
  bcoef = 0;
  for (csz_idx_0 = 0; csz_idx_0 < 3; csz_idx_0++) {
    if (obj_Sigma[csz_idx_0] > 0.0) {
      bcoef++;
    }
  }

  b_acoef = 0;
  for (csz_idx_0 = 0; csz_idx_0 < 3; csz_idx_0++) {
    if (obj_Sigma[csz_idx_0] > 0.0) {
      tmp_data[b_acoef] = csz_idx_0 + 1;
      b_acoef++;
    }
  }

  i0 = X->size[0];
  if (bcoef == 1) {
    csz_idx_0 = 1;
  } else if (bcoef == 1) {
    csz_idx_0 = 1;
  } else {
    csz_idx_0 = bcoef;
  }

  emxInit_real_T(&c, 2);
  k = c->size[0] * c->size[1];
  c->size[0] = i0;
  c->size[1] = csz_idx_0;
  emxEnsureCapacity_real_T1(c, k);
  if (!((c->size[0] == 0) || (c->size[1] == 0))) {
    szc = c->size[1];
    acoef = (bcoef != 1);
    bcoef = (bcoef != 1);
    for (k = 0; k < szc; k++) {
      ia = acoef * k;
      ib = bcoef * k;
      b_szc = c->size[0];
      i0 = X->size[0];
      b_acoef = (i0 != 1);
      for (csz_idx_0 = 0; csz_idx_0 < b_szc; csz_idx_0++) {
        c->data[csz_idx_0 + c->size[0] * k] = X->data[b_acoef * csz_idx_0 +
          X->size[0] * (tmp_data[ia] - 1)] / obj_Sigma[tmp_data[ib] - 1];
      }
    }
  }

  b_acoef = 0;
  for (csz_idx_0 = 0; csz_idx_0 < 3; csz_idx_0++) {
    if (obj_Sigma[csz_idx_0] > 0.0) {
      b_tmp_data[b_acoef] = csz_idx_0 + 1;
      b_acoef++;
    }
  }

  csz_idx_0 = c->size[1];
  for (i0 = 0; i0 < csz_idx_0; i0++) {
    b_acoef = c->size[0];
    for (k = 0; k < b_acoef; k++) {
      X->data[k + X->size[0] * (b_tmp_data[i0] - 1)] = c->data[k + c->size[0] *
        i0];
    }
  }

  emxFree_real_T(&c);
}

/* End of code generation (CompactSVM.c) */
