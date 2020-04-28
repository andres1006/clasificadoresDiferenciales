/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "bsxfun.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxutil.h"

/* Function Definitions */
void bsxfun(const emxArray_real_T *a, const double b[4], emxArray_real_T *c)
{
  int csz_idx_0;
  int k;
  int szc;
  int b_k;
  csz_idx_0 = a->size[0];
  k = c->size[0] * c->size[1];
  c->size[0] = csz_idx_0;
  c->size[1] = 4;
  emxEnsureCapacity_real_T1(c, k);
  if (c->size[0] != 0) {
    csz_idx_0 = (a->size[0] != 1);
    for (k = 0; k < 4; k++) {
      szc = c->size[0];
      for (b_k = 0; b_k < szc; b_k++) {
        c->data[b_k + c->size[0] * k] = a->data[csz_idx_0 * b_k + a->size[0] * k]
          - b[k];
      }
    }
  }
}

/* End of code generation (bsxfun.c) */
