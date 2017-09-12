// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your structs and related functions shouldn't live in the main
// This is just an example for in-class

/**
 * Stores basic book information.
 */
typedef struct book {
    double price;
    char *name;
} Book;

// Typedef for the function pointer
typedef void (*PrintBookFunc)(Book*);

/**
 * [createBook description]
 * @param  title static string of title
 * @param  price double
 * @return       a dynamically created Book.
 */
Book* createBook( char * title, double price )
{
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

/**
 * Get price of book
 * @param  b Book
 * @return   Double price
 */
double getPrice( Book * b ) 
{ 
    return b->price;
}

/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book *b )
{
	return b->name;
}

/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( Book * b ) 
{
    printf("%s : %f\n", getName(b), getPrice(b) );
}

/**
 * Print the book in another order
 * @param b [description]
 */
void printBookReverse( Book * b )
{
    printf("%f : %s\n", getPrice(b), getName(b));
}

int main(int argc, char ** argv)
{
    Book * b = createBook( "Harry Potter And The Cursed Child", 19.99);

    PrintBookFunc display = &printBook;
    display(b);

    display = &printBookReverse;
    display(b);
    
    free(b);
    return 0;
}

