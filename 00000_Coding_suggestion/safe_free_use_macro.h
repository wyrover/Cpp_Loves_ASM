//
//  safe_free_use_macro.h
//
//    Safer release the memory space.

// Very odd name to avoid confrontation of naming
#ifndef     USER_DEFINED_MACRO___INCLUDE_THE_FILE_safe_free_use_macro_H_____________
#define     USER_DEFINED_MACRO___INCLUDE_THE_FILE_safe_free_use_macro_H_____________


/*
       this module require "stdlib.h" for C or "cstdlib" for C++ 
*/
#define     SAFE_FREE(x)    {\
                                x = (void*)x;\
								\
                                if(x)\
                                {\
                                    free(x);\
                                    x=(void *)0;\
                                }\
                            }

#endif   // #ifndef USER_DEFINED_MACRO___INCLUDE_THE_FILE_safe_free_use_macro_H_____________