/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "repmat.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"

/* Function Definitions */
void b_repmat(double a, double varargin_1, emxArray_real_T *b)
{
  int i4;
  int loop_ub;
  i4 = b->size[0];
  b->size[0] = (int)varargin_1;
  emxEnsureCapacity_real_T(b, i4);
  loop_ub = (int)varargin_1;
  for (i4 = 0; i4 < loop_ub; i4++) {
    b->data[i4] = a;
  }
}

void c_repmat(const emxArray_boolean_T *a, emxArray_boolean_T *b)
{
  int outsize_idx_0;
  int jtilecol;
  int ibtile;
  int k;
  outsize_idx_0 = a->size[0];
  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = 2;
  emxEnsureCapacity_boolean_T(b, jtilecol);
  outsize_idx_0 = a->size[0];
  for (jtilecol = 0; jtilecol < 2; jtilecol++) {
    ibtile = jtilecol * outsize_idx_0;
    for (k = 1; k <= outsize_idx_0; k++) {
      b->data[(ibtile + k) - 1] = true;
    }
  }
}

void repmat(double a, int varargin_1, emxArray_real_T *b)
{
  int i3;
  i3 = b->size[0];
  b->size[0] = varargin_1;
  emxEnsureCapacity_real_T(b, i3);
  for (i3 = 0; i3 < varargin_1; i3++) {
    b->data[i3] = a;
  }
}

/* End of code generation (repmat.c) */
