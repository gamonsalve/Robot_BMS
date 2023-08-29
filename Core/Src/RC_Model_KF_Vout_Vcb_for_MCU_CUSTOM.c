/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM.c
 *
 * Code generated for Simulink model 'RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM'.
 *
 * Model version                  : 4.97
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Aug 29 14:46:32 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T look1_binlca(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

/* Forward declaration for local functions */
static void mrdiv(const real_T A[6], const real_T B_0[4], real_T Y[6]);
static real_T look1_binlca(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    real_T yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

static real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Binary Search */
  bpIdx = maxIndex >> 1U;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u0 < bp0[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]) * (table[iLeft + 1U]
    - yL_0d0) + yL_0d0;
}

/* Function for MATLAB Function: '<Root>/Custom Kalman Filter' */
static void mrdiv(const real_T A[6], const real_T B_0[4], real_T Y[6])
{
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  int32_T Y_tmp;
  int32_T Y_tmp_0;
  int32_T r1;
  int32_T r2;
  if (fabs(B_0[1]) > fabs(B_0[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = B_0[r2] / B_0[r1];
  a22_tmp = B_0[r1 + 2];
  a22 = B_0[r2 + 2] - a22_tmp * a21;
  Y[3 * r1] = A[0] / B_0[r1];
  Y[3 * r2] = (A[3] - Y[3 * r1] * a22_tmp) / a22;
  Y[3 * r1] -= Y[3 * r2] * a21;
  Y_tmp = 3 * r1 + 1;
  Y[Y_tmp] = A[1] / B_0[r1];
  Y_tmp_0 = 3 * r2 + 1;
  Y[Y_tmp_0] = (A[4] - Y[Y_tmp] * a22_tmp) / a22;
  Y[Y_tmp] -= Y[Y_tmp_0] * a21;
  Y_tmp = 3 * r1 + 2;
  Y[Y_tmp] = A[2] / B_0[r1];
  Y_tmp_0 = 3 * r2 + 2;
  Y[Y_tmp_0] = (A[5] - Y[Y_tmp] * a22_tmp) / a22;
  Y[Y_tmp] -= Y[Y_tmp_0] * a21;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_step(void)
{
  real_T Q[9];
  real_T Q_0[9];
  real_T b_I_0[9];
  real_T rtb_A[9];
  real_T rtb_A_1[9];
  real_T L[6];
  real_T rtb_C_0[6];
  real_T tmp[6];
  real_T rtb_C_1[4];
  real_T rtb_A_0[3];
  real_T rtb_B[3];
  real_T rtb_y_est[2];
  real_T a_vo;
  real_T rtb_Cbulk;
  real_T rtb_Csurface;
  real_T rtb_Rb;
  int32_T i;
  int32_T j;
  int8_T b_I[9];
  int8_T rtb_C[6];
  static const int8_T tmp_0[6] = { 0, 1, 0, 0, 1, 0 };

  static const real_T b_b[4] = { 0.01, 0.0, 0.0, 1.0 };

  /* Lookup_n-D: '<Root>/Rb' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Rb = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled2, rtConstP.pooled3,
                        11U);

  /* Lookup_n-D: '<Root>/Cbulk' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Cbulk = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled2,
    rtConstP.Cbulk_tableData, 11U);

  /* Lookup_n-D: '<Root>/Csurface' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Csurface = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled2,
    rtConstP.Csurface_tableData, 11U);

  /* MATLAB Function: '<Root>/Matrix Generator' incorporates:
   *  Delay: '<Root>/Delay'
   *  Lookup_n-D: '<Root>/Rt'
   */
  for (i = 0; i < 6; i++) {
    rtb_C[i] = tmp_0[i];
  }

  real_T a_vo_tmp;
  real_T a_vo_tmp_0;
  real_T a_vo_tmp_tmp;
  real_T rtb_A_tmp;
  real_T rtb_A_tmp_0;
  real_T rtb_A_tmp_1;
  a_vo_tmp = 2.0 * rtb_Cbulk * rtb_Rb;
  a_vo_tmp_tmp = 2.0 * rtb_Csurface * rtb_Rb;
  a_vo_tmp_0 = 1.0 / a_vo_tmp_tmp;
  a_vo = 1.0 / a_vo_tmp - a_vo_tmp_0;
  rtb_A_tmp = exp(-0.1 / (2.0 * rtb_Rb * rtb_Cbulk));
  rtb_A_tmp_0 = exp(-0.1 / (2.0 * rtb_Rb * rtb_Csurface));
  rtb_A_tmp_1 = exp(-a_vo * 0.1);
  rtb_A[0] = rtb_A_tmp;
  rtb_A[3] = 1.0 - rtb_A_tmp;
  rtb_A[6] = 0.0;
  rtb_A[1] = 1.0 - rtb_A_tmp_0;
  rtb_A[4] = rtb_A_tmp_0;
  rtb_A[7] = 0.0;
  rtb_A[2] = (-1.0 / a_vo_tmp + a_vo_tmp_0) * (1.0 / a_vo * (rtb_A_tmp_1 - 1.0));
  rtb_A[5] = 0.0;
  rtb_A[8] = rtb_A_tmp_1;
  rtb_B[0] = (1.0 - exp(-0.1 / (2.0 * rtb_Rb * rtb_Cbulk))) * rtb_Rb;
  rtb_B[1] = (1.0 - exp(-0.1 / (2.0 * rtb_Rb * rtb_Csurface))) * rtb_Rb;
  rtb_Rb = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled2,
                        rtConstP.Rt_tableData, 11U) / a_vo_tmp_tmp;
  rtb_B[2] = ((1.0 / (2.0 * rtb_Csurface) - rtb_Rb) + rtb_Rb) * ((exp(-a_vo *
    0.1) - 1.0) * (1.0 / a_vo));

  /* Product: '<Root>/Divide9' incorporates:
   *  Constant: '<Root>/Battery Capacity Ah'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  rtb_Csurface = rtDW.DiscreteTimeIntegrator_DSTATE / 5.0;

  /* Lookup_n-D: '<Root>/1-D Lookup Table2' incorporates:
   *  Gain: '<S1>/Output'
   *  RandomNumber: '<S1>/White Noise'
   *  Sum: '<Root>/Add1'
   */
  rtb_Rb = look1_binlg(0.099999999999999992 * rtDW.NextOutput + rtb_Csurface,
                       rtConstP.pooled2, rtConstP.pooled6, 11U);

  /* MATLAB Function: '<Root>/Custom Kalman Filter' incorporates:
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/voltage'
   *  Lookup_n-D: '<Root>/1-D Lookup Table2'
   *  MATLAB Function: '<Root>/Matrix Generator'
   */
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = 0.0001;
  Q[4] = 0.001;
  Q[8] = 0.1;
  if (!rtDW.x_hat_not_empty) {
    int32_T rtb_A_tmp_2;
    rtDW.x_hat_not_empty = true;
    memset(&rtDW.P0[0], 0, 9U * sizeof(real_T));
    for (j = 0; j < 3; j++) {
      rtDW.P0[j + 3 * j] = 1.0;
      rtb_A_0[j] = ((rtb_A[j + 3] * 0.0 + rtb_A[j] * 0.0) + rtb_A[j + 6] * 0.0)
        + rtb_B[j] * 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtDW.x_hat[i] = rtb_A_0[i];
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        rtb_A_1[rtb_A_tmp_2] = 0.0;
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j] * rtb_A[i];
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j + 1] * rtb_A[i + 3];
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j + 2] * rtb_A[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        rtDW.P0[rtb_A_tmp_2] = ((rtb_A_1[i + 3] * rtb_A[j + 3] + rtb_A_1[i] *
          rtb_A[j]) + rtb_A_1[i + 6] * rtb_A[j + 6]) + Q[rtb_A_tmp_2];
      }
    }

    rtDW.u_0 = rtU.current;
    for (i = 0; i < 2; i++) {
      a_vo = 0.0;
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = (j << 1) + i;
        rtb_Cbulk = rtb_C[rtb_A_tmp_2];
        a_vo += rtb_Cbulk * rtDW.x_hat[j];
        L[j + 3 * i] = rtb_Cbulk;
        rtb_C_0[rtb_A_tmp_2] = 0.0;
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j] * (real_T)rtb_C[i];
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 1] * (real_T)rtb_C[i + 2];
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 2] * (real_T)rtb_C[i + 4];
      }

      rtb_y_est[i] = 0.0 * rtU.current + a_vo;
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * i + j;
        tmp[rtb_A_tmp_2] = 0.0;
        tmp[rtb_A_tmp_2] += L[3 * i] * rtDW.P0[j];
        tmp[rtb_A_tmp_2] += L[3 * i + 1] * rtDW.P0[j + 3];
        tmp[rtb_A_tmp_2] += L[3 * i + 2] * rtDW.P0[j + 6];
      }
    }

    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        rtb_A_tmp_2 = (j << 1) + i;
        rtb_C_1[rtb_A_tmp_2] = ((L[3 * j + 1] * rtb_C_0[i + 2] + L[3 * j] *
          rtb_C_0[i]) + L[3 * j + 2] * rtb_C_0[i + 4]) + b_b[rtb_A_tmp_2];
      }
    }

    mrdiv(tmp, rtb_C_1, L);
    a_vo = rtU.voltage - rtb_y_est[0];
    rtb_Rb -= rtb_y_est[1];
    for (i = 0; i < 3; i++) {
      rtDW.x_hat[i] += L[i + 3] * rtb_Rb + L[i] * a_vo;
    }

    memset(&Q[0], 0, 9U * sizeof(real_T));
    Q[0] = 1.0;
    Q[4] = 1.0;
    Q[8] = 1.0;
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
    }

    for (j = 0; j < 3; j++) {
      b_I[j + 3 * j] = 1;
      for (i = 0; i < 3; i++) {
        int32_T rtb_A_tmp_3;
        rtb_A_tmp_2 = i << 1;
        rtb_A_tmp_3 = 3 * i + j;
        Q_0[rtb_A_tmp_3] = Q[rtb_A_tmp_3] - ((real_T)rtb_C[rtb_A_tmp_2 + 1] *
          L[j + 3] + (real_T)rtb_C[rtb_A_tmp_2] * L[j]);
      }

      for (i = 0; i < 3; i++) {
        rtb_A_tmp_2 = 3 * i + j;
        b_I_0[rtb_A_tmp_2] = 0.0;
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * i] * Q_0[j];
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * i + 1] * Q_0[j + 3];
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * i + 2] * Q_0[j + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = i << 1;
        rtb_A_1[i + 3 * j] = (real_T)b_I[3 * i + j] - ((real_T)rtb_C[rtb_A_tmp_2
          + 1] * L[j + 3] + (real_T)rtb_C[rtb_A_tmp_2] * L[j]);
      }

      rtb_C_0[i] = 0.0;
      rtb_C_0[i] += L[i] * 0.01;
      rtb_Rb = L[i + 3];
      rtb_C_0[i] += rtb_Rb * 0.0;
      rtb_C_0[i + 3] = 0.0;
      rtb_C_0[i + 3] += L[i] * 0.0;
      rtb_C_0[i + 3] += rtb_Rb;
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        Q[rtb_A_tmp_2] = 0.0;
        Q[rtb_A_tmp_2] += rtb_A_1[3 * j] * b_I_0[i];
        Q[rtb_A_tmp_2] += rtb_A_1[3 * j + 1] * b_I_0[i + 3];
        Q[rtb_A_tmp_2] += rtb_A_1[3 * j + 2] * b_I_0[i + 6];
        rtb_A[rtb_A_tmp_2] = 0.0;
        rtb_A[rtb_A_tmp_2] += rtb_C_0[i] * L[j];
        rtb_A[rtb_A_tmp_2] += rtb_C_0[i + 3] * L[j + 3];
      }
    }

    for (i = 0; i < 9; i++) {
      rtDW.P0[i] = Q[i] + rtb_A[i];
    }
  } else {
    int32_T rtb_A_tmp_2;
    for (i = 0; i < 3; i++) {
      rtb_A_0[i] = ((rtb_A[i + 3] * rtDW.x_hat[1] + rtb_A[i] * rtDW.x_hat[0]) +
                    rtb_A[i + 6] * rtDW.x_hat[2]) + rtb_B[i] * rtDW.u_0;
    }

    for (i = 0; i < 3; i++) {
      rtDW.x_hat[i] = rtb_A_0[i];
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        rtb_A_1[rtb_A_tmp_2] = 0.0;
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j] * rtb_A[i];
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j + 1] * rtb_A[i + 3];
        rtb_A_1[rtb_A_tmp_2] += rtDW.P0[3 * j + 2] * rtb_A[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        rtDW.P0[rtb_A_tmp_2] = ((rtb_A_1[i + 3] * rtb_A[j + 3] + rtb_A_1[i] *
          rtb_A[j]) + rtb_A_1[i + 6] * rtb_A[j + 6]) + Q[rtb_A_tmp_2];
      }
    }

    rtDW.u_0 = rtU.current;
    for (i = 0; i < 2; i++) {
      a_vo = 0.0;
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = (j << 1) + i;
        rtb_Cbulk = rtb_C[rtb_A_tmp_2];
        a_vo += rtb_Cbulk * rtDW.x_hat[j];
        L[j + 3 * i] = rtb_Cbulk;
        rtb_C_0[rtb_A_tmp_2] = 0.0;
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j] * (real_T)rtb_C[i];
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 1] * (real_T)rtb_C[i + 2];
        rtb_C_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 2] * (real_T)rtb_C[i + 4];
      }

      rtb_y_est[i] = 0.0 * rtU.current + a_vo;
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * i + j;
        tmp[rtb_A_tmp_2] = 0.0;
        tmp[rtb_A_tmp_2] += L[3 * i] * rtDW.P0[j];
        tmp[rtb_A_tmp_2] += L[3 * i + 1] * rtDW.P0[j + 3];
        tmp[rtb_A_tmp_2] += L[3 * i + 2] * rtDW.P0[j + 6];
      }
    }

    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        rtb_A_tmp_2 = (j << 1) + i;
        rtb_C_1[rtb_A_tmp_2] = ((L[3 * j + 1] * rtb_C_0[i + 2] + L[3 * j] *
          rtb_C_0[i]) + L[3 * j + 2] * rtb_C_0[i + 4]) + b_b[rtb_A_tmp_2];
      }
    }

    mrdiv(tmp, rtb_C_1, L);
    a_vo = rtU.voltage - rtb_y_est[0];
    rtb_Rb -= rtb_y_est[1];
    for (i = 0; i < 3; i++) {
      rtDW.x_hat[i] += L[i + 3] * rtb_Rb + L[i] * a_vo;
    }

    memset(&Q[0], 0, 9U * sizeof(real_T));
    Q[0] = 1.0;
    Q[4] = 1.0;
    Q[8] = 1.0;
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
    }

    for (j = 0; j < 3; j++) {
      b_I[j + 3 * j] = 1;
      for (i = 0; i < 3; i++) {
        int32_T rtb_A_tmp_3;
        rtb_A_tmp_2 = 3 * i + j;
        rtb_A[rtb_A_tmp_2] = 0.0;
        rtb_A_tmp_3 = i << 1;
        rtb_A[rtb_A_tmp_2] += (real_T)rtb_C[rtb_A_tmp_3] * L[j];
        rtb_A[rtb_A_tmp_2] += (real_T)rtb_C[rtb_A_tmp_3 + 1] * L[j + 3];
      }
    }

    for (i = 0; i < 9; i++) {
      rtb_A_1[i] = (real_T)b_I[i] - rtb_A[i];
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        b_I_0[rtb_A_tmp_2] = 0.0;
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * j] * rtb_A_1[i];
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 1] * rtb_A_1[i + 3];
        b_I_0[rtb_A_tmp_2] += rtDW.P0[3 * j + 2] * rtb_A_1[i + 6];
        Q_0[j + 3 * i] = Q[rtb_A_tmp_2] - rtb_A[rtb_A_tmp_2];
      }

      rtb_C_0[i] = 0.0;
      rtb_C_0[i] += L[i] * 0.01;
      rtb_Rb = L[i + 3];
      rtb_C_0[i] += rtb_Rb * 0.0;
      rtb_C_0[i + 3] = 0.0;
      rtb_C_0[i + 3] += L[i] * 0.0;
      rtb_C_0[i + 3] += rtb_Rb;
    }

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        rtb_A_tmp_2 = 3 * j + i;
        rtb_A_1[rtb_A_tmp_2] = 0.0;
        rtb_A_1[rtb_A_tmp_2] += Q_0[3 * j] * b_I_0[i];
        rtb_A_1[rtb_A_tmp_2] += Q_0[3 * j + 1] * b_I_0[i + 3];
        rtb_A_1[rtb_A_tmp_2] += Q_0[3 * j + 2] * b_I_0[i + 6];
        rtb_A[rtb_A_tmp_2] = 0.0;
        rtb_A[rtb_A_tmp_2] += rtb_C_0[i] * L[j];
        rtb_A[rtb_A_tmp_2] += rtb_C_0[i + 3] * L[j + 3];
      }
    }

    for (i = 0; i < 9; i++) {
      rtDW.P0[i] = rtb_A_1[i] + rtb_A[i];
    }
  }

  /* Outport: '<Root>/voltage_estimated' */
  rtY.voltage_estimated[0] = rtb_y_est[0];
  rtY.voltage_estimated[1] = rtb_y_est[1];

  /* Lookup_n-D: '<Root>/1-D Lookup Table' incorporates:
   *  MATLAB Function: '<Root>/Custom Kalman Filter'
   */
  rtb_Rb = look1_binlg(rtDW.x_hat[0], rtConstP.pooled6, rtConstP.pooled2, 11U);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Rb > 1.0) {
    rtb_Rb = 1.0;
  } else if (rtb_Rb < 0.0) {
    rtb_Rb = 0.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/soc_estimated' */
  rtY.soc_estimated = rtb_Rb;

  /* Outport: '<Root>/standard_deviation' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLAB Function: '<Root>/Custom Kalman Filter'
   *  Selector: '<Root>/Selector2'
   *  Sqrt: '<Root>/Sqrt'
   */
  rtY.standard_deviation = 3.0 * sqrt(rtDW.P0[0]);

  /* Outport: '<Root>/soc_measured' */
  rtY.soc_measured = rtb_Csurface;

  /* Update for Delay: '<Root>/Delay' */
  rtDW.Delay_DSTATE = rtb_Rb;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/Convert to Ah'
   *  Inport: '<Root>/current'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.00027777777777777778 * rtU.current *
    0.1;
  if (rtDW.DiscreteTimeIntegrator_DSTATE >= 5.0) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 5.0;
  } else if (rtDW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Update for RandomNumber: '<S1>/White Noise' */
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed);
}

/* Model initialize function */
void RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_initialize(void)
{
  /* InitializeConditions for Delay: '<Root>/Delay' */
  rtDW.Delay_DSTATE = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = 5.0;

  /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
  rtDW.RandSeed = 1529675776U;
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
