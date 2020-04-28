/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateCache.c
 *
 * Code generation for function 'updateCache'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "updateCache.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"

/* Function Definitions */
void updateCache(const emxArray_real_T *learnerscore, emxArray_real_T
                 *cachedScore, emxArray_real_T *cachedWeights, boolean_T *cached,
                 const char combinerName[15], const emxArray_boolean_T
                 *obsIndices, emxArray_real_T *score)
{
  int i23;
  int loop_ub;
  int end;
  int i;
  emxArray_int32_T *r13;
  emxArray_int32_T *r14;
  emxArray_real_T *b_cachedScore;
  emxArray_int32_T *r15;
  emxArray_real_T *b_cachedWeights;
  boolean_T b_bool;
  int exitg1;
  static const char cv0[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

  static const char cv1[15] = { 'w', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'a', 'v',
    'e', 'r', 'a', 'g', 'e' };

  double c[2];
  boolean_T x[2];
  boolean_T exitg2;
  i23 = score->size[0] * score->size[1];
  score->size[0] = cachedScore->size[0];
  score->size[1] = 2;
  emxEnsureCapacity_real_T1(score, i23);
  loop_ub = cachedScore->size[0] * cachedScore->size[1];
  for (i23 = 0; i23 < loop_ub; i23++) {
    score->data[i23] = cachedScore->data[i23];
  }

  if (!*cached) {
    *cached = true;
    end = obsIndices->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r13, 1);
    i23 = r13->size[0];
    r13->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r13, i23);
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        r13->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    end = obsIndices->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r14, 1);
    i23 = r14->size[0];
    r14->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r14, i23);
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        r14->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_cachedScore, 2);
    i23 = b_cachedScore->size[0] * b_cachedScore->size[1];
    b_cachedScore->size[0] = r14->size[0];
    b_cachedScore->size[1] = 2;
    emxEnsureCapacity_real_T1(b_cachedScore, i23);
    for (i23 = 0; i23 < 2; i23++) {
      loop_ub = r14->size[0];
      for (end = 0; end < loop_ub; end++) {
        b_cachedScore->data[end + b_cachedScore->size[0] * i23] =
          cachedScore->data[(r14->data[end] + cachedScore->size[0] * i23) - 1] +
          learnerscore->data[(r13->data[end] + learnerscore->size[0] * i23) - 1];
      }
    }

    emxFree_int32_T(&r13);
    for (i23 = 0; i23 < 2; i23++) {
      loop_ub = b_cachedScore->size[0];
      for (end = 0; end < loop_ub; end++) {
        cachedScore->data[(r14->data[end] + cachedScore->size[0] * i23) - 1] =
          b_cachedScore->data[end + b_cachedScore->size[0] * i23];
      }
    }

    emxFree_real_T(&b_cachedScore);
    emxFree_int32_T(&r14);
    end = obsIndices->size[0] - 1;
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r15, 1);
    i23 = r15->size[0];
    r15->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r15, i23);
    loop_ub = 0;
    for (i = 0; i <= end; i++) {
      if (obsIndices->data[i]) {
        r15->data[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    emxInit_real_T1(&b_cachedWeights, 1);
    i23 = b_cachedWeights->size[0];
    b_cachedWeights->size[0] = r15->size[0];
    emxEnsureCapacity_real_T(b_cachedWeights, i23);
    loop_ub = r15->size[0];
    for (i23 = 0; i23 < loop_ub; i23++) {
      b_cachedWeights->data[i23] = cachedWeights->data[r15->data[i23] - 1] + 1.0;
    }

    loop_ub = b_cachedWeights->size[0];
    for (i23 = 0; i23 < loop_ub; i23++) {
      cachedWeights->data[r15->data[i23] - 1] = b_cachedWeights->data[i23];
    }

    emxFree_real_T(&b_cachedWeights);
    emxFree_int32_T(&r15);
    b_bool = false;
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub + 1 < 16) {
        if (cv0[(unsigned char)combinerName[loop_ub]] != cv0[(int)cv1[loop_ub]])
        {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (b_bool) {
      for (i = 0; i < cachedScore->size[0]; i++) {
        if (cachedWeights->data[i] == 0.0) {
          for (i23 = 0; i23 < 2; i23++) {
            x[i23] = (cachedScore->data[i + cachedScore->size[0] * i23] == 0.0);
          }

          b_bool = true;
          loop_ub = 1;
          exitg2 = false;
          while ((!exitg2) && (loop_ub < 3)) {
            if (!x[loop_ub - 1]) {
              b_bool = false;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }

          if (b_bool) {
            for (i23 = 0; i23 < 2; i23++) {
              score->data[i + score->size[0] * i23] = rtNaN;
            }
          } else {
            for (i23 = 0; i23 < 2; i23++) {
              x[i23] = (cachedScore->data[i + cachedScore->size[0] * i23] < 0.0);
            }

            b_bool = true;
            loop_ub = 1;
            exitg2 = false;
            while ((!exitg2) && (loop_ub < 3)) {
              if (!x[loop_ub - 1]) {
                b_bool = false;
                exitg2 = true;
              } else {
                loop_ub++;
              }
            }

            if (b_bool) {
              for (i23 = 0; i23 < 2; i23++) {
                score->data[i + score->size[0] * i23] = rtMinusInf;
              }
            } else {
              for (i23 = 0; i23 < 2; i23++) {
                score->data[i + score->size[0] * i23] = rtInf;
              }
            }
          }
        } else {
          for (loop_ub = 0; loop_ub < 2; loop_ub++) {
            c[loop_ub] = cachedScore->data[i + cachedScore->size[0] * loop_ub] /
              cachedWeights->data[i];
          }

          for (i23 = 0; i23 < 2; i23++) {
            score->data[i + score->size[0] * i23] = c[i23];
          }
        }
      }
    } else {
      for (i = 0; i < cachedScore->size[0]; i++) {
        for (i23 = 0; i23 < 2; i23++) {
          score->data[i + score->size[0] * i23] = cachedScore->data[i +
            cachedScore->size[0] * i23];
        }
      }
    }
  }
}

/* End of code generation (updateCache.c) */
