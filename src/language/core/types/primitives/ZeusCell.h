#ifndef ZeusCell_h
#define ZeusCell_h

// #include "ZeusAtom.h"

struct ZeusAtom;

/* Immutable linked list with a data head and a data/cell tail */
struct ZeusCell {
  struct ZeusAtom * data;
  struct ZeusCell * cell;
  int marked;
};

// Returns a created cell from data and some other cell
struct ZeusCell * ZeusCell_create ( struct ZeusAtom * data, struct ZeusCell * cell );
// Frees the ZeusCell, for garbage collector
void ZeusCell_collect ( struct ZeusCell * cell );
// Recursively marks the cell for collection
void ZeusCell_mark ( struct ZeusCell * cell );
// Returns a duplicate of the cell
struct ZeusCell * ZeusCell_copy ( struct ZeusCell * cell );
// Returns a new cell with the data value different, but the same tail cell
void ZeusCell_swapValue ( struct ZeusCell * cell, struct ZeusAtom * data );

void ZeusCell_head ( struct ZeusCell * cell );

void ZeusCell_tail ( struct ZeusCell * cell );




#endif
