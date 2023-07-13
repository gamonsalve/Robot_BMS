/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RC_Model_KF_vout_for_MCU_data.c
 *
 * Code generated for Simulink model 'RC_Model_KF_vout_for_MCU'.
 *
 * Model version                  : 4.14
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 13:33:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "RC_Model_KF_vout_for_MCU.h"

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: pInitialization.Qbar
   * Referenced by: '<S23>/Qbar_'
   */
  { 1.0E-5, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 1.0E-5 },

  /* Expression: pInitialization.P0
   * Referenced by: '<S1>/P0'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: Rt
   * Referenced by: '<Root>/Rt'
   */
  { 0.47733242753624167, 0.2026011587928917, 0.1436015118790499,
    0.11558629672598775, 0.096322457212193846, 0.084763762346730442,
    0.0745198246047434 },

  /* Pooled Parameter (Expression: SOC_LUT)
   * Referenced by:
   *   '<Root>/Cbulk'
   *   '<Root>/Csurface'
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   *   '<Root>/Rt'
   */
  { 0.42690086916024472, 0.51824494036215463, 0.61115478730126793,
    0.70668573605424212, 0.80287711950108653, 0.90083781496597481, 1.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   */
  { 0.57279891304349, 0.24312139055147006, 0.17232181425485987,
    0.13870355607118529, 0.11558694865463261, 0.10171651481607652,
    0.089423789525692091 },

  /* Expression: Cbulk
   * Referenced by: '<Root>/Cbulk'
   */
  { 17651.58845002532, 17651.58845002532, 17651.58845002532, 17651.58845002532,
    17651.58845002532, 17651.58845002532, 17651.58845002532 },

  /* Expression: Csurface
   * Referenced by: '<Root>/Csurface'
   */
  { 3.2972873054827274, 10.436659367613609, 14.189152449458119, 4.14381592662727,
    10.921769816525082, 32.117980891289136, 23.92323029306943 },

  /* Expression: SOC_EST
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.35062040476127188, 0.42690086916024472, 0.51824494036215463,
    0.61115478730126793, 0.70668573605424212, 0.80287711950108653,
    0.90083781496597481, 1.0 },

  /* Expression: Vocv
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 11.778607, 11.896808, 12.050467, 12.210037, 12.369606, 12.529177, 12.688745,
    12.842405 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
