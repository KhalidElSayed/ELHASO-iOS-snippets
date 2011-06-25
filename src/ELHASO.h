#ifndef __MACRO_H__
#define __MACRO_H__

/// Returns the value var restrained to inclusive lower and higher limits.
#define MID(low,var,high)  (MIN(MAX(low, var), high))

/// Useful macro to get the number of elements in any array type.
#define DIM(x)	(sizeof((x)) / sizeof((x)[0]))

/// Log only if the symbol DEBUG is defined.
#ifdef DEBUG
#define DLOG(X, ...)		NSLog(X, ##__VA_ARGS__)
#else
#define DLOG(X, ...)		do {} while (0)
#endif // DEBUG

/// Log always, avoid stupid CamelCase.
#define LOG(X, ...)			NSLog(X, ##__VA_ARGS__)

/// Verifies if the mask value VAL is set in the variable.
#define IS_BIT(VAR,VAL)		((VAR) & (VAL))

/// Sets the mask value VAL to the variable.
#define SET_BIT(VAR,VAL)	((VAR) |= (VAL))

/// Clears the bits in mask value VAL of the variable.
#define DEL_BIT(VAR,VAL)	((VAR) &= ~(VAL))

/// Returns the emtpy string if the parameter is nil.
#define NON_NIL_STRING(VAR)	((nil == VAR) ? @"": VAR)

/// Experimenting with new runtime assert macro.
#ifdef DEBUG
#define RASSERT(COND,TEXT,EXPR)											\
	NSAssert(COND, TEXT)
#else
#define RASSERT(COND,TEXT,EXPR)											\
	if (!(COND)) {														\
		LOG(@"Runtime assertion %s, %@\nat %s:%s:%d", #COND, TEXT,		\
			__PRETTY_FUNCTION__, __FILE__, __LINE__);					\
		do {															\
			EXPR;														\
		} while (0);													\
	}
#endif

#define ASK_GETTER(OBJECT, GETTER, DEF)								\
	((![OBJECT respondsToSelector:@selector(GETTER)]) ? (DEF) :		\
		([OBJECT performSelector:@selector(GETTER)]))

#define IS_IPAD		(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

/// Transforms degrees to radians. You need to import math.h.
#define DEG2RAD(X)              ((X) * M_PI / 180.0)
/// Transforms radians to degrees. You need to import math.h.
#define RAD2DEG(X)              ((X) * 180 / M_PI)

/// Maximum distance for objects, bigger than earth's diameter.
#define MAX_DISTANCE		(20000 * 1000)

/// Handy shortcut for all flexible margins in a view's autoresizingMask.
#define FLEXIBLE_MARGINS \
	(UIViewAutoresizingFlexibleTopMargin | \
	UIViewAutoresizingFlexibleBottomMargin | \
	UIViewAutoresizingFlexibleLeftMargin | \
	UIViewAutoresizingFlexibleRightMargin)

/// Handy shortcut for flexible size in a view's autoresizingMask.
#define FLEXIBLE_SIZE \
	(UIViewAutoresizingFlexibleHeight | \
	UIViewAutoresizingFlexibleWidth)


#endif // __MACRO_H__

// vim:tabstop=4 shiftwidth=4 syntax=objc
