#ifndef ZeusVirtualMachine_h
#define ZeusVirtualMachine_h

#include "types/primitives/ZeusAtom.h"

struct ZeusVirtualMachine {
  struct ZeusAtom * stack;
};

// void markAll(VM* vm)
// {
//   for (int i = 0; i < vm->stackSize; i++) {
//     mark(vm->stack[i]);
//   }
// }
//
// void mark(Object* object) {
//   /* If already marked, we're done. Check this first
//      to avoid recursing on cycles in the object graph. */
//   if (object->marked) return;
//
//   object->marked = 1;
//
//   if (object->type == OBJ_PAIR) {
//     mark(object->head);
//     mark(object->tail);
//   }
// }



#endif
