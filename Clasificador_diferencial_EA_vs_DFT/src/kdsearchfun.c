/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kdsearchfun.c
 *
 * Code generation for function 'kdsearchfun'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DFT.h"
#include "kdsearchfun.h"
#include "sort1.h"
#include "Clasificador_diferencial_EA_vs_DFT_emxutil.h"
#include "bsxfun.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_36
#define struct_emxArray_real_T_36

struct emxArray_real_T_36
{
  double data[36];
  int size[1];
};

#endif                                 /*struct_emxArray_real_T_36*/

#ifndef typedef_emxArray_real_T_36
#define typedef_emxArray_real_T_36

typedef struct emxArray_real_T_36 emxArray_real_T_36;

#endif                                 /*typedef_emxArray_real_T_36*/

#ifndef struct_emxArray_uint32_T_36
#define struct_emxArray_uint32_T_36

struct emxArray_uint32_T_36
{
  unsigned int data[36];
  int size[1];
};

#endif                                 /*struct_emxArray_uint32_T_36*/

#ifndef typedef_emxArray_uint32_T_36
#define typedef_emxArray_uint32_T_36

typedef struct emxArray_uint32_T_36 emxArray_uint32_T_36;

#endif                                 /*typedef_emxArray_uint32_T_36*/

#ifndef struct_sBea98RFqHxedvJT7WuQkRF_tag
#define struct_sBea98RFqHxedvJT7WuQkRF_tag

struct sBea98RFqHxedvJT7WuQkRF_tag
{
  emxArray_real_T_36 D;
  emxArray_uint32_T_36 I;
};

#endif                                 /*struct_sBea98RFqHxedvJT7WuQkRF_tag*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct sBea98RFqHxedvJT7WuQkRF_tag struct_T;

#endif                                 /*typedef_struct_T*/

/* Function Declarations */
static void accuDist(const double distIn_data[], const int distIn_size[2],
                     double distOut_data[], int distOut_size[1]);
static void search_node(const double X[216], const double queryPt[6], const
  unsigned int node_idx_start_data[], const int node_idx_start_size[1], int
  numNN, struct_T *pq);

/* Function Definitions */
static void accuDist(const double distIn_data[], const int distIn_size[2],
                     double distOut_data[], int distOut_size[1])
{
  int vstride;
  int aDistOut_size_idx_0;
  int j;
  double aDistOut_data[36];
  int k;
  int xoffset;
  if (distIn_size[0] == 0) {
    aDistOut_size_idx_0 = 0;
  } else {
    vstride = distIn_size[0];
    aDistOut_size_idx_0 = (signed char)distIn_size[0];
    for (j = 0; j < vstride; j++) {
      aDistOut_data[j] = distIn_data[j];
    }

    for (k = 0; k < 5; k++) {
      xoffset = (k + 1) * vstride;
      for (j = 0; j < vstride; j++) {
        aDistOut_data[j] += distIn_data[xoffset + j];
      }
    }
  }

  distOut_size[0] = aDistOut_size_idx_0;
  if (0 <= aDistOut_size_idx_0 - 1) {
    memcpy(&distOut_data[0], &aDistOut_data[0], (unsigned int)
           (aDistOut_size_idx_0 * (int)sizeof(double)));
  }
}

