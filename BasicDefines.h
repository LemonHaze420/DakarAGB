// FILE:		BasicDefines.h
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// ----
// COMMENT:		Define common values here.

#ifndef _BASICDEFINES_H_
#define _BASICDEFINES_H_

#define	TRUE	1
#define	FALSE	0

#define	NULL	(0)

// Fixed point stuff.
#define IntToFP16(a)	((a) << 8)
#define FP16ToInt(a)	((a) >> 8)
#define	FP16Mul(a, b)	(((a) * (b)) >> 8)
#define	FP16Div(a, b)	((a << 8) / (b))

#define IntToFP32(a)	((a) << 16)
#define FP32ToInt(a)	((a) >> 16)
#define	FP32Mul(a, b)	((a) * (b) >> 16)
#define	FP32Div(a, b)	((a << 16) / (b))


#endif
