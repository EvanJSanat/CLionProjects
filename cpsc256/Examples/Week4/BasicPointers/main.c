/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 1, 2021, 1:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Prototypes of functions that we will use
 */
#include "functions.h"

int main(int argc, char** argv) {
    
    /* Example 1:  Basic pointer concepts
     * 
     * The ability to access and manipulate the actual memory locations in C
     * is what makes it (a) fast, and (b) powerful.  The way that we do that is
     * by using pointers - a variable which "points" to the actual location in 
     * memory! 
     */
    
    int x = 10, y = 20;
    printf("x = %d, y = %d\n",x,y);
    
    /*
     * In C, arguments of functions are just numbers or letters - they are just
     * VALUES that get sent to the function. 
     * 
     * The notation, &x , means "the hexadecinal numerical value 
     * of the MEMORY LOCATION where the variable x is stored" 
     * 
     * - this is called a pointer in C.  
     * 
     * So, in the function call below, we are
     * not passing the values stored in x and y, but rather the actual memory 
     * locations of x and y
     * 
     * Let's begin by printing out these memory locations (using the %p 
     * formatting code).
     */
    
    printf("location of x = %p, location of y = %p\n",&x,&y);
    
    /* Define two new variables, which are pointers - they hold memory
     * locations.  Set their initial values to the memory locations
     * corresponding to x and y, from above.
     * 
     * Then, call a function which takes the values of these POINTERS 
     * as arguments 
     */
    
    int* px = &x;
    int* py = &y;
  
    swap(px, py); /* the purpose of this function is to swap the values x, y */
    
    printf("x = %d, y = %d\n",x,y);
    
    /* Example 2: Another simple example to reinforce the concepts */
    
    int i = 7; /* define an integer variable at set it equal to 7 */
    int* p = &i; /* define an integer pointer variable, and set it equal to
                  * the location of the integer variable, i */
    int val = *p; /* define an integer variable and set it equal to the value
                   * that is stored at the memory location, p, which is a
                   * pointer to the memory location of the integer variable, i */
    
    printf("i = %d, p = %p, val = %d\n",i,p,val);
    
    i = 8;
    
    printf("i = %d, p = %p, val = %d\n",i,p,val);
    
    /* 
     * Example 3:  Character Arrays a.k.a. strings in C
     * 
     * And now, some examples with arrays!!!! 
     * 
     * The usage of pointers with arrays is where C really shines :)
     * 
     * Remember - "strings" in C are just arrays of characters ...
     * 
     */
    
    char a[] = "The quick brown fox";
    char b[] = "jumped over the lazy dog.";
    
    /* Define two pointers, which point to the first character of each string */
    char* pa = &a[0];
    char* pb = &b[0];
    
    printf ("%s %s\n",a,b); /* The original strings ... %s makes sense */
    printf ("%p %p\n",pa,pb); /* Pointers to the first character ... %p makes sense */
    printf ("%c %c\n",*pa,*pb); /* The value stored at the first character location ... %c makes sense  */
    
    /* Example 4: Let's pass a string to a function! */
    
    int n = 8;
    
    printf("The address of a[0] is %p.\n",&a[0]);
    
    /* Method 1: a function which makes a local copy */
    char myChar1 = getChar(a,n); /* this function should return the n-th character of the string
                                 * Note that when we pass the STRING itself, we are passing an
                                 * array ... in reality, we are passing a pointer to the first
                                 * element in that array!!! */
    
    /* Method 2: a function which uses pointers */
    char myChar2 = getCharPointer(a,n); /* this function should return the n-th character of the string
                                 * Note that when we pass the STRING itself, we are passing an
                                 * array ... in reality, we are passing a pointer to the first
                                 * element in that array!!! */
    
    printf("The %d-th character of '%s' is %c.\n",n,a,myChar1);
    printf("The %d-th character of '%s' is %c.\n",n,a,myChar2);
    
    /* Example 5:  Let's CHANGE the string in some way within a function
     * 
     * This REQUIRES that we use pointers, because we actually want to change
     * the value of a location in memory, and not just a copy that is passed
     * to the function!
     * 
     */
    printf("The original string is '%s'.\n",a);
    changeChar(a,n,'X'); /* This function should change the n-th character of the string to the specified character */
    printf("The new string is      '%s'.\n",a);
    
    /* Example 6:  Now let's work with an array of doubles */
    
    double xd[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    
    int length = sizeof(xd)/sizeof(double); /* get the number of elements */
    
    printf("%d\n",length);
    
    /* print out the original array */
    for (int i = 0; i<length;i++) {
        printf("%g ",xd[i]);
    }
    printf("\n");
    
    /* 
     * call the function to swap elements 3 and 4 ... note that 
     * we pass the array as the first argument ... but the first
     * argument of the function is a POINTER to this array, so within
     * the function we can change the actual array in memory 
     */
    
    swapNumber(xd,3,4);
    
    
    /* print out the new array */
    for (int i = 0; i<length;i++) {
        printf("%g ",xd[i]);
    }
    printf("\n");
    
    
    swapNumberCopy(xd,1,2);
    
    for (int i=0; i<length; i++){
        printf("%g ",xd[i]);
    }
    printf("\n");
    
    
            
    return (EXIT_SUCCESS);

}


