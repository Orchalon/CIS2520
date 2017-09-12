#ifndef MEDIA_H
#define MEDIA_H



/**
 * A structure to store media
 */
typedef struct media
{
    void * data;

} Media;

/**
 * Set data for a media type
 * @param media Media Storage
 * @param data  to be inserted
 */
void setMedia( Media * media, void * data );

/**
 * Retrieve the data from the media.
 * @param media [description]
 */
void* getMedia( Media * media );

typedef void (*PrintMediaType)(void*);
void printMedia( Media* media, PrintMediaType print);

#endif
