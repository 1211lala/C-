#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
using namespace std;

enum AB
{
    AB_EXIT,
    AB_ADD,
    AB_SHOW,
    AB_RM,
    AB_FIND,
    AB_CLEAR,
};
#define MAX_PERSON_NUM 1000
struct PERSON
{
    string name;
    string number;
    string address;
    int sex;
    int age;
};
struct ADDRESS_BOOK
{
    struct PERSON person[MAX_PERSON_NUM];
    uint16_t num_person;
};

int load_info_from_file(struct ADDRESS_BOOK &ab, const string path);
int write_info_to_file(struct ADDRESS_BOOK &ab, const string path);

void show_list(struct ADDRESS_BOOK *ad);
void show_menu(void);

void add_person(struct ADDRESS_BOOK *ad);