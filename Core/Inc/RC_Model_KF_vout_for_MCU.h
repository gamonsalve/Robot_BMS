/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RC_Model_KF_vout_for_MCU.h
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

#ifndef RTW_HEADER_RC_Model_KF_vout_for_MCU_h_
#define RTW_HEADER_RC_Model_KF_vout_for_MCU_h_
#ifndef RC_Model_KF_vout_for_MCU_COMMON_INCLUDES_
#define RC_Model_KF_vout_for_MCU_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* RC_Model_KF_vout_for_MCU_COMMON_INCLUDES_ */

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
  real_T MemoryP_DSTATE[9];            /* '<S1>/MemoryP' */
  real_T MemoryX_DSTATE[3];            /* '<S1>/MemoryX' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  boolean_T icLoad;                    /* '<S1>/MemoryP' */
  boolean_T icLoad_o;                  /* '<S1>/MemoryX' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: pInitialization.Qbar
   * Referenced by: '<S23>/Qbar_'
   */
  real_T Qbar_Value[9];

  /* Expression: pInitialization.P0
   * Referenced by: '<S1>/P0'
   */
  real_T P0_Value[9];

  /* Expression: Rt
   * Referenced by: '<Root>/Rt'
   */
  real_T Rt_tableData[7];

  /* Pooled Parameter (Expression: SOC_LUT)
   * Referenced by:
   *   '<Root>/Cbulk'
   *   '<Root>/Csurface'
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   *   '<Root>/Rt'
   */
  real_T pooled3[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rb'
   *   '<Root>/Rs'
   */
  real_T pooled4[7];

  /* Expression: Cbulk
   * Referenced by: '<Root>/Cbulk'
   */
  real_T Cbulk_tableData[7];

  /* Expression: Csurface
   * Referenced by: '<Root>/Csurface'
   */
  real_T Csurface_tableData[7];

  /* Expression: SOC_EST
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[8];

  /* Expression: Vocv
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[8];
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
  real_T voltage_estimated;            /* '<Root>/voltage_estimated' */
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
extern void RC_Model_KF_vout_for_MCU_initialize(void);
extern void RC_Model_KF_vout_for_MCU_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/1-D Lookup Table2' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/G' : Unused code path elimination
 * Block '<S1>/H' : Unused code path elimination
 * Block '<S1>/N' : Unused code path elimination
 * Block '<S1>/Q' : Unused code path elimination
 * Block '<S1>/R' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/CheckSignalProperties' : Unused code path elimination
 * Block '<S30>/CheckSignalProperties' : Unused code path elimination
 * Block '<S31>/CheckSignalProperties' : Unused code path elimination
 * Block '<S32>/CheckSignalProperties' : Unused code path elimination
 * Block '<S42>/CheckSignalProperties' : Unused code path elimination
 * Block '<S43>/CheckSignalProperties' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope11' : Unused code path elimination
 * Block '<Root>/Scope12' : Unused code path elimination
 * Block '<Root>/Scope13' : Unused code path elimination
 * Block '<Root>/Scope14' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S14>/Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Reshape' : Reshape block reduction
 * Block '<S48>/Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/ReshapeX0' : Reshape block reduction
 * Block '<S1>/Reshapeu' : Reshape block reduction
 * Block '<S1>/Reshapexhat' : Reshape block reduction
 * Block '<S1>/Reshapey' : Reshape block reduction
 * Block '<S1>/Reshapeyhat' : Reshape block reduction
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
 * '<Root>' : 'RC_Model_KF_vout_for_MCU'
 * '<S1>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter'
 * '<S2>'   : 'RC_Model_KF_vout_for_MCU/Matrix Generator'
 * '<S3>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CalculatePL'
 * '<S4>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CalculateYhat'
 * '<S5>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CovarianceOutputConfigurator'
 * '<S6>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionA'
 * '<S7>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionB'
 * '<S8>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionC'
 * '<S9>'   : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionD'
 * '<S10>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionEnable'
 * '<S11>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionG'
 * '<S12>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionH'
 * '<S13>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionN'
 * '<S14>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionP'
 * '<S15>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionP0'
 * '<S16>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionQ'
 * '<S17>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionR'
 * '<S18>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionReset'
 * '<S19>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionX'
 * '<S20>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionX0'
 * '<S21>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/DataTypeConversionu'
 * '<S22>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/Observer'
 * '<S23>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ReducedQRN'
 * '<S24>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/Reset'
 * '<S25>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ScalarExpansionP0'
 * '<S26>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ScalarExpansionQ'
 * '<S27>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ScalarExpansionR'
 * '<S28>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/UseCurrentEstimator'
 * '<S29>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkA'
 * '<S30>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkB'
 * '<S31>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkC'
 * '<S32>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkD'
 * '<S33>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkEnable'
 * '<S34>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkG'
 * '<S35>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkH'
 * '<S36>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkN'
 * '<S37>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkP0'
 * '<S38>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkQ'
 * '<S39>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkR'
 * '<S40>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkReset'
 * '<S41>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checkX0'
 * '<S42>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checku'
 * '<S43>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/checky'
 * '<S44>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CalculatePL/Discrete-Time SqrtKF - Calculate SLMZ'
 * '<S45>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S46>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S47>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/Observer/MeasurementUpdate'
 * '<S48>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ReducedQRN/DataTypeConversionNbar'
 * '<S49>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ReducedQRN/DataTypeConversionQbar'
 * '<S50>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/ReducedQRN/DataTypeConversionRbar'
 * '<S51>'  : 'RC_Model_KF_vout_for_MCU/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                              /* RTW_HEADER_RC_Model_KF_vout_for_MCU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
