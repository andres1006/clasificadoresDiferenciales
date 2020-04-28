/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.c
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "CompactClassificationTree.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"
#include "repmat.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(const double obj_CutVar[11], const double
  obj_Children[22], const double obj_ClassProb[22], const double obj_CutPoint[11],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i0;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i1;
  int boffset;
  int i2;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r1;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i0 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i0);
    i0 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i0);
  } else {
    emxInit_real_T1(&node, 1);
    i0 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i0);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i0 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i0);
    n = node->size[0];
    i0 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i0);
    for (i0 = 0; i0 < 2; i0++) {
      for (i1 = 0; i1 < n; i1++) {
        unusedU4->data[i1 + unusedU4->size[0] * i0] = obj_ClassProb[((int)
          node->data[i1] + 11 * i0) - 1];
      }
    }

    coffset = scores->size[0];
    for (i0 = 0; i0 < 2; i0++) {
      n = unusedU4->size[0];
      for (i1 = 0; i1 < n; i1++) {
        scores->data[i1 + coffset * i0] = unusedU4->data[i1 + unusedU4->size[0] *
          i0];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i0 = scores->size[0];
    i1 = scores->size[0];
    i2 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i1;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i2);
    for (n = 0; n < 2; n++) {
      coffset = n * i0 - 1;
      boffset = n << 1;
      for (i = 1; i <= i0; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i0;
          for (i = 1; i <= i0; i++) {
            i1 = scores->size[0];
            i2 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i2 % i1 + scores_idx_0 * (i2 / i1)];
          }
        }
      }
    }

    i0 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i1 = scores->size[0];
    i2 = node->size[0];
    node->size[0] = i1;
    emxEnsureCapacity_real_T(node, i2);
    for (n = 0; n < i0; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r1, 1);
    i1 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i1, r1);
    for (boffset = 0; boffset < i0; boffset++) {
      r1->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r1->size[0];
    for (i0 = 0; i0 < n; i0++) {
      labels->data[i0] = r1->data[i0];
    }

    emxFree_real_T(&r1);
  }
}

void d_CompactClassificationTree_pre(const double obj_CutVar[9], const double
  obj_Children[18], const double obj_ClassProb[18], const double obj_CutPoint[9],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i5;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i6;
  int boffset;
  int i7;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r2;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i5 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i5);
    i5 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i5);
  } else {
    emxInit_real_T1(&node, 1);
    i5 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i5);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i5 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i5);
    n = node->size[0];
    i5 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i5);
    for (i5 = 0; i5 < 2; i5++) {
      for (i6 = 0; i6 < n; i6++) {
        unusedU4->data[i6 + unusedU4->size[0] * i5] = obj_ClassProb[((int)
          node->data[i6] + 9 * i5) - 1];
      }
    }

    coffset = scores->size[0];
    for (i5 = 0; i5 < 2; i5++) {
      n = unusedU4->size[0];
      for (i6 = 0; i6 < n; i6++) {
        scores->data[i6 + coffset * i5] = unusedU4->data[i6 + unusedU4->size[0] *
          i5];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i5 = scores->size[0];
    i6 = scores->size[0];
    i7 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i6;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i7);
    for (n = 0; n < 2; n++) {
      coffset = n * i5 - 1;
      boffset = n << 1;
      for (i = 1; i <= i5; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i5;
          for (i = 1; i <= i5; i++) {
            i6 = scores->size[0];
            i7 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i7 % i6 + scores_idx_0 * (i7 / i6)];
          }
        }
      }
    }

    i5 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i6 = scores->size[0];
    i7 = node->size[0];
    node->size[0] = i6;
    emxEnsureCapacity_real_T(node, i7);
    for (n = 0; n < i5; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r2, 1);
    i6 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i6, r2);
    for (boffset = 0; boffset < i5; boffset++) {
      r2->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r2->size[0];
    for (i5 = 0; i5 < n; i5++) {
      labels->data[i5] = r2->data[i5];
    }

    emxFree_real_T(&r2);
  }
}

