#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// ofstream ofs;
// ifstream ifs;
fstream fs;

string str = "hello fstream\n";
int main(void)
{
    fs.open("./text.txt", ios::out);

    for (int i = 0; i < 1000; i++)
    {
        fs << i << " ";
        fs.write(str.c_str(), strlen(str.c_str()));
    }
    fs.close();

    fs.open("./text.txt", ios::in);
    if (!fs.is_open())
    {
        cout << "文件打开失败" << endl;
        return 0;
    }
    fs.seekg(0, ios::end);
    size_t fileSize = fs.tellg();
    fs.seekg(0, ios::beg);
    char *buf = (char *)malloc(fileSize + 1);
    fs.read(buf, fileSize);
    buf[fs.gcount()] = '\0';
    cout << buf << endl;
    
    fs.close();
    free(buf);
}