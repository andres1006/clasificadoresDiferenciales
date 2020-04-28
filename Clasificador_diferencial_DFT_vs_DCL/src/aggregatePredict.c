/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aggregatePredict.c
 *
 * Code generation for function 'aggregatePredict'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "aggregatePredict.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxutil.h"
#include "predictOneWithCache.h"

/* Function Definitions */
void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score, const
                      boolean_T isCached[30], const double classNames[2], const
                      double nonzeroProbClasses[2], const boolean_T learners[30],
                      const emxArray_boolean_T *useObsForLearner)
{
  emxArray_real_T *cachedScore;
  int i;
  int loop_ub;
  emxArray_real_T *cachedWeights;
  boolean_T firstCache;
  emxArray_boolean_T *b_useObsForLearner;
  boolean_T initCache;
  double weak_learner_ClassNames[2];
  double weak_learner_CutPoint[11];
  static const double dv0[11] = { 25.0, 0.0, 70.833333500000009,
    1.0614335000000001, 0.0, 0.2872725, 0.0, 0.0, 0.51029600000000008, 0.0, 0.0
  };

  double weak_learner_CutVar[11];
  static const signed char iv1[11] = { 5, 0, 5, 8, 0, 9, 0, 0, 8, 0, 0 };

  double weak_learner_Children[22];
  static const signed char iv2[22] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 0, 0,
    0, 0, 10, 11, 0, 0, 0, 0 };

  double weak_learner_ClassProb[22];
  static const double dv1[22] = { 0.32558139534883723, 1.0, 0.17142857142857143,
    0.35294117647058831, 0.0, 0.21428571428571436, 1.0, 0.0, 0.75, 1.0, 0.0,
    0.67441860465116288, 0.0, 0.82857142857142851, 0.64705882352941169, 1.0,
    0.7857142857142857, 0.0, 1.0, 0.24999999999999997, 0.0, 1.0 };

  double b_weak_learner_CutPoint[9];
  static const double dv2[9] = { 3.5, 0.0, 67.177588, 431.3500365, 0.0, 0.0,
    451.135087, 0.0, 0.0 };

  static const signed char iv3[6] = { 1, 4, 6, 7, 9, 10 };

  double b_weak_learner_CutVar[9];
  static const signed char iv4[9] = { 4, 0, 2, 3, 0, 0, 1, 0, 0 };

  static const double dv3[9] = { 0.1586745, 25.0, 6.5, 0.0, 0.0, 19.62359, 0.0,
    0.0, 0.0 };

  double b_weak_learner_Children[18];
  static const signed char iv5[18] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9,
    0, 0, 0, 0 };

  double weak_learner_Prior[2];
  static const signed char iv6[9] = { 9, 5, 6, 0, 0, 2, 0, 0, 0 };

  double b_weak_learner_ClassProb[18];
  static const double dv4[18] = { 0.41860465116279066, 1.0, 0.16666666666666669,
    0.038461538461538464, 1.0, 0.0, 0.5, 1.0, 0.0, 0.58139534883720934, 0.0,
    0.83333333333333337, 0.96153846153846145, 0.0, 1.0, 0.5, 0.0, 1.0 };

  double c_weak_learner_CutPoint[13];
  static const double dv5[13] = { 0.099886499999999989, 0.0, 0.284127, 25.0,
    63.284641500000006, 0.0, 0.0, 0.2701905, 83.333333500000009, 0.0, 0.0, 0.0,
    0.0 };

  static const signed char iv7[18] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv8[5] = { 1, 4, 5, 7, 8 };

  signed char I[4];
  double c_weak_learner_CutVar[13];
  static const signed char iv9[13] = { 9, 0, 9, 5, 2, 0, 0, 8, 5, 0, 0, 0, 0 };

  static const double dv6[18] = { 0.39534883720930231, 0.04545454545454547,
    0.76190476190476186, 1.0, 0.0, 0.94117647058823528, 0.0, 0.0, 1.0,
    0.60465116279069775, 0.95454545454545459, 0.23809523809523817, 0.0, 1.0,
    0.058823529411764726, 1.0, 1.0, 0.0 };

  double d_weak_learner_CutPoint[7];
  static const double dv7[7] = { 7.0, 29.1666665, 0.0, 0.0, 0.323639, 0.0, 0.0 };

  double c_weak_learner_Children[26];
  static const signed char iv10[26] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0,
    10, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv11[5] = { 3, 4, 6, 7, 8 };

  double d_weak_learner_CutVar[7];
  static const signed char iv12[7] = { 4, 5, 0, 0, 9, 0, 0 };

  double c_weak_learner_ClassProb[26];
  static const double dv8[26] = { 0.441860465116279, 1.0, 0.36842105263157893,
    0.23076923076923081, 0.66666666666666663, 1.0, 0.0, 0.4, 0.8571428571428571,
    1.0, 0.0, 1.0, 0.0, 0.55813953488372092, 0.0, 0.631578947368421,
    0.76923076923076916, 0.33333333333333331, 0.0, 1.0, 0.6, 0.14285714285714285,
    0.0, 1.0, 0.0, 1.0 };

  static const double dv9[9] = { 29.1666665, 0.0, 1.22147, 0.14940750000000003,
    0.0, 4.5, 0.0, 0.0, 0.0 };

  double d_weak_learner_Children[14];
  static const signed char iv13[14] = { 2, 3, 4, 5, 0, 0, 0, 0, 6, 7, 0, 0, 0, 0
  };

  static const signed char iv14[7] = { 1, 5, 6, 9, 10, 11, 12 };

  boolean_T b1;
  double weak_learner_Cost[4];
  static const signed char iv15[9] = { 5, 0, 8, 8, 0, 4, 0, 0, 0 };

  double d_weak_learner_ClassProb[14];
  static const double dv10[14] = { 0.41860465116279066, 0.78260869565217384, 0.0,
    1.0, 0.54545454545454541, 0.0, 1.0, 0.58139534883720934, 0.21739130434782614,
    1.0, 0.0, 0.45454545454545453, 1.0, 0.0 };

  static const double dv11[9] = { 43.75, 29.1666665, 0.0, 0.0, 0.4459635,
    0.1003225, 0.0, 0.0, 0.0 };

  static const signed char iv16[18] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv17[4] = { 2, 3, 5, 6 };

  static const signed char iv18[9] = { 7, 5, 0, 0, 9, 9, 0, 0, 0 };

  static const double dv12[18] = { 0.34883720930232548, 1.0, 0.12499999999999996,
    0.034482758620689648, 1.0, 0.19999999999999998, 0.0, 1.0, 0.0,
    0.65116279069767458, 0.0, 0.875, 0.96551724137931028, 0.0, 0.8, 1.0, 0.0,
    1.0 };

  static const double dv13[11] = { 29.1666665, 0.0, 0.340786, 326.153091, 10.0,
    0.0, 341.4339165, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv19[18] = { 2, 3, 4, 5, 0, 0, 0, 0, 6, 7, 8, 9, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv20[5] = { 1, 4, 6, 7, 8 };

  static const signed char iv21[11] = { 5, 0, 9, 3, 4, 0, 1, 0, 0, 0, 0 };

  static const double dv14[18] = { 0.441860465116279, 0.70370370370370372, 0.0,
    1.0, 0.5, 0.11111111111111112, 1.0, 1.0, 0.0, 0.55813953488372092,
    0.29629629629629639, 1.0, 0.0, 0.5, 0.888888888888889, 0.0, 0.0, 1.0 };

  static const double dv15[11] = { 3.0, 3.5, 326.153091, 0.0, 0.4459635, 0.0,
    0.284127, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv22[22] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10,
    11, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv23[5] = { 2, 3, 6, 7, 8 };

  static const signed char iv24[11] = { 6, 4, 3, 0, 9, 0, 9, 0, 0, 0, 0 };

  static const double dv16[22] = { 0.30232558139534876, 1.0, 0.14285714285714282,
    0.066666666666666666, 0.6, 0.0, 0.1428571428571429, 1.0, 0.0, 1.0, 0.0,
    0.69767441860465129, 0.0, 0.85714285714285721, 0.93333333333333335, 0.4, 1.0,
    0.85714285714285721, 0.0, 1.0, 0.0, 1.0 };

  static const char combiner[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'A',
    'v', 'e', 'r', 'a', 'g', 'e' };

  static const double dv17[11] = { 4.0, 29.1666665, 6.5, 0.0, 1.215706, 6.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const signed char iv25[22] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 0, 0, 10,
    11, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv26[6] = { 1, 5, 7, 8, 9, 10 };

  static const signed char iv27[11] = { 6, 5, 6, 0, 8, 4, 0, 0, 0, 0, 0 };

  static const double dv18[22] = { 0.46511627906976744, 0.77272727272727282,
    0.1428571428571429, 1.0, 0.28571428571428575, 0.0, 0.4285714285714286, 0.0,
    1.0, 0.0, 1.0, 0.53488372093023262, 0.22727272727272732, 0.8571428571428571,
    0.0, 0.7142857142857143, 1.0, 0.5714285714285714, 1.0, 0.0, 1.0, 0.0 };

  double e_weak_learner_CutPoint[15];
  static const double dv19[15] = { 3.5, 0.0, 0.2872725, 0.097860499999999989,
    451.135087, 0.1321345, 0.0, 6.5, 0.0, 0.0, 301.93816649999997, 0.0, 0.0, 0.0,
    0.0 };

  static const signed char iv28[22] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv29[6] = { 3, 5, 7, 8, 9, 10 };

  double e_weak_learner_CutVar[15];
  static const signed char iv30[15] = { 4, 0, 9, 9, 1, 8, 0, 6, 0, 0, 1, 0, 0, 0,
    0 };

  static const double dv20[22] = { 0.34883720930232548, 0.608695652173913, 0.05,
    1.0, 0.18181818181818177, 0.19999999999999998, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.65116279069767458, 0.39130434782608714, 0.95000000000000007, 0.0,
    0.81818181818181823, 0.8, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv21[9] = { 29.1666665, 0.0, 67.177588, 0.0, 62.5,
    0.2364715, 0.0, 0.0, 0.0 };

  double e_weak_learner_Children[30];
  static const signed char iv31[30] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0,
    0, 12, 13, 0, 0, 0, 0, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv32[6] = { 3, 6, 7, 8, 9, 10 };

  static const signed char iv33[9] = { 5, 0, 2, 0, 5, 9, 0, 0, 0 };

  double e_weak_learner_ClassProb[30];
  static const double dv22[30] = { 0.37209302325581389, 1.0, 0.1818181818181818,
    0.04347826086956523, 0.5, 0.25, 0.0, 0.625, 0.0, 0.0, 0.5, 1.0, 0.0, 0.0,
    1.0, 0.62790697674418616, 0.0, 0.81818181818181812, 0.9565217391304347, 0.5,
    0.75, 1.0, 0.375, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.0 };

  static const double dv23[15] = { 67.177588, 0.089859, 6.5, 0.0, 3.5, 0.2062475,
    0.0, 31.619408, 0.0, 0.0, 0.0, 0.0, 0.2701905, 0.0, 0.0 };

  static const signed char iv34[18] = { 2, 3, 0, 0, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv35[8] = { 1, 6, 8, 9, 11, 12, 13, 14 };

  static const signed char iv36[15] = { 2, 8, 6, 0, 6, 9, 0, 2, 0, 0, 0, 0, 8, 0,
    0 };

  static const double dv24[18] = { 0.30232558139534876, 1.0, 0.0909090909090909,
    0.0, 0.42857142857142855, 0.75, 0.0, 0.0, 1.0, 0.69767441860465129, 0.0,
    0.90909090909090906, 1.0, 0.5714285714285714, 0.25, 1.0, 1.0, 0.0 };

  static const double dv25[9] = { 3.5, 0.0, 252.0466085, 0.0, 0.340786, 0.0,
    10.0, 0.0, 0.0 };

  static const signed char iv37[30] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 0,
    0, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 0, 0, 0, 0 };

  static const signed char iv38[5] = { 1, 3, 6, 7, 8 };

  static const signed char iv39[9] = { 4, 0, 1, 0, 9, 0, 4, 0, 0 };

  static const double dv26[30] = { 0.34883720930232548, 0.13793103448275859,
    0.7857142857142857, 1.0, 0.07407407407407407, 0.91666666666666674, 0.0,
    0.19999999999999996, 0.0, 0.0, 1.0, 0.0, 0.66666666666666663, 1.0, 0.0,
    0.65116279069767458, 0.86206896551724133, 0.21428571428571436, 0.0,
    0.92592592592592593, 0.083333333333333356, 1.0, 0.8, 1.0, 1.0, 0.0, 1.0,
    0.33333333333333337, 0.0, 1.0 };

  static const double dv27[13] = { 70.833333500000009, 300.1895, 0.0, 64.011821,
    0.5, 0.0, 0.0, 41.0257035, 21.124108999999997, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv40[18] = { 2, 3, 0, 0, 4, 5, 0, 0, 6, 7, 0, 0, 8, 9,
    0, 0, 0, 0 };

  static const signed char iv41[8] = { 3, 6, 8, 9, 10, 11, 13, 14 };

  static const signed char iv42[13] = { 5, 1, 0, 2, 6, 0, 0, 2, 2, 0, 0, 0, 0 };

  static const double dv28[18] = { 0.39534883720930231, 1.0, 0.16129032258064516,
    1.0, 0.13333333333333336, 0.0, 0.5, 1.0, 0.0, 0.60465116279069775, 0.0,
    0.83870967741935487, 0.0, 0.8666666666666667, 1.0, 0.5, 0.0, 1.0 };

  double f_weak_learner_CutPoint[17];
  static const double dv29[17] = { 62.5, 300.1895, 0.14940750000000003, 6.25,
    409.32340899999997, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0, 451.8795,
    0.18366500000000002, 0.0, 0.0, 0.0 };

  static const signed char iv43[26] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 0, 0,
    10, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv44[5] = { 1, 3, 5, 7, 8 };

  double f_weak_learner_CutVar[17];
  static const signed char iv45[17] = { 7, 1, 8, 7, 3, 0, 0, 0, 0, 0, 4, 0, 3, 8,
    0, 0, 0 };

  static const double dv30[26] = { 0.37209302325581389, 0.6399999999999999, 0.0,
    0.3, 0.86666666666666659, 0.0, 1.0, 0.5, 0.92307692307692313, 0.0, 1.0, 0.0,
    1.0, 0.62790697674418616, 0.36000000000000004, 1.0, 0.7, 0.13333333333333336,
    1.0, 0.0, 0.5, 0.076923076923076941, 1.0, 0.0, 1.0, 0.0 };

  static const double dv31[13] = { 330.288498, 136.442135, 58.3333335, 1.2383515,
    0.0, 465.7279205, 332.483248, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  double f_weak_learner_Children[34];
  static const signed char iv46[34] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 12, 13, 0, 0, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0 };

  static const signed char iv47[7] = { 2, 5, 6, 9, 10, 11, 12 };

  static const signed char iv48[13] = { 1, 2, 5, 8, 0, 1, 1, 0, 0, 0, 0, 0, 0 };

  double f_weak_learner_ClassProb[34];
  static const double dv32[34] = { 0.441860465116279, 0.67999999999999983,
    0.11111111111111115, 0.4, 0.75, 1.0, 0.0, 1.0, 0.0, 1.0, 0.5, 1.0,
    0.16666666666666666, 0.33333333333333331, 0.0, 0.0, 1.0, 0.55813953488372092,
    0.32000000000000006, 0.888888888888889, 0.6, 0.25000000000000006, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.5, 0.0, 0.83333333333333337, 0.66666666666666663, 1.0, 1.0,
    0.0 };

  double g_weak_learner_CutPoint[21];
  static const double dv33[21] = { 56.25, 454.2860455, 0.3204935, 3.5, 0.0, 0.0,
    0.619189, 0.0, 31.25, 0.0, 0.0, 5.5, 290.122441, 0.0, 0.42881650000000004,
    7.5, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv49[26] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv50[9] = { 5, 6, 7, 8, 9, 11, 14, 15, 16 };

  double g_weak_learner_CutVar[21];
  static const signed char iv51[21] = { 7, 3, 9, 4, 0, 0, 9, 0, 7, 0, 0, 4, 3, 0,
    9, 4, 0, 0, 0, 0, 0 };

  static const double dv34[26] = { 0.48837209302325585, 0.16666666666666671,
    0.71999999999999986, 0.062500000000000014, 1.0, 0.94117647058823528, 0.25,
    0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.51162790697674421, 0.83333333333333326,
    0.28000000000000008, 0.9375, 0.0, 0.058823529411764726, 0.75, 1.0, 0.0, 0.0,
    1.0, 0.0, 1.0 };

  static const double dv35[11] = { 70.833333500000009, 309.4053185, 0.0,
    224.922435, 14.3570195, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0 };

  double g_weak_learner_Children[42];
  static const signed char iv52[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 10,
    11, 0, 0, 12, 13, 0, 0, 0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv53[7] = { 4, 7, 8, 9, 10, 11, 12 };

  static const signed char iv54[11] = { 5, 3, 0, 3, 2, 0, 0, 0, 6, 0, 0 };

  double g_weak_learner_ClassProb[42];
  static const double dv36[42] = { 0.32558139534883723, 0.48148148148148151,
    0.062500000000000028, 0.39130434782608714, 1.0, 0.0, 0.50000000000000011,
    1.0, 0.2631578947368422, 1.0, 0.0, 0.076923076923076955, 0.66666666666666663,
    0.0, 0.20000000000000004, 0.33333333333333337, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.67441860465116288, 0.51851851851851838, 0.9375, 0.608695652173913, 0.0,
    1.0, 0.5, 0.0, 0.73684210526315785, 0.0, 1.0, 0.92307692307692313,
    0.33333333333333326, 1.0, 0.8, 0.66666666666666663, 0.0, 1.0, 0.0, 0.0, 1.0
  };

  static const double dv37[11] = { 337.3475835, 58.3333335, 3.5, 224.922435, 0.0,
    0.0, 353.941125, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv55[22] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 0, 0,
    0, 0, 10, 11, 0, 0, 0, 0 };

  static const signed char iv56[11] = { 4, 5, 7, 9, 10, 13, 16, 17, 18, 19, 20 };

  static const signed char iv57[11] = { 1, 5, 4, 3, 0, 0, 1, 0, 0, 0, 0 };

  static const double dv38[22] = { 0.48837209302325585, 0.74999999999999989, 0.0,
    0.2, 0.86956521739130432, 1.0, 0.0, 0.0, 0.95238095238095244, 1.0, 0.0,
    0.51162790697674421, 0.25000000000000011, 1.0, 0.8, 0.13043478260869568, 0.0,
    1.0, 1.0, 0.047619047619047637, 0.0, 1.0 };

  static const double dv39[7] = { 29.1666665, 0.0, 45.833333, 0.170302, 0.0, 0.0,
    0.0 };

  static const signed char iv58[22] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 10,
    11, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv59[6] = { 2, 5, 6, 7, 9, 10 };

  static const signed char iv60[7] = { 5, 0, 5, 8, 0, 0, 0 };

  static const double dv40[22] = { 0.39534883720930231, 0.10526315789473686,
    0.625, 0.4, 0.0, 1.0, 0.1818181818181818, 1.0, 0.0, 1.0, 0.0,
    0.60465116279069775, 0.894736842105263, 0.37500000000000006, 0.6, 1.0, 0.0,
    0.81818181818181812, 0.0, 1.0, 0.0, 1.0 };

  static const double dv41[9] = { 0.3220275, 0.5, 75.0, 0.1837365, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const signed char iv61[14] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0
  };

  static const signed char iv62[6] = { 4, 5, 7, 8, 9, 10 };

  static const signed char iv63[9] = { 9, 6, 5, 9, 0, 0, 0, 0, 0 };

  static const double dv42[14] = { 0.441860465116279, 1.0, 0.040000000000000008,
    0.25, 0.0, 1.0, 0.0, 0.55813953488372092, 0.0, 0.96, 0.75, 1.0, 0.0, 1.0 };

  static const double dv43[17] = { 5.0, 46.082968, 71.273926499999988, 2.5,
    70.833333500000009, 0.0, 77.678035, 0.0, 339.79695449999997,
    409.32340899999997, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv64[18] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv65[4] = { 1, 4, 5, 6 };

  static const signed char iv66[17] = { 6, 2, 2, 6, 5, 0, 2, 0, 3, 3, 0, 0, 0, 0,
    0, 0, 0 };

  static const double dv44[18] = { 0.18604651162790689, 0.10810810810810809,
    0.66666666666666663, 0.66666666666666663, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.813953488372093, 0.891891891891892, 0.33333333333333331,
    0.33333333333333331, 1.0, 0.0, 1.0, 0.0, 1.0 };

  static const double dv45[9] = { 29.1666665, 0.0, 8.5, 62.5, 0.0, 0.0,
    249.82998200000003, 0.0, 0.0 };

  static const signed char iv67[34] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 0, 0, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv68[9] = { 5, 0, 4, 5, 0, 0, 3, 0, 0 };

  static const double dv46[34] = { 0.27906976744186041, 0.45833333333333337,
    0.052631578947368439, 0.083333333333333356, 0.83333333333333337, 0.0, 0.2,
    0.0, 0.5, 0.90909090909090917, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.72093023255813971, 0.54166666666666663, 0.94736842105263164,
    0.91666666666666674, 0.16666666666666671, 1.0, 0.8, 1.0, 0.5,
    0.090909090909090925, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv47[9] = { 3.5, 0.0, 35.072340999999994, 0.0, 2.0, 0.0,
    5.0, 0.0, 0.0 };

  static const signed char iv69[9] = { 5, 7, 10, 11, 12, 13, 14, 15, 16 };

  static const signed char iv70[9] = { 4, 0, 2, 0, 6, 0, 6, 0, 0 };

  static const double dv48[18] = { 0.20930232558139528, 1.0,
    0.081081081081081058, 0.17647058823529416, 0.0, 0.0, 0.6, 0.0, 1.0,
    0.79069767441860472, 0.0, 0.918918918918919, 0.82352941176470584, 1.0, 1.0,
    0.4, 1.0, 0.0 };

  static const double dv49[11] = { 29.1666665, 0.0, 0.097860499999999989,
    35.072340999999994, 0.2872725, 0.0, 0.0, 0.0, 0.3010105, 0.0, 0.0 };

  static const signed char iv71[11] = { 5, 0, 9, 2, 9, 0, 0, 0, 8, 0, 0 };

  static const double dv50[18] = { 0.37209302325581389, 1.0, 0.1818181818181818,
    0.0, 0.375, 0.0, 0.54545454545454541, 1.0, 0.0, 0.62790697674418616, 0.0,
    0.81818181818181812, 1.0, 0.62499999999999989, 1.0, 0.45454545454545453, 0.0,
    1.0 };

  static const double dv51[9] = { 3.5, 0.0, 1.0614335000000001, 437.4379545, 0.0,
    0.0, 418.74731399999996, 0.0, 0.0 };

  static const signed char iv72[22] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0,
    0, 0, 10, 11, 0, 0, 0, 0 };

  static const signed char iv73[9] = { 4, 0, 8, 3, 0, 0, 1, 0, 0 };

  static const double dv52[22] = { 0.34883720930232548, 1.0, 0.15151515151515149,
    0.6, 0.071428571428571425, 0.0, 1.0, 0.0, 0.5, 1.0, 0.0, 0.65116279069767458,
    0.0, 0.84848484848484851, 0.4, 0.9285714285714286, 1.0, 0.0, 1.0,
    0.50000000000000011, 0.0, 1.0 };

  static const double dv53[17] = { 3.5, 0.0, 217.62497150000002, 0.0, 330.288498,
    356.827073, 0.329026, 0.0, 0.0, 80.985182500000008, 0.0, 54.166666500000005,
    0.0, 45.833333499999995, 0.0, 0.0, 0.0 };

  static const signed char iv74[6] = { 1, 5, 6, 7, 9, 10 };

  static const double dv54[11] = { 4.5, 32.4968925, 0.0, 0.0, 0.285437,
    0.23827099999999998, 0.0, 0.0, 371.5416365, 0.0, 0.0 };

  static const signed char iv75[17] = { 4, 0, 3, 0, 1, 3, 9, 0, 0, 2, 0, 5, 0, 5,
    0, 0, 0 };

  static const double dv55[18] = { 0.34883720930232548, 1.0, 0.15151515151515149,
    0.034482758620689648, 1.0, 0.0, 0.19999999999999998, 1.0, 0.0,
    0.65116279069767458, 0.0, 0.84848484848484851, 0.96551724137931028, 0.0, 1.0,
    0.8, 0.0, 1.0 };

  static const signed char iv76[11] = { 6, 2, 0, 0, 8, 9, 0, 0, 3, 0, 0 };

  static const double dv56[11] = { 3.5, 0.0, 70.833333500000009, 5.0, 0.0, 0.0,
    32.2823395, 0.0, 4.5, 0.0, 0.0 };

  static const signed char iv77[34] = { 2, 3, 0, 0, 4, 5, 0, 0, 6, 7, 8, 9, 10,
    11, 0, 0, 0, 0, 12, 13, 0, 0, 14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0 };

  static const signed char iv78[22] = { 2, 3, 4, 5, 0, 0, 0, 0, 6, 7, 8, 9, 0, 0,
    0, 0, 10, 11, 0, 0, 0, 0 };

  static const signed char iv79[11] = { 4, 0, 5, 4, 0, 0, 2, 0, 6, 0, 0 };

  static const double dv57[34] = { 0.39534883720930231, 1.0, 0.23529411764705882,
    1.0, 0.1875, 0.055555555555555573, 0.35714285714285715, 0.0, 1.0,
    0.1818181818181818, 1.0, 0.1, 1.0, 0.25, 0.0, 0.0, 1.0, 0.60465116279069775,
    0.0, 0.76470588235294112, 0.0, 0.8125, 0.94444444444444442,
    0.6428571428571429, 1.0, 0.0, 0.81818181818181812, 0.0, 0.9, 0.0, 0.75, 1.0,
    1.0, 0.0 };

  static const double dv58[22] = { 0.53488372093023262, 0.793103448275862, 0.0,
    0.0, 0.92, 0.81818181818181823, 1.0, 1.0, 0.49999999999999994, 0.0, 1.0,
    0.46511627906976744, 0.20689655172413796, 1.0, 1.0, 0.080000000000000029,
    0.18181818181818188, 0.0, 0.0, 0.5, 1.0, 0.0 };

  static const signed char iv80[22] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9,
    0, 0, 10, 11, 0, 0, 0, 0 };

  static const signed char iv81[9] = { 1, 3, 7, 8, 10, 12, 14, 15, 16 };

  static const signed char iv82[6] = { 2, 3, 6, 7, 9, 10 };

  static const double dv59[22] = { 0.41860465116279066, 1.0, 0.16666666666666669,
    0.26315789473684215, 0.0, 0.0, 0.5, 0.0, 0.71428571428571419, 1.0, 0.0,
    0.58139534883720934, 0.0, 0.83333333333333337, 0.73684210526315785, 1.0, 1.0,
    0.5, 1.0, 0.2857142857142857, 0.0, 1.0 };

  static const signed char iv83[6] = { 1, 4, 5, 7, 9, 10 };

  emxInit_real_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real_T1(cachedScore, i);
  loop_ub = score->size[0] * score->size[1];
  for (i = 0; i < loop_ub; i++) {
    cachedScore->data[i] = score->data[i];
  }

  emxInit_real_T1(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real_T(cachedWeights, i);
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    cachedWeights->data[i] = 0.0;
  }

  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv0[i];
      weak_learner_CutVar[i] = iv1[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv2[i];
      weak_learner_ClassProb[i] = dv1[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv3[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.32558139534883723 + 0.34883720930232553 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = false;
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, true, score);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv2[i];
      b_weak_learner_CutVar[i] = iv4[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv5[i];
      b_weak_learner_ClassProb[i] = dv4[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv8[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.41860465116279072 + 0.16279069767441862 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[1];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0]];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv3[i];
      b_weak_learner_CutVar[i] = iv6[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv7[i];
      b_weak_learner_ClassProb[i] = dv6[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv11[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.39534883720930231 + 0.20930232558139533 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[2];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        (useObsForLearner->size[0] << 1)];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 13; i++) {
      c_weak_learner_CutPoint[i] = dv5[i];
      c_weak_learner_CutVar[i] = iv9[i];
    }

    for (i = 0; i < 26; i++) {
      c_weak_learner_Children[i] = iv10[i];
      c_weak_learner_ClassProb[i] = dv8[i];
    }

    for (i = 0; i < 7; i++) {
      c_weak_learner_CutPoint[iv14[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.44186046511627908 + 0.11627906976744184 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[3];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 3];
    }

    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutVar, c_weak_learner_Children,
                          c_weak_learner_ClassProb, c_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 7; i++) {
      d_weak_learner_CutPoint[i] = dv7[i];
      d_weak_learner_CutVar[i] = iv12[i];
    }

    for (i = 0; i < 14; i++) {
      d_weak_learner_Children[i] = iv13[i];
      d_weak_learner_ClassProb[i] = dv10[i];
    }

    for (i = 0; i < 4; i++) {
      d_weak_learner_CutPoint[iv17[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.41860465116279072 + 0.16279069767441862 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[4];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        (useObsForLearner->size[0] << 2)];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutVar, d_weak_learner_Children,
                          d_weak_learner_ClassProb, d_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv9[i];
      b_weak_learner_CutVar[i] = iv15[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv16[i];
      b_weak_learner_ClassProb[i] = dv12[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv20[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.34883720930232559 + 0.30232558139534887 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[5];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 5];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv11[i];
      b_weak_learner_CutVar[i] = iv18[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv19[i];
      b_weak_learner_ClassProb[i] = dv14[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv23[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.44186046511627908 + 0.11627906976744184 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[6];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 6];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv13[i];
      weak_learner_CutVar[i] = iv21[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv22[i];
      weak_learner_ClassProb[i] = dv16[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv26[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.30232558139534882 + 0.39534883720930236 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[7];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 7];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv15[i];
      weak_learner_CutVar[i] = iv24[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv25[i];
      weak_learner_ClassProb[i] = dv18[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv29[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.46511627906976744 + 0.069767441860465074 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[8];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        (useObsForLearner->size[0] << 3)];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv17[i];
      weak_learner_CutVar[i] = iv27[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv28[i];
      weak_learner_ClassProb[i] = dv20[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv32[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.34883720930232559 + 0.30232558139534887 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[9];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 9];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 15; i++) {
      e_weak_learner_CutPoint[i] = dv19[i];
      e_weak_learner_CutVar[i] = iv30[i];
    }

    for (i = 0; i < 30; i++) {
      e_weak_learner_Children[i] = iv31[i];
      e_weak_learner_ClassProb[i] = dv22[i];
    }

    for (i = 0; i < 8; i++) {
      e_weak_learner_CutPoint[iv35[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.37209302325581395 + 0.2558139534883721 * (double)
        i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[10];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 10];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutVar, e_weak_learner_Children,
                          e_weak_learner_ClassProb, e_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv21[i];
      b_weak_learner_CutVar[i] = iv33[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv34[i];
      b_weak_learner_ClassProb[i] = dv24[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv38[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.30232558139534882 + 0.39534883720930236 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[11];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 11];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 15; i++) {
      e_weak_learner_CutPoint[i] = dv23[i];
      e_weak_learner_CutVar[i] = iv36[i];
    }

    for (i = 0; i < 30; i++) {
      e_weak_learner_Children[i] = iv37[i];
      e_weak_learner_ClassProb[i] = dv26[i];
    }

    for (i = 0; i < 8; i++) {
      e_weak_learner_CutPoint[iv41[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.34883720930232559 + 0.30232558139534887 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[12];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 12];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutVar, e_weak_learner_Children,
                          e_weak_learner_ClassProb, e_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv25[i];
      b_weak_learner_CutVar[i] = iv39[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv40[i];
      b_weak_learner_ClassProb[i] = dv28[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv44[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.39534883720930231 + 0.20930232558139533 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[13];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 13];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 13; i++) {
      c_weak_learner_CutPoint[i] = dv27[i];
      c_weak_learner_CutVar[i] = iv42[i];
    }

    for (i = 0; i < 26; i++) {
      c_weak_learner_Children[i] = iv43[i];
      c_weak_learner_ClassProb[i] = dv30[i];
    }

    for (i = 0; i < 7; i++) {
      c_weak_learner_CutPoint[iv47[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.37209302325581395 + 0.2558139534883721 * (double)
        i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[14];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 14];
    }

    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutVar, c_weak_learner_Children,
                          c_weak_learner_ClassProb, c_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 17; i++) {
      f_weak_learner_CutPoint[i] = dv29[i];
      f_weak_learner_CutVar[i] = iv45[i];
    }

    for (i = 0; i < 34; i++) {
      f_weak_learner_Children[i] = iv46[i];
      f_weak_learner_ClassProb[i] = dv32[i];
    }

    for (i = 0; i < 9; i++) {
      f_weak_learner_CutPoint[iv50[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.44186046511627908 + 0.11627906976744184 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[15];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 15];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutVar, f_weak_learner_Children,
                          f_weak_learner_ClassProb, f_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 13; i++) {
      c_weak_learner_CutPoint[i] = dv31[i];
      c_weak_learner_CutVar[i] = iv48[i];
    }

    for (i = 0; i < 26; i++) {
      c_weak_learner_Children[i] = iv49[i];
      c_weak_learner_ClassProb[i] = dv34[i];
    }

    for (i = 0; i < 7; i++) {
      c_weak_learner_CutPoint[iv53[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.48837209302325579 + 0.023255813953488413 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[16];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        (useObsForLearner->size[0] << 4)];
    }

    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutVar, c_weak_learner_Children,
                          c_weak_learner_ClassProb, c_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 21; i++) {
      g_weak_learner_CutPoint[i] = dv33[i];
      g_weak_learner_CutVar[i] = iv51[i];
    }

    for (i = 0; i < 42; i++) {
      g_weak_learner_Children[i] = iv52[i];
      g_weak_learner_ClassProb[i] = dv36[i];
    }

    for (i = 0; i < 11; i++) {
      g_weak_learner_CutPoint[iv56[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.32558139534883723 + 0.34883720930232553 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[17];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 17];
    }

    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutVar, g_weak_learner_Children,
                          g_weak_learner_ClassProb, g_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv35[i];
      weak_learner_CutVar[i] = iv54[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv55[i];
      weak_learner_ClassProb[i] = dv38[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv59[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.48837209302325579 + 0.023255813953488413 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[18];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 18];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv37[i];
      weak_learner_CutVar[i] = iv57[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv58[i];
      weak_learner_ClassProb[i] = dv40[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv62[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.39534883720930231 + 0.20930232558139533 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[19];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 19];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 7; i++) {
      d_weak_learner_CutPoint[i] = dv39[i];
      d_weak_learner_CutVar[i] = iv60[i];
    }

    for (i = 0; i < 14; i++) {
      d_weak_learner_Children[i] = iv61[i];
      d_weak_learner_ClassProb[i] = dv42[i];
    }

    for (i = 0; i < 4; i++) {
      d_weak_learner_CutPoint[iv65[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.44186046511627908 + 0.11627906976744184 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[20];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 20];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutVar, d_weak_learner_Children,
                          d_weak_learner_ClassProb, d_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv41[i];
      b_weak_learner_CutVar[i] = iv63[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv64[i];
      b_weak_learner_ClassProb[i] = dv44[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[i + 4] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.18604651162790697 + 0.627906976744186 * (double)
        i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[21];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 21];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 17; i++) {
      f_weak_learner_CutPoint[i] = dv43[i];
      f_weak_learner_CutVar[i] = iv66[i];
    }

    for (i = 0; i < 34; i++) {
      f_weak_learner_Children[i] = iv67[i];
      f_weak_learner_ClassProb[i] = dv46[i];
    }

    for (i = 0; i < 9; i++) {
      f_weak_learner_CutPoint[iv69[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.27906976744186046 + 0.441860465116279 * (double)
        i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[22];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 22];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutVar, f_weak_learner_Children,
                          f_weak_learner_ClassProb, f_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv45[i];
      b_weak_learner_CutVar[i] = iv68[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv5[i];
      b_weak_learner_ClassProb[i] = dv48[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv8[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.20930232558139536 + 0.58139534883720922 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[23];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 23];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv47[i];
      b_weak_learner_CutVar[i] = iv70[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv40[i];
      b_weak_learner_ClassProb[i] = dv50[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv44[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.37209302325581395 + 0.2558139534883721 * (double)
        i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[24];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 24];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv49[i];
      weak_learner_CutVar[i] = iv71[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv72[i];
      weak_learner_ClassProb[i] = dv52[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv74[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.34883720930232559 + 0.30232558139534887 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[25];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 25];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 9; i++) {
      b_weak_learner_CutPoint[i] = dv51[i];
      b_weak_learner_CutVar[i] = iv73[i];
    }

    for (i = 0; i < 18; i++) {
      b_weak_learner_Children[i] = iv5[i];
      b_weak_learner_ClassProb[i] = dv55[i];
    }

    for (i = 0; i < 5; i++) {
      b_weak_learner_CutPoint[iv8[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.34883720930232559 + 0.30232558139534887 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[26];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 26];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutVar, b_weak_learner_Children,
                          b_weak_learner_ClassProb, b_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 17; i++) {
      f_weak_learner_CutPoint[i] = dv53[i];
      f_weak_learner_CutVar[i] = iv75[i];
    }

    for (i = 0; i < 34; i++) {
      f_weak_learner_Children[i] = iv77[i];
      f_weak_learner_ClassProb[i] = dv57[i];
    }

    for (i = 0; i < 9; i++) {
      f_weak_learner_CutPoint[iv81[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.39534883720930231 + 0.20930232558139533 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[27];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 27];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutVar, f_weak_learner_Children,
                          f_weak_learner_ClassProb, f_weak_learner_CutPoint,
                          weak_learner_ClassNames, weak_learner_Prior,
                          weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv56[i];
      weak_learner_CutVar[i] = iv79[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv80[i];
      weak_learner_ClassProb[i] = dv59[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv83[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.41860465116279072 + 0.16279069767441862 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[28];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 28];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, initCache, score);
  }

  if (learners[29]) {
    for (i = 0; i < 2; i++) {
      weak_learner_ClassNames[i] = 5.0 + 4.0 * (double)i;
    }

    for (i = 0; i < 11; i++) {
      weak_learner_CutPoint[i] = dv54[i];
      weak_learner_CutVar[i] = iv76[i];
    }

    for (i = 0; i < 22; i++) {
      weak_learner_Children[i] = iv78[i];
      weak_learner_ClassProb[i] = dv58[i];
    }

    for (i = 0; i < 6; i++) {
      weak_learner_CutPoint[iv82[i]] = rtNaN;
    }

    for (i = 0; i < 2; i++) {
      weak_learner_Prior[i] = 0.53488372093023251 + -0.069767441860465074 *
        (double)i;
    }

    for (i = 0; i < 4; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 2; i++) {
      I[i + (i << 1)] = 1;
    }

    for (i = 0; i < 4; i++) {
      weak_learner_Cost[i] = 1.0 - (double)I[i];
    }

    b1 = isCached[29];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T1(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i +
        useObsForLearner->size[0] * 29];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutVar, weak_learner_Children,
                        weak_learner_ClassProb, weak_learner_CutPoint,
                        weak_learner_ClassNames, weak_learner_Prior,
                        weak_learner_Cost, &b1, classNames, nonzeroProbClasses,
                        b_useObsForLearner, firstCache, score);
  }

  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real_T(&cachedWeights);
  emxFree_real_T(&cachedScore);
}

/* End of code generation (aggregatePredict.c) */
