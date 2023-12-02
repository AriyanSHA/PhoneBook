#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <stdbool.h>

struct 
{
    char name[30];
    char phoneNum[30];
}typedef Entries;

struct 
{
    int size;
    int ind;
    Entries* Entry;
}typedef phoneBook;

void init(phoneBook* pb, int size);
void destroy(phoneBook* pb);
bool insert(phoneBook* pb, char* newName, char* newPhoneNum);
char* get(phoneBook* pb, char* findName);
void print(phoneBook* pb);
void dump(phoneBook* pb, char* textFile);


#endif