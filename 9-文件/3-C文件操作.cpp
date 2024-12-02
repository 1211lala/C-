/**
    stat 函数：适用于所有类 Unix 系统，通过检查 S_ISDIR 来判断是否为目录。
    opendir 函数：更简洁地判断目录是否存在，并且能够在打开目录时直接返回 DIR 指针。
    access 函数：检查路径是否存在，并且判断是否有读取权限。

    "r"：以只读模式打开文件。如果文件不存在，则返回 NULL。
    "w"：以写入模式打开文件。如果文件已存在，文件内容会被清空；如果文件不存在，则创建新文件。
    "a"：以附加模式打开文件，数据写入到文件末尾。如果文件不存在，则会创建新文件。
    "r+"：以读写模式打开文件。如果文件不存在，则返回 NULL。
    "w+"：以读写模式打开文件。如果文件已存在，文件内容会被清空；如果文件不存在，则创建
 */

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string.h>
using namespace std;

void scan_file(const char *path)
{
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("无法打开文件夹");
        return;
    }
    struct dirent *entry;
    struct stat statbuf;

    char file_path[5000];
    while ((entry = readdir(dir)) != NULL)
    {
        // 忽略 "." 和 ".."
        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || (entry->d_name[1] == '.' && entry->d_name[2] == '\0')))
        {
            continue;
        }
        sprintf(file_path, "%s/%s", path, entry->d_name);
        // 如果是目录
        if (stat(file_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
        {
            scan_file(file_path);
        }
        else
        {
            printf("%s  size: %ld\n", file_path, statbuf.st_size);
        }
    }
    closedir(dir); // 关闭目录
}

void test_01(void)
{
    char buf[50];
    mkdir("./testDir", 0777);
    for (int i = 0; i < 5; i++)
    {
        sprintf(buf, "./testDir/text%d.c", i);
        FILE *f = fopen(buf, "w");
        if (strlen("hello C") != fwrite("hello C", sizeof(char), strlen("hello C"), f))
        {
            perror("文件写入失败\n");
        }
        fclose(f);
    }
    scan_file("./testDir");
}
int main(void)
{
    char path[100];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len != -1)
    {
        path[len] = '\0'; // Null-terminate the string
        printf("PWD: %s\n", path);
    }
    else
    {
        perror("readlink");
    }
    test_01();

    printf("access(\"/home\") :%d\n", access("/home", F_OK));
    printf("access(\"/hom\") :%d\n", access("/hom", F_OK));

    
}