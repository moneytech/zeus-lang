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
void ZeusPlatform_setLineEnding( struct ZeusPlatform * platform );
// System path separator
void ZeusPlatform_setPathSeparator( struct ZeusPlatform * platform );
void ZeusPlatform_setPathDelimiter( struct ZeusPlatform * platform );
void ZeusPlatform_setEndianness( struct ZeusPlatform * platform );

#define OS_NAME(X)            (X->name)
#define OS_ENDIANNESS(X)      (X->endianness)
#define OS_PATH_SEPARATOR(X)  (X->path_separator)
#define OS_PATH_DELIMITER(X)  (X->path_delimiter)
#define OS_LINE_ENDING(X)     (X->line_ending)

#endif
