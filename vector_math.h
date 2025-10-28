/* FileName: vector_math.h
 * Author: Larissa Welti
 * Date: 10.7.2025
 * Description: Does basic vector math like addition, subtraction, and scalar multiplication
*/
#include <stdio.h>
#include "vector.h"
#include <stdbool.h>

vector add(vector a, vector b);
vector sub(vector a, vector b);
vector cross(vector a, vector b);
double dot(vector a, vector b);
vector scalar(double mult, vector b);
void help();
int clear(vector* listed);
bool quit();
vector get_vector(vector* listed, int num_vectors, char named[]);
void list(vector* listed, int num_vectors);
void print_vector(vector a);
vector save_vector(char* string, float x, float y, float z);
int check_duplicate(vector* listed, int num_vectors, char* named);

int load(char* filename, vector** list, int num_vectors, int capacity);
int save(char* filename, vector* list, int num_vectors);

