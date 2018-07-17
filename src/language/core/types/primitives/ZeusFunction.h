#ifndef ZeusFunction_h
#define ZeusFunction_h

#include <stdio.h>
#include <stdlib.h>

struct ZeusAtom;

struct ZeusEnvironment {
  struct ZeusAtom * var;
};

typedef void (*ZeusCallback)(struct ZeusEnvironment*);
struct ZeusClosure {
  ZeusCallback call;
  struct ZeusEnvironment * environment;
};

typedef struct ZeusClosure ZeusFunction;

struct ZeusClosure * ZeusClosure_create( struct ZeusAtom * atom );




// struct ZeusClosure * ZeusClosure_example( struct ZeusAtom * atom, ZeusCallback * call ) {
//   struct ZeusEnvironment * environment = malloc( sizeof struct ZeusEnvironment );
//   environment->var = atom;
//   struct ZeusClosure * closure = malloc( sizeof struct * ZeusClosure);
//   closure->environment = environment;
//   closure->call = call;
//   return closure;
// }
//
//
// void ZeusClosure_exampleBlock( struct ZeusEnvironment * environment ) {
//   environment->var += 1;
// }
//
// void Test_ZeusClosure_example() {
//   struct ZeusClosure * c = ZeusClosure_example(5, ZeusClosure_exampleBlock);
//   printf("Closure: var = 5");
//   c->call(c->env);
//   printf("Block: var = %d", c->environment->var);
//   c->call(c->env);
//   printf("Block: var = %d", c->environment->var);
// };

// TODO fix memory leaks in test cases



#endif
