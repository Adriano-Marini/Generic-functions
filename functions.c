#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insert at the beginning of the list
void insert_at_beginning(PList list, void * data) {
    PElement new_element = (PElement)malloc(sizeof(element));
    if (!new_element) {
        printf("Memory allocation error");
        return;
    }
    new_element->data = list->duplicate(data);
    new_element->next = list->elem;
    list->elem = new_element;
}

// Insert at the end of the list
void insert_at_end(PList list, void * data) {
    PElement tmp = list->elem;
    PElement new_element = malloc(sizeof(element));
    new_element->data = list->duplicate(data);
    new_element->next = NULL;
    if (!new_element) {
        printf("Memory allocation error\n");
        return;
    }
    if (!tmp) {
        list->elem = new_element;
        return;
    }
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_element;
}

// Search for an element
PElement search_list(PList list, void* data) {
    PElement tmp = list->elem;
    while (tmp) {
        if (list->compare(tmp->data, data))
            return tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}

// Display the list
void display_list(PList list) {
    PElement tmp = list->elem;

    while (tmp) {
        list->display(tmp->data);
        tmp = tmp->next;
    }
}

// Destroy the list
void destroy_list(PList list) {
    PElement tmp = list->elem;
    PElement next = NULL;
    while (tmp) {
        next = tmp->next;
        list->destroy(tmp->data);
        free(tmp);
        tmp = next;
    }
    free(list);
}

// Write the list to a file
int write_list(PList list, const char* filename) {
    FILE* f = fopen(filename, "w");
    PElement tmp = list->elem;
    if (!f) {
        printf("Error opening the file");
        return 0;
    }
    while (tmp) {
        list->write(tmp->data, f);
        tmp = tmp->next;
    }
    fclose(f);
    return 1;
}

// Read the list from a file
int read_list(PList list, const char* filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error opening the file\n");
        return 0;
    }
    void *tmp = list->read(f);
    while (tmp) {
        insert_at_end(list, tmp);
        free(tmp);
        tmp = list->read(f);
    }
    fclose(f);
    return 1;
}

// Define our functions for integers
void* insert_int(const void* src) {
    const int* num = (int *)src;
    int* dst = (int *)malloc(sizeof(int));
    if (!dst) {
        printf("Memory allocation error\n");
        return NULL;
    }
    *dst = *num;
    return (void *)dst;
}

int compare_int(const void *data1, const void* data2) {
    const int* d1 = (int *)data1;
    const int* d2 = (int *)data2;
    return *d1 == *d2;
}

void display_int(const void *src) {
    const int *num = (int *)src;
    printf("Number: %d\n", *num);
}

void destroy(void *data) {
    free(data);
}

int write_int(const void* data, FILE*f) {
    const int* num = (int *)data;
    return fprintf(f, "data: %i\n", *num);
}

void* read_int(FILE*f) {
    int i;
    int r = fscanf(f, "data: %i\n", &i);
    if (r < 1) {
        return NULL;
        printf("Error reading data\n");
    }
    int *p = (int *)malloc(sizeof(int));
    *p = i;
    return (void *)p;
}

void copy_int(const void *src, void *dst) {
    const int *isrc = (const int*)src;
    int* idst = (int*)dst;
    *idst = *isrc;
}

// Define functions for strings

void* insert_str(const void* src) {
    const char* str = (char *)src;
    char* dst = strdup(str);
    if (!dst) {
        printf("Memory allocation error\n");
        return NULL;
    }
    return (void *)dst;
}

int compare_str(const void *data1, const void* data2) {
    const char* str1 = (char *)data1;
    const char* str2 = (char *)data2;
    return strncmp(str1, str2, 128);
}

void display_str(const void *src) {
    const char *str = (char *)src;
    printf("Word: %s\n", str);
}

int write_str(const void* data, FILE* f) {
    const char* str = (char *)data;
    return fprintf(f, "data: %s\n", str);
}

void* read_str(FILE* f) {
    char* buffer = (char *)malloc(sizeof(char) * 256);
    if (!buffer) {
        printf("Memory allocation error\n");
        return NULL;
    }
    int r = fscanf(f, "data: %s\n", buffer);
    if (r < 1) {
        free(buffer);
        return NULL;
    }
    return (void *)buffer;
}

//Defining triage function

/*
The contents of the array are sorted in ascending order according to  a
comparison  function pointed to by glist, by generic_tri.
*/
void generic_tri(void *glist, int nb_elem, int size_oct, cmp_fun cmp){
	char *tab=(char *)glist;
	char *tmp=(char *)malloc(sizeof(char)*size_oct);
	if(!tmp){
		printf("Memory allocation eror\n");
		return ;
	}
	for(int i=nb_elem; i>1; i--){
		for(int j=0; j<i-1; j++){
			if((*cmp)(tab+(j+1)*size_oct,tab+j*size_oct)<1){
				memcpy(tmp,tab+j*size_oct,size_oct);
				memcpy(tab+j*size_oct,tab+(j+1)*size_oct,size_oct);
				memcpy(tab+(j+1)*size_oct,tmp,size_oct);
			}
		}
	}
	free(tmp);
}
//Our comparison function
int equals_int(const void *e1, const void *e2){
		const int *a1=(int *)e1;
		const int *a2=(int *)e2;
		return (*a1>*a2)-(*a2>*a1);
}
