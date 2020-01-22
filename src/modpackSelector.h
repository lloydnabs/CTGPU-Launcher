#ifndef _MODPACK_SELECTOR_H_
#define _MODPACK_SELECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <dynamic_libs/os_types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void HandleMultiModPacks(u64 titleid/*,bool showMenu = true*/);
void console_print_pos(int x, int y, const char *format, ...);
extern void Mergerman(const char *src, char *dest);


#ifdef __cplusplus
}
#endif

#endif //_MODPACK_SELECTOR_H_
