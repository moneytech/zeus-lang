#ifndef ZeusCell_h
#define ZeusCell_h

#include "ZeusVariant.h"

/* Immutable linked list */
struct ZeusCell {
  struct ZeusVariant data;
  struct ZeusCell * cell;
};





#endif