void e_CompactClassificationTree_pre(const double obj_CutVar[13], const double
  obj_Children[26], const double obj_ClassProb[26], const double obj_CutPoint[13],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i8;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i9;
  int boffset;
  int i10;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r3;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i8 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i8);
    i8 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i8);
  } else {
    emxInit_real_T1(&node, 1);
    i8 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i8);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i8 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i8);
    n = node->size[0];
    i8 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i8);
    for (i8 = 0; i8 < 2; i8++) {
      for (i9 = 0; i9 < n; i9++) {
        unusedU4->data[i9 + unusedU4->size[0] * i8] = obj_ClassProb[((int)
          node->data[i9] + 13 * i8) - 1];
      }
    }

    coffset = scores->size[0];
    for (i8 = 0; i8 < 2; i8++) {
      n = unusedU4->size[0];
      for (i9 = 0; i9 < n; i9++) {
        scores->data[i9 + coffset * i8] = unusedU4->data[i9 + unusedU4->size[0] *
          i8];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i8 = scores->size[0];
    i9 = scores->size[0];
    i10 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i9;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i10);
    for (n = 0; n < 2; n++) {
      coffset = n * i8 - 1;
      boffset = n << 1;
      for (i = 1; i <= i8; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i8;
          for (i = 1; i <= i8; i++) {
            i9 = scores->size[0];
            i10 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i10 % i9 + scores_idx_0 * (i10 / i9)];
          }
        }
      }
    }

    i8 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i9 = scores->size[0];
    i10 = node->size[0];
    node->size[0] = i9;
    emxEnsureCapacity_real_T(node, i10);
    for (n = 0; n < i8; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r3, 1);
    i9 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i9, r3);
    for (boffset = 0; boffset < i8; boffset++) {
      r3->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r3->size[0];
    for (i8 = 0; i8 < n; i8++) {
      labels->data[i8] = r3->data[i8];
    }

    emxFree_real_T(&r3);
  }
}

void f_CompactClassificationTree_pre(const double obj_CutVar[7], const double
  obj_Children[14], const double obj_ClassProb[14], const double obj_CutPoint[7],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i11;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i12;
  int boffset;
  int i13;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r4;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i11 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i11);
    i11 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i11);
  } else {
    emxInit_real_T1(&node, 1);
    i11 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i11);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i11 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i11);
    n = node->size[0];
    i11 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i11);
    for (i11 = 0; i11 < 2; i11++) {
      for (i12 = 0; i12 < n; i12++) {
        unusedU4->data[i12 + unusedU4->size[0] * i11] = obj_ClassProb[((int)
          node->data[i12] + 7 * i11) - 1];
      }
    }

    coffset = scores->size[0];
    for (i11 = 0; i11 < 2; i11++) {
      n = unusedU4->size[0];
      for (i12 = 0; i12 < n; i12++) {
        scores->data[i12 + coffset * i11] = unusedU4->data[i12 + unusedU4->size
          [0] * i11];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i11 = scores->size[0];
    i12 = scores->size[0];
    i13 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i12;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i13);
    for (n = 0; n < 2; n++) {
      coffset = n * i11 - 1;
      boffset = n << 1;
      for (i = 1; i <= i11; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i11;
          for (i = 1; i <= i11; i++) {
            i12 = scores->size[0];
            i13 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i13 % i12 + scores_idx_0 * (i13 / i12)];
          }
        }
      }
    }

    i11 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i12 = scores->size[0];
    i13 = node->size[0];
    node->size[0] = i12;
    emxEnsureCapacity_real_T(node, i13);
    for (n = 0; n < i11; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r4, 1);
    i12 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i12, r4);
    for (boffset = 0; boffset < i11; boffset++) {
      r4->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r4->size[0];
    for (i11 = 0; i11 < n; i11++) {
      labels->data[i11] = r4->data[i11];
    }

    emxFree_real_T(&r4);
  }
}

