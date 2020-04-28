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
#include "Clasificador_diferencial_EA_vs_DFT.h"
#include "repmat.h"
#include "Clasificador_diferencial_EA_vs_DFT_emxutil.h"

/* Function Definitions */
void b_repmat(const double a_data[], const int a_size[2], double varargin_1,
              emxArray_real_T *b)
{
  int jcol;
  jcol = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = a_size[1];
  emxEnsureCapacity_real_T1(b, jcol);
  jcol = 1;
  while (jcol <= a_size[1]) {
    for (jcol = 1; jcol <= (int)varargin_1; jcol++) {
      b->data[jcol - 1] = a_data[0];
    }

    jcol = 2;
  }
}

void repmat(const double a_data[], const double varargin_1[2], emxArray_real_T
            *b)
{
  int itilerow;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1[0];
  b->size[1] = 1;
  emxEnsureCapacity_real_T1(b, itilerow);
  for (itilerow = 1; itilerow <= (int)varargin_1[0]; itilerow++) {
    b->data[itilerow - 1] = a_data[0];
  }
}

/* End of code generation (repmat.c) */
