#ifndef STASH_H
#define STASH_H
typedef struct STASHtag {
    int size;
    int quantity;
    int next;
    char* storage;
}Stash;

void initialize(Stash* s,int size);
int add(Stash* s, void* element);
void* fetch(Stash* s, int index);
void cleanup(Stash* s);
int count(Stash* s);
void inflate(Stash* s, int increase);

#endif // STASH_H
