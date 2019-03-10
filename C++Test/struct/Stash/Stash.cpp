#include"Stash.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void initialize(Stash *s, int size) {
    s->size = size;
    s->next = 0;
    s->quantity = 0;
    s->storage = 0;
}

void cleanup(Stash *s) {
    if (s->storage) {
        puts("freeing storage");
        free(s->storage);
    }
}

int add(Stash *s, void *element) {
    if (s->next >= s->quantity) {
        inflate(s, 100);
    }

    memcpy(&(s->storage[s->next * s->size]), element, s->size);
    s->next++;
    return(s->next - 1);
}

void* fetch(Stash *s, int index) {
    if (index >= s->next || index < 0) {
        return 0;
    }
    return &(s->storage[index * s->size]);
}

int count(Stash *s) {
    return s->next;
}

void inflate(Stash *s, int increase) {
    char* v = (char*)realloc(s->storage, (s->quantity + increase) * s->size);
    assert(v);
    s->storage = v;
    s->quantity += increase;
}
