/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictOneWithCache.h
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_DFT_vs_DCL_types.h"

/* Function Declarations */
extern void b_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[9], const double weak_learner_Children[18], const
  double weak_learner_ClassProb[18], const double weak_learner_CutPoint[9],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void c_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[13], const double weak_learner_Children[26], const
  double weak_learner_ClassProb[26], const double weak_learner_CutPoint[13],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void d_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[7], const double weak_learner_Children[14], const
  double weak_learner_ClassProb[14], const double weak_learner_CutPoint[7],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void e_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[15], const double weak_learner_Children[30], const
  double weak_learner_ClassProb[30], const double weak_learner_CutPoint[15],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void f_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[17], const double weak_learner_Children[34], const
  double weak_learner_ClassProb[34], const double weak_learner_CutPoint[17],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void g_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[21], const double weak_learner_Children[42], const
  double weak_learner_ClassProb[42], const double weak_learner_CutPoint[21],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);
extern void predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutVar[11], const double weak_learner_Children[22], const
  double weak_learner_ClassProb[22], const double weak_learner_CutPoint[11],
  const double weak_learner_ClassNames[2], const double weak_learner_Prior[2],
  const double weak_learner_Cost[4], boolean_T *cached, const double classnames
  [2], const double nonzeroProbClasses[2], const emxArray_boolean_T
  *useObsForLearner, boolean_T initCache, emxArray_real_T *score);

#endif

/* End of code generation (predictOneWithCache.h) */
