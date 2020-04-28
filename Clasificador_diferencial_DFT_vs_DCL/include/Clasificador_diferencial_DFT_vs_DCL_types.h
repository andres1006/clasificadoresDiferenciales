/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_DFT_vs_DCL_types.h
 *
 * Code generation for function 'Clasificador_diferencial_DFT_vs_DCL'
 *
 */

#ifndef CLASIFICADOR_DIFERENCIAL_DFT_VS_DCL_TYPES_H
#define CLASIFICADOR_DIFERENCIAL_DFT_VS_DCL_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c_classreg_learning_coder_class
#define typedef_c_classreg_learning_coder_class

typedef struct {
  boolean_T IsCached[30];
  double LearnerWeights[30];
  double ClassNames[2];
  int ClassNamesLength[2];
  double Prior[2];
  double NonzeroProbClasses[2];
  double Cost[4];
} c_classreg_learning_coder_class;

#endif                                 /*typedef_c_classreg_learning_coder_class*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/
#endif

/* End of code generation (Clasificador_diferencial_DFT_vs_DCL_types.h) */
