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
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "knnsearch.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxutil.h"
#include "kdsearchfun.h"
#include "repmat.h"
#include "any.h"
#include "sum.h"
#include "createkds.h"

/* Function Definitions */
void knnsearch(const double X[172], const emxArray_real_T *Y, emxArray_real_T
               *Idx, emxArray_real_T *D)
{
  b_struct_T expl_temp;
  double cgstruct_X[172];
  int iy;
  double cgstruct_wasnanIdx_data[43];
  unsigned int cgstruct_idxAll[43];
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
  int cgstruct_wasnanIdx_size[2];
  int noNanCol_data[43];
  double b_cgstruct_wasnanIdx_data[10];
  emxArray_real_T *r0;
  double b_Y[2];
  double x;
  double c_Y[4];
  int t2_D_size[1];
  unsigned int t2_I_data[10];
  int t2_I_size[1];
  double nanUpLim;
  double distTemp_data[10];
  int tmp_data[43];
  emxArray_int32_T *r1;
  unsigned int b_t2_I_data[10];
  int tmp_size[2];
  createkds(X, &expl_temp);
  memcpy(&cgstruct_X[0], &expl_temp.X[0], 172U * sizeof(double));
  iy = expl_temp.wasnanIdx.size[0] * expl_temp.wasnanIdx.size[1];
  if (0 <= iy - 1) {
    memcpy(&cgstruct_wasnanIdx_data[0], &expl_temp.wasnanIdx.data[0], (unsigned
            int)(iy * (int)sizeof(double)));
  }

  memcpy(&cgstruct_idxAll[0], &expl_temp.idxAll[0], 43U * sizeof(unsigned int));
  emxInit_boolean_T1(&b, 2);
  cgstruct_idxDim_data[0] = expl_temp.idxDim.data[0];
  i0 = b->size[0] * b->size[1];
  b->size[0] = Y->size[0];
  b->size[1] = 4;
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
  i2 = 3 * b->size[0];
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
    Idx->size[1] = 10;
    emxEnsureCapacity_real_T1(Idx, i0);
    i0 = D->size[0] * D->size[1];
    D->size[0] = 0;
    D->size[1] = 10;
    emxEnsureCapacity_real_T1(D, i0);
  } else {
    if (10.0 > expl_temp.nx_nonan) {
      numNN = (int)expl_temp.nx_nonan;
    } else {
      numNN = 10;
    }

    if (numNN > 0) {
      i0 = Idx->size[0] * Idx->size[1];
      Idx->size[0] = Y->size[0];
      Idx->size[1] = 10;
      emxEnsureCapacity_real_T1(Idx, i0);
      iy = Y->size[0] * 10;
      for (i0 = 0; i0 < iy; i0++) {
        Idx->data[i0] = 0.0;
      }

      i0 = D->size[0] * D->size[1];
      D->size[0] = Y->size[0];
      D->size[1] = 10;
      emxEnsureCapacity_real_T1(D, i0);
      iy = Y->size[0] * 10;
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
          for (i0 = 0; i0 < 4; i0++) {
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

          for (iy = 0; iy < t2_D_size[0]; iy++) {
            distTemp_data[iy] = sqrt(distTemp_data[iy]);
          }

          for (i0 = 0; i0 < numNN; i0++) {
            tmp_data[i0] = noNanCol_data[i0] - 1;
          }

          memcpy(&b_cgstruct_wasnanIdx_data[0], &distTemp_data[0], (unsigned int)
                 (numNN * (int)sizeof(double)));
          for (i0 = 0; i0 < numNN; i0++) {
            D->data[j + D->size[0] * tmp_data[i0]] =
              b_cgstruct_wasnanIdx_data[i0];
          }

          for (i0 = 0; i0 < numNN; i0++) {
            tmp_data[i0] = noNanCol_data[i0] - 1;
          }

          memcpy(&b_t2_I_data[0], &t2_I_data[0], (unsigned int)(numNN * (int)
                  sizeof(unsigned int)));
          for (i0 = 0; i0 < numNN; i0++) {
            Idx->data[j + Idx->size[0] * tmp_data[i0]] = b_t2_I_data[i0];
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

    if (10 - numNN > 0) {
      if (numNN + 1 > 10) {
        i0 = 1;
      } else {
        i0 = numNN + 1;
      }

      iy = 10 - numNN;
      cgstruct_wasnanIdx_size[0] = 1;
      cgstruct_wasnanIdx_size[1] = 10 - numNN;
      if (0 <= iy - 1) {
        memcpy(&b_cgstruct_wasnanIdx_data[0], &cgstruct_wasnanIdx_data[0],
               (unsigned int)(iy * (int)sizeof(double)));
      }

      emxInit_real_T(&r0, 2);
      b_Y[0] = Y->size[0];
      b_Y[1] = 1.0;
      repmat(b_cgstruct_wasnanIdx_data, cgstruct_wasnanIdx_size, b_Y, r0);
      iy = r0->size[1];
      for (ix = 0; ix < iy; ix++) {
        vstride = r0->size[0];
        for (j = 0; j < vstride; j++) {
          Idx->data[j + Idx->size[0] * ((i0 + ix) - 1)] = r0->data[j + r0->size
            [0] * ix];
        }
      }

      x = sum(wasNaNY);
      nanUpLim = Y->size[0];
      if (x < nanUpLim) {
        nanUpLim = x;
      }

      if (b_any(wasNaNY)) {
        if (numNN + 1 > 10) {
          i0 = 1;
          ix = 1;
          j = 1;
        } else {
          i0 = numNN + 1;
          ix = 11;
          j = numNN + 1;
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

        b_repmat(b_cgstruct_wasnanIdx_data, tmp_size, nanUpLim, r0);
        iy = r0->size[1];
        for (i0 = 0; i0 < iy; i0++) {
          vstride = r0->size[0];
          for (ix = 0; ix < vstride; ix++) {
            Idx->data[(r1->data[ix] + Idx->size[0] * ((j + i0) - 1)) - 1] =
              r0->data[ix + r0->size[0] * i0];
          }
        }

        emxFree_int32_T(&r1);
      }

      emxFree_real_T(&r0);
      for (i0 = 0; i0 < 2; i0++) {
        outsize[i0] = (unsigned int)D->size[i0];
      }

      if (numNN + 1 > 10) {
        i0 = 1;
        ix = 0;
        j = 1;
      } else {
        i0 = numNN + 1;
        ix = 10;
        j = numNN + 1;
      }

      iy = ix - i0;
      for (i0 = 0; i0 <= iy; i0++) {
        vstride = (int)outsize[0];
        for (ix = 0; ix < vstride; ix++) {
          D->data[ix + D->size[0] * ((j + i0) - 1)] = rtNaN;
        }
      }
    }
  }

  emxFree_boolean_T(&wasNaNY);
}

/* End of code generation (knnsearch.c) */
