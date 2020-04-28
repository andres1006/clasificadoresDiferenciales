/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateCache.h
 *
 * Code generation for function 'updateCache'
 *
 */

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_DFT_vs_DCL_types.h"

/* Function Declarations */
extern void updateCache(const emxArray_real_T *learnerscore, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, boolean_T *cached, const char
  combinerName[15], const emxArray_boolean_T *obsIndices, emxArray_real_T *score);

#endif

/* End of code generation (updateCache.h) */
