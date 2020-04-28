/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Linear.c
 *
 * Code generation for function 'Linear'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EP_vs_PKS.h"
#include "Linear.h"
#include "Clasificador_diferencial_EP_vs_PKS_emxutil.h"

/* Function Definitions */
void Linear(const emxArray_real_T *x, emxArray_real_T *kernelProduct)
{
  int m;
  int j;
  int coffset;
  int boffset;
  int i;
  int k;
  static const double dv3[57] = { 0.120472169342691, -0.75583968331823947,
    -0.12155905597234055, 0.13032280071989724, 0.46783573390239352,
    -0.27784927079392169, -0.12211833539401214, 0.49918209963789795,
    -0.27784927079392169, -0.17265403022705314, -1.2721474769928491,
    -0.59042970043708387, 0.0061578237680928521, 0.24808284807256267,
    -0.43413948561550275, -0.25134498415389367, 0.51638114447137129,
    0.034731158849240537, -0.38682569472099376, -0.32804280353740806,
    -0.43413948561550275, -0.045607916426776529, 0.010738918570163968,
    -0.43413948561550275, -0.30971622768793278, -0.091813818904619385,
    -0.12155905597234055, 0.22121379822442044, 0.29316245610970376,
    0.034731158849240537, -0.52440706717225527, 0.52180093203287625,
    0.34731158849240273, -0.14619208033265402, 0.29835631380600308,
    -0.27784927079392169, -0.29958832172170907, -0.87127566612997642,
    0.50360180331398385, -0.19128841872799898, 0.27833948712736639,
    -0.43413948561550275, -0.34681727123139328, -0.28119323309654837,
    -0.27784927079392169, 0.74719853698438676, -0.69467701838288154,
    -0.12155905597234055, 1.30742600696938, 0.69002157496844718,
    0.50360180331398385, -0.41762475261196991, 0.20628822298360455,
    0.034731158849240537, -0.025695558718736314, 0.39419131159736048,
    -0.27784927079392169 };

  int aoffset;
  m = x->size[0];
  j = kernelProduct->size[0] * kernelProduct->size[1];
  kernelProduct->size[0] = x->size[0];
  kernelProduct->size[1] = 19;
  emxEnsureCapacity_real_T1(kernelProduct, j);
  for (j = 0; j < 19; j++) {
    coffset = j * m - 1;
    boffset = j * 3;
    for (i = 1; i <= m; i++) {
      kernelProduct->data[coffset + i] = 0.0;
    }

    for (k = 0; k < 3; k++) {
      if (dv3[boffset + k] != 0.0) {
        aoffset = k * m;
        for (i = 1; i <= m; i++) {
          kernelProduct->data[coffset + i] += dv3[boffset + k] * x->data
            [(aoffset + i) - 1];
        }
      }
    }
  }
}

/* End of code generation (Linear.c) */
