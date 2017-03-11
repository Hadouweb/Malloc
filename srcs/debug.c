#include "../includes/malloc.h"

char	*debug_enum(enum e_type type) {
	switch (type) {
		case TINY:
			return "TINY";
		case SMALL:
			return "SMALL";
		case LARGE:
			return "LARGE";
		default:
			return "NULL_TYPE";
	}
}