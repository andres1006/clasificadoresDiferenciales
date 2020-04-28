/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "sort1.h"
#include "sortIdx.h"

/* Function Definitions */
void sort(double x_data[], int x_size[1], int idx_data[], int idx_size[1])
{
  int dim;
  int i2;
  int vwork_size[1];
  int vstride;
  int k;
  double vwork_data[43];
  int iidx_data[43];
  int iidx_size[1];
  dim = 2;
  if (x_size[0] != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    i2 = x_size[0];
  } else {
    i2 = 1;
  }

  vwork_size[0] = (signed char)i2;
  idx_size[0] = (signed char)x_size[0];
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x_size[0];
    k = 2;
  }

  for (dim = 0; dim < vstride; dim++) {
    for (k = 0; k < i2; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }

    sortIdx(vwork_data, vwork_size, iidx_data, iidx_size);
    for (k = 0; k < i2; k++) {
      x_data[dim + k * vstride] = vwork_data[k];
      idx_data[dim + k * vstride] = iidx_data[k];
    }
  }
}

/* End of code generation (sort1.c) */
