#ifndef __APE_DEFINE_H__
#define __APE_DEFINE_H__

#define APE_ABS(x) (((x) < 0) ? (-(x)) : (x))

#define APE_MIN(a, b) (((b) < (a)) ? (b) : (a))
#define APE_MAX(a, b) (((b) > (a)) ? (b) : (a))

#define APE_CLAMP(a, b, x) (((b) < (a)) ? (((x) < (b)) ? (b) : (((x) > (a)) ? (a) : (x))) : (((x) < (a)) ? (a) : (((x) > (b)) ? (b) : (x))))
// This only work if a <= b. It's recommend to use APE_CLAMP for safer.
#define APE_FAST_CLAMP(a, b, x) (((x) < (a)) ? (a) : (((x) > (b)) ? (b) : (x)))

// Call this inside a class (in public scope) with the class type to disable default copy constuction.
#define APE_NOT_COPYABLE(Type) Type(const Type&)=delete;Type(Type&&)=delete;
// Call this inside a class (in public scope) with the class type to disable default copy assignment operator '='.
#define APE_NOT_ASSIGNABLE(Type) void operator=(const Type&)=delete;void operator=(Type&&)=delete;
// Call this inside a class (in public scope) with the class type to disable both default copy constuction and default copy assignment operator '='.
#define APE_NOT_COPY_ASSIGNABLE(Type) APE_NOT_COPYABLE(Type)APE_NOT_ASSIGNABLE(Type)

#define APE_DEFINE_ENUM_OPERATORS(Type) inline Type operator~ (Type a) { return (Type)(~(unsigned long long)a); } \
    inline Type operator| (Type a, Type b) { return (Type)((unsigned long long)a | (unsigned long long)b); } \
    inline Type operator& (Type a, Type b) { return (Type)((unsigned long long)a & (unsigned long long)b); } \
    inline Type operator^ (Type a, Type b) { return (Type)((unsigned long long)a ^ (unsigned long long)b); } \
    inline Type& operator|= (Type& a, Type b) { return (Type&)((unsigned long long&)a |= (unsigned long long)b); } \
    inline Type& operator&= (Type& a, Type b) { return (Type&)((unsigned long long&)a &= (unsigned long long)b); } \
    inline Type& operator^= (Type& a, Type b) { return (Type&)((unsigned long long&)a ^= (unsigned long long)b); }


#endif // __APE_DEFINE_H__