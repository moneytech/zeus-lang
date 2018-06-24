#include "ZeusAtom.h"


ZeusAtom * ZeusAtom_create ( ZeusAtomType tag, ZeusAtomValue value ) {
  struct ZeusAtom * atom = malloc(sizeof(struct ZeusAtom));
  atom->tag = tag;
  atom->value = value;
  atom->marked = 0;
  return atom;
}

void ZeusAtom_collect ( ZeusAtom * atom ) {
  if(!atom) return;
  if(atom->marked) {
    if(isCell(atom)) ZeusCell_collect(atom));
    if(isArray(atom)) ZeusArray_collect(atom));

    free(atom);
  }
}

void ZeusAtom_mark ( ZeusAtom * atom ) {
  if(!atom) return;
  if (atom->marked) return;
  atom->marked = 1;

  if(isCell(atom))  ZeusCell_mark(atom->value);
  if(isArray(atom)) ZeusArray_mark(atom->value);
}

ZeusAtom * ZeusAtom_eval ( ZeusAtom * atom ) {
  if(!atom) return 0;
  if(isFunction(atom))  return ZeusFunction_call( ZeusAtom_toFunction(atom) );
  if(isNumber(atom))    return ZeusAtom_toNumber(atom)->value;
  if(isString(atom))    return ZeusAtom_toString(atom)->value;
  if(isCell(atom))      return ZeusAtom_toCell(atom);
  if(isArray(atom))     return ZeusAtom_toArray(atom);
}

ZeusAtom * ZeusAtom_copy ( ZeusAtom * atom ) {
  if(!atom) return 0;
  struct ZeusAtom * copy = ZeusAtom_create( atom->tag, atom->value);
  return copy
}
