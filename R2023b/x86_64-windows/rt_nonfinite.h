#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_

#include <stddef.h>
#include "rtwtypes.h"

#define NOT_USING_NONFINITE_LITERALS 1
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;

extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
typedef struct  {
struct {
    uint32_T wordH;
    uint32_T wordL;
} words;
} BigEndianIEEEDouble;

typedef struct  {
struct {
    uint32_T wordL;
    uint32_T wordH;
} words;
} LittleEndianIEEEDouble;

typedef struct  {
union {
    real32_T wordLreal;
    uint32_T wordLuint;
} wordL;
} IEEESingle;

#endif /* RTW_HEADER_rt_nonfinite_h_ */
