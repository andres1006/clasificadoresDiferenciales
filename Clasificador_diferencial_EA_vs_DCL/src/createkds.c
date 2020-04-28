/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * createkds.c
 *
 * Code generation for function 'createkds'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "createkds.h"
#include "log2.h"
#include "any.h"

/* Type Definitions */
#ifndef struct_sZzxkR5zNHgok8QXMBL2vI_tag
#define struct_sZzxkR5zNHgok8QXMBL2vI_tag

struct sZzxkR5zNHgok8QXMBL2vI_tag
{
  emxArray_real_T_1x43 f1;
};

#endif                                 /*struct_sZzxkR5zNHgok8QXMBL2vI_tag*/

#ifndef typedef_cell_wrap_25
#define typedef_cell_wrap_25

typedef struct sZzxkR5zNHgok8QXMBL2vI_tag cell_wrap_25;

#endif                                 /*typedef_cell_wrap_25*/

#ifndef struct_c_emxArray_sZzxkR5zNHgok8QXMBL2
#define struct_c_emxArray_sZzxkR5zNHgok8QXMBL2

struct c_emxArray_sZzxkR5zNHgok8QXMBL2
{
  cell_wrap_25 data[1];
  int size[1];
};

#endif                                 /*struct_c_emxArray_sZzxkR5zNHgok8QXMBL2*/

#ifndef typedef_emxArray_cell_wrap_25_1
#define typedef_emxArray_cell_wrap_25_1

typedef struct c_emxArray_sZzxkR5zNHgok8QXMBL2 emxArray_cell_wrap_25_1;

#endif                                 /*typedef_emxArray_cell_wrap_25_1*/

/* Function Definitions */
void createkds(const double X[172], b_struct_T *sObj)
{
  int notnan_size_idx_1;
  int i1;
  int notnan_data[43];
  boolean_T bv0[43];
  int nx;
  int wasnanIdx_size_idx_0;
  boolean_T exitg1;
  emxArray_cell_wrap_25_1 idxTemp;
  int ii_data[43];
  char t1_Distance[9];
  static const char dist[9] = { 'e', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  unsigned int tempIdx[43];
  unsigned int idxTemp_data[43];
  unsigned int u0;
  notnan_size_idx_1 = 43;
  for (i1 = 0; i1 < 43; i1++) {
    notnan_data[i1] = 1 + i1;
  }

  for (i1 = 0; i1 < 43; i1++) {
    bv0[i1] = false;
  }

  if (any(bv0)) {
    nx = 0;
    wasnanIdx_size_idx_0 = 1;
    exitg1 = false;
    while ((!exitg1) && (wasnanIdx_size_idx_0 < 44)) {
      nx++;
      ii_data[nx - 1] = wasnanIdx_size_idx_0;
      if (nx >= 43) {
        exitg1 = true;
      } else {
        wasnanIdx_size_idx_0++;
      }
    }

    if (1 > nx) {
      notnan_size_idx_1 = 0;
    } else {
      notnan_size_idx_1 = nx;
    }

    if (0 <= notnan_size_idx_1 - 1) {
      memcpy(&notnan_data[0], &ii_data[0], (unsigned int)(notnan_size_idx_1 *
              (int)sizeof(int)));
    }

    wasnanIdx_size_idx_0 = 1;
    nx = notnan_size_idx_1;
  } else {
    nx = 43;
    wasnanIdx_size_idx_0 = 0;
  }

  b_log2();
  for (i1 = 0; i1 < notnan_size_idx_1; i1++) {
    idxTemp.data[0].f1.data[i1] = notnan_data[i1];
  }

  for (i1 = 0; i1 < 9; i1++) {
    t1_Distance[i1] = dist[i1];
  }

  memcpy(&sObj->X[0], &X[0], 172U * sizeof(double));
  for (i1 = 0; i1 < 9; i1++) {
    sObj->Distance[i1] = t1_Distance[i1];
  }

  sObj->BucketSize = 50.0;
  sObj->wasnanIdx.size[0] = wasnanIdx_size_idx_0;
  sObj->wasnanIdx.size[1] = 0;
  sObj->numNodes = 1;
  sObj->nx_nonan = nx;
  sObj->cutDim.size[0] = 1;
  sObj->cutDim.data[0] = 0.0;
  sObj->cutVal.size[0] = 1;
  sObj->cutVal.data[0] = 0.0;
  sObj->lowerBounds.size[0] = 1;
  sObj->lowerBounds.size[1] = 4;
  sObj->upperBounds.size[0] = 1;
  sObj->upperBounds.size[1] = 4;
  for (i1 = 0; i1 < 4; i1++) {
    sObj->lowerBounds.data[sObj->lowerBounds.size[0] * i1] = rtMinusInf;
    sObj->upperBounds.data[sObj->upperBounds.size[0] * i1] = rtInf;
  }

  memset(&tempIdx[0], 0, 43U * sizeof(unsigned int));
  if (notnan_size_idx_1 > 0) {
    for (i1 = 0; i1 < notnan_size_idx_1; i1++) {
      ii_data[i1] = i1;
    }

    for (i1 = 0; i1 < notnan_size_idx_1; i1++) {
      nx = (int)idxTemp.data[0].f1.data[i1];
      if (nx >= 0) {
        u0 = (unsigned int)nx;
      } else {
        u0 = 0U;
      }

      idxTemp_data[i1] = u0;
    }

    for (i1 = 0; i1 < notnan_size_idx_1; i1++) {
      tempIdx[ii_data[i1]] = idxTemp_data[i1];
    }
  }

  memcpy(&sObj->idxAll[0], &tempIdx[0], 43U * sizeof(unsigned int));
  sObj->idxDim.size[0] = 1;
  sObj->idxDim.data[0] = notnan_size_idx_1;
  sObj->leftChild.size[0] = 1;
  sObj->leftChild.data[0] = 0.0;
  sObj->rightChild.size[0] = 1;
  sObj->rightChild.data[0] = 0.0;
  sObj->leafNode.size[0] = 1;
  sObj->leafNode.data[0] = true;
}

/* End of code generation (createkds.c) */
