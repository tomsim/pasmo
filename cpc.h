#ifndef INCLUDE_CPCCRC_H
#define INCLUDE_CPCCRC_H

// cpc.h
// Revision 11-aug-2005

#include "pasmotypes.h"

#include <stdlib.h>


namespace pasmo {
namespace cpc {


unsigned short crc (const unsigned char * data, size_t size);

class Header {
public:
	Header ();
	Header (const string & filename);

	enum Type { Basic, Binary };

	void clear ();
	void setfilename (const string & filename);
	void settype (Type type);
	void setblock (byte n);
	void firstblock (bool isfirst);
	void lastblock (bool islast);
	void setlength (address len);
	void setblocklength (address blen);
	void setloadaddress (address load);
	void setentry (address entry);
	void write (std::ostream & out);
private:
	static const size_t headsize= 64;
	byte data [headsize];
};

class AmsdosHeader {
public:
	AmsdosHeader ();
	AmsdosHeader (const string & filename);

	void clear ();
	void setfilename (const string & filename);
	void setlength (address len);
	void setloadaddress (address load);
	void setentry (address entry);
	void write (std::ostream & out);
private:
	static const size_t headsize= 128;
	byte amsdos [headsize];
};

// CPC Locomotive Basic generation.

extern const string tokHexNumber;

extern const string tokCALL;
extern const string tokLOAD;
extern const string tokMEMORY;

string number (address n);
string hexnumber (address n);
string basicline (address linenum, const string & line);


} // namespace cpc
} // namespace pasmo

#endif

// End of cpc.h
