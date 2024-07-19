#ifndef RTW_HEADER_default_model_sf_h_
#define RTW_HEADER_default_model_sf_h_
#ifndef default_model_sf_COMMON_INCLUDES_
#define default_model_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                default_model_sf
#define S_FUNCTION_LEVEL               2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif

#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif

#include "default_model_sf_types.h"
#include <string.h>
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rt_defines.h"

typedef struct {
  real_T *In1;
} ExternalUPtrs_default_model_T;

typedef struct {
  real_T *Out1;
} ExtY_default_model_T;

#endif
