/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * knnsearch.h
 *
 * Code generation for function 'knnsearch'
 *
 */

#ifndef KNNSEARCH_H
#define KNNSEARCH_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_EA_vs_DFT_types.h"

/* Function Declarations */
extern void knnsearch(const double X[216], const emxArray_real_T *Y,
                      emxArray_real_T *Idx, emxArray_real_T *D);

#endif

/* End of code generation (knnsearch.h) */
