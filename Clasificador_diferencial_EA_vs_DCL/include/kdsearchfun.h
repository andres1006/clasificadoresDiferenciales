/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kdsearchfun.h
 *
 * Code generation for function 'kdsearchfun'
 *
 */

#ifndef KDSEARCHFUN_H
#define KDSEARCHFUN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_EA_vs_DCL_types.h"

/* Function Declarations */
extern void search_kdtree(const unsigned int obj_idxAll[43], const double
  obj_idxDim_data[], const double X[172], const double queryPt[4], int numNN,
  double pq_D_data[], int pq_D_size[1], unsigned int pq_I_data[], int pq_I_size
  [1]);

#endif

/* End of code generation (kdsearchfun.h) */
