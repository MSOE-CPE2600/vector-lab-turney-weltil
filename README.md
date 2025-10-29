# Description:
    Does basic vector math like addition subtraction, and scalar multiplication can store vectors to do math with

# How to Run:
    ./compile
    valgrind ./compile

# Commands:
    a = 1 1 1 - assigns a vector some inital values, can also override old values in vector

## all comands listed below can be used with or without the 'a =' 

    * a = b + c - stores the value of b + c in a
    * a = b - c - stores the value of b - c in a
    * a = b * c - stores the value of b dot c in a
    * a = b x c - stores the value of b cross c in a
    * b * 2 - outputs the value of b * 2
    * quit - leaves the program
    * list - lists all of the sotred vectors
    * clear - clears the stored vectors
    * load filename.csv - loads vectors from a valid csv file
    * save filename.csv - saves current vector list to a csv file

# To Compile:
    gcc -o compile main.c vector_math.c

# Use of Dynamic Memory
    This program uses dynamic memory to store a list of vectors to perform functions
    with. It starts with space for one vector and adds more space everytime it runs
    out. If you are manually adding vectors it doubles the capacity everytime space
    is full, or if loading from a list it adds one more spot per vector. When 
    clearing the list the memory is reallocated back to a capacity of one vector. 