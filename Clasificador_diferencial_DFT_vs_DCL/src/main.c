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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "Clasificador_diferencial_DFT_vs_DCL.h"
#include "main.h"
#include "Clasificador_diferencial_DFT_vs_DCL_terminate.h"
#include "Clasificador_diferencial_DFT_vs_DCL_emxAPI.h"
#include "Clasificador_diferencial_DFT_vs_DCL_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_Unboundedx9_real_T(char *datos[], int argc);
static double argInit_real_T(void);
static void main_Clasificador_diferencial_DFT_vs_DCL(char *vec[], int size);

/* Function Definitions */
static emxArray_real_T *argInit_Unboundedx9_real_T(char *vec[], int size)
{

 double datos[size-2];

  int i;
  for (i = 0; i < (size - 2); i++)
  {
    datos[i] = atof(vec[i + 2]);
  }
  emxArray_real_T *result;

  result = emxCreateWrapper_real_T(datos, 1, ((int)(sizeof(datos) / sizeof(datos[2])) - 1));

  return result;
}

static void main_Clasificador_diferencial_DFT_vs_DCL(char *vec[], int size)
{
  emxArray_real_T *label;
  emxArray_real_T *x;
  char result[10];

  emxInitArray_real_T(&label, 1);
  emxInitArray_real_T(&x, 2);

  double datos[size-2];

  int i;
  for (i = 0; i < (size - 2); i++)
  {
    datos[i] = atof(vec[i + 2]);
  }

  for (i = 0; i < ((int)(sizeof(datos) / sizeof(datos[2])) ); i++)
  {
    printf("datos[%d] = %f\n", i, datos[i]);
  }

  /* Initialize function 'Clasificador_diferencial_DFT_vs_DCL' input arguments. */
  /* Initialize function input argument 'x'. */
  x = emxCreateWrapper_real_T(datos, 1, ((int)(sizeof(datos) / sizeof(datos[2]))));

   for (int i = 0; i < ((int)(sizeof(datos) / sizeof(datos[2])) ); i = i + 1)
    {
      printf("%f\n", x->data[i]);
    }

  /* Call the entry-point 'Clasificador_diferencial_DFT_vs_DCL'. */
  Clasificador_diferencial_DFT_vs_DCL(x, label);

    //Mostrar información del LABEL
  printf("%f\n", label->data[0]);

  //Convertir el label tipo double a string
  sprintf(result, "%f", label->data[0]);

  //EXPORTAR RESULTADO A CSV
  //Crear puntero para el archivo
  FILE *f1;
    // //EXPORTAR RESULTADO A CSV
  // //Crear puntero para el archivo
  strcat(vec[1],"/Class_Diferencial_DFT_vs_DCL.csv" );
  printf("%s", vec[1]);

  // //Abrir archivo para la lectura
  f1 = fopen(vec[1], "w");

  //Escribir el resultado del clasificador en el archivo
  fputs(result, f1);
  fclose(f1);

  emxDestroyArray_real_T(label);
  emxDestroyArray_real_T(x);
}

int main(int argc,char  *argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  Clasificador_diferencial_DFT_vs_DCL_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Clasificador_diferencial_DFT_vs_DCL(argv, argc);

  /* Terminate the application.
     You do not need to do this more than one time. */
  Clasificador_diferencial_DFT_vs_DCL_terminate();
  return 0;
}

/* End of code generation (main.c) */
