/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * knnsearch.c
 *
 * Code generation for function 'knnsearch'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DFT.h"
#include "knnsearch.h"
#include "Clasificador_diferencial_EA_vs_DFT_emxutil.h"
#include "kdsearchfun.h"
#include "repmat.h"
#include "any.h"
#include "sum.h"
#include "createkds.h"

/* Function Definitions */
void knnsearch(const double X[216], const emxArray_real_T *Y, emxArray_real_T
               *Idx, emxArray_real_T *D)
{
  b_struct_T expl_temp;
  double cgstruct_X[216];
  int iy;
  double cgstruct_wasnanIdx_data[36];
  unsigned int cgstruct_idxAll[36];
  emxArray_boolean_T *b;
  double cgstruct_idxDim_data[1];
  int i0;
  emxArray_boolean_T *wasNaNY;
  unsigned int outsize[2];
  int vstride;
  int i1;
  int i2;
  int j;
  int numNN;
  int ix;
  boolean_T exitg1;
  boolean_T b0;
  emxArray_real_T *r0;
  double b_cgstruct_wasnanIdx_data[1];
  double b_Y[2];
  int noNanCol_data[36];
  double x;
  double nanUpLim;
  double c_Y[6];
  int t2_D_size[1];
  unsigned int t2_I_data[1];
  int t2_I_size[1];
  double distTemp_data[1];
  emxArray_int32_T *r1;
  int tmp_data[36];
  int tmp_size[2];
  emxArray_real_T *r2;
  createkds(X, &expl_temp);
  memcpy(&cgstruct_X[0], &expl_temp.X[0], 216U * sizeof(double));
  iy = expl_temp.wasnanIdx.size[0] * expl_temp.wasnanIdx.size[1];
  if (0 <= iy - 1) {
    memcpy(&cgstruct_wasnanIdx_data[0], &expl_temp.wasnanIdx.data[0], (unsigned
            int)(iy * (int)sizeof(double)));
  }

  memcpy(&cgstruct_idxAll[0], &expl_temp.idxAll[0], 36U * sizeof(unsigned int));
  emxInit_boolean_T1(&b, 2);
  cgstruct_idxDim_data[0] = expl_temp.idxDim.data[0];
  i0 = b->size[0] * b->size[1];
  b->size[0] = Y->size[0];
  b->size[1] = 6;
  emxEnsureCapacity_boolean_T1(b, i0);
  iy = Y->size[0] * Y->size[1];
  for (i0 = 0; i0 < iy; i0++) {
    b->data[i0] = rtIsNaN(Y->data[i0]);
  }

  for (i0 = 0; i0 < 2; i0++) {
    outsize[i0] = (unsigned int)b->size[i0];
  }

  emxInit_boolean_T(&wasNaNY, 1);
  i0 = wasNaNY->size[0];
  wasNaNY->size[0] = (int)outsize[0];
  emxEnsureCapacity_boolean_T(wasNaNY, i0);
  iy = (int)outsize[0];
  for (i0 = 0; i0 < iy; i0++) {
    wasNaNY->data[i0] = false;
  }

  vstride = b->size[0];
  iy = -1;
  i1 = 0;
  i2 = 5 * b->size[0];
  for (j = 1; j <= vstride; j++) {
    i1++;
    i2++;
    iy++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
      b0 = !b->data[ix - 1];
      if (!b0) {
        wasNaNY->data[iy] = true;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }

  emxFree_boolean_T(&b);
  if (Y->size[0] == 0) {
    i0 = Idx->size[0] * Idx->size[1];
    Idx->size[0] = 0;
    Idx->size[1] = 1;
    emxEnsureCapacity_real_T1(Idx, i0);
    i0 = D->size[0] * D->size[1];
    D->size[0] = 0;
    D->size[1] = 1;
    emxEnsureCapacity_real_T1(D, i0);
  } else {
    if (1.0 > expl_temp.nx_nonan) {
      numNN = (int)expl_temp.nx_nonan;
    } else {
      numNN = 1;
    }

    if (numNN > 0) {
      i0 = Idx->size[0] * Idx->size[1];
      Idx->size[0] = Y->size[0];
      Idx->size[1] = 1;
      emxEnsureCapacity_real_T1(Idx, i0);
      iy = Y->size[0];
      for (i0 = 0; i0 < iy; i0++) {
        Idx->data[i0] = 0.0;
      }

      i0 = D->size[0] * D->size[1];
      D->size[0] = Y->size[0];
      D->size[1] = 1;
      emxEnsureCapacity_real_T1(D, i0);
      iy = Y->size[0];
      for (i0 = 0; i0 < iy; i0++) {
        D->data[i0] = 0.0;
      }

      noNanCol_data[0] = 1;
      vstride = 1;
      for (iy = 2; iy <= numNN; iy++) {
        vstride++;
        noNanCol_data[iy - 1] = vstride;
      }

      for (j = 0; j < Y->size[0]; j++) {
        if (wasNaNY->data[j]) {
          for (i0 = 0; i0 < numNN; i0++) {
            D->data[j + D->size[0] * (noNanCol_data[i0] - 1)] = rtNaN;
          }

          for (i0 = 0; i0 < numNN; i0++) {
            Idx->data[j + Idx->size[0] * (noNanCol_data[i0] - 1)] =
              noNanCol_data[i0];
          }
        } else {
          for (i0 = 0; i0 < 6; i0++) {
            c_Y[i0] = Y->data[j + Y->size[0] * i0];
          }

          search_kdtree(cgstruct_idxAll, cgstruct_idxDim_data, cgstruct_X, c_Y,
                        numNN, b_cgstruct_wasnanIdx_data, t2_D_size, t2_I_data,
                        t2_I_size);
          iy = t2_D_size[0];
          if (0 <= iy - 1) {
            memcpy(&distTemp_data[0], &b_cgstruct_wasnanIdx_data[0], (unsigned
                    int)(iy * (int)sizeof(double)));
          }

          iy = 1;
          while (iy <= t2_D_size[0]) {
            distTemp_data[0] = sqrt(distTemp_data[0]);
            iy = 2;
          }

          for (i0 = 0; i0 < numNN; i0++) {
            tmp_data[i0] = noNanCol_data[i0] - 1;
          }

          b_cgstruct_wasnanIdx_data[0] = distTemp_data[0];
          for (i0 = 0; i0 < numNN; i0++) {
            D->data[j + D->size[0] * tmp_data[i0]] =
              b_cgstruct_wasnanIdx_data[i0];
          }

          for (i0 = 0; i0 < numNN; i0++) {
            tmp_data[i0] = noNanCol_data[i0] - 1;
          }

          for (i0 = 0; i0 < numNN; i0++) {
            Idx->data[j + Idx->size[0] * tmp_data[i0]] = t2_I_data[i0];
          }
        }
      }
    } else {
      i0 = Idx->size[0] * Idx->size[1];
      Idx->size[0] = Y->size[0];
      Idx->size[1] = 0;
      emxEnsureCapacity_real_T1(Idx, i0);
      i0 = D->size[0] * D->size[1];
      D->size[0] = Y->size[0];
      D->size[1] = 0;
      emxEnsureCapacity_real_T1(D, i0);
    }

    if (1 - numNN > 0) {
      emxInit_real_T(&r0, 2);
      b_cgstruct_wasnanIdx_data[0] = cgstruct_wasnanIdx_data[0];
      b_Y[0] = Y->size[0];
      b_Y[1] = 1.0;
      repmat(b_cgstruct_wasnanIdx_data, b_Y, r0);
      iy = r0->size[0];
      for (i0 = 0; i0 < iy; i0++) {
        Idx->data[i0] = r0->data[i0];
      }

      emxFree_real_T(&r0);
      x = sum(wasNaNY);
      nanUpLim = Y->size[0];
      if (x < nanUpLim) {
        nanUpLim = x;
      }

      if (b_any(wasNaNY)) {
        if (numNN + 1 > 1) {
          i0 = 1;
          ix = 1;
        } else {
          i0 = numNN + 1;
          ix = 2;
        }

        i2 = wasNaNY->size[0] - 1;
        iy = 0;
        for (i1 = 0; i1 <= i2; i1++) {
          if (wasNaNY->data[i1]) {
            iy++;
          }
        }

        emxInit_int32_T(&r1, 1);
        vstride = r1->size[0];
        r1->size[0] = iy;
        emxEnsureCapacity_int32_T(r1, vstride);
        vstride = 0;
        for (i1 = 0; i1 <= i2; i1++) {
          if (wasNaNY->data[i1]) {
            r1->data[vstride] = i1 + 1;
            vstride++;
          }
        }

        tmp_size[0] = 1;
        tmp_size[1] = ix - i0;
        iy = ix - i0;
        for (ix = 0; ix < iy; ix++) {
          b_cgstruct_wasnanIdx_data[ix] = (signed char)(1 + (signed char)((i0 +
            ix) - 1));
        }

        emxInit_real_T(&r2, 2);
        b_repmat(b_cgstruct_wasnanIdx_data, tmp_size, nanUpLim, r2);
        iy = r2->size[1];
        for (i0 = 0; i0 < iy; i0++) {
          vstride = r2->size[0];
          for (ix = 0; ix < vstride; ix++) {
            Idx->data[(r1->data[ix] + Idx->size[0] * i0) - 1] = r2->data[ix +
              r2->size[0] * i0];
          }
        }

        emxFree_real_T(&r2);
        emxFree_int32_T(&r1);
      }

      for (i0 = 0; i0 < 2; i0++) {
        outsize[i0] = (unsigned int)D->size[i0];
      }

      if (numNN + 1 > 1) {
        iy = -1;
      } else {
        iy = 0;
      }

      for (i0 = 0; i0 <= iy; i0++) {
        vstride = (int)outsize[0];
        for (ix = 0; ix < vstride; ix++) {
          D->data[ix + D->size[0] * i0] = rtNaN;
        }
      }
    }
  }

  emxFree_boolean_T(&wasNaNY);
}

/* End of code generation (knnsearch.c) */
