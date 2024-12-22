#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    PList list = (PList)malloc(sizeof(PList4));
    PList list2 = (PList)malloc(sizeof(PList4));
//Function referencing
    list->elem = NULL;
    list->duplicate = insert_int; 
    list->compare = compare_int;   
    list->display = display_int;   
    list->destroy = destroy;        
    list->write = write_int;       
    list->read = read_int;          
    list->copy = copy_int;          
    list2->elem = NULL;
    list2->duplicate = insert_int;  
    list2->compare = compare_int;   
    list2->display = display_int;    
    list2->destroy = destroy;         
    list2->write = write_int;        
    list2->read = read_int;           
    list2->copy = copy_int;          
//Testing our functions
    for (int i = 0; i < 20; i++) {
        int j = rand() % (20);
        insert_at_beginning(list, &j);
    }
    write_list(list, "tmp.txt"); 
    printf("Content of tmp.txt: \n");     
    read_list(list2, "tmp.txt");      
    display_list(list2);             
    destroy_list(list);               
    destroy_list(list2);            

    return 0;
}
