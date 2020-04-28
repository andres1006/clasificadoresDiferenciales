/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_DFT_vs_DCL_types.h"

/* Function Declarations */
extern void b_repmat(double a, double varargin_1, emxArray_real_T *b);
extern void c_repmat(const emxArray_boolean_T *a, emxArray_boolean_T *b);
extern void repmat(double a, int varargin_1, emxArray_real_T *b);

#endif

/* End of code generation (repmat.h) */
