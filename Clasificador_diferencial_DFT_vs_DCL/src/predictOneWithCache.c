/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictOneWithCache.c
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "predictOneWithCache.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"
#include "updateCache.h"
#include "repmat.h"
#include "any.h"
#include "CompactClassificationTree.h"

/* Function Definitions */
void b_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[9], const double weak_learner_Children[18], const
  double weak_learner_ClassProb[18], const double weak_learner_CutPoint[9],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r16;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r17;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r18;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r19;
  int loc[2];
  emxArray_int32_T *r20;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r17, 1);
    i = r17->size[0];
    r17->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r17, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r17->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r17->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r17->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r17->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r17);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r19, 2);
    d_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r19);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r20, 1);
    i = r20->size[0];
    r20->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r20, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r20->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r19->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r20->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r19->data[exponent + r19->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r20);
    emxFree_real_T(&r19);
  }

  emxInit_int32_T(&r16, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r16->size[0];
    r16->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r16, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r16->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r16->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r16->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r18, 2);
      c_repmat(useObsForLearner, r18);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r18->data[i]) {
          trueCount++;
        }
      }

      i = r16->size[0];
      r16->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r16, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r18->data[i]) {
          r16->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r18);
      loop_ub = r16->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r16->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r16);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void c_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[13], const double weak_learner_Children[26], const
  double weak_learner_ClassProb[26], const double weak_learner_CutPoint[13],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r21;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r22;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r23;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r24;
  int loc[2];
  emxArray_int32_T *r25;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r22, 1);
    i = r22->size[0];
    r22->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r22, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r22->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r22->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r22->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r22->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r22);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r24, 2);
    e_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r24);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r25, 1);
    i = r25->size[0];
    r25->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r25, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r25->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r24->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r25->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r24->data[exponent + r24->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r25);
    emxFree_real_T(&r24);
  }

  emxInit_int32_T(&r21, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r21->size[0];
    r21->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r21, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r21->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r21->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r21->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r23, 2);
      c_repmat(useObsForLearner, r23);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r23->data[i]) {
          trueCount++;
        }
      }

      i = r21->size[0];
      r21->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r21, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r23->data[i]) {
          r21->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r23);
      loop_ub = r21->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r21->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r21);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void d_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[7], const double weak_learner_Children[14], const
  double weak_learner_ClassProb[14], const double weak_learner_CutPoint[7],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r26;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r27;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r28;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r29;
  int loc[2];
  emxArray_int32_T *r30;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r27, 1);
    i = r27->size[0];
    r27->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r27, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r27->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r27->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r27->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r27->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r27);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r29, 2);
    f_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r29);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r30, 1);
    i = r30->size[0];
    r30->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r30, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r30->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r29->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r30->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r29->data[exponent + r29->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r30);
    emxFree_real_T(&r29);
  }

  emxInit_int32_T(&r26, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r26->size[0];
    r26->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r26, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r26->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r26->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r26->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r28, 2);
      c_repmat(useObsForLearner, r28);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r28->data[i]) {
          trueCount++;
        }
      }

      i = r26->size[0];
      r26->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r26, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r28->data[i]) {
          r26->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r28);
      loop_ub = r26->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r26->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r26);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void e_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[15], const double weak_learner_Children[30], const
  double weak_learner_ClassProb[30], const double weak_learner_CutPoint[15],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r31;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r32;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r33;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r34;
  int loc[2];
  emxArray_int32_T *r35;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r32, 1);
    i = r32->size[0];
    r32->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r32, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r32->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r32->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r32->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r32->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r32);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r34, 2);
    g_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r34);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r35, 1);
    i = r35->size[0];
    r35->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r35, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r35->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r34->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r35->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r34->data[exponent + r34->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r35);
    emxFree_real_T(&r34);
  }

  emxInit_int32_T(&r31, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r31->size[0];
    r31->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r31, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r31->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r31->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r31->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r33, 2);
      c_repmat(useObsForLearner, r33);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r33->data[i]) {
          trueCount++;
        }
      }

      i = r31->size[0];
      r31->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r31, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r33->data[i]) {
          r31->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r33);
      loop_ub = r31->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r31->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r31);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void f_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[17], const double weak_learner_Children[34], const
  double weak_learner_ClassProb[34], const double weak_learner_CutPoint[17],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r36;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r37;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r38;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r39;
  int loc[2];
  emxArray_int32_T *r40;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r37, 1);
    i = r37->size[0];
    r37->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r37, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r37->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r37->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r37->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r37->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r37);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r39, 2);
    h_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r39);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r40, 1);
    i = r40->size[0];
    r40->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r40, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r40->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r39->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r40->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r39->data[exponent + r39->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r40);
    emxFree_real_T(&r39);
  }

  emxInit_int32_T(&r36, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r36->size[0];
    r36->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r36, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r36->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r36->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r36->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r38, 2);
      c_repmat(useObsForLearner, r38);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r38->data[i]) {
          trueCount++;
        }
      }

      i = r36->size[0];
      r36->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r36, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r38->data[i]) {
          r36->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r38);
      loop_ub = r36->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r36->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r36);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void g_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[21], const double weak_learner_Children[42], const
  double weak_learner_ClassProb[42], const double weak_learner_CutPoint[21],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r41;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r42;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r43;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r44;
  int loc[2];
  emxArray_int32_T *r45;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r42, 1);
    i = r42->size[0];
    r42->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r42, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r42->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r42->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r42->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r42->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r42);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r44, 2);
    i_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r44);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r45, 1);
    i = r45->size[0];
    r45->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r45, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r45->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r44->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r45->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r44->data[exponent + r44->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r45);
    emxFree_real_T(&r44);
  }

  emxInit_int32_T(&r41, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r41->size[0];
    r41->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r41, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r41->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r41->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r41->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r43, 2);
      c_repmat(useObsForLearner, r43);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r43->data[i]) {
          trueCount++;
        }
      }

      i = r41->size[0];
      r41->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r41, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r43->data[i]) {
          r41->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r43);
      loop_ub = r41->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r41->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r41);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

