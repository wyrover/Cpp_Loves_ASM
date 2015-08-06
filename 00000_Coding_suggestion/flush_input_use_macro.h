//
//    flush_input_use_macro.h
//  In a looping logic, some unproduced irrelevant input would do damage to the following logic.
//      It is necessary to flush the input line.
//

#ifndef     USER_DEFINED_MACRO___INCLUDE_THE_FILE_flush_input_use_macro_H_____________

/*
    This require the definition of "getchar"
        Or rather,  "stdio.h" for C    or "cstdio" for C++, or simply "iostream" for C++
*/

#define    flush_input( )      {\
                                   while(  '\n'  !=  (   getchar( )  )   )\
                                   {\
                                       continue;\
                                   }


#endif   // #ifndef USER_DEFINED_MACRO___INCLUDE_THE_FILE_flush_input_use_macro_H_____________