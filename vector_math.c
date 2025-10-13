/* FileName: vector_math.c
 * Author: Larissa Welti
 * Date: 10.7.2025
 * Description: Does basic vector math like addition, subtraction, and scalar multiplication
*/

#include <stdio.h>
#include "vector.h"
#include <stdbool.h>
#include <string.h>
vector get_vector(vector* listed, int num_vectors, char* named){        //returns the vector of a given name if it exists in the saved vector list
    vector ptr;
    for(int i = 0; i < num_vectors; i++){
        if(strcmp(listed[i].name, named) == 0){
            ptr = listed[i];
        }
    }
    return ptr;
}
void print_vector(vector a){    //prints out a vector
    printf("%s = %f %f %f\n", a.name, a.x, a.y, a.z);
}
vector add(vector a, vector b){ //adds two vectors together component by component
    vector ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    return ret;
}
vector sub(vector a, vector b){ //subtracts one vector from another
    vector ret = { .x = (a.x -b.x), .y = a.y-b.y, .z = a.z-b.z};
    return ret;
}
vector cross(vector a, vector b){   //takes the cross product of two vectors
    vector ret = { .x = a.y *b.z - a.z*b.y, .y = a.z*b.x - a.x*b.z, .z = a.x*b.y - a.y*b.x};
    return ret;
}
double dot(vector a, vector b){     //takes the dot product of two vectors
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
vector scalar(double mult, vector a){   //multiplies a vector by a scalar
    vector ret = { .x = mult*a.x, .y = mult*a.y, .z = mult*a.z};
    return ret;
}
void help(){        //prints instructions to the display
    printf("Commands to use\n"
                "a = 1 1 1 - assigns a vector some inital values, can also override old values in vector\n"
                "all comands listed below can be used with or without the 'a =' \n"
                "a = b + c - stores the value of b + c in a\n"
                "a = b - c - stores the value of b - c in a\n"
                "a = b * c - stores the value of b dot c in a\n"
                "a = b x c - stores the value of b cross c in a\n"
                "b * 2 - outputs the value of b * 2\n"
                "quit - leaves the program\n"
                "list - lists all of the sotred vectors\n"
                "clear - clears the stored vectors\n");
}
int clear(vector* listed){  //clears the list of saved vectors
    for(int i = 0; i < 10; i++){
        memset(&listed[i], 0, sizeof(listed[i]));
    }
    return 0;
}
bool quit(){    //triggers the end of the program
    printf("Thank you for using the vector calculator\n");
    return false;
}


void list(vector* listed, int num_vectors){ //lists out all saved vectors
   for(int i = 0; i < num_vectors; i++){
        print_vector(listed[i]);
    } 
}

vector save_vector(char* string, float x, float y, float z){    //adds a vector to the saved vector list
    vector new = {.x = x, .y = y, .z = z};
    strcpy(new.name, string);
    print_vector(new);
    return new;
}

int check_duplicate(vector* listed, int num_vectors, char* named){  //checks if the vector is already in the saved vector list (goes off of name)
    int i = 0;
    bool duplicate = false;
    if(num_vectors != 0){
        while(!duplicate && i < num_vectors){
        duplicate = (strcmp(listed[i].name, named) == 0);
        if(!duplicate){
           i++; 
        }
        }
    }

    return i;
}
