/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ClassificationKNN.h
 *
 * Code generation for function 'ClassificationKNN'
 *
 */

#ifndef CLASSIFICATIONKNN_H
#define CLASSIFICATIONKNN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_EA_vs_DFT_types.h"

/* Function Declarations */
extern void ClassificationKNN_score(const double obj_X[216], const unsigned int
  obj_YIdx[36], const emxArray_real_T *X, emxArray_real_T *scores,
  emxArray_boolean_T *nonnanscoreindices);

#endif

/* End of code generation (ClassificationKNN.h) */
