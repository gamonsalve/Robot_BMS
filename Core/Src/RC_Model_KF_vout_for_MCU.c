/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RC_Model_KF_vout_for_MCU.c
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
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
static real_T look1_binlca(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

/* Forward declaration for local functions */
static real_T xnrm2(int32_T n, const real_T x[4], int32_T ix0);
static real_T qrFactor(const real_T A[3], const real_T S[9], real_T Ns);
static void trisolve(real_T A, real_T B_1[3]);
static void mtimes(const real_T A[9], const real_T B_0[9], real_T C[9]);
static real_T xnrm2_g(int32_T n, const real_T x[12], int32_T ix0);
static void xgemv(int32_T m, int32_T n, const real_T A[12], int32_T ia0, const
                  real_T x[12], int32_T ix0, real_T y[3]);
static void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T
                  y[3], real_T A[12], int32_T ia0);
static void qrFactor_j(const real_T A[9], real_T S[9], const real_T Ns[3]);
static real_T xnrm2_gw(int32_T n, const real_T x[18], int32_T ix0);
static void xgemv_g(int32_T m, int32_T n, const real_T A[18], int32_T ia0, const
                    real_T x[18], int32_T ix0, real_T y[3]);
static void xgerc_a(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                    real_T y[3], real_T A[18], int32_T ia0);
static void qrFactor_jq(const real_T A[9], real_T S[9], const real_T Ns[9]);
static real_T xnrm2_gwq(int32_T n, const real_T x[9], int32_T ix0);
static real_T xdotc(int32_T n, const real_T x[9], int32_T ix0, const real_T y[9],
                    int32_T iy0);
static void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0);
static real_T xnrm2_gwqu(int32_T n, const real_T x[3], int32_T ix0);
static void xaxpy_c(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T
                    y[3], int32_T iy0);
static void xaxpy_cs(int32_T n, real_T a, const real_T x[3], int32_T ix0, real_T
                     y[9], int32_T iy0);
static void xswap(real_T x[9], int32_T ix0, int32_T iy0);
static void xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s);
static void svd(const real_T A[9], real_T U[9], real_T s[3], real_T V[9]);
static void xgemv_gp(int32_T m, int32_T n, const real_T A[9], int32_T ia0, const
                     real_T x[9], int32_T ix0, real_T y[3]);
static void xgerc_aq(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                     real_T y[3], real_T A[9], int32_T ia0);
static void qr(const real_T A[9], real_T Q[9], real_T R[9]);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

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

