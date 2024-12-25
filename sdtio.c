// FILE:		stdio.c
// COPYRIGHT:	2001, Broadsword Interactive Ltd.
// DATE:		

// ----
// COMMENT:		Provide some of the functionality normally delivered by a stdio library.

#include	"stdio.h"

/*
// ----
// Returns the length of a NULL terminated string array.
UHWORD strlen(const char *string)
{
	UHWORD	ret;

	ret = 0;
	while (*string)
	{
		ret++;
		string++;
	}

	return ret;
}
*/