/**
    ios::in	    为读文件而打开文件
    ios::out	为写文件而打开文件
    ios::ate	初始位置：文件尾
    ios::app	追加方式写文件
    ios::trunc	如果文件存在先删除，再创建
    ios::binary	二进制方式

原文链接：https://blog.csdn.net/houbincarson/article/details/136327765
    open()：打开文件。可以使用 open() 方法指定要打开的文件名和打开模式（如读取、写入等）。
    close()：关闭文件。使用 close() 方法关闭文件流，释放资源。
    is_open()：判断文件是否打开。可以使用 is_open() 方法检查文件流是否成功打开。
    good()、fail()、bad()、eof()：用于检查文件流的状态，如是否出错、是否到达文件末尾等。
    getline()：从文件中逐行读取数据。
    get()、put()：逐字符读取和写入数据。
    seekg()、seekp()：定位文件读写位置。
    tellg()、tellp()：获取当前文件读写位置。
    << >>：重载运算符用于文件流的输出和输入操作
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string.h>
using namespace std;
// C++语言文件函数
void test_01(void)
{
    fstream fs;
    fs.open("./text.txt", ios::out);
    if (!fs.is_open()) // 检查fs是否打开文件
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fs.write("hello C++\n", strlen("hello C++\n"));
    if (!fs.good()) // 检查fs对象有没有错误标志
    {
        cout << "文件写入出错" << endl;
    }
    fs.close();

    fs.open("./text.txt", ios::in);
    if (!fs.is_open()) // 检查fs是否打开文件
    {
        cout << "文件打开失败" << endl;
        return;
    }

    fs.seekg(0, ios::end);

    int fileSize = fs.tellg();
    fs.seekg(0, ios::beg);

    char *buf = (char *)malloc(fileSize + 1);
    fs.read(buf, fileSize);
    buf[fileSize] = '\0';
    if (!fs.good()) // 检查fs对象有没有错误标志
    {
        cout << "文件写入出错" << endl;
    }
    cout << buf << endl;
    fs.close();
    free(buf);
}

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
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
// C语言文件函数
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
    test_01();
}