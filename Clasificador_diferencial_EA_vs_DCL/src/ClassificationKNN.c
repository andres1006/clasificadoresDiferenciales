/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ClassificationKNN.c
 *
 * Code generation for function 'ClassificationKNN'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "ClassificationKNN.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxutil.h"
#include "knnsearch.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      absNumerator = ~(unsigned int)numerator + 1U;
    } else {
      absNumerator = (unsigned int)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(unsigned int)denominator + 1U;
    } else {
      absDenominator = (unsigned int)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int)absNumerator;
    } else {
      quotient = (int)absNumerator;
    }
  }

  return quotient;
}

static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = 1.0;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

void ClassificationKNN_score(const double obj_X[172], const unsigned int
  obj_YIdx[43], const double obj_W[43], const emxArray_real_T *X,
  emxArray_real_T *scores, emxArray_boolean_T *nonnanscoreindices)
{
  emxArray_real_T *count;
  int nx;
  int acoef;
  int sck;
  emxArray_real_T *cidx;
  emxArray_real_T *dist;
  int numNeighbors;
  int i;
  emxArray_boolean_T *b;
  boolean_T nonnanIndices[10];
  int vstride;
  emxArray_real_T *distWgt;
  emxArray_real_T *countT;
  boolean_T y;
  int ix;
  boolean_T exitg1;
  emxArray_real_T *wgt;
  emxArray_uint32_T *CNeighbor;
  emxArray_real_T *b_y;
  double wgtval;
  int siz_idx_0;
  emxArray_boolean_T *b_b;
  unsigned int sz[2];
  emxInit_real_T(&count, 2);
  nx = X->size[0];
  acoef = count->size[0] * count->size[1];
  count->size[0] = 2;
  count->size[1] = X->size[0];
  emxEnsureCapacity_real_T1(count, acoef);
  sck = X->size[0] << 1;
  for (acoef = 0; acoef < sck; acoef++) {
    count->data[acoef] = 0.0;
  }

  emxInit_real_T(&cidx, 2);
  emxInit_real_T(&dist, 2);
  knnsearch(obj_X, X, cidx, dist);
  numNeighbors = 0;
  for (i = 0; i < 10; i++) {
    nonnanIndices[i] = true;
  }

  emxInit_boolean_T(&b, 1);
  for (vstride = 0; vstride < 10; vstride++) {
    sck = dist->size[0];
    acoef = b->size[0];
    b->size[0] = sck;
    emxEnsureCapacity_boolean_T(b, acoef);
    for (acoef = 0; acoef < sck; acoef++) {
      b->data[acoef] = rtIsNaN(dist->data[acoef + dist->size[0] * vstride]);
    }

    y = true;
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= b->size[0])) {
      if (!b->data[ix - 1]) {
        y = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }

    if (!y) {
      numNeighbors++;
    } else {
      nonnanIndices[vstride] = false;
    }
  }

  emxFree_boolean_T(&b);
  if (numNeighbors > 0) {
    emxInit_real_T(&distWgt, 2);
    acoef = distWgt->size[0] * distWgt->size[1];
    distWgt->size[0] = X->size[0];
    distWgt->size[1] = numNeighbors;
    emxEnsureCapacity_real_T1(distWgt, acoef);
    for (i = 0; i < 10; i++) {
      if (nonnanIndices[i]) {
        for (vstride = 0; vstride < nx; vstride++) {
          if (dist->data[vstride + dist->size[0] * i] == 0.0) {
            wgtval = 1.0;
          } else {
            wgtval = 1.0 / rt_powd_snf(dist->data[vstride + dist->size[0] * i] /
              dist->data[vstride], 2.0);
          }

          distWgt->data[vstride + distWgt->size[0] * i] = wgtval;
        }
      }
    }

    emxInit_real_T(&wgt, 2);
    emxInit_uint32_T(&CNeighbor, 2);
    acoef = CNeighbor->size[0] * CNeighbor->size[1];
    CNeighbor->size[0] = 10;
    CNeighbor->size[1] = X->size[0];
    emxEnsureCapacity_uint32_T(CNeighbor, acoef);
    acoef = wgt->size[0] * wgt->size[1];
    wgt->size[0] = 10;
    wgt->size[1] = X->size[0];
    emxEnsureCapacity_real_T1(wgt, acoef);
    acoef = X->size[0] * numNeighbors;
    if (1 <= acoef) {
      siz_idx_0 = nx;
    }

    for (vstride = 0; vstride < acoef; vstride++) {
      sck = div_s32(vstride, siz_idx_0);
      sck += numNeighbors * (vstride - sck * siz_idx_0);
      CNeighbor->data[sck] = obj_YIdx[(int)cidx->data[vstride] - 1];
      wgtval = distWgt->data[vstride] * obj_W[(int)cidx->data[vstride] - 1];
      if (rtIsNaN(wgtval)) {
        wgt->data[sck] = 0.0;
      } else {
        wgt->data[sck] = wgtval;
      }
    }

    emxFree_real_T(&distWgt);
    for (sck = 0; sck < nx; sck++) {
      for (vstride = 0; vstride < 2; vstride++) {
        for (i = 0; i < 10; i++) {
          if (CNeighbor->data[i + CNeighbor->size[0] * sck] == (unsigned int)
              (vstride + 1)) {
            count->data[vstride + count->size[0] * sck] += wgt->data[i +
              wgt->size[0] * sck];
          }
        }
      }
    }

    emxFree_uint32_T(&CNeighbor);
    emxFree_real_T(&wgt);
  }

  emxFree_real_T(&dist);
  emxFree_real_T(&cidx);
  emxInit_real_T(&countT, 2);
  acoef = countT->size[0] * countT->size[1];
  countT->size[0] = count->size[1];
  countT->size[1] = 2;
  emxEnsureCapacity_real_T1(countT, acoef);
  for (acoef = 0; acoef < 2; acoef++) {
    sck = count->size[1];
    for (i = 0; i < sck; i++) {
      countT->data[i + countT->size[0] * acoef] = count->data[acoef +
        count->size[0] * i];
    }
  }

  emxFree_real_T(&count);
  emxInit_real_T1(&b_y, 1);
  if (countT->size[0] == 0) {
    acoef = b_y->size[0];
    b_y->size[0] = 0;
    emxEnsureCapacity_real_T(b_y, acoef);
  } else {
    vstride = countT->size[0];
    acoef = b_y->size[0];
    b_y->size[0] = countT->size[0];
    emxEnsureCapacity_real_T(b_y, acoef);
    for (sck = 0; sck < vstride; sck++) {
      b_y->data[sck] = countT->data[sck];
    }

    for (sck = 0; sck < vstride; sck++) {
      b_y->data[sck] += countT->data[vstride + sck];
    }
  }

  sck = b_y->size[0];
  i = countT->size[0];
  if (sck < i) {
    i = sck;
  }

  if (b_y->size[0] == 1) {
    sck = countT->size[0];
  } else if (countT->size[0] == 1) {
    sck = b_y->size[0];
  } else if (countT->size[0] == b_y->size[0]) {
    sck = countT->size[0];
  } else {
    sck = i;
  }

  acoef = scores->size[0] * scores->size[1];
  scores->size[0] = sck;
  scores->size[1] = 2;
  emxEnsureCapacity_real_T1(scores, acoef);
  if (scores->size[0] != 0) {
    for (sck = 0; sck < 2; sck++) {
      i = scores->size[0];
      acoef = (countT->size[0] != 1);
      numNeighbors = (b_y->size[0] != 1);
      for (vstride = 0; vstride < i; vstride++) {
        scores->data[vstride + scores->size[0] * sck] = countT->data[acoef *
          vstride + countT->size[0] * sck] / b_y->data[numNeighbors * vstride];
      }
    }
  }

  emxFree_real_T(&b_y);
  emxFree_real_T(&countT);
  emxInit_boolean_T1(&b_b, 2);
  acoef = b_b->size[0] * b_b->size[1];
  b_b->size[0] = scores->size[0];
  b_b->size[1] = 2;
  emxEnsureCapacity_boolean_T1(b_b, acoef);
  sck = scores->size[0] * scores->size[1];
  for (acoef = 0; acoef < sck; acoef++) {
    b_b->data[acoef] = rtIsNaN(scores->data[acoef]);
  }

  for (acoef = 0; acoef < 2; acoef++) {
    sz[acoef] = (unsigned int)b_b->size[acoef];
  }

  acoef = nonnanscoreindices->size[0];
  nonnanscoreindices->size[0] = (int)sz[0];
  emxEnsureCapacity_boolean_T(nonnanscoreindices, acoef);
  sck = (int)sz[0];
  for (acoef = 0; acoef < sck; acoef++) {
    nonnanscoreindices->data[acoef] = true;
  }

  vstride = b_b->size[0];
  i = -1;
  acoef = 0;
  numNeighbors = b_b->size[0];
  for (sck = 1; sck <= vstride; sck++) {
    acoef++;
    numNeighbors++;
    i++;
    ix = acoef;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= numNeighbors))) {
      if (!b_b->data[ix - 1]) {
        nonnanscoreindices->data[i] = false;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }

  emxFree_boolean_T(&b_b);
  acoef = nonnanscoreindices->size[0];
  emxEnsureCapacity_boolean_T(nonnanscoreindices, acoef);
  sck = nonnanscoreindices->size[0];
  for (acoef = 0; acoef < sck; acoef++) {
    nonnanscoreindices->data[acoef] = !nonnanscoreindices->data[acoef];
  }
}

/* End of code generation (ClassificationKNN.c) */
