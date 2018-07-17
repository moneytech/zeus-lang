#include "ZeusPlatform.h"
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

ZeusPlatform * ZeusPlatform_create() {
  ZeusPlatform * platform = malloc(sizeof(struct ZeusPlatform));
  ZeusPlatform_setName(platform);
  ZeusPlatform_setLineEnding(platform);
  ZeusPlatform_setPathSeparator(platform);
  ZeusPlatform_setPathDelimiter(platform);
  ZeusPlatform_setEndianness(platform);
  return platform;
}

void ZeusPlatform_free( ZeusPlatform * platform ) {
  if(platform) {
    if(platform->line_ending)
      free(platform->line_ending);
    if(platform->name)
      free(platform->name);
    free(platform);
  }
}

void ZeusPlatform_setName( ZeusPlatform * platform ) {
  #if defined(__linux__)
    platform->name = malloc(5*sizeof(char));
    strcpy(platform->name, 'linux');

  #elif defined(__APPLE__) && defined(__MACH__)
    platform->name = malloc(5*sizeof(char));
    strcpy(platform->name, 'apple');

  #elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
    platform->name = malloc(7*sizeof(char));
    strcpy(platform->name, 'windows');
  #endif
}

void ZeusPlatform_setLineEnding( ZeusPlatform * platform ) {
  #if defined(__linux__)
    platform->line_ending = malloc(1*sizeof(char));
    strcpy(platform->line_ending, 0x0A);

  #elif defined(__APPLE__) && defined(__MACH__)
    platform->line_ending = malloc(1*sizeof(char));
    strcpy(platform->line_ending, 0x0A);

  #elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
    platform->line_ending = malloc(2*sizeof(char));
    strcpy(platform->line_ending, 0x0D0A);
  #endif
}


void ZeusPlatform_setPathSeparator( ZeusPlatform * platform ) {
  #if defined(__linux__)
    platform->path_separator = '/';

  #elif defined(__APPLE__) && defined(__MACH__)
    platform->path_separator = '/';

  #elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
    platform->path_separator = '\\';
  #endif
}

void ZeusPlatform_setPathDelimiter( ZeusPlatform * platform ) {
  #if defined(__linux__)
    platform->path_delimiter = ':';

  #elif defined(__APPLE__) && defined(__MACH__)
    platform->path_delimiter = ':';

  #elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
    platform->path_delimiter = ';';
  #endif
}

void ZeusPlatform_setEndianness( ZeusPlatform * platform ) {
  volatile uint32_t i=0x01234567;
  unsigned char endianness = (*((uint8_t*)(&i)));
  switch(endianness) {
    case 0x01: platform->endianness = Endianness::LITTLE; break
    case 0x23:
    case 0x45: platform->endianness = Endianness::MIXED; break
    case 0x67: platform->endianness = Endianness::BIG; break
    default: platform->endianness = Endianness::UNKNOWN;
  }
}
