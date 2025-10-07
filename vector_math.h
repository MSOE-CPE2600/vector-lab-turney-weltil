/* FileName: vector_math.h
 * Author: Larissa Welti
 * Date: 10.7.2025
 * Description: Does basic vector math like addition, subtraction, and scalar multiplication
*/
#include <stdio.h>
#include "vector.h"

vector add(vector a, vector b);
vector sub(vector a, vector b);
vector cross(vector a, vector b);
vector dot(vector a, vector b);
vector scalar(double mult, vector b);
void help();
void clear();
void quit();
vector get_vector(vector a);
void list();
void print_vector(vector a);
