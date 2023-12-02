#include "phonebook.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void init(phoneBook* pb, int size)
{
    pb->size = size;
    pb->ind = 0;
    pb->Entry = (Entries*)malloc(pb->size * sizeof(Entries));
}

void destroy(phoneBook* pb)
{
    for (int i = 0; i < pb->size; i++)
    {
        free(pb->Entry[i].name);
        free(pb->Entry[i].phoneNum);
    }
}

bool insert(phoneBook* pb ,char* newName ,char* newPhone)
{
    if(pb->ind == pb->size)
    {
        printf("Insertion #%d not Successful\n", pb->ind + 1);
        return false;
    }
    else
    {
        bool contains = false;
        for(int i = 0; i < pb->ind ; i++)
        {
            if(strcmp((*(pb->Entry + i)).name, newName) == 0)
            {
                strcpy((*(pb->Entry + i)).phoneNum, newPhone);
                contains = true;
            }
        }
        if(contains == false)
        {
            char* temp1 = (char*)malloc(strlen(newName)+1);
                strcpy(temp1, newName);
            char* temp2 = (char*)malloc(strlen(newPhone)+1);
                strcpy(temp2, newPhone);
            
            strcpy((*(pb->Entry + pb->ind)).name, temp1);
            strcpy((*(pb->Entry + pb->ind++)).phoneNum, temp2);
            printf("Insertion #%d Successful\n", pb->ind);
        } 
        return true;
    }
}

char* get(phoneBook* pb, char* findName)
{
    for (int i = 0; i < pb->size; i++)
    {
        if (strcmp(pb->Entry[i].name, findName) == 0)
            return pb->Entry[i].phoneNum;
    }
    return NULL;
}

void print(phoneBook* pb)
{
    for (int i = 0; i < pb->ind; i++)
        printf("Number #%d: %s %s\n", i+1, pb->Entry[i].name, pb->Entry[i].phoneNum);
}

void dump(phoneBook* pb, char* textFile)
{
    FILE* fileName = fopen("entries.txt","w");
    if (fileName == NULL)
        printf("file opening not successful");
    for (int i = 0; i < pb->size; i++)
        fprintf(fileName, "%s %s\n", pb->Entry[i].name, pb->Entry[i].phoneNum);

    fclose(fileName);
}
