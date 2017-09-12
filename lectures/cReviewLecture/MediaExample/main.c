#include <stdio.h>
#include <stdlib.h>

#include "media.h"

/* These print statements should be in their own Media files 
 * For demonstration purposes only they exist here in the main file.
 * /

/**
 * Prints integer data, does the same things as printIntType
 * but shows the steps for casting
 * @param data [description]
 */
void printIntSteps( void * data )
{
    // Cast void pointer to integer pointer
    int* intPtr = (int*)data;
    //Dereference the value
    int value = *intPtr;
    printf( "INTDATA %d\n", value );
}


void printIntType( void * data)
{
    // Same as printIntSteps but in 1 step
    printf( "INT MEDIA DATA %d\n", *((int*)data) );
}

void printDoubleType( void * data  )
{
    printf( "DOUBLE MEDIA DATA %f\n", *((double*) data ) );
}

int main( int argc, char ** argv )
{
    // Lets create a library (array) of media 
    Media* myLibrary;
    myLibrary = (Media*)malloc(sizeof(Media)*10);

    // Lets Create two types of contrived media and insert the media into the library
    // Pretending that integer is a media type
    // See void can be anything so we have to be careful
    int val = 7;
    int * myPtr = &val;
    setMedia( &myLibrary[0], myPtr );

    // Another unrealistic type of media.
    // Pointer to type double
    double* dptr = malloc(sizeof(double));
    *dptr = 123.321;
    setMedia( &myLibrary[1], dptr);

    // What about getting our information back.

    // Printing using different function pointers
    printMedia( getMedia(&myLibrary[0]), printIntSteps);
    printMedia( getMedia(&myLibrary[0]), printIntType);
    printMedia( getMedia(&myLibrary[1]), printDoubleType);

    free(myLibrary);
    free(dptr);

    return 0;
}