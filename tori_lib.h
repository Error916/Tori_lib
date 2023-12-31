#ifndef TORI_LIB_H_
#define TORI_LIB_H_

#include <stdio.h>

#define STMNT(S) do{ S }while(0)

#define CRASH() (*(int*)0 = 0)

#define UNUSED(x) (void)(x)

#define STRINGFY_(S) #S
#define STRINGFY(S) STRINGFY_(S)

#define GLUE_(A, B) A##B
#define GLUE(A, B) GLUE_(A, B)

#define ASSERTBREAK(message) \
	STMNT( \
        	fprintf(stderr, "%s:%d: VIOLETED ASSERTION: %s\n", \
			__FILE__, __LINE__, message); \
        	CRASH(); \
    	)

#define ASSERT(c) STMNT( if (!(c)){ASSERTBREAK(STRINGFY(c));})

#define UNIMPLEMENTED(message) \
	STMNT( \
        	fprintf(stderr, "%s:%d: UNIMPLEMENTED: %s\n", \
			__FILE__, __LINE__, message); \
        	CRASH(); \
	)

#define UNREACHABLE(message) \
	STMNT( \
        	fprintf(stderr, "%s:%d: UNREACHABLE: %s\n", \
			__FILE__, __LINE__, message); \
        	CRASH(); \
	)

#define ARRAYCOUNT(a) (sizeof(a) / sizeof(*(a)))

#define INTFROMPTR(p) (unsigned long long)((char*)p - (char*)0)
#define PTRFROMINT(n) (void*)((char*)0 + (n))

#define MEMBER(T, m) (((T*) 0)->m)
#define OFFSETOFMEMBER(T, m) INTFROMPTR(&MEMBER(T, m))

#define IMPLIES(x, y) (!(x) || (y))

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)
#define PI                  3.14159265
#define RAD2DEG(x)          ((x)/PI*180)
#define DEG2RAD(x)          ((x)*PI/180)
#define ABS(x) (((x) <  0) ? -(x) : (x))
#define DIFF(a,b) ABS((a)-(b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define CLAMP(a, x, b) (((x) < (a)) ? (a) : \
			((b) < (x)) ? (b) : (x))
#define CLAMPTOP(a, b) MIN(a, b)
#define CLAMPBOT(a, b) MAX(a, b)

#define BIT(x)          (1<<(x))
#define SETBIT(x,p)     ((x)|(1<<(p)))
#define CLEARBIT(x,p)   ((x)&(~(1<<(p))))
#define GETBIT(x,p)     (((x)>>(p))&1)
#define TOGGLEBIT(x,p)  ((x)^(1<<(p)))

#define global   static
#define local    static
#define function static

#include <string.h>

#define MEMORYZERO(p, z) memset((p), 0, (z))
#define MEMORYZEROSTRUCT(p) MEMORYZERO((p), sizeof(*(p)))
#define MEMORYZEROARRAY(p) MEMORYZERO((p), sizeof(p))
#define MEMORYZEROTYPED(p, c) MEMORYZERO((p), sizeof(*(p))*(c))

#define MEMORYMATCH(a, b, z) (memcmp((a), (b), (z)) == 0)

#define MEMORYCOPY(d, s, z) memmove((d), (s), (z))
#define MEMORYCOPYSTRUCT(d, s) MEMORYCOPY((d), (s), \
					MIN(sizeof(*(d)), sizeof(*(s))))
#define MEMORYCOPYARRAY(d, s) MEMORYCOPY((d), (s), MIN(sizeof(d), sizeof(s)))
#define MEMORYCOPYTYPED(d, s, c) MEMORYCOPY((d), (s), \
					MIN(sizeof(*(d)), sizeof(*(s))*(c)))

#endif
