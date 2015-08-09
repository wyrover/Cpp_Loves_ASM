//
//  trace_mark.h
//
//   Convenient for further debug

// Very odd name to avoid confrontation of naming
#ifndef     USER_DEFINED_MACRO___INCLUDE_THE_FILE_trace_mark_H________
#define     USER_DEFINED_MACRO___INCLUDE_THE_FILE_trace_mark_H________


#ifndef     TRACE_MARK_ENABLE

//
//    Here is the switvh.
//     If you do not want to add external Debug information inside your Ultimate Release,
//        write an 0(numeric 0, or rather, free from single quote mark),
//     otherwise, leave nonzero numeric number.
//
#define     TRACE_MARK_ENABLE       1


#if    (TRACE_MARK_ENABLE)
    #define     TraceMark(x)          __asm mov  eax, x;
#else
    #define     TraceMark(x)
#endif    // #if    (TRACE_MARK_ENABLE)

#endif    // #ifndef     TRACE_MARK_ENABLE



//-----------------------------------------------------------------
// It is necessary for solving confrontation due to naming scheme
//  Because "TRACE_MARK_ENABLE" might be a frequently used macro,
//     and once this file is compiled,
//        this macro will never be useful but form a further obstacle.
#undef    TRACE_MARK_ENABLE



#endif    // #ifndef     USER_DEFINED_MACRO___INCLUDE_THE_FILE_trace_mark_H________
