#include <stdio.h>
#include <stdlib.h>

#include "media.h"

/****** Casting from void *********************/
void printIntType( void * data)
{
    printf( "INT MEDIA DATA %d\n", *((int*)mediaData) );
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
    // Everything is now in a void pointer

    // Now we have the ugly business of casting, lets do it in steps
    // Get the media back
    void* mediaData = getMedia( &myLibrary[0] ); 
    // Convert it to int*, we know its int* only because we put it there.
    int* tmpPtr = (int*)mediaData; 
    // Dereference (Get the value) from the pointer which is an integer.
    int value = *tmpPtr;
    printf( "1) The first value in the library is %d\n", value );

    // Or do all the casting together in an ugly mess
    printf( "2) The first value in the library is %d\n", *((int*)mediaData) );


    // Printing our double
    mediaData = getMedia( &myLibrary[1] );
    printf( "The second value in the library is %f\n", *( (double*) mediaData ) );


    // Combination of tools used 
    printMedia( getMedia(&myLibrary[0], printIntType) );
    printMedia( getMedia(&myLibrary[1], printDoubleType) );

    return 0;
}