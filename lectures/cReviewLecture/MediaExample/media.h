#ifndef MEDIA_H
#define MEDIA_H

/**
 * A structure to store media
 */
typedef struct media
{
	void * data;

} Media;


void setMedia( Media * media, void * data );

void* getMedia( Media * media );

void voidSwap( void * data1 , void* data2 );


#endif