void g_CompactClassificationTree_pre(const double obj_CutVar[15], const double
  obj_Children[30], const double obj_ClassProb[30], const double obj_CutPoint[15],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i14;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i15;
  int boffset;
  int i16;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r5;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i14 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i14);
    i14 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i14);
  } else {
    emxInit_real_T1(&node, 1);
    i14 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i14);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i14 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i14);
    n = node->size[0];
    i14 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i14);
    for (i14 = 0; i14 < 2; i14++) {
      for (i15 = 0; i15 < n; i15++) {
        unusedU4->data[i15 + unusedU4->size[0] * i14] = obj_ClassProb[((int)
          node->data[i15] + 15 * i14) - 1];
      }
    }

    coffset = scores->size[0];
    for (i14 = 0; i14 < 2; i14++) {
      n = unusedU4->size[0];
      for (i15 = 0; i15 < n; i15++) {
        scores->data[i15 + coffset * i14] = unusedU4->data[i15 + unusedU4->size
          [0] * i14];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i14 = scores->size[0];
    i15 = scores->size[0];
    i16 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i15;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i16);
    for (n = 0; n < 2; n++) {
      coffset = n * i14 - 1;
      boffset = n << 1;
      for (i = 1; i <= i14; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i14;
          for (i = 1; i <= i14; i++) {
            i15 = scores->size[0];
            i16 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i16 % i15 + scores_idx_0 * (i16 / i15)];
          }
        }
      }
    }

    i14 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i15 = scores->size[0];
    i16 = node->size[0];
    node->size[0] = i15;
    emxEnsureCapacity_real_T(node, i16);
    for (n = 0; n < i14; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r5, 1);
    i15 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i15, r5);
    for (boffset = 0; boffset < i14; boffset++) {
      r5->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r5->size[0];
    for (i14 = 0; i14 < n; i14++) {
      labels->data[i14] = r5->data[i14];
    }

    emxFree_real_T(&r5);
  }
}

void h_CompactClassificationTree_pre(const double obj_CutVar[17], const double
  obj_Children[34], const double obj_ClassProb[34], const double obj_CutPoint[17],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i17;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i18;
  int boffset;
  int i19;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r6;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i17 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i17);
    i17 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i17);
  } else {
    emxInit_real_T1(&node, 1);
    i17 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i17);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i17 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i17);
    n = node->size[0];
    i17 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i17);
    for (i17 = 0; i17 < 2; i17++) {
      for (i18 = 0; i18 < n; i18++) {
        unusedU4->data[i18 + unusedU4->size[0] * i17] = obj_ClassProb[((int)
          node->data[i18] + 17 * i17) - 1];
      }
    }

    coffset = scores->size[0];
    for (i17 = 0; i17 < 2; i17++) {
      n = unusedU4->size[0];
      for (i18 = 0; i18 < n; i18++) {
        scores->data[i18 + coffset * i17] = unusedU4->data[i18 + unusedU4->size
          [0] * i17];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i17 = scores->size[0];
    i18 = scores->size[0];
    i19 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i18;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i19);
    for (n = 0; n < 2; n++) {
      coffset = n * i17 - 1;
      boffset = n << 1;
      for (i = 1; i <= i17; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i17;
          for (i = 1; i <= i17; i++) {
            i18 = scores->size[0];
            i19 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i19 % i18 + scores_idx_0 * (i19 / i18)];
          }
        }
      }
    }

    i17 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i18 = scores->size[0];
    i19 = node->size[0];
    node->size[0] = i18;
    emxEnsureCapacity_real_T(node, i19);
    for (n = 0; n < i17; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r6, 1);
    i18 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i18, r6);
    for (boffset = 0; boffset < i17; boffset++) {
      r6->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r6->size[0];
    for (i17 = 0; i17 < n; i17++) {
      labels->data[i17] = r6->data[i17];
    }

    emxFree_real_T(&r6);
  }
}