void predictOneWithCache(const emxArray_real_T *X, emxArray_real_T *cachedScore,
  emxArray_real_T *cachedWeights, const char combiner[15], const double
  weak_learner_CutVar[11], const double weak_learner_Children[22], const double
  weak_learner_ClassProb[22], const double weak_learner_CutPoint[11], const
  double weak_learner_ClassNames[2], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], boolean_T *cached, const double classnames[2],
  const double nonzeroProbClasses[2], const emxArray_boolean_T *useObsForLearner,
  boolean_T initCache, emxArray_real_T *score)
{
  emxArray_real_T *learnerscore;
  int i;
  int loop_ub;
  int iloc[2];
  int exponent;
  emxArray_int32_T *r8;
  int trueCount;
  boolean_T exitg1;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r9;
  boolean_T rowmatch;
  double absxk;
  int b_tf[1];
  emxArray_real_T *b_X;
  emxArray_boolean_T c_tf;
  emxArray_boolean_T *r10;
  emxArray_real_T *unusedU1;
  emxArray_real_T *r11;
  int loc[2];
  emxArray_int32_T *r12;
  int tmp_data[2];
  int b_exponent;
  emxInit_real_T(&learnerscore, 2);
  i = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T1(learnerscore, i);
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore->data[i] = rtNaN;
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(classnames[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }

      if (!(fabs(classnames[i - 1] - weak_learner_ClassNames[loop_ub]) < absxk))
      {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (any(useObsForLearner)) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r9, 1);
    i = r9->size[0];
    r9->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r9, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r9->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r9->size[0];
    b_X->size[1] = 9;
    emxEnsureCapacity_real_T1(b_X, i);
    for (i = 0; i < 9; i++) {
      loop_ub = r9->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        b_X->data[exponent + b_X->size[0] * i] = X->data[(r9->data[exponent] +
          X->size[0] * i) - 1];
      }
    }

    emxFree_int32_T(&r9);
    emxInit_real_T1(&unusedU1, 1);
    emxInit_real_T(&r11, 2);
    c_CompactClassificationTree_pre(weak_learner_CutVar, weak_learner_Children,
      weak_learner_ClassProb, weak_learner_CutPoint, weak_learner_ClassNames,
      weak_learner_Prior, weak_learner_Cost, b_X, unusedU1, r11);
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    emxFree_real_T(&b_X);
    emxFree_real_T(&unusedU1);
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r12, 1);
    i = r12->size[0];
    r12->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r12, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r12->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    for (i = 0; i < 2; i++) {
      loop_ub = r11->size[0];
      for (exponent = 0; exponent < loop_ub; exponent++) {
        learnerscore->data[(r12->data[exponent] + learnerscore->size[0] *
                            (iloc[i] - 1)) - 1] = r11->data[exponent + r11->
          size[0] * i];
      }
    }

    emxFree_int32_T(&r12);
    emxFree_real_T(&r11);
  }

  emxInit_int32_T(&r8, 1);
  if (initCache) {
    exponent = useObsForLearner->size[0] - 1;
    trueCount = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        trueCount++;
      }
    }

    i = r8->size[0];
    r8->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r8, i);
    loop_ub = 0;
    for (i = 0; i <= exponent; i++) {
      if (useObsForLearner->data[i]) {
        r8->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    loop_ub = r8->size[0];
    for (i = 0; i < 2; i++) {
      for (exponent = 0; exponent < loop_ub; exponent++) {
        cachedScore->data[(r8->data[exponent] + cachedScore->size[0] * i) - 1] =
          0.0;
      }
    }
  } else {
    emxInit_boolean_T1(&tf, 2);
    i = tf->size[0] * tf->size[1];
    tf->size[0] = cachedScore->size[0];
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, i);
    loop_ub = cachedScore->size[0] * cachedScore->size[1];
    for (i = 0; i < loop_ub; i++) {
      tf->data[i] = rtIsNaN(cachedScore->data[i]);
    }

    b_tf[0] = tf->size[0] << 1;
    c_tf = *tf;
    c_tf.size = (int *)&b_tf;
    c_tf.numDimensions = 1;
    if (any(&c_tf)) {
      emxInit_boolean_T1(&r10, 2);
      c_repmat(useObsForLearner, r10);
      exponent = (tf->size[0] << 1) - 1;
      trueCount = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r10->data[i]) {
          trueCount++;
        }
      }

      i = r8->size[0];
      r8->size[0] = trueCount;
      emxEnsureCapacity_int32_T(r8, i);
      loop_ub = 0;
      for (i = 0; i <= exponent; i++) {
        if (tf->data[i] && r10->data[i]) {
          r8->data[loop_ub] = i + 1;
          loop_ub++;
        }
      }

      emxFree_boolean_T(&r10);
      loop_ub = r8->size[0];
      for (i = 0; i < loop_ub; i++) {
        cachedScore->data[r8->data[i] - 1] = 0.0;
      }
    }

    emxFree_boolean_T(&tf);
  }

  emxFree_int32_T(&r8);
  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    iloc[loop_ub] = 0;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      rowmatch = true;
      absxk = fabs(nonzeroProbClasses[i - 1] / 2.0);
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &b_exponent);
        absxk = ldexp(1.0, b_exponent - 53);
      }

      if (!(fabs(nonzeroProbClasses[i - 1] - classnames[loop_ub]) < absxk)) {
        rowmatch = false;
      }

      if (rowmatch) {
        iloc[loop_ub] = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  trueCount = 0;
  for (i = 0; i < 2; i++) {
    if (!(iloc[i] != 0)) {
      trueCount++;
    }

    loc[i] = iloc[i];
  }

  loop_ub = 0;
  for (i = 0; i < 2; i++) {
    if (!(loc[i] != 0)) {
      tmp_data[loop_ub] = i + 1;
      loop_ub++;
    }
  }

  loop_ub = score->size[0];
  for (i = 0; i < trueCount; i++) {
    for (exponent = 0; exponent < loop_ub; exponent++) {
      score->data[exponent + score->size[0] * (tmp_data[i] - 1)] = rtNaN;
    }
  }
}

/* End of code generation (predictOneWithCache.c) */
