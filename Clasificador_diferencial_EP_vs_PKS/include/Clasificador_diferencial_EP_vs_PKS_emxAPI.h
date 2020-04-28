/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_EP_vs_PKS_emxAPI.h
 *
 * Code generation for function 'Clasificador_diferencial_EP_vs_PKS_emxAPI'
 *
 */

#ifndef CLASIFICADOR_DIFERENCIAL_EP_VS_PKS_EMXAPI_H
#define CLASIFICADOR_DIFERENCIAL_EP_VS_PKS_EMXAPI_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_EP_vs_PKS_types.h"

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (Clasificador_diferencial_EP_vs_PKS_emxAPI.h) */
