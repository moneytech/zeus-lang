#ifndef ZeusAtom_h
#define ZeusAtom_h

#include "ZeusFunction.h"
#include "ZeusNumber.h"
#include "ZeusString.h"
#include "ZeusCell.h"
#include "ZeusArray.h"

/*@
  Zeus atoms are immutable structures used as variables
    - They are tagged unions so a type is provided at instantiation time
    - They are garbage collected when their reference count reaches 0
    - Their reference is incremented and decremented
@*/
enum ZeusAtomType { FUNCTION, NUMBER, STRING, CELL, ARRAY };
union ZeusAtomValue {
  struct ZeusFunction f;
  struct ZeusNumber n;
  struct ZeusString s;
  struct ZeusCell c;
  struct ZeusArray a;
};
struct ZeusAtom {
  union ZeusAtomValue value;
  enum ZeusAtomType tag;
  int marked;
};

// Returns the created atom
struct ZeusAtom * ZeusAtom_create ( enum ZeusAtomType type, union ZeusAtomValue value );
// Frees the ZeusAtom, for garbage collector
void ZeusAtom_collect ( struct ZeusAtom * atom );
// Marks the atom for collection
void ZeusAtom_mark ( struct ZeusAtom * atom );
// Returns an atom which is a duplicate of some other atom
struct ZeusAtom * ZeusAtom_copy ( struct ZeusAtom * atom );
// Returns the result of evaluating the given atom, as an atom
struct ZeusAtom * ZeusAtom_eval ( struct ZeusAtom * atom );

// Coerce a ZeusFunction from a ZeusAtom
struct ZeusFunction * ZeusAtom_toFunction ( struct ZeusAtom * atom );
// Coerce a ZeusNumber from a ZeusAtom
struct ZeusNumber * ZeusAtom_toNumber ( struct ZeusAtom * atom );
// Coerce a ZeusString from a ZeusAtom
struct ZeusString * ZeusAtom_toString ( struct ZeusAtom * atom );
// Coerce a ZeusCell from a ZeusAtom
struct ZeusCell * ZeusAtom_toCell ( struct ZeusAtom * atom );
// Coerce a ZeusArray from a ZeusAtom
struct ZeusArray * ZeusAtom_toArray ( struct ZeusAtom * atom );

#define ATOM_IS_TYPE(a, T)    (a->tag == T)
#define isFunction(a)         ATOM_IS_TYPE(a, FUNCTION)
#define isNumber(a)           ATOM_IS_TYPE(a, NUMBER)
#define isString(a)           ATOM_IS_TYPE(a, STRING)
#define isCell(a)             ATOM_IS_TYPE(a, CELL)
#define isArray(a)            ATOM_IS_TYPE(a, ARRAY)

#endif
