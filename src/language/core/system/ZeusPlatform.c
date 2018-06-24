#include "ZeusPlatform.h"
#include <stdlib.h>
#include <limits.h>

ZeusPlatform * ZeusPlatform_create() {
  ZeusPlatform * platform = malloc(sizeof(struct ZeusPlatform));
  ZeusPlatform_setName(platform);
  ZeusPlatform_setWordSize(platform);
  ZeusPlatform_setEndianness(platform);
  ZeusPlatform_setPathSeparator(platform);
  ZeusPlatform_setLineEnding(platform);
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

void ZeusPlatform_setEndianness( ZeusPlatform * platform ) {
  byte    swaptest[2] = {1,0};
  if ( *(short *)swaptest == 1) {
      bigendien = false;

  switch(e.c[0]) {
  case 0x01: BIG
  case 0x02: MIX
  default: LITTLE
}

void ZeusPlatform_setEndianness( ZeusPlatform * platform ) {

}

void ZeusPlatform_setEndianness( ZeusPlatform * platform ) {

}
