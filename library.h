#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Element *PElement;

typedef struct Element{
	void* data;
	PElement next;
} element;

typedef struct PList_ *PList;
typedef struct PList_{
	PElement elem;
	void* (*duplicate)(const void *);
	void (*copy)(const void*, void*);
	void (*destroy)(void*);
	void (*display)(const void*);
	int (*compare)(const void*, const void*);
	void* (*read)(FILE*);
	int (*write)(const void*, FILE*);
} PList4;
// Generic functions

void insert_at_beginning(PList list, void * data);
PElement search_list(PList list, void* data);
void display_list(PList list);
void destroy_list(PList list);
int write_list(PList list, const char* filename);
int read_list(PList list, const char* filename);
void destroy(void *data);
void insert_at_end(PList list, void * data);

// Integer functions

int compare_int(const void *data1, const void* data2);
void* insert_int(const void* src);
void display_int(const void *src);
int write_int(const void* data, FILE*f); 
void* read_int(FILE*f);
void copy_int(const void *src, void *dst);
// String functions

void* insert_str(const void* src);
int compare_str(const void *data1, const void* data2);
void display_str(const void *src);
int write_str(const void* data, FILE*f);
void* read_str(FILE*f);
//Triage function

typedef int(*cmp_fun) (const void *a, const void *b);
void generic_tri(void *glist, int nb_elem, int size_oct, cmp_fun cmp);
int equals_int(const void *e1, const void *e2);
