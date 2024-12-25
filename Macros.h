// FILE:		Macros.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:

// COMMENT:		Basic macros to make our lives easier.

#ifndef	_MACROS_H_
	#define	_MACROS_H_

	// Macros that are not for final release builds
	#ifndef FINAL_BUILD

		#define	ERROR_PATH_TRAP(msg)	Debug_NoSuchChoice(__FILE__, __LINE__, msg);

		// ----
		// Output debug strings
		#ifndef ODS
			#define	ODS	(0);
		#endif

		// ----
		// Output a debug string, automatically adding a 
		// trailing new line character.
		#ifndef ODSN
			#define	ODSN	{ODS(msg); ODS("\n");}
		#endif

	#else	// FINAL_BUILD substitutes

		// ----
		// Null 'bodied' OutputDebugString.
		#ifndef ODSN
			#define	ODSN(msg)	{}
		#endif
			
	#endif	// End 'ifndef FINAL_BUILD'

	// ----
	// Macros for all builds
	#ifndef	SAFELY_DELETE
		#define SAFELY_DELETE(addr)			{if (addr) {delete addr;}}
	#endif

	#ifndef	SAFELY_DELETE_ARRAY
		#define	SAFELY_DELETE_ARRAY(addr)	{if (addr) {delete[] addr;}}
	#endif

	#ifndef	abs
		#define	abs(a)						(((a) < 0)?(-a):(a))
	#endif

	#ifndef	min
		#define	min(a, b)					(((a) < (b))?(a):(b))
	#endif

	#ifndef	max
		#define	max(a, b)					(((a) > (b))?(a):(b))
	#endif

	#ifndef GET_BIT
		#define	GET_BIT(var, bit)		((var >> bit) & 0x01)
	#endif

	#ifndef	SET_BIT
		#define	SET_BIT(var, bit)		{var |= 1 << bit;}
	#endif

	#ifndef	CLEAR_BIT
		#define	CLEAR_BIT(var, bit)		{var = (var | (1 << bit)) ^ (1 << bit);}
	#endif

	#ifndef	TOGGLE_BIT
		#define	TOGGLE_BIT(var, bit)	{var ^= (1 << bit);}
	#endif


	#ifndef GET_BIT_AT_ADDRESS
		#define	GET_BIT_AT_ADDRESS(addr, size, bit)		(((*(size*)addr) >> bit) & 0x01)
	#endif

	#ifndef	SET_BIT_AT_ADDRESS
		#define	SET_BIT_AT_ADDRESS(addr, size, bit)		{*(size*)addr = (*(size*)addr) | (1 << bit);}
	#endif

	#ifndef	CLEAR_BIT_AT_ADDRESS
		#define	CLEAR_BIT_AT_ADDRESS(addr, size, bit)	{*(size*)addr = (((*(size*)addr) | (1 << bit)) ^ (1 << bit));}
	#endif

	#ifndef	TOGGLE_BIT_AT_ADDRESS
		#define	TOGGLE_BIT_AT_ADDRESS(addr, size, bit)	{*(size*)addr = (*(size*)addr) ^ (1 << bit);}
	#endif
		
#endif