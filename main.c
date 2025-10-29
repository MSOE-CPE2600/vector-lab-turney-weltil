/* FileName: main.c
 * Author: Larissa Welti
 * Date: 10.7.2025
 * Description: Does basic vector math like addition, subtraction, and scalar multiplication
 * can store vectors to do math with
 * To Compile: gcc -o compile main.c vector_math.c
*/

#include <stdio.h>
#include "vector_math.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int capacity = 1;
    vector* listed = malloc(capacity * sizeof(vector));
    char user_input[80];
    char *token;
    char* tokens[5];
    bool cont = true;
    int num_vectors = 0;
    while(cont){ //while quit has not been entered
        printf("\nminimat>");
        fgets(user_input, 50, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        token = strtok(user_input, " ");
        int i = 0;
        while(token != NULL){   //collect user input and store it
            tokens[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        
        printf("\n");

        if(strcmp(tokens[0], "quit") == 0){ //are we ending the program?
            cont = quit();
        }else if(strcmp(tokens[0], "") == 0){   //did they forget to enter anything?
            printf("Please enter a command or '-h' for the list of commands\n");
        } else{
            if(strcmp(tokens[0], "clear") == 0){    //clear the saved vectors?
                capacity = 1;
                listed = realloc(listed, sizeof(vector));
                num_vectors = 0;
            }
            else if(strcmp(tokens[0], "list") == 0){    //list the saved vectors?
                list(listed, num_vectors);
            } 
            else if(strcmp(tokens[0], "-h") == 0){  //display the commands?
                help();
            }
            else if(strcmp(tokens[0], "load") == 0){    //load a file?
                int result = load(tokens[1], &listed, num_vectors, capacity);
                if(result == -1){
                    printf("Error loading the file\n");
                } else{
                    num_vectors = result;
                    capacity = result;
                }
                    
            }
             else if(strcmp(tokens[0], "save") == 0){
                if(save(tokens[1], listed, num_vectors) == 1){
                    printf("Error saving to the file\n");
                }
            }
            else if(strcmp(tokens[1], "=") == 0){       //storing a vector?
                bool new_vector = false;
                if(num_vectors >= capacity){        //is there more space?
                    printf("Making space for more vectors\n");
                    listed = realloc(listed, 2* capacity * sizeof(vector));     //no? make more space
                    capacity *= 2;
                } 
                if(isdigit(tokens[2][0]) != 0 &&
                         isdigit(tokens[3][0]) != 0 && isdigit(tokens[4][0]) != 0){//if setting a vector to a value
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = save_vector(
                        tokens[0], atof(tokens[2]), atof(tokens[3]), atof(tokens[4]));
                    if(index == num_vectors || num_vectors == 0){   //check if new or updating an old vector
                        new_vector = true;
                    }
                 
                } else if(strcmp(tokens[3], "+")== 0){  //adding two vectors and saving
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = add(get_vector(listed, num_vectors, tokens[2]),
                                         get_vector(listed, num_vectors, tokens[4]));
                    strcpy(listed[index].name, tokens[0]);
                    print_vector(listed[index]);
                    if(index == num_vectors || num_vectors == 0){//check if new or updating an old vector
                        new_vector = true;
                    }
                } else if(strcmp(tokens[3], "-")== 0){  // subtracting two vectors and saving
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = sub(get_vector(listed, num_vectors, tokens[2]),
                                         get_vector(listed, num_vectors, tokens[4]));
                    strcpy(listed[index].name, tokens[0]);
                    print_vector(listed[index]);
                    if(index == num_vectors || num_vectors == 0){//check if new or updating an old vector
                        new_vector = true;
                    }
                }  else if(strcmp(tokens[3], "x")== 0){ //cross product of the vectors and saving
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = cross(get_vector(listed, num_vectors, tokens[2]),
                                          get_vector(listed, num_vectors, tokens[4]));
                    strcpy(listed[index].name, tokens[0]);
                    print_vector(listed[index]);
                    if(index == num_vectors || num_vectors == 0){//check if new or updating an old vector
                        new_vector = true;
                    }
                }  else if(strcmp(tokens[3], "*")== 0 && isdigit(tokens[2][0]) != 0){ //scalar multiple of an existing vector and saving
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = scalar(atof(tokens[2]), get_vector(listed, num_vectors, tokens[4]));
                    strcpy(listed[index].name, tokens[0]);
                    print_vector(listed[index]);
                    if(index == num_vectors || num_vectors == 0){//check if new or updating an old vector
                        new_vector = true;
                    }
                }  else if(strcmp(tokens[3], "*")== 0 && isdigit(tokens[4][0]) != 0){//scalar multiple of an existing vector and saving
                    int index = check_duplicate(listed, num_vectors, tokens[0]);
                    listed[index] = scalar(atof(tokens[4]), get_vector(listed, num_vectors, tokens[2]));
                    strcpy(listed[index].name, tokens[0]);
                    print_vector(listed[index]);
                    if(index == num_vectors || num_vectors == 0){//check if new or updating an old vector
                        new_vector = true;
                    }
                }
                if (new_vector){
                    num_vectors = num_vectors +1;
                }
            } else if(strcmp(tokens[1], "+") == 0){     //add two vectors and display
                vector result = add(get_vector(listed, num_vectors, tokens[0]),
                                     get_vector(listed, num_vectors, tokens[2]));
                strcpy(result.name, "ans");
                print_vector(result);
            } else if(strcmp(tokens[1], "-") == 0){     //subtract two vectors and display
                vector result = sub(get_vector(listed, num_vectors, tokens[0]),
                                     get_vector(listed, num_vectors, tokens[2]));
                strcpy(result.name, "ans");   
                print_vector(result);
            } else if(strcmp(tokens[1], "x") == 0){     //cross product of two vectors and display
                vector result = cross(get_vector(listed, num_vectors, tokens[0]),
                                      get_vector(listed, num_vectors, tokens[2]));
                strcpy(result.name, "ans");
                print_vector(result);
            } else if(strcmp(tokens[1], "*") == 0 &&    //dot product of two vectors and display result
                         isdigit(tokens[0][0]) == 0 && isdigit(tokens[2][0]) == 0){
                printf("%f\n",dot(get_vector(listed, num_vectors, tokens[0]),
                                  get_vector(listed, num_vectors, tokens[2])));
            } else if(strcmp(tokens[1], "*") == 0 && isdigit(tokens[0][0]) != 0){   //scalar multiple of a vector and display
                vector result = scalar(atof(tokens[0]), get_vector(listed, num_vectors, tokens[2]));
                strcpy(result.name, "ans");
                print_vector(result);
            } else if(strcmp(tokens[1], "*") == 0 && isdigit(tokens[2][0]) != 0){   //scalar multiple of a vector and display
                vector result = scalar(atof(tokens[2]), get_vector(listed, num_vectors, tokens[0]));
                strcpy(result.name, "ans");
                print_vector(result);
            } else if(check_duplicate(listed, num_vectors, tokens[0]) < num_vectors){   //display entered vector
                print_vector(get_vector(listed, num_vectors, tokens[0]));
            } else{ //if none of the above print an error
                printf("Error with the input, try -h for options\n");
            }
        }
    } 
       
    free(listed);
    return 0;
}


