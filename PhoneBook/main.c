#include <stdio.h>
#include "phonebook.h"

//Code Written By Aryan Shams Ansari.

int main ()
{
    phoneBook pb;
    Entries Entry;
    int size = 5;
    init(&pb, size);

    insert(&pb, "Aryan", "123123");
    insert(&pb, "Pedram", "456456");
    insert(&pb, "Baran", "899532");
    insert(&pb, "Tibor", "555555");
    insert(&pb, "Aryan", "999999");
    insert(&pb, "Chris", "1234567");
    insert(&pb, "Jones", "2456731");

    print(&pb);

    printf("The phoneNum of the input name is: %s", get(&pb, "Aryan"));

    dump(&pb, "entries.txt");

    destroy(&pb);
}