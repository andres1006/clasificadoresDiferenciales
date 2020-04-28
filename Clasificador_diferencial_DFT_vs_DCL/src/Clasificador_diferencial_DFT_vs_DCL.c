/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_DFT_vs_DCL.c
 *
 * Code generation for function 'Clasificador_diferencial_DFT_vs_DCL'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"
#include "repmat.h"
#include "aggregatePredict.h"
#include "CompactEnsemble.h"

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

void Clasificador_diferencial_DFT_vs_DCL(const emxArray_real_T *x,
  emxArray_real_T *label)
{
  int vstride;
  c_classreg_learning_coder_class Mdl;
  emxArray_real_T *score;
  int iy;
  emxArray_boolean_T *r0;
  boolean_T bv0[30];
  emxArray_boolean_T *b;
  emxArray_boolean_T *notNaN;
  int outsize[2];
  int i1;
  int i2;
  int j;
  int ix;
  boolean_T exitg1;
  emxArray_real_T *classnum;

  /* PREDICTLABELSSVM Label new observations using trained SVM model Mdl */
  /*    predictLabelsSVM predicts the vector of labels label using  */
  /*    the saved SVM model Mdl and the predictor data x. */
  for (vstride = 0; vstride < 2; vstride++) {
    Mdl.ClassNames[vstride] = 5.0 + 4.0 * (double)vstride;
    Mdl.ClassNamesLength[vstride] = 1;
    Mdl.NonzeroProbClasses[vstride] = 5.0 + 4.0 * (double)vstride;
  }

  CompactEnsemble_CompactEnsemble(&Mdl);
  if (x->size[0] == 0) {
    vstride = label->size[0];
    label->size[0] = 0;
    emxEnsureCapacity_real_T(label, vstride);
  } else {
    emxInit_real_T(&score, 2);
    vstride = score->size[0] * score->size[1];
    score->size[0] = x->size[0];
    score->size[1] = 2;
    emxEnsureCapacity_real_T1(score, vstride);
    iy = x->size[0] << 1;
    for (vstride = 0; vstride < iy; vstride++) {
      score->data[vstride] = 0.0;
    }

    for (vstride = 0; vstride < 30; vstride++) {
      bv0[vstride] = true;
    }

    emxInit_boolean_T1(&r0, 2);
    vstride = r0->size[0] * r0->size[1];
    r0->size[0] = x->size[0];
    r0->size[1] = 30;
    emxEnsureCapacity_boolean_T(r0, vstride);
    iy = x->size[0] * 30;
    for (vstride = 0; vstride < iy; vstride++) {
      r0->data[vstride] = true;
    }

    emxInit_boolean_T1(&b, 2);
    aggregatePredict(x, score, Mdl.IsCached, Mdl.ClassNames,
                     Mdl.NonzeroProbClasses, bv0, r0);
    vstride = b->size[0] * b->size[1];
    b->size[0] = score->size[0];
    b->size[1] = 2;
    emxEnsureCapacity_boolean_T(b, vstride);
    iy = score->size[0] * score->size[1];
    emxFree_boolean_T(&r0);
    for (vstride = 0; vstride < iy; vstride++) {
      b->data[vstride] = rtIsNaN(score->data[vstride]);
    }

    for (vstride = 0; vstride < 2; vstride++) {
      outsize[vstride] = b->size[vstride];
    }

    emxInit_boolean_T(&notNaN, 1);
    vstride = notNaN->size[0];
    notNaN->size[0] = outsize[0];
    emxEnsureCapacity_boolean_T1(notNaN, vstride);
    iy = outsize[0];
    for (vstride = 0; vstride < iy; vstride++) {
      notNaN->data[vstride] = true;
    }

    vstride = b->size[0];
    iy = -1;
    i1 = 0;
    i2 = b->size[0];
    for (j = 1; j <= vstride; j++) {
      i1++;
      i2++;
      iy++;
      ix = i1;
      exitg1 = false;
      while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
        if (!b->data[ix - 1]) {
          notNaN->data[iy] = false;
          exitg1 = true;
        } else {
          ix += vstride;
        }
      }
    }

    emxFree_boolean_T(&b);
    vstride = notNaN->size[0];
    emxEnsureCapacity_boolean_T1(notNaN, vstride);
    iy = notNaN->size[0];
    for (vstride = 0; vstride < iy; vstride++) {
      notNaN->data[vstride] = !notNaN->data[vstride];
    }

    emxInit_real_T1(&classnum, 1);
    vstride = classnum->size[0];
    classnum->size[0] = score->size[0];
    emxEnsureCapacity_real_T(classnum, vstride);
    iy = score->size[0];
    for (vstride = 0; vstride < iy; vstride++) {
      classnum->data[vstride] = rtNaN;
    }

    for (vstride = 0; vstride < notNaN->size[0]; vstride++) {
      if (notNaN->data[vstride]) {
        if ((score->data[vstride] < score->data[vstride + score->size[0]]) ||
            (rtIsNaN(score->data[vstride]) && (!rtIsNaN(score->data[vstride +
               score->size[0]])))) {
          iy = 2;
        } else {
          iy = 1;
        }

        classnum->data[vstride] = iy;
      }
    }

    b_repmat(Mdl.ClassNames[1], score->size[0], label);
    vstride = 0;
    emxFree_real_T(&score);
    while (vstride + 1 <= notNaN->size[0]) {
      if (notNaN->data[vstride]) {
        label->data[vstride] = Mdl.ClassNames[(int)(unsigned int)rt_roundd_snf
          (classnum->data[vstride]) - 1];
      }

      vstride++;
    }

    emxFree_real_T(&classnum);
    emxFree_boolean_T(&notNaN);
  }
}

/* End of code generation (Clasificador_diferencial_DFT_vs_DCL.c) */
