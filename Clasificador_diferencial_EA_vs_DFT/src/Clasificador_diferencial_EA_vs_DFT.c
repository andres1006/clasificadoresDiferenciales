/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Clasificador_diferencial_EA_vs_DFT.c
 *
 * Code generation for function 'Clasificador_diferencial_EA_vs_DFT'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DFT.h"
#include "Clasificador_diferencial_EA_vs_DFT_emxutil.h"
#include "ClassificationKNN.h"
#include "bsxfun.h"

/* Function Definitions */
void Clasificador_diferencial_EA_vs_DFT(const emxArray_real_T *x,
  emxArray_real_T *label)
{
  double Mdl_X[216];
  static const double dv0[216] = { 0.56274363145123329, 0.35070797953644745,
    -0.18967517946630613, 0.78138206353776252, -1.166810675211478,
    0.90488490616305706, -0.80461109301989753, -0.283374342169232,
    -1.5606699915704465, -0.38539296687629182, -1.1187011583823552,
    0.90366184015452833, -0.42419705090349596, -1.2984497409347544,
    -1.4562650767242633, -0.64599956513185275, -0.71231071169849258,
    0.40476581228535846, -0.26260294784304428, 1.3794244860945977,
    0.45317564694365836, 0.13653604601354877, 0.27252771814101667,
    0.33302458683536335, 1.3882993040031859, 1.2322574714263437,
    0.45687380295138841, 0.43594319514538182, 0.37962061264939034,
    2.2865131862990453, -0.48960127226475825, 0.34811321963687253,
    -2.3929473798533412, -1.3593472412337442, 0.24155565984434077,
    1.2989452241712915, -0.71506811267956716, -1.1788960776609083,
    -0.019326165207555403, -0.71506811267956716, -0.94698209517023779,
    0.21258781728311521, -0.71506811267956716, 0.44450179977378579,
    -1.1788960776609083, -0.94698209517023779, -1.1788960776609083,
    -0.94698209517023779, -0.94698209517023779, -0.251240147698226,
    0.44450179977378579, -0.71506811267956716, -0.94698209517023779,
    -1.1788960776609083, 0.21258781728311521, -0.48315413018889658,
    -0.019326165207555403, 0.908329764755127, 1.6040717122271388,
    -0.48315413018889658, -0.48315413018889658, 1.3721577297364682,
    1.3721577297364682, 1.6040717122271388, 1.6040717122271388,
    -0.019326165207555403, 1.6040717122271388, 1.1402437472457976,
    1.6040717122271388, -0.71506811267956716, -0.71506811267956716,
    1.3721577297364682, -0.26526898610838917, -1.4021360694300611,
    0.41685126388461397, 0.41685126388461397, -1.1747626527657267,
    -0.03789556944405479, -0.03789556944405479, 0.41685126388461397,
    -1.4021360694300611, -0.94738923610139236, -1.4021360694300611,
    -1.1747626527657267, -0.720015819437058, -0.03789556944405479,
    0.41685126388461397, -0.94738923610139236, -1.1747626527657267,
    -1.4021360694300611, 0.41685126388461397, -0.26526898610838917,
    -0.26526898610838917, 1.3263449305419515, 1.3263449305419515,
    -0.720015819437058, -0.720015819437058, 1.3263449305419515,
    1.098971513877617, 1.3263449305419515, 1.3263449305419515, 1.098971513877617,
    1.3263449305419515, 1.098971513877617, 1.3263449305419515,
    -0.94738923610139236, -0.720015819437058, 1.098971513877617,
    -0.97839918094045675, -1.3452988737931282, -0.61149948808778531,
    -0.97839918094045675, -0.97839918094045675, 0.85609928332290031,
    -0.61149948808778531, 0.48919959047022893, -0.97839918094045675,
    -0.97839918094045675, -1.3452988737931282, 0.85609928332290031,
    -0.61149948808778531, 0.85609928332290031, 0.48919959047022893,
    -0.97839918094045675, -0.97839918094045675, -1.3452988737931282,
    0.85609928332290031, 0.48919959047022893, 0.85609928332290031,
    0.12229989761755752, 1.5898986690282431, -0.61149948808778531,
    -0.97839918094045675, 1.5898986690282431, 1.5898986690282431,
    1.2229989761755717, 1.5898986690282431, 0.12229989761755752,
    0.85609928332290031, 0.48919959047022893, 1.2229989761755717,
    -0.97839918094045675, -0.97839918094045675, 0.12229989761755752,
    0.13638795655425542, -1.6171714848575902, -0.9157477082928519,
    0.13638795655425542, -1.266459596575221, 0.48709984483662455,
    -0.9157477082928519, 0.13638795655425542, -1.266459596575221,
    -1.266459596575221, -1.6171714848575902, 1.1885236214013628,
    0.13638795655425542, 0.48709984483662455, 0.13638795655425542,
    -1.266459596575221, -1.266459596575221, -1.266459596575221,
    0.8378117331189936, 1.1885236214013628, 0.8378117331189936,
    1.1885236214013628, 1.1885236214013628, -0.9157477082928519,
    -1.266459596575221, 1.1885236214013628, 1.1885236214013628,
    0.8378117331189936, 1.1885236214013628, 1.1885236214013628,
    0.48709984483662455, 0.8378117331189936, 0.8378117331189936,
    -0.5650358200104828, -0.2143239317281137, -0.2143239317281137,
    -1.2913050939296009, 1.1770303068561863, -0.879915860465303,
    2.4111980072490797, -0.67422124373315406, 0.97133569012403742,
    0.35425183992759057, 1.3827249235883352, 0.76564107339188847,
    -0.057137393536707284, -1.085610477197452, 1.9998087737847818,
    -1.085610477197452, 1.1770303068561863, 1.5884195403204842,
    -0.46852662700100517, 0.14855722319544165, -0.26283201026885622,
    -0.879915860465303, -0.46852662700100517, -1.085610477197452,
    -1.2913050939296009, -0.46852662700100517, 0.35425183992759057,
    0.97133569012403742, -0.057137393536707284, -0.46852662700100517,
    -0.879915860465303, 0.35425183992759057, -1.2913050939296009,
    0.97133569012403742, -0.46852662700100517, 0.14855722319544165,
    -1.085610477197452, -0.67422124373315406, 0.14855722319544165 };

  int i;
  int acoef;
  unsigned int Mdl_YIdx[36];
  static const signed char iv0[36] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

  double Mdl_Mu[6];
  static const double dv1[6] = { 362.020528611111, 5.0833333333333313,
    6.1666666666666625, 3.6666666666666656, 4.6111111111111089,
    6.2777777777777741 };

  double Mdl_Sigma[6];
  static const double dv2[6] = { 72.173537147187872, 4.31194354588011,
    4.3980515166215524, 2.7255405754769875, 2.8513433202893559,
    4.8615759414947561 };

  int k;
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
  memcpy(&Mdl_X[0], &dv0[0], 216U * sizeof(double));
  for (i = 0; i < 36; i++) {
    Mdl_YIdx[i] = (unsigned int)iv0[i];
  }

  for (acoef = 0; acoef < 6; acoef++) {
    Mdl_Mu[acoef] = dv1[acoef];
    Mdl_Sigma[acoef] = dv2[acoef];
  }

  for (acoef = 0; acoef < 4; acoef++) {
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
    a->size[1] = 6;
    emxEnsureCapacity_real_T1(a, acoef);
    i = Xin->size[0] * Xin->size[1];
    for (acoef = 0; acoef < i; acoef++) {
      a->data[acoef] = Xin->data[acoef];
    }

    i = Xin->size[0];
    acoef = Xin->size[0] * Xin->size[1];
    Xin->size[0] = i;
    Xin->size[1] = 6;
    emxEnsureCapacity_real_T1(Xin, acoef);
    if (Xin->size[0] != 0) {
      for (k = 0; k < 6; k++) {
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
    ClassificationKNN_score(Mdl_X, Mdl_YIdx, Xin, posteriors, nonnanscoreindices);
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
      label->data[acoef] = 2.0;
    }

    for (i = 0; i < nonnanscoreindices->size[0]; i++) {
      if (nonnanscoreindices->data[i]) {
        label->data[i] = (signed char)(2 + (signed char)(3 * (signed char)((int)
          classnum->data[i] - 1)));
      }
    }

    emxFree_real_T(&classnum);
    emxFree_boolean_T(&nonnanscoreindices);
  }
}

/* End of code generation (Clasificador_diferencial_EA_vs_DFT.c) */
