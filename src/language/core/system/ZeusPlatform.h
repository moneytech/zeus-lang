#ifndef ZeusPlatform_h
#define ZeusPlatform_h

#include <stdint.h>

enum Endianness { BIG, LITTLE, MIXED };
struct ZeusPlatform {
  enum Endianness endianness;
  char path_separator;
  char path_delimiter;
  char * line_ending;
  char * name;
};

struct ZeusPlatform * ZeusPlatform_create();
void ZeusPlatform_free( struct ZeusPlatform * platform );
void ZeusPlatform_setName( struct ZeusPlatform * platform );
void ZeusPlatform_setEndianness( struct ZeusPlatform * platform );
void ZeusPlatform_setPathSeparator( struct ZeusPlatform * platform );
void ZeusPlatform_setLineEnding( struct ZeusPlatform * platform );


#endif
