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
void Mergerman(const char *src, char *dest)
{
        
    struct dirent *de;
    DIR *dir = opendir(src);
    if (!dir)
        return;

    char buffer[0x200] = {0};

    while ((de = readdir(dir)))
    {
        snprintf(buffer, sizeof(buffer), "%s/%s", dest, de->d_name);

        // check if the file is a directory.
        if (dir)
        {
            copy_dir(de->d_name, de->d_name);
        }
        else
{
    FILE *srcfile = fopen(src, "rb");
    if (!srcfile)
    {
        return;
    }

    FILE *newfile = fopen(dest, "wb");
    if (!newfile)
    {
        fclose(srcfile);
        return;
    }
    
    void *buf = malloc(0x800000);
    size_t bytes; // size of the file to write (8MiB or filesize max)

    while (0 < (bytes = fread(buf, 1, 0x800000, srcfile)))
        fwrite(buf, bytes, 1, newfile);
    free(buf);
    
    fclose(srcfile);
    fclose(newfile);
}
    }
    closedir(dir);
}


#ifdef __cplusplus
}
#endif

#endif //_MODPACK_SELECTOR_H_
