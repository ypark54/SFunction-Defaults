

    /*
  * rt_nonfinite.h
  *
    * Code generation for model "default_model_sf".
  *
  * Model version              : 1.3
  * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
  * C source code generated on : Fri Jul 19 13:39:07 2024
 * 
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection: 
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
  */


  #ifndef RTW_HEADER_rt_nonfinite_h_
  #define RTW_HEADER_rt_nonfinite_h_
  

    

  
#include <stddef.h>
  #include "rtwtypes.h"



  

  

  

  

  

  

  

  

  

  

  

  

  

  

     
  


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
  
  
   


  

  

  

  

  

    #endif /* RTW_HEADER_rt_nonfinite_h_ */
