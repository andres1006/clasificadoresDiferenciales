/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_EA_vs_DCL_types.h
 *
 * Code generation for function 'Clasificador_diferencial_EA_vs_DCL'
 *
 */

#ifndef CLASIFICADOR_DIFERENCIAL_EA_VS_DCL_TYPES_H
#define CLASIFICADOR_DIFERENCIAL_EA_VS_DCL_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_boolean_T_1
#define struct_emxArray_boolean_T_1

struct emxArray_boolean_T_1
{
  boolean_T data[1];
  int size[1];
};

#endif                                 /*struct_emxArray_boolean_T_1*/

#ifndef typedef_emxArray_boolean_T_1
#define typedef_emxArray_boolean_T_1

typedef struct emxArray_boolean_T_1 emxArray_boolean_T_1;

#endif                                 /*typedef_emxArray_boolean_T_1*/

#ifndef struct_emxArray_real_T_1
#define struct_emxArray_real_T_1

struct emxArray_real_T_1
{
  double data[1];
  int size[1];
};

#endif                                 /*struct_emxArray_real_T_1*/

#ifndef typedef_emxArray_real_T_1
#define typedef_emxArray_real_T_1

typedef struct emxArray_real_T_1 emxArray_real_T_1;

#endif                                 /*typedef_emxArray_real_T_1*/

#ifndef struct_emxArray_real_T_1x4
#define struct_emxArray_real_T_1x4

struct emxArray_real_T_1x4
{
  double data[4];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x4*/

#ifndef typedef_emxArray_real_T_1x4
#define typedef_emxArray_real_T_1x4

typedef struct emxArray_real_T_1x4 emxArray_real_T_1x4;

#endif                                 /*typedef_emxArray_real_T_1x4*/

#ifndef struct_emxArray_real_T_1x43
#define struct_emxArray_real_T_1x43

struct emxArray_real_T_1x43
{
  double data[43];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x43*/

#ifndef typedef_emxArray_real_T_1x43
#define typedef_emxArray_real_T_1x43

typedef struct emxArray_real_T_1x43 emxArray_real_T_1x43;

#endif                                 /*typedef_emxArray_real_T_1x43*/

#ifndef struct_sJexZ8tMkhF4JBtRpqPhM9C_tag
#define struct_sJexZ8tMkhF4JBtRpqPhM9C_tag

struct sJexZ8tMkhF4JBtRpqPhM9C_tag
{
  double X[172];
  char Distance[9];
  double BucketSize;
  emxArray_real_T_1x43 wasnanIdx;
  int numNodes;
  emxArray_real_T_1 cutDim;
  emxArray_real_T_1 cutVal;
  emxArray_real_T_1x4 lowerBounds;
  emxArray_real_T_1x4 upperBounds;
  emxArray_real_T_1 leftChild;
  emxArray_real_T_1 rightChild;
  emxArray_boolean_T_1 leafNode;
  double nx_nonan;
  unsigned int idxAll[43];
  emxArray_real_T_1 idxDim;
};

#endif                                 /*struct_sJexZ8tMkhF4JBtRpqPhM9C_tag*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct sJexZ8tMkhF4JBtRpqPhM9C_tag b_struct_T;

#endif                                 /*typedef_b_struct_T*/

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

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/
#endif

/* End of code generation (Clasificador_diferencial_EA_vs_DCL_types.h) */
