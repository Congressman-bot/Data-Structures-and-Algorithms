/*
$ Program to demonstrate the implementation of Array operations
$ in C (Data Structures)
$ Written by Alex Mwangi
$ BSE 2.1 DSA class
*/
#include <stdio.h>

int main()
{
    // Declaration and initialization of the array
    int array[5] = {10, 20, 30, 40, 50};
    int size = 5;
    for(int i = 0; i < 5; i++){ // Displaying the array
        printf(" Element [%d]: %d", i, array[i]);
    }
    printf("\n");
    
    // Declaration of the new element;
    int newElement = 25;
    
    // Insertion of an element in index 2
    if(size < 6){
        for(int i = size; i > 2; i--){
            array[i] = array[i - 1];
        }
        array[2] = newElement;
        size++;
    }
    
    // Displaying array after addition of new element and index
    for(int i = 0; i < size; i++){
        printf(" Element [%d]: %d", i, array[i]);
    }
    printf("\n");
    
    // Deleting index 3
    int deleteIndex = 3;
    if(deleteIndex < size){
        for(int i = deleteIndex; i < size - 1; i++){
            array[i] = array[i + 1];
        }
    }
    
    // Displaying the new array
    for(int i = 0; i < 5; i++){
        printf(" Element [%d]: %d", i, array[i]);
    }
    printf("\n");
    
    return 0;
}
