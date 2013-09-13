#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

// In this header file we will include a list of all of the possible statuses
// that a tower can posssible inflict on a unit

namespace s{
	int poison = 1;			// First bit
	int poison2 = 2;		// Second bit
	int frost = 4;			// Third bit
	int slowMagic = 8;		// Fourth bit

}
#endif