void i_CompactClassificationTree_pre(const double obj_CutVar[21], const double
  obj_Children[42], const double obj_ClassProb[42], const double obj_CutPoint[21],
  const double obj_ClassNames[2], const double obj_Prior[2], const double
  obj_Cost[4], const emxArray_real_T *X, emxArray_real_T *labels,
  emxArray_real_T *scores)
{
  emxArray_real_T *node;
  int i20;
  int n;
  emxArray_real_T *unusedU4;
  double m;
  int coffset;
  int i21;
  int boffset;
  int i22;
  int i;
  int k;
  int aoffset;
  emxArray_real_T *r7;
  int scores_idx_0;
  if (X->size[0] == 0) {
    i20 = scores->size[0] * scores->size[1];
    scores->size[0] = 0;
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i20);
    i20 = labels->size[0];
    labels->size[0] = 0;
    emxEnsureCapacity_real_T(labels, i20);
  } else {
    emxInit_real_T1(&node, 1);
    i20 = node->size[0];
    node->size[0] = X->size[0];
    emxEnsureCapacity_real_T(node, i20);
    for (n = 0; n < X->size[0]; n++) {
      m = 1.0;
      while (!((obj_CutVar[(int)m - 1] == 0.0) || rtIsNaN(X->data[n + X->size[0]
               * ((int)obj_CutVar[(int)m - 1] - 1)]))) {
        if (X->data[n + X->size[0] * ((int)obj_CutVar[(int)m - 1] - 1)] <
            obj_CutPoint[(int)m - 1]) {
          m = obj_Children[((int)m - 1) << 1];
        } else {
          m = obj_Children[1 + (((int)m - 1) << 1)];
        }
      }

      node->data[n] = m;
    }

    emxInit_real_T(&unusedU4, 2);
    i20 = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T1(scores, i20);
    n = node->size[0];
    i20 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = n;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i20);
    for (i20 = 0; i20 < 2; i20++) {
      for (i21 = 0; i21 < n; i21++) {
        unusedU4->data[i21 + unusedU4->size[0] * i20] = obj_ClassProb[((int)
          node->data[i21] + 21 * i20) - 1];
      }
    }

    coffset = scores->size[0];
    for (i20 = 0; i20 < 2; i20++) {
      n = unusedU4->size[0];
      for (i21 = 0; i21 < n; i21++) {
        scores->data[i21 + coffset * i20] = unusedU4->data[i21 + unusedU4->size
          [0] * i20];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    repmat(obj_ClassNames[boffset], node->size[0], labels);
    i20 = scores->size[0];
    i21 = scores->size[0];
    i22 = unusedU4->size[0] * unusedU4->size[1];
    unusedU4->size[0] = i21;
    unusedU4->size[1] = 2;
    emxEnsureCapacity_real_T1(unusedU4, i22);
    for (n = 0; n < 2; n++) {
      coffset = n * i20 - 1;
      boffset = n << 1;
      for (i = 1; i <= i20; i++) {
        unusedU4->data[coffset + i] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (obj_Cost[boffset + k] != 0.0) {
          aoffset = k * i20;
          for (i = 1; i <= i20; i++) {
            i21 = scores->size[0];
            i22 = (aoffset + i) - 1;
            scores_idx_0 = scores->size[0];
            unusedU4->data[coffset + i] += obj_Cost[boffset + k] * scores->
              data[i22 % i21 + scores_idx_0 * (i22 / i21)];
          }
        }
      }
    }

    i20 = scores->size[0];
    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i21 = scores->size[0];
    i22 = node->size[0];
    node->size[0] = i21;
    emxEnsureCapacity_real_T(node, i22);
    for (n = 0; n < i20; n++) {
      if ((unusedU4->data[n] > unusedU4->data[n + unusedU4->size[0]]) ||
          (rtIsNaN(unusedU4->data[n]) && (!rtIsNaN(unusedU4->data[n +
             unusedU4->size[0]])))) {
        coffset = 2;
      } else {
        coffset = 1;
      }

      node->data[n] = coffset;
    }

    emxFree_real_T(&unusedU4);
    emxInit_real_T1(&r7, 1);
    i21 = scores->size[0];
    b_repmat(obj_ClassNames[boffset], i21, r7);
    for (boffset = 0; boffset < i20; boffset++) {
      r7->data[boffset] = obj_ClassNames[(int)node->data[boffset] - 1];
    }

    emxFree_real_T(&node);
    n = r7->size[0];
    for (i20 = 0; i20 < n; i20++) {
      labels->data[i20] = r7->data[i20];
    }

    emxFree_real_T(&r7);
  }
}

/* End of code generation (CompactClassificationTree.c) */
