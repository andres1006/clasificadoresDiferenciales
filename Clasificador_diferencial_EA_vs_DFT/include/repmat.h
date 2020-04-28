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
#include "Clasificador_diferencial_EA_vs_DFT_types.h"

/* Function Declarations */
extern void b_repmat(const double a_data[], const int a_size[2], double
                     varargin_1, emxArray_real_T *b);
extern void repmat(const double a_data[], const double varargin_1[2],
                   emxArray_real_T *b);

#endif

/* End of code generation (repmat.h) */
