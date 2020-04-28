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
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "repmat.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxutil.h"

/* Function Definitions */
void b_repmat(const double a_data[], const int a_size[2], double varargin_1,
              emxArray_real_T *b)
{
  int jcol;
  int ibmat;
  int itilerow;
  jcol = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = a_size[1];
  emxEnsureCapacity_real_T1(b, jcol);
  for (jcol = 0; jcol < a_size[1]; jcol++) {
    ibmat = jcol * (int)varargin_1;
    for (itilerow = 1; itilerow <= (int)varargin_1; itilerow++) {
      b->data[(ibmat + itilerow) - 1] = a_data[jcol];
    }
  }
}

void repmat(const double a_data[], const int a_size[2], const double varargin_1
            [2], emxArray_real_T *b)
{
  int ntilerows;
  int jcol;
  int ibmat;
  int itilerow;
  ntilerows = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1[0];
  b->size[1] = a_size[1];
  emxEnsureCapacity_real_T1(b, ntilerows);
  ntilerows = (int)varargin_1[0];
  for (jcol = 0; jcol < a_size[1]; jcol++) {
    ibmat = jcol * ntilerows;
    for (itilerow = 1; itilerow <= ntilerows; itilerow++) {
      b->data[(ibmat + itilerow) - 1] = a_data[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
