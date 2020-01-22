#ifndef _MODPACK_SELECTOR_H_
#define _MODPACK_SELECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <dynamic_libs/os_types.h>

void HandleMultiModPacks(u64 titleid/*,bool showMenu = true*/);
void console_print_pos(int x, int y, const char *format, ...);
void copy_dir(const char *src, char *dest)
{
    if (!create_dir(dest))
        return;
        
    struct dirent *de;
    DIR *dir = open_dir(src);
    if (!dir)
        return;

    char buffer[0x200] = {0};

    while ((de = readdir(dir)))
    {
        snprintf(buffer, sizeof(buffer), "%s/%s", dest, de->d_name);

        // check if the file is a directory.
        if (is_dir(de->d_name))
        {
            create_dir(buffer);
            copy_dir(de->d_name, de->d_name);
        }
        else
            copy_file(de->d_name, buffer);
    }
    closedir(dir);
}

void copy_file(const char *src, char *dest)
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
#ifdef __cplusplus
}
#endif

#endif //_MODPACK_SELECTOR_H_
