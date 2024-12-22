#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    PList list = (PList)malloc(sizeof(PList4));
    PList list2 = (PList)malloc(sizeof(PList4));
//Function referencing
    list->elem = NULL;
    list2->elem = NULL;
    list->duplicate = insert_str;    
    list->compare = compare_str;      
    list->display = display_str;      
    list->destroy = destroy;          
    list->write = write_str;          
    list->read = read_str;        
    list2->duplicate = insert_str;    
    list2->compare = compare_str;      
    list2->display = display_str;    
    list2->destroy = destroy;       
    list2->write = write_str;         
    list2->read = read_str;     
//Testing our functions  
    insert_at_beginning(list,"Albero");
    insert_at_beginning(list,"Adriano");
    insert_at_beginning(list,"Casa");
    insert_at_beginning(list,"Macchina");
    insert_at_beginning(list,"Moto");
    insert_at_beginning(list,"Giochi");
    insert_at_beginning(list,"Castello");
    insert_at_beginning(list,"Aereo");
    write_list(list, "chaines.txt");     
    read_list(list2, "chaines.txt");    
    display_list(list2);                
    destroy_list(list);                  
    destroy_list(list2);                
    return 0;
}
