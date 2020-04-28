/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.h
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Clasificador_diferencial_DFT_vs_DCL_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_pre(const double obj_CutVar[11], const
  double obj_Children[22], const double obj_ClassProb[22], const double
  obj_CutPoint[11], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void d_CompactClassificationTree_pre(const double obj_CutVar[9], const
  double obj_Children[18], const double obj_ClassProb[18], const double
  obj_CutPoint[9], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void e_CompactClassificationTree_pre(const double obj_CutVar[13], const
  double obj_Children[26], const double obj_ClassProb[26], const double
  obj_CutPoint[13], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void f_CompactClassificationTree_pre(const double obj_CutVar[7], const
  double obj_Children[14], const double obj_ClassProb[14], const double
  obj_CutPoint[7], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void g_CompactClassificationTree_pre(const double obj_CutVar[15], const
  double obj_Children[30], const double obj_ClassProb[30], const double
  obj_CutPoint[15], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void h_CompactClassificationTree_pre(const double obj_CutVar[17], const
  double obj_Children[34], const double obj_ClassProb[34], const double
  obj_CutPoint[17], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);
extern void i_CompactClassificationTree_pre(const double obj_CutVar[21], const
  double obj_Children[42], const double obj_ClassProb[42], const double
  obj_CutPoint[21], const double obj_ClassNames[2], const double obj_Prior[2],
  const double obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores);

#endif

/* End of code generation (CompactClassificationTree.h) */
