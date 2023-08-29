/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM.h
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

#ifndef RTW_HEADER_RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_h_
#define RTW_HEADER_RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_h_
#ifndef RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_COMMON_INCLUDES_
#define RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                /* RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T x_hat[3];                     /* '<Root>/Custom Kalman Filter' */
  real_T P0[9];                        /* '<Root>/Custom Kalman Filter' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  real_T u_0;                          /* '<Root>/Custom Kalman Filter' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  boolean_T x_hat_not_empty;           /* '<Root>/Custom Kalman Filter' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Rt
   * Referenced by: '<Root>/Rt'
   */
  real_T Rt_tableData[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/1-D Lookup Table'
   *   '<Root>/1-D Lookup Table2'
   *   '<Root>/Cbulk'
   *   '<Root>/Csurface'
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   *   '<Root>/Rt'
   */
  real_T pooled2[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   */
  real_T pooled3[12];

  /* Expression: Cbulk
   * Referenced by: '<Root>/Cbulk'
   */
  real_T Cbulk_tableData[12];

  /* Expression: Csurface
   * Referenced by: '<Root>/Csurface'
   */
  real_T Csurface_tableData[12];

  /* Pooled Parameter (Expression: Vocv)
   * Referenced by:
   *   '<Root>/1-D Lookup Table'
   *   '<Root>/1-D Lookup Table2'
   */
  real_T pooled6[12];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T current;                      /* '<Root>/current' */
  real_T voltage;                      /* '<Root>/voltage' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T soc_estimated;                /* '<Root>/soc_estimated' */
  real_T soc_measured;                 /* '<Root>/soc_measured' */
  real_T voltage_estimated[2];         /* '<Root>/voltage_estimated' */
  real_T standard_deviation;           /* '<Root>/standard_deviation' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_initialize(void);
extern void RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Gain1' : Eliminated nontunable gain of 1
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM'
 * '<S1>'   : 'RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM/Band-Limited White Noise'
 * '<S2>'   : 'RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM/Custom Kalman Filter'
 * '<S3>'   : 'RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM/Matrix Generator'
 */
#endif                   /* RTW_HEADER_RC_Model_KF_Vout_Vcb_for_MCU_CUSTOM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
