#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BIT_NUM) 		VAR=VAR|(1<<(BIT_NUM))

#define CLR_BIT(VAR,BIT_NUM)		VAR=VAR&~(1<<(BIT_NUM))

#define TOGGLE_BIT(VAR,BIT_NUM)		VAR=VAR^(1<<(BIT_NUM))

#define GET_BIT(VAR,BIT_NUM)		(VAR>>BIT_NUM)&1

#endif