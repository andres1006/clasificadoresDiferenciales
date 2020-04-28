/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_EA_vs_DCL.c
 *
 * Code generation for function 'Clasificador_diferencial_EA_vs_DCL'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxutil.h"
#include "ClassificationKNN.h"
#include "bsxfun.h"

/* Function Definitions */
void Clasificador_diferencial_EA_vs_DCL(const emxArray_real_T *x,
  emxArray_real_T *label)
{
  double Mdl_X[172];
  static const double dv0[172] = { -0.85418725898320336, -1.3789022895014575,
    -0.067114713205822157, -0.85418725898320336, -1.1165447742423305,
    0.19524280205330491, -0.85418725898320336, 0.45760031731243195,
    -1.3789022895014575, 0.98231534783068608, -1.1165447742423305,
    -0.32947222846494922, -1.3789022895014575, -1.1165447742423305,
    -1.1165447742423305, -0.32947222846494922, 0.45760031731243195,
    -0.85418725898320336, -1.1165447742423305, -1.3789022895014575,
    -0.067114713205822157, 0.19524280205330491, -0.32947222846494922,
    0.719957832571559, -0.59182974372407626, 1.5070303783489403,
    1.5070303783489403, 1.2446728630898132, 1.2446728630898132,
    1.2446728630898132, -0.067114713205822157, 0.45760031731243195,
    1.5070303783489403, 0.98231534783068608, 1.5070303783489403,
    -1.1165447742423305, -0.59182974372407626, -0.59182974372407626,
    0.719957832571559, 0.719957832571559, 1.2446728630898132, 1.7693878936080674,
    -0.067114713205822157, -0.46318722291333259, -1.5948378243493189,
    0.21580313794825925, 0.21580313794825925, -1.3685077040621216,
    -0.2368571026261353, -0.2368571026261353, 0.21580313794825925,
    -1.5948378243493189, 1.1211236190970484, -1.1421775837749244,
    1.1211236190970484, -1.5948378243493189, -1.3685077040621216,
    -0.915847463487727, -0.2368571026261353, 0.21580313794825925,
    -1.1421775837749244, -1.3685077040621216, -1.5948378243493189,
    -0.46318722291333259, -0.010526982338938019, -0.46318722291333259,
    0.894793498809851, 0.894793498809851, 0.894793498809851, 1.1211236190970484,
    1.1211236190970484, 0.894793498809851, 1.1211236190970484, 0.894793498809851,
    1.1211236190970484, 1.1211236190970484, 0.44213325823545652,
    0.894793498809851, -1.3685077040621216, -0.915847463487727,
    -0.915847463487727, 0.44213325823545652, 1.1211236190970484,
    0.66846337852265381, 1.1211236190970484, 1.1211236190970484,
    -0.85418724699863047, -1.3789022872456507, -0.067114702369551055,
    -0.85418724699863047, -1.1165447828635915, 0.19524280201250829,
    -0.85418724699863047, 0.45760030639456767, -1.3789022872456507,
    0.98231534664158782, -1.1165447828635915, -0.32947223823451188,
    -1.3789022872456507, -1.1165447828635915, -1.1165447828635915,
    -0.32947223823451188, 0.45760030639456767, -0.85418724699863047,
    -1.1165447828635915, -1.3789022872456507, -0.067114702369551055,
    0.19524280201250829, -0.32947223823451188, 0.71995784225952875,
    -0.59182974261657129, 1.5070303868886084, 1.5070303868886084,
    1.2446728510236469, 1.2446728510236469, 1.2446728510236469,
    -0.067114702369551055, 0.45760030639456767, 1.5070303868886084,
    0.98231534664158782, 1.5070303868886084, -1.1165447828635915,
    -0.59182974261657129, -0.59182974261657129, 0.71995784225952875,
    0.71995784225952875, 1.2446728510236469, 1.7693878912706673,
    -0.067114702369551055, -1.0208923506771237, -0.46468307918113594,
    0.91156288151798393, 0.14661762354038968, -1.3081841358537922,
    -0.055791633035974356, 0.32637036712506723, 0.45057872484491229,
    0.79884669279673193, 0.9758736592709506, 1.2487133376203532,
    -1.4678590613561144, 1.1736289715728125, 1.2975695079712006,
    -0.80498006993450466, 1.7267187832508446, 0.14101532835712122,
    1.0612618286721485, 1.1080259193562028, 0.80145173078686194,
    -0.43188887059527531, -0.69027205160394545, -0.82645407129921078,
    -0.17679345242077737, 0.13786659844938851, 0.064193782481331257,
    -0.18986035224935882, -1.4885025239234055, 0.20578564651958292,
    -1.3971315481718416, -1.1225685932868334, -0.0064327488932115554,
    2.1690864310736648, -1.2701418001709619, -0.52838723432347934,
    1.8916118340081152, -0.2407361587948014, 1.1027016900258135,
    -0.41379922336100494, -1.4217857447907909, -0.46099577962151095,
    -0.6682836284114132, -1.283057227284949 };

  int i;
  int acoef;
  unsigned int Mdl_YIdx[43];
  static const signed char iv0[43] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2 };

  double Mdl_W[43];
  static const double dv1[43] = { 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488372, 0.023255813953488372, 0.023255813953488372,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368, 0.023255813953488368,
    0.023255813953488368, 0.023255813953488368 };

  int k;
  double Mdl_Mu[4];
  static const double dv2[4] = { 5.2558139534883681, 7.0465116279069706,
    43.798449604651132, 2.8010908837209283 };

  double Mdl_Sigma[4];
  static const double dv3[4] = { 3.811592738299542, 4.4183248731148517,
    31.763272865503964, 1.3665827575214788 };

  signed char I[4];
  signed char cost[4];
  emxArray_real_T *Xin;
  signed char Mdl_Cost[4];
  emxArray_real_T *a;
  emxArray_real_T *posteriors;
  emxArray_boolean_T *nonnanscoreindices;
  emxArray_real_T *b_cost;
  int coffset;
  int m;
  emxArray_real_T *classnum;
  int boffset;
  int aoffset;

  /* PREDICTLABELSSVM Label new observations using trained SVM model Mdl */
  /*    predictLabelsSVM predicts the vector of labels label using  */
  /*    the saved SVM model Mdl and the predictor data x. */
  memcpy(&Mdl_X[0], &dv0[0], 172U * sizeof(double));
  for (i = 0; i < 43; i++) {
    Mdl_YIdx[i] = (unsigned int)iv0[i];
    Mdl_W[i] = dv1[i];
  }

  for (acoef = 0; acoef < 4; acoef++) {
    Mdl_Mu[acoef] = dv2[acoef];
    Mdl_Sigma[acoef] = dv3[acoef];
    I[acoef] = 0;
  }

  for (k = 0; k < 2; k++) {
    I[k + (k << 1)] = 1;
  }

  for (acoef = 0; acoef < 4; acoef++) {
    cost[acoef] = (signed char)(1 - I[acoef]);
    Mdl_Cost[acoef] = (signed char)(1 - I[acoef]);
  }

  if (x->size[0] == 0) {
    acoef = label->size[0];
    label->size[0] = 0;
    emxEnsureCapacity_real_T(label, acoef);
  } else {
    emxInit_real_T(&Xin, 2);
    emxInit_real_T(&a, 2);
    bsxfun(x, Mdl_Mu, Xin);
    acoef = a->size[0] * a->size[1];
    a->size[0] = Xin->size[0];
    a->size[1] = 4;
    emxEnsureCapacity_real_T1(a, acoef);
    i = Xin->size[0] * Xin->size[1];
    for (acoef = 0; acoef < i; acoef++) {
      a->data[acoef] = Xin->data[acoef];
    }

    i = Xin->size[0];
    acoef = Xin->size[0] * Xin->size[1];
    Xin->size[0] = i;
    Xin->size[1] = 4;
    emxEnsureCapacity_real_T1(Xin, acoef);
    if (Xin->size[0] != 0) {
      for (k = 0; k < 4; k++) {
        i = Xin->size[0];
        acoef = (a->size[0] != 1);
        for (coffset = 0; coffset < i; coffset++) {
          Xin->data[coffset + Xin->size[0] * k] = a->data[acoef * coffset +
            a->size[0] * k] / Mdl_Sigma[k];
        }
      }
    }

    emxFree_real_T(&a);
    emxInit_real_T(&posteriors, 2);
    emxInit_boolean_T(&nonnanscoreindices, 1);
    emxInit_real_T(&b_cost, 2);
    ClassificationKNN_score(Mdl_X, Mdl_YIdx, Mdl_W, Xin, posteriors,
      nonnanscoreindices);
    m = posteriors->size[0];
    acoef = b_cost->size[0] * b_cost->size[1];
    b_cost->size[0] = posteriors->size[0];
    b_cost->size[1] = 2;
    emxEnsureCapacity_real_T1(b_cost, acoef);
    emxFree_real_T(&Xin);
    for (acoef = 0; acoef < 2; acoef++) {
      coffset = acoef * m;
      boffset = acoef << 1;
      for (i = 1; i <= m; i++) {
        b_cost->data[(coffset + i) - 1] = 0.0;
      }

      for (k = 0; k < 2; k++) {
        if (Mdl_Cost[boffset + k] != 0) {
          aoffset = k * m;
          for (i = 0; i < m; i++) {
            b_cost->data[coffset + i] += (double)cost[boffset + k] *
              posteriors->data[aoffset + i];
          }
        }
      }
    }

    emxInit_real_T1(&classnum, 1);
    acoef = classnum->size[0];
    classnum->size[0] = posteriors->size[0];
    emxEnsureCapacity_real_T(classnum, acoef);
    for (i = 0; i < nonnanscoreindices->size[0]; i++) {
      if (nonnanscoreindices->data[i]) {
        if ((b_cost->data[i] > b_cost->data[i + b_cost->size[0]]) || (rtIsNaN
             (b_cost->data[i]) && (!rtIsNaN(b_cost->data[i + b_cost->size[0]]))))
        {
          acoef = 2;
        } else {
          acoef = 1;
        }

        classnum->data[i] = acoef;
      }
    }

    emxFree_real_T(&b_cost);
    i = posteriors->size[0];
    acoef = label->size[0];
    label->size[0] = i;
    emxEnsureCapacity_real_T(label, acoef);
    emxFree_real_T(&posteriors);
    for (acoef = 0; acoef < i; acoef++) {
      label->data[acoef] = 9.0;
    }

    for (i = 0; i < nonnanscoreindices->size[0]; i++) {
      if (nonnanscoreindices->data[i]) {
        label->data[i] = (signed char)(2 + (signed char)(7 * (signed char)((int)
          classnum->data[i] - 1)));
      }
    }

    emxFree_real_T(&classnum);
    emxFree_boolean_T(&nonnanscoreindices);
  }
}

/* End of code generation (Clasificador_diferencial_EA_vs_DCL.c) */
