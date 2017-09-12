#include <stdio.h>
#include <stdlib.h>

#include "media.h"
//#include "book.h"

typedef int* IntPtr;

/**
 * printBook is the name of function
 * Book* is the parameter
 */
typedef void (*PrintIntFunc)(int*);

void printInt( int* i )
{
	printf("%d\n", *i);
}

void printInt2( int* i2 )
{
	printf("%d %d\n", *i2, *i2 );
}

int main( int argc, char ** argv )
{
	int val = 7;
	int * myPtr = &val;
	
	// This is an ugly function pointer, name intFunc
	void (*intFunc)(int*);

	// Set the pointer to the address of printInt2 function
	intFunc = &printInt2;

	// Calling the function pointer
	intFunc(myPtr);

	printf("END FIRST SECTION\n\n");
	
	PrintIntFunc p;
	p = &printInt;
	PrintIntFunc p2;
	p2 = &printInt2;

	p(myPtr);
	p2(myPtr);

	printf("END Second SECTION\n\n");

	return 0;
}

/*
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

	// With our new typedef
	printf( "3) The first value in the library is %d\n", *( (IntPtr)mediaData ) );

	// Printing our double
	mediaData = getMedia( &myLibrary[1] );
	printf( "The second value in the library is %f\n", *( (double*) mediaData ) );
	return 0;
}
*/