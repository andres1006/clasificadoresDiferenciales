/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_EA_vs_DCL.h"
#include "main.h"
#include "Clasificador_diferencial_EA_vs_DCL_terminate.h"
#include "Clasificador_diferencial_EA_vs_DCL_emxAPI.h"
#include "Clasificador_diferencial_EA_vs_DCL_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_Unboundedx4_real_T(void);
static double argInit_real_T(void);
static void main_Clasificador_diferencial_EA_vs_DCL(void);

/* Function Definitions */
static emxArray_real_T *argInit_Unboundedx4_real_T(void)
{
  emxArray_real_T *result;
  static int iv1[2] = { 2, 4 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv1);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 4; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_Clasificador_diferencial_EA_vs_DCL(void)
{
  emxArray_real_T *label;
  emxArray_real_T *x;
  emxInitArray_real_T(&label, 1);

  /* Initialize function 'Clasificador_diferencial_EA_vs_DCL' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_Unboundedx4_real_T();

  /* Call the entry-point 'Clasificador_diferencial_EA_vs_DCL'. */
  Clasificador_diferencial_EA_vs_DCL(x, label);
  emxDestroyArray_real_T(label);
  emxDestroyArray_real_T(x);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  Clasificador_diferencial_EA_vs_DCL_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Clasificador_diferencial_EA_vs_DCL();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Clasificador_diferencial_EA_vs_DCL_terminate();
  return 0;
}

/* End of code generation (main.c) */
