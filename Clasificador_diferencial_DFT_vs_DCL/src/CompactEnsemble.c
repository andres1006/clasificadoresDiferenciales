/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactEnsemble.c
 *
 * Code generation for function 'CompactEnsemble'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "CompactEnsemble.h"

/* Function Definitions */
void CompactEnsemble_CompactEnsemble(c_classreg_learning_coder_class *obj)
{
  int i;
  for (i = 0; i < 30; i++) {
    obj->LearnerWeights[i] = 1.0;
    obj->IsCached[i] = false;
  }
}

/* End of code generation (CompactEnsemble.c) */