static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xnrm2(int32_T n, const real_T x[4], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T qrFactor(const real_T A[3], const real_T S[9], real_T Ns)
{
  real_T b_A[4];
  real_T b_S;
  real_T s;
  int32_T aoffset;
  int32_T i;
  for (i = 0; i < 3; i++) {
    aoffset = i * 3;
    b_A[i] = (S[aoffset + 1] * A[1] + S[aoffset] * A[0]) + S[aoffset + 2] * A[2];
  }

  b_A[3] = Ns;
  b_S = b_A[0];
  s = xnrm2(3, b_A, 2);
  if (s != 0.0) {
    s = rt_hypotd_snf(b_A[0], s);
    if (b_A[0] >= 0.0) {
      s = -s;
    }

    if (fabs(s) < 1.0020841800044864E-292) {
      aoffset = 0;
      do {
        aoffset++;
        b_A[1] *= 9.9792015476736E+291;
        b_A[2] *= 9.9792015476736E+291;
        b_A[3] *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
        b_S *= 9.9792015476736E+291;
      } while ((fabs(s) < 1.0020841800044864E-292) && (aoffset < 20));

      s = rt_hypotd_snf(b_S, xnrm2(3, b_A, 2));
      if (b_S >= 0.0) {
        s = -s;
      }

      for (i = 0; i < aoffset; i++) {
        s *= 1.0020841800044864E-292;
      }

      b_S = s;
    } else {
      b_S = s;
    }
  }

  return b_S;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void trisolve(real_T A, real_T B_1[3])
{
  if (B_1[0] != 0.0) {
    B_1[0] /= A;
  }

  if (B_1[1] != 0.0) {
    B_1[1] /= A;
  }

  if (B_1[2] != 0.0) {
    B_1[2] /= A;
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void mtimes(const real_T A[9], const real_T B_0[9], real_T C[9])
{
  int32_T i;
  int32_T j;
  for (j = 0; j < 3; j++) {
    int32_T coffset;
    coffset = j * 3;
    for (i = 0; i < 3; i++) {
      int32_T aoffset;
      aoffset = i * 3;
      C[coffset + i] = (A[aoffset + 1] * B_0[j + 3] + A[aoffset] * B_0[j]) +
        A[aoffset + 2] * B_0[j + 6];
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xnrm2_g(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgemv(int32_T m, int32_T n, const real_T A[12], int32_T ia0, const
                  real_T x[12], int32_T ix0, real_T y[3])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = ((n - 1) << 2) + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 4) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (iyend = b_iy; iyend < d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = (b_iy - ia0) >> 2;
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T
                  y[3], real_T A[12], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 4;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void qrFactor_j(const real_T A[9], real_T S[9], const real_T Ns[3])
{
  real_T b_A[12];
  real_T R[9];
  real_T tau[3];
  real_T work[3];
  int32_T coltop;
  int32_T i;
  int32_T ii;
  int32_T knt;
  int32_T lastv;
  mtimes(S, A, R);
  for (i = 0; i < 3; i++) {
    ii = i << 2;
    b_A[ii] = R[3 * i];
    b_A[ii + 1] = R[3 * i + 1];
    b_A[ii + 2] = R[3 * i + 2];
    b_A[ii + 3] = Ns[i];
    work[i] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    real_T atmp;
    real_T beta1;
    int32_T c_tmp;
    ii = (i << 2) + i;
    atmp = b_A[ii];
    lastv = ii + 2;
    tau[i] = 0.0;
    beta1 = xnrm2_g(3 - i, b_A, ii + 2);
    if (beta1 != 0.0) {
      beta1 = rt_hypotd_snf(b_A[ii], beta1);
      if (b_A[ii] >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        c_tmp = (ii - i) + 4;
        do {
          knt++;
          for (coltop = lastv; coltop <= c_tmp; coltop++) {
            b_A[coltop - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(atmp, xnrm2_g(3 - i, b_A, ii + 2));
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[i] = (beta1 - atmp) / beta1;
        atmp = 1.0 / (atmp - beta1);
        for (coltop = lastv; coltop <= c_tmp; coltop++) {
          b_A[coltop - 1] *= atmp;
        }

        for (lastv = 0; lastv < knt; lastv++) {
          beta1 *= 1.0020841800044864E-292;
        }

        atmp = beta1;
      } else {
        tau[i] = (beta1 - b_A[ii]) / beta1;
        atmp = 1.0 / (b_A[ii] - beta1);
        coltop = (ii - i) + 4;
        for (knt = lastv; knt <= coltop; knt++) {
          b_A[knt - 1] *= atmp;
        }

        atmp = beta1;
      }
    }

    b_A[ii] = atmp;
    if (i + 1 < 3) {
      beta1 = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[i] != 0.0) {
        boolean_T exitg2;
        lastv = 4 - i;
        knt = (ii - i) + 3;
        while ((lastv > 0) && (b_A[knt] == 0.0)) {
          lastv--;
          knt--;
        }

        knt = 2 - i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          int32_T exitg1;
          coltop = (((knt - 1) << 2) + ii) + 4;
          c_tmp = coltop;
          do {
            exitg1 = 0;
            if (c_tmp + 1 <= coltop + lastv) {
              if (b_A[c_tmp] != 0.0) {
                exitg1 = 1;
              } else {
                c_tmp++;
              }
            } else {
              knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        knt = 0;
      }

      if (lastv > 0) {
        xgemv(lastv, knt, b_A, ii + 5, b_A, ii + 1, work);
        xgerc(lastv, knt, -tau[i], ii + 1, work, b_A, ii + 5);
      }

      b_A[ii] = beta1;
    }
  }

  for (i = 0; i < 3; i++) {
    for (ii = 0; ii <= i; ii++) {
      R[ii + 3 * i] = b_A[(i << 2) + ii];
    }

    for (ii = i + 2; ii < 4; ii++) {
      R[(ii + 3 * i) - 1] = 0.0;
    }
  }

  for (i = 0; i < 3; i++) {
    S[3 * i] = R[i];
    S[3 * i + 1] = R[i + 3];
    S[3 * i + 2] = R[i + 6];
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xnrm2_gw(int32_T n, const real_T x[18], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgemv_g(int32_T m, int32_T n, const real_T A[18], int32_T ia0, const
                    real_T x[18], int32_T ix0, real_T y[3])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = (n - 1) * 6 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 6) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (iyend = b_iy; iyend < d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = div_nde_s32_floor(b_iy - ia0, 6);
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgerc_a(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                    real_T y[3], real_T A[18], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 6;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void qrFactor_jq(const real_T A[9], real_T S[9], const real_T Ns[9])
{
  real_T b_A[18];
  real_T R[9];
  real_T tau[3];
  real_T work[3];
  int32_T coltop;
  int32_T i;
  int32_T ii;
  int32_T knt;
  int32_T lastv;
  mtimes(S, A, R);
  for (i = 0; i < 3; i++) {
    b_A[6 * i] = R[3 * i];
    b_A[6 * i + 3] = Ns[i];
    b_A[6 * i + 1] = R[3 * i + 1];
    b_A[6 * i + 4] = Ns[i + 3];
    b_A[6 * i + 2] = R[3 * i + 2];
    b_A[6 * i + 5] = Ns[i + 6];
    work[i] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    real_T atmp;
    real_T beta1;
    int32_T c_tmp;
    ii = i * 6 + i;
    atmp = b_A[ii];
    lastv = ii + 2;
    tau[i] = 0.0;
    beta1 = xnrm2_gw(5 - i, b_A, ii + 2);
    if (beta1 != 0.0) {
      beta1 = rt_hypotd_snf(b_A[ii], beta1);
      if (b_A[ii] >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        c_tmp = (ii - i) + 6;
        do {
          knt++;
          for (coltop = lastv; coltop <= c_tmp; coltop++) {
            b_A[coltop - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(atmp, xnrm2_gw(5 - i, b_A, ii + 2));
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[i] = (beta1 - atmp) / beta1;
        atmp = 1.0 / (atmp - beta1);
        for (coltop = lastv; coltop <= c_tmp; coltop++) {
          b_A[coltop - 1] *= atmp;
        }

        for (lastv = 0; lastv < knt; lastv++) {
          beta1 *= 1.0020841800044864E-292;
        }

        atmp = beta1;
      } else {
        tau[i] = (beta1 - b_A[ii]) / beta1;
        atmp = 1.0 / (b_A[ii] - beta1);
        coltop = (ii - i) + 6;
        for (knt = lastv; knt <= coltop; knt++) {
          b_A[knt - 1] *= atmp;
        }

        atmp = beta1;
      }
    }

    b_A[ii] = atmp;
    if (i + 1 < 3) {
      beta1 = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[i] != 0.0) {
        boolean_T exitg2;
        lastv = 6 - i;
        knt = (ii - i) + 5;
        while ((lastv > 0) && (b_A[knt] == 0.0)) {
          lastv--;
          knt--;
        }

        knt = 2 - i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          int32_T exitg1;
          coltop = ((knt - 1) * 6 + ii) + 6;
          c_tmp = coltop;
          do {
            exitg1 = 0;
            if (c_tmp + 1 <= coltop + lastv) {
              if (b_A[c_tmp] != 0.0) {
                exitg1 = 1;
              } else {
                c_tmp++;
              }
            } else {
              knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        knt = 0;
      }

      if (lastv > 0) {
        xgemv_g(lastv, knt, b_A, ii + 7, b_A, ii + 1, work);
        xgerc_a(lastv, knt, -tau[i], ii + 1, work, b_A, ii + 7);
      }

      b_A[ii] = beta1;
    }
  }

  for (i = 0; i < 3; i++) {
    for (ii = 0; ii <= i; ii++) {
      R[ii + 3 * i] = b_A[6 * i + ii];
    }

    for (ii = i + 2; ii < 4; ii++) {
      R[(ii + 3 * i) - 1] = 0.0;
    }
  }

  for (i = 0; i < 3; i++) {
    S[3 * i] = R[i];
    S[3 * i + 1] = R[i + 3];
    S[3 * i + 2] = R[i + 6];
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xnrm2_gwq(int32_T n, const real_T x[9], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xdotc(int32_T n, const real_T x[9], int32_T ix0, const real_T y[9],
                    int32_T iy0)
{
  real_T d;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T xnrm2_gwqu(int32_T n, const real_T x[3], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xaxpy_c(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T
                    y[3], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xaxpy_cs(int32_T n, real_T a, const real_T x[3], int32_T ix0, real_T
                     y[9], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xswap(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + temp * s;
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void svd(const real_T A[9], real_T U[9], real_T s[3], real_T V[9])
{
  real_T b_A[9];
  real_T b_s[3];
  real_T e[3];
  real_T work[3];
  real_T nrm;
  real_T rt;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T kase;
  int32_T m;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  b_s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (m = 0; m < 9; m++) {
    b_A[m] = A[m];
    U[m] = 0.0;
    V[m] = 0.0;
  }

  for (m = 0; m < 2; m++) {
    boolean_T apply_transform;
    qp1 = m + 2;
    qq = (3 * m + m) + 1;
    apply_transform = false;
    nrm = xnrm2_gwq(3 - m, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        b_s[m] = -nrm;
      } else {
        b_s[m] = nrm;
      }

      if (fabs(b_s[m]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b_s[m];
        qjj = (qq - m) + 2;
        for (kase = qq; kase <= qjj; kase++) {
          b_A[kase - 1] *= nrm;
        }
      } else {
        qjj = (qq - m) + 2;
        for (kase = qq; kase <= qjj; kase++) {
          b_A[kase - 1] /= b_s[m];
        }
      }

      b_A[qq - 1]++;
      b_s[m] = -b_s[m];
    } else {
      b_s[m] = 0.0;
    }

    for (kase = qp1; kase < 4; kase++) {
      qjj = (kase - 1) * 3 + m;
      if (apply_transform) {
        xaxpy(3 - m, -(xdotc(3 - m, b_A, qq, b_A, qjj + 1) / b_A[m + 3 * m]), qq,
              b_A, qjj + 1);
      }

      e[kase - 1] = b_A[qjj];
    }

    for (qq = m + 1; qq < 4; qq++) {
      kase = (3 * m + qq) - 1;
      U[kase] = b_A[kase];
    }

    if (m + 1 <= 1) {
      nrm = xnrm2_gwqu(2, e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }

        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (qq = qp1; qq < 4; qq++) {
            e[qq - 1] *= nrm;
          }
        } else {
          for (qq = qp1; qq < 4; qq++) {
            e[qq - 1] /= nrm;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (qq = qp1; qq < 4; qq++) {
          work[qq - 1] = 0.0;
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_c(2, e[qq - 1], b_A, 3 * (qq - 1) + 2, work, 2);
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_cs(2, -e[qq - 1] / e[1], work, 2, b_A, 3 * (qq - 1) + 2);
        }
      }

      for (qq = qp1; qq < 4; qq++) {
        V[qq - 1] = e[qq - 1];
      }
    }
  }

  m = 1;
  b_s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qp1 = 1; qp1 >= 0; qp1--) {
    qq = 3 * qp1 + qp1;
    if (b_s[qp1] != 0.0) {
      for (kase = qp1 + 2; kase < 4; kase++) {
        qjj = ((kase - 1) * 3 + qp1) + 1;
        xaxpy(3 - qp1, -(xdotc(3 - qp1, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }

      for (qjj = qp1 + 1; qjj < 4; qjj++) {
        kase = (3 * qp1 + qjj) - 1;
        U[kase] = -U[kase];
      }

      U[qq]++;
      if (qp1 - 1 >= 0) {
        U[3 * qp1] = 0.0;
      }
    } else {
      U[3 * qp1] = 0.0;
      U[3 * qp1 + 1] = 0.0;
      U[3 * qp1 + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (qp1 = 2; qp1 >= 0; qp1--) {
    if ((qp1 + 1 <= 1) && (e[0] != 0.0)) {
      xaxpy(2, -(xdotc(2, V, 2, V, 5) / V[1]), 2, V, 5);
      xaxpy(2, -(xdotc(2, V, 2, V, 8) / V[1]), 2, V, 8);
    }

    V[3 * qp1] = 0.0;
    V[3 * qp1 + 1] = 0.0;
    V[3 * qp1 + 2] = 0.0;
    V[qp1 + 3 * qp1] = 1.0;
  }

  for (qp1 = 0; qp1 < 3; qp1++) {
    smm1 = e[qp1];
    if (b_s[qp1] != 0.0) {
      rt = fabs(b_s[qp1]);
      nrm = b_s[qp1] / rt;
      b_s[qp1] = rt;
      if (qp1 + 1 < 3) {
        smm1 /= nrm;
      }

      qq = 3 * qp1 + 1;
      for (qjj = qq; qjj <= qq + 2; qjj++) {
        U[qjj - 1] *= nrm;
      }
    }

    if ((qp1 + 1 < 3) && (smm1 != 0.0)) {
      rt = fabs(smm1);
      nrm = rt / smm1;
      smm1 = rt;
      b_s[qp1 + 1] *= nrm;
      qq = (qp1 + 1) * 3 + 1;
      for (qjj = qq; qjj <= qq + 2; qjj++) {
        V[qjj - 1] *= nrm;
      }
    }

    e[qp1] = smm1;
  }

  qp1 = 0;
  nrm = fmax(fmax(fmax(0.0, fmax(fabs(b_s[0]), fabs(e[0]))), fmax(fabs(b_s[1]),
    fabs(e[1]))), fmax(fabs(b_s[2]), fabs(e[2])));
  while ((m + 2 > 0) && (qp1 < 75)) {
    kase = m + 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      qq = kase;
      if (kase == 0) {
        exitg1 = 1;
      } else {
        rt = fabs(e[kase - 1]);
        if (rt <= (fabs(b_s[kase - 1]) + fabs(b_s[kase])) *
            2.2204460492503131E-16) {
          e[kase - 1] = 0.0;
          exitg1 = 1;
        } else if ((rt <= 1.0020841800044864E-292) || ((qp1 > 20) && (rt <=
                     2.2204460492503131E-16 * nrm))) {
          e[kase - 1] = 0.0;
          exitg1 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg1 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      int32_T k_ii;
      boolean_T exitg2;
      qjj = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= kase)) {
        qjj = k_ii;
        if (k_ii == kase) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (k_ii < m + 2) {
            rt = fabs(e[k_ii - 1]);
          }

          if (k_ii > kase + 1) {
            rt += fabs(e[k_ii - 2]);
          }

          ztest = fabs(b_s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qjj == kase) {
        kase = 3;
      } else if (m + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        qq = qjj;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qjj = m + 1; qjj >= qq + 1; qjj--) {
        smm1 = e[0];
        xrotg(&b_s[qjj - 1], &rt, &ztest, &sqds);
        if (qjj > qq + 1) {
          rt = -sqds * e[0];
          smm1 = e[0] * ztest;
        }

        xrot(V, 3 * (qjj - 1) + 1, 3 * (m + 1) + 1, ztest, sqds);
        e[0] = smm1;
      }
      break;

     case 2:
      {
        rt = e[qq - 1];
        e[qq - 1] = 0.0;
        for (qjj = qq + 1; qjj <= m + 2; qjj++) {
          real_T emm1;
          xrotg(&b_s[qjj - 1], &rt, &ztest, &sqds);
          emm1 = e[qjj - 1];
          rt = emm1 * -sqds;
          e[qjj - 1] = emm1 * ztest;
          xrot(U, 3 * (qjj - 1) + 1, 3 * (qq - 1) + 1, ztest, sqds);
        }
      }
      break;

     case 3:
      {
        real_T emm1;
        real_T shift;
        sqds = b_s[m + 1];
        ztest = fmax(fmax(fmax(fmax(fabs(sqds), fabs(b_s[m])), fabs(e[m])), fabs
                          (b_s[qq])), fabs(e[qq]));
        rt = sqds / ztest;
        smm1 = b_s[m] / ztest;
        emm1 = e[m] / ztest;
        sqds = b_s[qq] / ztest;
        smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
        emm1 *= rt;
        emm1 *= emm1;
        if ((smm1 != 0.0) || (emm1 != 0.0)) {
          shift = sqrt(smm1 * smm1 + emm1);
          if (smm1 < 0.0) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0;
        }

        rt = (sqds + rt) * (sqds - rt) + shift;
        ztest = e[qq] / ztest * sqds;
        for (qjj = qq + 1; qjj <= m + 1; qjj++) {
          xrotg(&rt, &ztest, &sqds, &smm1);
          if (qjj > qq + 1) {
            e[0] = rt;
          }

          emm1 = e[qjj - 1];
          rt = b_s[qjj - 1];
          e[qjj - 1] = emm1 * sqds - rt * smm1;
          ztest = smm1 * b_s[qjj];
          b_s[qjj] *= sqds;
          xrot(V, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds, smm1);
          b_s[qjj - 1] = rt * sqds + emm1 * smm1;
          xrotg(&b_s[qjj - 1], &ztest, &sqds, &smm1);
          rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
          b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
          ztest = smm1 * e[qjj];
          e[qjj] *= sqds;
          xrot(U, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds, smm1);
        }

        e[m] = rt;
        qp1++;
      }
      break;

     default:
      if (b_s[qq] < 0.0) {
        b_s[qq] = -b_s[qq];
        qp1 = 3 * qq + 1;
        for (qjj = qp1; qjj <= qp1 + 2; qjj++) {
          V[qjj - 1] = -V[qjj - 1];
        }
      }

      qp1 = qq + 1;
      while ((qq + 1 < 3) && (b_s[qq] < b_s[qp1])) {
        rt = b_s[qq];
        b_s[qq] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(V, 3 * qq + 1, 3 * (qq + 1) + 1);
        xswap(U, 3 * qq + 1, 3 * (qq + 1) + 1);
        qq = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
  s[2] = b_s[2];
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgemv_gp(int32_T m, int32_T n, const real_T A[9], int32_T ia0, const
                     real_T x[9], int32_T ix0, real_T y[3])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = (n - 1) * 3 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 3) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (iyend = b_iy; iyend < d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = div_nde_s32_floor(b_iy - ia0, 3);
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void xgerc_aq(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                     real_T y[3], real_T A[9], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 3;
    }
  }
}

/* Function for MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void qr(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T tau[3];
  real_T work[3];
  int32_T b_coltop;
  int32_T b_lastv;
  int32_T coltop;
  int32_T exitg1;
  int32_T ii;
  int32_T itau;
  int32_T knt;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  tau[2] = 0.0;
  work[2] = 0.0;
  for (itau = 0; itau < 3; itau++) {
    ii = itau * 3 + itau;
    if (itau + 1 < 3) {
      real_T atmp;
      real_T beta1;
      atmp = b_A[ii];
      b_lastv = ii + 2;
      tau[itau] = 0.0;
      beta1 = xnrm2_gwq(2 - itau, b_A, ii + 2);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(b_A[ii], beta1);
        if (b_A[ii] >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          b_coltop = (ii - itau) + 3;
          do {
            knt++;
            for (coltop = b_lastv; coltop <= b_coltop; coltop++) {
              b_A[coltop - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(atmp, xnrm2_gwq(2 - itau, b_A, ii + 2));
          if (atmp >= 0.0) {
            beta1 = -beta1;
          }

          tau[itau] = (beta1 - atmp) / beta1;
          atmp = 1.0 / (atmp - beta1);
          for (coltop = b_lastv; coltop <= b_coltop; coltop++) {
            b_A[coltop - 1] *= atmp;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            beta1 *= 1.0020841800044864E-292;
          }

          atmp = beta1;
        } else {
          tau[itau] = (beta1 - b_A[ii]) / beta1;
          atmp = 1.0 / (b_A[ii] - beta1);
          knt = (ii - itau) + 3;
          for (b_coltop = b_lastv; b_coltop <= knt; b_coltop++) {
            b_A[b_coltop - 1] *= atmp;
          }

          atmp = beta1;
        }
      }

      b_A[ii] = atmp;
      beta1 = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[itau] != 0.0) {
        b_lastv = 3 - itau;
        knt = (ii - itau) + 2;
        while ((b_lastv > 0) && (b_A[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - itau;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 3 + ii) + 3;
          coltop = b_coltop;
          do {
            exitg1 = 0;
            if (coltop + 1 <= b_coltop + b_lastv) {
              if (b_A[coltop] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        xgemv_gp(b_lastv, knt, b_A, ii + 4, b_A, ii + 1, work);
        xgerc_aq(b_lastv, knt, -tau[itau], ii + 1, work, b_A, ii + 4);
      }

      b_A[ii] = beta1;
    } else {
      tau[2] = 0.0;
    }
  }

  for (itau = 0; itau < 3; itau++) {
    for (ii = 0; ii <= itau; ii++) {
      R[ii + 3 * itau] = b_A[3 * itau + ii];
    }

    for (ii = itau + 2; ii < 4; ii++) {
      R[(ii + 3 * itau) - 1] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (ii = 2; ii >= 0; ii--) {
    b_lastv = (ii * 3 + ii) + 4;
    if (ii + 1 < 3) {
      b_A[b_lastv - 4] = 1.0;
      if (tau[ii] != 0.0) {
        knt = 3 - ii;
        b_coltop = b_lastv - ii;
        while ((knt > 0) && (b_A[b_coltop - 2] == 0.0)) {
          knt--;
          b_coltop--;
        }

        b_coltop = 2 - ii;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = (b_coltop - 1) * 3 + b_lastv;
          itau = coltop;
          do {
            exitg1 = 0;
            if (itau <= (coltop + knt) - 1) {
              if (b_A[itau - 1] != 0.0) {
                exitg1 = 1;
              } else {
                itau++;
              }
            } else {
              b_coltop--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        b_coltop = 0;
      }

      if (knt > 0) {
        xgemv_gp(knt, b_coltop, b_A, b_lastv, b_A, b_lastv - 3, work);
        xgerc_aq(knt, b_coltop, -tau[ii], b_lastv - 3, work, b_A, b_lastv);
      }

      knt = (b_lastv - ii) - 1;
      for (b_coltop = b_lastv - 2; b_coltop <= knt; b_coltop++) {
        b_A[b_coltop - 1] *= -tau[ii];
      }
    }

    b_A[b_lastv - 4] = 1.0 - tau[ii];
    for (b_coltop = 0; b_coltop < ii; b_coltop++) {
      b_A[(b_lastv - b_coltop) - 5] = 0.0;
    }
  }

  for (itau = 0; itau < 3; itau++) {
    Q[3 * itau] = b_A[3 * itau];
    ii = 3 * itau + 1;
    Q[ii] = b_A[ii];
    ii = 3 * itau + 2;
    Q[ii] = b_A[ii];
  }
}

/* Model step function */
void RC_Model_KF_vout_for_MCU_step(void)
{
  real_T Ss[9];
  real_T a__1[9];
  real_T rtb_A[9];
  real_T rtb_SNew[9];
  real_T rtb_SNew_0[9];
  real_T rtb_Zs[9];
  real_T Hnew[3];
  real_T b_c[3];
  real_T rtb_C[3];
  real_T rtb_L[3];
  real_T rtb_M[3];
  real_T s[3];
  real_T Product3_idx_1;
  real_T Product3_idx_2;
  real_T a_vo;
  real_T a_vo_tmp;
  real_T a_vo_tmp_tmp;
  real_T absxk;
  real_T rtb_Cbulk;
  real_T rtb_Csurface;
  real_T rtb_Rb;
  real_T rtb_Rt;
  real_T scale;
  real_T yCovSqrt;
  int32_T i;
  int32_T iAcol;
  int32_T j;
  boolean_T errorCondition;

  /* Delay: '<S1>/MemoryP' incorporates:
   *  Constant: '<S1>/P0'
   */
  if (rtDW.icLoad) {
    memcpy(&rtDW.MemoryP_DSTATE[0], &rtConstP.P0_Value[0], 9U * sizeof(real_T));
  }

  /* Lookup_n-D: '<Root>/Rt' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Rt = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled3,
                        rtConstP.Rt_tableData, 6U);

  /* Lookup_n-D: '<Root>/Rb' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Rb = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled3, rtConstP.pooled4,
                        6U);

  /* Lookup_n-D: '<Root>/Cbulk' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Cbulk = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled3,
    rtConstP.Cbulk_tableData, 6U);

  /* Lookup_n-D: '<Root>/Csurface' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Csurface = look1_binlca(rtDW.Delay_DSTATE, rtConstP.pooled3,
    rtConstP.Csurface_tableData, 6U);

  /* MATLAB Function: '<Root>/Matrix Generator' */
  rtb_C[0] = 0.0;
  rtb_C[1] = 0.0;
  rtb_C[2] = 1.0;
  Product3_idx_2 = 2.0 * rtb_Cbulk * rtb_Rb;
  a_vo_tmp_tmp = 2.0 * rtb_Csurface * rtb_Rb;
  a_vo_tmp = 1.0 / a_vo_tmp_tmp;
  a_vo = 1.0 / Product3_idx_2 - a_vo_tmp;
  yCovSqrt = exp(-0.1 / (2.0 * rtb_Rb * rtb_Cbulk));
  scale = exp(-0.1 / (2.0 * rtb_Rb * rtb_Csurface));
  absxk = exp(-a_vo * 0.1);
  rtb_A[0] = yCovSqrt;
  rtb_A[3] = 1.0 - yCovSqrt;
  rtb_A[6] = 0.0;
  rtb_A[1] = 1.0 - scale;
  rtb_A[4] = scale;
  rtb_A[7] = 0.0;
  rtb_A[2] = (-1.0 / Product3_idx_2 + a_vo_tmp) * (1.0 / a_vo * (absxk - 1.0));
  rtb_A[5] = 0.0;
  rtb_A[8] = absxk;

  /* Outputs for Atomic SubSystem: '<S1>/CalculatePL' */
  /* MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' incorporates:
   *  Constant: '<S23>/Bbar_'
   *  Constant: '<S23>/Qbar_'
   *  Constant: '<S23>/Rbar_'
   *  Delay: '<S1>/MemoryP'
   */
  yCovSqrt = qrFactor(rtb_C, rtDW.MemoryP_DSTATE, 1.0);
  for (j = 0; j < 3; j++) {
    Hnew[j] = 0.0;
    for (iAcol = 0; iAcol < 3; iAcol++) {
      i = 3 * iAcol + j;
      Ss[i] = 0.0;
      Ss[i] += rtDW.MemoryP_DSTATE[j] * rtDW.MemoryP_DSTATE[iAcol];
      Ss[i] += rtDW.MemoryP_DSTATE[j + 3] * rtDW.MemoryP_DSTATE[iAcol + 3];
      Ss[i] += rtDW.MemoryP_DSTATE[j + 6] * rtDW.MemoryP_DSTATE[iAcol + 6];
      Hnew[j] += Ss[i] * rtb_C[iAcol];
    }
  }

  for (j = 0; j < 3; j++) {
    b_c[j] = (rtb_A[j + 3] * Hnew[1] + rtb_A[j] * Hnew[0]) + rtb_A[j + 6] *
      Hnew[2];
  }

  trisolve(yCovSqrt, b_c);
  rtb_L[0] = b_c[0];
  rtb_L[1] = b_c[1];
  rtb_L[2] = b_c[2];
  trisolve(yCovSqrt, rtb_L);
  b_c[0] = Hnew[0];
  b_c[1] = Hnew[1];
  b_c[2] = Hnew[2];
  trisolve(yCovSqrt, b_c);
  rtb_M[0] = b_c[0];
  rtb_M[1] = b_c[1];
  rtb_M[2] = b_c[2];
  trisolve(yCovSqrt, rtb_M);
  for (i = 0; i < 9; i++) {
    Ss[i] = 0.0;
    rtb_Zs[i] = rtDW.MemoryP_DSTATE[i];
  }

  Ss[0] = 1.0;
  Ss[4] = 1.0;
  Ss[8] = 1.0;
  for (j = 0; j < 3; j++) {
    yCovSqrt = rtb_C[j];
    rtb_SNew[3 * j] = Ss[3 * j] - rtb_M[0] * yCovSqrt;
    iAcol = 3 * j + 1;
    rtb_SNew[iAcol] = Ss[iAcol] - rtb_M[1] * yCovSqrt;
    iAcol = 3 * j + 2;
    rtb_SNew[iAcol] = Ss[iAcol] - rtb_M[2] * yCovSqrt;
    Hnew[j] = rtb_M[j];
  }

  qrFactor_j(rtb_SNew, rtb_Zs, Hnew);
  memcpy(&Ss[0], &rtb_Zs[0], 9U * sizeof(real_T));
  for (j = 0; j < 3; j++) {
    rtb_SNew[3 * j] = rtb_A[3 * j];
    iAcol = 3 * j + 1;
    rtb_SNew[iAcol] = rtb_A[iAcol];
    iAcol = 3 * j + 2;
    rtb_SNew[iAcol] = rtb_A[iAcol];
  }

  qrFactor_jq(rtb_SNew, Ss, rtConstP.Qbar_Value);
  for (j = 0; j < 3; j++) {
    rtb_SNew[3 * j] = Ss[j];
    rtb_SNew[3 * j + 1] = Ss[j + 3];
    rtb_SNew[3 * j + 2] = Ss[j + 6];
  }

  for (j = 0; j < 3; j++) {
    if (1 - j >= 0) {
      memset(&rtb_SNew[(j << 2) + 1], 0, (uint32_T)((1 - j) + 1) * sizeof(real_T));
    }
  }

  errorCondition = (rtb_SNew[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_SNew[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_SNew[8] == 0.0);
  }

  if (errorCondition) {
    boolean_T exitg2;
    for (j = 0; j < 3; j++) {
      for (iAcol = 0; iAcol < 3; iAcol++) {
        i = 3 * iAcol + j;
        rtb_SNew_0[i] = 0.0;
        rtb_SNew_0[i] += rtb_SNew[3 * j] * rtb_SNew[3 * iAcol];
        rtb_SNew_0[i] += rtb_SNew[3 * j + 1] * rtb_SNew[3 * iAcol + 1];
        rtb_SNew_0[i] += rtb_SNew[3 * j + 2] * rtb_SNew[3 * iAcol + 2];
      }
    }

    for (j = 0; j < 9; j++) {
      yCovSqrt = rtb_SNew_0[j];
      if (errorCondition && (rtIsInf(yCovSqrt) || rtIsNaN(yCovSqrt))) {
        errorCondition = false;
      }

      Ss[j] = yCovSqrt;
    }

    if (errorCondition) {
      svd(Ss, a__1, s, rtb_SNew_0);
    } else {
      s[0] = (rtNaN);
      s[1] = (rtNaN);
      s[2] = (rtNaN);
      for (j = 0; j < 9; j++) {
        rtb_SNew_0[j] = (rtNaN);
      }
    }

    memset(&Ss[0], 0, 9U * sizeof(real_T));
    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (j = 0; j < 9; j++) {
      Ss[j] = sqrt(Ss[j]);
    }

    for (j = 0; j < 3; j++) {
      for (iAcol = 0; iAcol < 3; iAcol++) {
        i = 3 * iAcol + j;
        rtb_SNew[i] = 0.0;
        rtb_SNew[i] += Ss[3 * j] * rtb_SNew_0[iAcol];
        rtb_SNew[i] += Ss[3 * j + 1] * rtb_SNew_0[iAcol + 3];
        rtb_SNew[i] += Ss[3 * j + 2] * rtb_SNew_0[iAcol + 6];
      }
    }

    errorCondition = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 3)) {
      int32_T exitg1;
      iAcol = j + 1;
      do {
        exitg1 = 0;
        if (iAcol + 1 < 4) {
          if (!(rtb_SNew[3 * j + iAcol] == 0.0)) {
            errorCondition = false;
            exitg1 = 1;
          } else {
            iAcol++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      memcpy(&rtb_SNew_0[0], &rtb_SNew[0], 9U * sizeof(real_T));
      qr(rtb_SNew_0, a__1, rtb_SNew);
    }
  } else {
    Hnew[0] = 0.0;
    Hnew[1] = 0.0;
    Hnew[2] = 0.0;
    for (j = 0; j < 3; j++) {
      iAcol = 3 * j;
      yCovSqrt = Hnew[j];
      for (i = 0; i < j; i++) {
        yCovSqrt -= rtb_SNew[i + iAcol] * Hnew[i];
      }

      Hnew[j] = yCovSqrt / rtb_SNew[j + iAcol];
    }

    if (Hnew[2] == 0.0) {
      b_c[2] = 1.0;
      s[2] = 0.0;
    } else {
      b_c[2] = (rtNaN);
      s[2] = (rtNaN);
    }

    Hnew[2] = 0.0;
    if (Hnew[1] == 0.0) {
      b_c[1] = 1.0;
      s[1] = 0.0;
    } else {
      b_c[1] = (rtNaN);
      s[1] = (rtNaN);
    }

    Hnew[1] = 0.0;
    if (Hnew[0] == 0.0) {
      b_c[0] = 1.0;
      s[0] = 0.0;
    } else {
      b_c[0] = (rtNaN);
      s[0] = (rtNaN);
    }

    Hnew[0] = 0.0;
    for (j = 0; j < 3; j++) {
      for (iAcol = j + 1; iAcol >= 1; iAcol--) {
        yCovSqrt = Hnew[j];
        i = (3 * j + iAcol) - 1;
        Product3_idx_2 = rtb_SNew[i];
        a_vo_tmp = s[iAcol - 1];
        scale = b_c[iAcol - 1];
        rtb_SNew[i] = Product3_idx_2 * scale - a_vo_tmp * yCovSqrt;
        Hnew[j] = scale * yCovSqrt + Product3_idx_2 * a_vo_tmp;
      }
    }
  }

  for (j = 0; j < 3; j++) {
    rtb_SNew_0[3 * j] = rtb_SNew[j];
    rtb_SNew_0[3 * j + 1] = rtb_SNew[j + 3];
    rtb_SNew_0[3 * j + 2] = rtb_SNew[j + 6];
  }

  memcpy(&rtb_SNew[0], &rtb_SNew_0[0], 9U * sizeof(real_T));

  /* End of MATLAB Function: '<S3>/Discrete-Time SqrtKF - Calculate SLMZ' */
  /* End of Outputs for SubSystem: '<S1>/CalculatePL' */

  /* Delay: '<S1>/MemoryX' incorporates:
   *  Constant: '<S1>/X0'
   */
  if (rtDW.icLoad_o) {
    rtDW.MemoryX_DSTATE[0] = 12.6;
    rtDW.MemoryX_DSTATE[1] = 12.6;
    rtDW.MemoryX_DSTATE[2] = 12.6;
  }

  /* Outputs for Enabled SubSystem: '<S28>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* Sum: '<S51>/Add1' incorporates:
   *  Delay: '<S1>/MemoryX'
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/voltage'
   *  MATLAB Function: '<Root>/Matrix Generator'
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   */
  yCovSqrt = (rtU.voltage - ((0.0 * rtDW.MemoryX_DSTATE[0] + 0.0 *
    rtDW.MemoryX_DSTATE[1]) + rtDW.MemoryX_DSTATE[2])) - 0.0 * rtU.current;

  /* Sum: '<S28>/Add' incorporates:
   *  Delay: '<S1>/MemoryX'
   *  Product: '<S51>/Product2'
   */
  rtb_M[0] = rtb_M[0] * yCovSqrt + rtDW.MemoryX_DSTATE[0];

  /* Product: '<S51>/Product2' */
  a_vo_tmp = rtb_M[1] * yCovSqrt;

  /* Sum: '<S28>/Add' incorporates:
   *  Delay: '<S1>/MemoryX'
   *  Product: '<S51>/Product2'
   */
  scale = rtb_M[2] * yCovSqrt + rtDW.MemoryX_DSTATE[2];

  /* End of Outputs for SubSystem: '<S28>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S22>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S47>/Enable'
   */
  /* Sum: '<S47>/Sum' incorporates:
   *  Delay: '<S1>/MemoryX'
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/voltage'
   *  MATLAB Function: '<Root>/Matrix Generator'
   *  Product: '<S47>/C[k]*xhat[k|k-1]'
   *  Product: '<S47>/D[k]*u[k]'
   *  Sum: '<S47>/Add1'
   */
  yCovSqrt = rtU.voltage - (((0.0 * rtDW.MemoryX_DSTATE[0] + 0.0 *
    rtDW.MemoryX_DSTATE[1]) + rtDW.MemoryX_DSTATE[2]) + 0.0 * rtU.current);

  /* Product: '<S47>/Product3' */
  absxk = rtb_L[0] * yCovSqrt;
  Product3_idx_1 = rtb_L[1] * yCovSqrt;
  Product3_idx_2 = rtb_L[2] * yCovSqrt;

  /* End of Outputs for SubSystem: '<S22>/MeasurementUpdate' */

  /* Lookup_n-D: '<Root>/1-D Lookup Table' */
  yCovSqrt = look1_binlg(rtb_M[0], rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, 7U);

  /* Saturate: '<Root>/Saturation' */
  if (yCovSqrt > 1.0) {
    yCovSqrt = 1.0;
  } else if (yCovSqrt < 0.0) {
    yCovSqrt = 0.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/soc_estimated' */
  rtY.soc_estimated = yCovSqrt;

  /* Outport: '<Root>/voltage_estimated' incorporates:
   *  Delay: '<S1>/MemoryX'
   *  Inport: '<Root>/current'
   *  MATLAB Function: '<Root>/Matrix Generator'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sum: '<S28>/Add'
   *  Sum: '<S4>/Add1'
   */
  rtY.voltage_estimated = (((a_vo_tmp + rtDW.MemoryX_DSTATE[1]) * 0.0 + 0.0 *
    rtb_M[0]) + scale) + 0.0 * rtU.current;

  /* MATLAB Function: '<S45>/SqrtUsedFcn' */
  for (j = 0; j < 3; j++) {
    for (iAcol = 0; iAcol < 3; iAcol++) {
      Ss[j + 3 * iAcol] = (rtb_Zs[j + 3] * rtb_Zs[iAcol + 3] + rtb_Zs[j] *
                           rtb_Zs[iAcol]) + rtb_Zs[j + 6] * rtb_Zs[iAcol + 6];
    }
  }

  /* End of MATLAB Function: '<S45>/SqrtUsedFcn' */

  /* Outport: '<Root>/standard_deviation' incorporates:
   *  Gain: '<Root>/Gain'
   *  Selector: '<Root>/Selector2'
   *  Sqrt: '<Root>/Sqrt'
   */
  rtY.standard_deviation = 3.0 * sqrt(Ss[0]);

  /* Outport: '<Root>/soc_measured' incorporates:
   *  Constant: '<Root>/Battery Capacity Ah'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<Root>/Divide9'
   */
  rtY.soc_measured = rtDW.DiscreteTimeIntegrator_DSTATE / 5.0;

  /* Update for Delay: '<S1>/MemoryP' */
  rtDW.icLoad = false;
  memcpy(&rtDW.MemoryP_DSTATE[0], &rtb_SNew[0], 9U * sizeof(real_T));

  /* Update for Delay: '<Root>/Delay' */
  rtDW.Delay_DSTATE = yCovSqrt;

  /* Update for Delay: '<S1>/MemoryX' */
  rtDW.icLoad_o = false;

  /* Product: '<S22>/A[k]*xhat[k|k-1]' incorporates:
   *  Delay: '<S1>/MemoryX'
   */
  for (j = 0; j < 3; j++) {
    rtb_C[j] = (rtb_A[j + 3] * rtDW.MemoryX_DSTATE[1] + rtb_A[j] *
                rtDW.MemoryX_DSTATE[0]) + rtb_A[j + 6] * rtDW.MemoryX_DSTATE[2];
  }

  /* End of Product: '<S22>/A[k]*xhat[k|k-1]' */

  /* Update for Delay: '<S1>/MemoryX' incorporates:
   *  Inport: '<Root>/current'
   *  MATLAB Function: '<Root>/Matrix Generator'
   *  Product: '<S22>/B[k]*u[k]'
   *  Sum: '<S22>/Add'
   */
  rtDW.MemoryX_DSTATE[0] = ((1.0 - exp(-0.1 / (2.0 * rtb_Rb * rtb_Cbulk))) *
    rtb_Rb * rtU.current + rtb_C[0]) + absxk;
  rtDW.MemoryX_DSTATE[1] = ((1.0 - exp(-0.1 / (2.0 * rtb_Rb * rtb_Csurface))) *
    rtb_Rb * rtU.current + rtb_C[1]) + Product3_idx_1;

  /* MATLAB Function: '<Root>/Matrix Generator' */
  rtb_Rt /= a_vo_tmp_tmp;

  /* Update for Delay: '<S1>/MemoryX' incorporates:
   *  Inport: '<Root>/current'
   *  MATLAB Function: '<Root>/Matrix Generator'
   *  Product: '<S22>/B[k]*u[k]'
   *  Sum: '<S22>/Add'
   */
  rtDW.MemoryX_DSTATE[2] = (((1.0 / (2.0 * rtb_Csurface) - rtb_Rt) + rtb_Rt) *
    ((exp(-a_vo * 0.1) - 1.0) * (1.0 / a_vo)) * rtU.current + rtb_C[2]) +
    Product3_idx_2;

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
}

/* Model initialize function */
void RC_Model_KF_vout_for_MCU_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/MemoryP' */
  rtDW.icLoad = true;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  rtDW.Delay_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S1>/MemoryX' */
  rtDW.icLoad_o = true;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = 5.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