static void search_node(const double X[216], const double queryPt[6], const
  unsigned int node_idx_start_data[], const int node_idx_start_size[1], int
  numNN, struct_T *pq)
{
  int X_size[2];
  int loop_ub;
  int i3;
  emxArray_real_T *r4;
  int diffAllDim_size_idx_0;
  emxArray_real_T X_data;
  double b_X_data[216];
  double diffAllDim_data[216];
  int diffAllDim_size[2];
  double b_diffAllDim_data[216];
  double distInP_data[36];
  int distInP_size[1];
  int iidx_data[36];
  int iidx_size[1];
  int sortedInd_data[36];
  X_size[0] = node_idx_start_size[0];
  X_size[1] = 6;
  loop_ub = node_idx_start_size[0];
  for (i3 = 0; i3 < 6; i3++) {
    for (diffAllDim_size_idx_0 = 0; diffAllDim_size_idx_0 < loop_ub;
         diffAllDim_size_idx_0++) {
      b_X_data[diffAllDim_size_idx_0 + X_size[0] * i3] = X[((int)
        node_idx_start_data[diffAllDim_size_idx_0] + 36 * i3) - 1];
    }
  }

  emxInit_real_T(&r4, 2);
  X_data.data = (double *)&b_X_data;
  X_data.size = (int *)&X_size;
  X_data.allocatedSize = 216;
  X_data.numDimensions = 2;
  X_data.canFreeData = false;
  bsxfun(&X_data, queryPt, r4);
  diffAllDim_size_idx_0 = r4->size[0];
  loop_ub = r4->size[0] * r4->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    diffAllDim_data[i3] = r4->data[i3];
  }

  emxFree_real_T(&r4);
  diffAllDim_size[0] = diffAllDim_size_idx_0;
  diffAllDim_size[1] = 6;
  loop_ub = diffAllDim_size_idx_0 * 6;
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_diffAllDim_data[i3] = diffAllDim_data[i3] * diffAllDim_data[i3];
  }

  accuDist(b_diffAllDim_data, diffAllDim_size, distInP_data, distInP_size);
  sort(distInP_data, distInP_size, iidx_data, iidx_size);
  loop_ub = iidx_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&sortedInd_data[0], &iidx_data[0], (unsigned int)(loop_ub * (int)
            sizeof(int)));
  }

  if (distInP_size[0] <= numNN) {
    pq->D.size[0] = distInP_size[0];
    loop_ub = distInP_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&pq->D.data[0], &distInP_data[0], (unsigned int)(loop_ub * (int)
              sizeof(double)));
    }

    pq->I.size[0] = iidx_size[0];
    loop_ub = iidx_size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      pq->I.data[i3] = node_idx_start_data[sortedInd_data[i3] - 1];
    }
  } else {
    pq->D.size[0] = numNN;
    if (0 <= numNN - 1) {
      memcpy(&pq->D.data[0], &distInP_data[0], (unsigned int)(numNN * (int)
              sizeof(double)));
    }

    pq->I.size[0] = numNN;
    for (i3 = 0; i3 < numNN; i3++) {
      pq->I.data[i3] = node_idx_start_data[sortedInd_data[i3] - 1];
    }
  }
}

void search_kdtree(const unsigned int obj_idxAll[36], const double
                   obj_idxDim_data[], const double X[216], const double queryPt
                   [6], int numNN, double pq_D_data[], int pq_D_size[1],
                   unsigned int pq_I_data[], int pq_I_size[1])
{
  int node_idx_this_size[1];
  int loop_ub;
  struct_T r3;
  unsigned int node_idx_this_data[36];
  if (obj_idxDim_data[0] == 0.0) {
    node_idx_this_size[0] = 0;
  } else {
    if (1.0 > obj_idxDim_data[0]) {
      loop_ub = 0;
    } else {
      loop_ub = (int)obj_idxDim_data[0];
    }

    node_idx_this_size[0] = loop_ub;
    if (0 <= loop_ub - 1) {
      memcpy(&node_idx_this_data[0], &obj_idxAll[0], (unsigned int)(loop_ub *
              (int)sizeof(unsigned int)));
    }
  }

  r3.D.size[0] = 0;
  r3.I.size[0] = 0;
  search_node(X, queryPt, node_idx_this_data, node_idx_this_size, numNN, &r3);
  pq_D_size[0] = r3.D.size[0];
  loop_ub = r3.D.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&pq_D_data[0], &r3.D.data[0], (unsigned int)(loop_ub * (int)sizeof
            (double)));
  }

  pq_I_size[0] = r3.I.size[0];
  loop_ub = r3.I.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&pq_I_data[0], &r3.I.data[0], (unsigned int)(loop_ub * (int)sizeof
            (unsigned int)));
  }
}

/* End of code generation (kdsearchfun.c) */
