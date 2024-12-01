#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

string str("abcdefgdefhijk");
int main(void)
{
    printf("%ld\n", str.find("def", 11));
    printf("%ld\n", str.find("def"));

    printf("%s\n", str.replace(1, 3, "1111").c_str());
    return 0;
}