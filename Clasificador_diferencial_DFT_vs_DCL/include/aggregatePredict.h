/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aggregatePredict.h
 *
 * Code generation for function 'aggregatePredict'
 *
 */

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_DFT_vs_DCL_types.h"

/* Function Declarations */
extern void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score,
  const boolean_T isCached[30], const double classNames[2], const double
  nonzeroProbClasses[2], const boolean_T learners[30], const emxArray_boolean_T *
  useObsForLearner);

#endif

/* End of code generation (aggregatePredict.h) */
