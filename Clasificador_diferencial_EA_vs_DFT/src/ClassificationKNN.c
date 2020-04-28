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
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DFT.h"
#include "ClassificationKNN.h"
#include "Clasificador_diferencial_EA_vs_DFT_emxutil.h"
#include "knnsearch.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);

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

void ClassificationKNN_score(const double obj_X[216], const unsigned int
  obj_YIdx[36], const emxArray_real_T *X, emxArray_real_T *scores,
  emxArray_boolean_T *nonnanscoreindices)
{
  emxArray_real_T *count;
  int nx;
  int acoef;
  int szc;
  emxArray_real_T *cidx;
  emxArray_real_T *dist;
  emxArray_boolean_T *b;
  boolean_T y;
  int ix;
  boolean_T exitg1;
  emxArray_int8_T *distWgt;
  emxArray_real_T *countT;
  emxArray_real_T *b_y;
  int sck;
  emxArray_real_T *wgt;
  emxArray_uint32_T *CNeighbor;
  int bcoef;
  double wgtval;
  emxArray_boolean_T *b_b;
  unsigned int sz[2];
  emxInit_real_T(&count, 2);
  nx = X->size[0];
  acoef = count->size[0] * count->size[1];
  count->size[0] = 2;
  count->size[1] = X->size[0];
  emxEnsureCapacity_real_T1(count, acoef);
  szc = X->size[0] << 1;
  for (acoef = 0; acoef < szc; acoef++) {
    count->data[acoef] = 0.0;
  }

  emxInit_real_T(&cidx, 2);
  emxInit_real_T(&dist, 2);
  emxInit_boolean_T(&b, 1);
  knnsearch(obj_X, X, cidx, dist);
  szc = dist->size[0];
  acoef = b->size[0];
  b->size[0] = szc;
  emxEnsureCapacity_boolean_T(b, acoef);
  for (acoef = 0; acoef < szc; acoef++) {
    b->data[acoef] = rtIsNaN(dist->data[acoef]);
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

  emxFree_boolean_T(&b);
  if (!y) {
    emxInit_int8_T(&distWgt, 2);
    acoef = distWgt->size[0] * distWgt->size[1];
    distWgt->size[0] = X->size[0];
    distWgt->size[1] = 1;
    emxEnsureCapacity_int8_T(distWgt, acoef);
    szc = X->size[0];
    for (acoef = 0; acoef < szc; acoef++) {
      distWgt->data[acoef] = 1;
    }

    for (acoef = 0; acoef < nx; acoef++) {
      if (rtIsNaN(dist->data[acoef])) {
        distWgt->data[acoef] = 0;
      }
    }

    emxInit_real_T(&wgt, 2);
    emxInit_uint32_T(&CNeighbor, 2);
    acoef = CNeighbor->size[0] * CNeighbor->size[1];
    CNeighbor->size[0] = 1;
    CNeighbor->size[1] = X->size[0];
    emxEnsureCapacity_uint32_T(CNeighbor, acoef);
    acoef = wgt->size[0] * wgt->size[1];
    wgt->size[0] = 1;
    wgt->size[1] = X->size[0];
    emxEnsureCapacity_real_T1(wgt, acoef);
    if (1 <= nx) {
      bcoef = nx;
    }

    for (acoef = 0; acoef < nx; acoef++) {
      sck = div_s32(acoef, bcoef);
      sck = (sck + acoef) - sck * bcoef;
      CNeighbor->data[sck] = obj_YIdx[(int)cidx->data[acoef] - 1];
      wgtval = (double)distWgt->data[acoef] * 0.027777777777777776;
      wgt->data[sck] = wgtval;
    }

    emxFree_int8_T(&distWgt);
    for (szc = 0; szc < nx; szc++) {
      for (acoef = 0; acoef < 2; acoef++) {
        if (CNeighbor->data[CNeighbor->size[0] * szc] == (unsigned int)(acoef +
             1)) {
          count->data[acoef + count->size[0] * szc] += wgt->data[wgt->size[0] *
            szc];
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
    szc = count->size[1];
    for (sck = 0; sck < szc; sck++) {
      countT->data[sck + countT->size[0] * acoef] = count->data[acoef +
        count->size[0] * sck];
    }
  }

  emxFree_real_T(&count);
  emxInit_real_T1(&b_y, 1);
  if (countT->size[0] == 0) {
    acoef = b_y->size[0];
    b_y->size[0] = 0;
    emxEnsureCapacity_real_T(b_y, acoef);
  } else {
    nx = countT->size[0];
    acoef = b_y->size[0];
    b_y->size[0] = countT->size[0];
    emxEnsureCapacity_real_T(b_y, acoef);
    for (sck = 0; sck < nx; sck++) {
      b_y->data[sck] = countT->data[sck];
    }

    for (sck = 0; sck < nx; sck++) {
      b_y->data[sck] += countT->data[nx + sck];
    }
  }

  sck = b_y->size[0];
  szc = countT->size[0];
  if (sck < szc) {
    szc = sck;
  }

  if (b_y->size[0] == 1) {
    sck = countT->size[0];
  } else if (countT->size[0] == 1) {
    sck = b_y->size[0];
  } else if (countT->size[0] == b_y->size[0]) {
    sck = countT->size[0];
  } else {
    sck = szc;
  }

  acoef = scores->size[0] * scores->size[1];
  scores->size[0] = sck;
  scores->size[1] = 2;
  emxEnsureCapacity_real_T1(scores, acoef);
  if (scores->size[0] != 0) {
    for (sck = 0; sck < 2; sck++) {
      szc = scores->size[0];
      acoef = (countT->size[0] != 1);
      bcoef = (b_y->size[0] != 1);
      for (nx = 0; nx < szc; nx++) {
        scores->data[nx + scores->size[0] * sck] = countT->data[acoef * nx +
          countT->size[0] * sck] / b_y->data[bcoef * nx];
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
  szc = scores->size[0] * scores->size[1];
  for (acoef = 0; acoef < szc; acoef++) {
    b_b->data[acoef] = rtIsNaN(scores->data[acoef]);
  }

  for (acoef = 0; acoef < 2; acoef++) {
    sz[acoef] = (unsigned int)b_b->size[acoef];
  }

  acoef = nonnanscoreindices->size[0];
  nonnanscoreindices->size[0] = (int)sz[0];
  emxEnsureCapacity_boolean_T(nonnanscoreindices, acoef);
  szc = (int)sz[0];
  for (acoef = 0; acoef < szc; acoef++) {
    nonnanscoreindices->data[acoef] = true;
  }

  nx = b_b->size[0];
  szc = -1;
  acoef = 0;
  bcoef = b_b->size[0];
  for (sck = 1; sck <= nx; sck++) {
    acoef++;
    bcoef++;
    szc++;
    ix = acoef;
    exitg1 = false;
    while ((!exitg1) && ((nx > 0) && (ix <= bcoef))) {
      if (!b_b->data[ix - 1]) {
        nonnanscoreindices->data[szc] = false;
        exitg1 = true;
      } else {
        ix += nx;
      }
    }
  }

  emxFree_boolean_T(&b_b);
  acoef = nonnanscoreindices->size[0];
  emxEnsureCapacity_boolean_T(nonnanscoreindices, acoef);
  szc = nonnanscoreindices->size[0];
  for (acoef = 0; acoef < szc; acoef++) {
    nonnanscoreindices->data[acoef] = !nonnanscoreindices->data[acoef];
  }
}

/* End of code generation (ClassificationKNN.c) */
