#ifndef ZeusVariant_h
#define ZeusVariant_h

/*@
  Zeus variants are immutable structures used as variables
    - They are tagged unions so a type is provided at instantiation time
    - They are garbage collected when their reference count reaches 0
    - Their reference is incremented and decremented
@*/
enum ZeusVariantType { FUNCTION, NUMBER, STRING, CELL, ARRAY };
union ZeusVariantValue {
  ZeusFunction f;
  ZeusNumber n;
  ZeusString s;
  ZeusCell c;
  ZeusArray a;
};
struct ZeusVariant
  union ZeusVariantValue value;
  enum ZeusVariantType tag;
  bool instantiated;

};

// Returns the created variant
ZeusVariant * ZeusVariant_instantiate ( ZeusVariant * variant, ZeusGarbageCollector * gc, ZeusVariantType type, ZeusVariantValue value );
// Returns the variants value returned from the garbage collector, should be 0
ZeusVariant * ZeusVariant_collect ( ZeusVariant * variant );
// Returns the result of evaluating the given variant, as a variant
ZeusVariant * ZeusVariant_eval ( ZeusVariant * variant );
// Returns a variant which is a duplicate of some other variant,
ZeusVariant * ZeusVariant_copy ( ZeusVariant * variant );
// Returns the new reference count as a ZeusNumber
void ZeusVariant_reference ( ZeusVariant * variant );
// Returns the new reference count
void ZeusVariant_dereference ( ZeusVariant * variant );

// TODO: Add casts...

#endif
