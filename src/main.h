#ifndef _MAIN_H_
#define _MAIN_H_

#include <dynamic_libs/os_functions.h>
#include <dynamic_libs/os_types.h>

/* Main */
#ifdef __cplusplus
extern "C" {
#endif

//! C wrapper for our C++ functions
int Menu_Main(void);
void deInit(void);
void ApplyPatches(void);
void RestorePatches();
void Init_SD_USB(void);
void deInit_SD_USB(void);

s32 isInMiiMakerHBL();

#ifdef __cplusplus
}
#endif

#endif
