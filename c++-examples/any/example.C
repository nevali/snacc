// c++_examples/any/example.C - an example of how to use C++ ASN.1-BER
//              for ANY Types
//
// AUTHOR: Mike Sample
// DATE:   92
//
// $Header: /usr/app/odstb/CVS/snacc/c++-examples/any/example.C,v 1.5 1995/07/24 15:33:33 rj Exp $
// $Log: example.C,v $
// Revision 1.5  1995/07/24 15:33:33  rj
// changed `_' to `-' in file names.
//
// any-test.[hC] becomes any.[hC] due to to snacc's new file name generation scheme.
//
// check return value of new.
//
// Revision 1.4  1995/02/18  13:53:07  rj
// added #define HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS since not every C++ compiler provides them.
//
// Revision 1.3  1994/10/08  01:26:21  rj
// several \size_t'
//
// Revision 1.2  1994/08/31  08:56:29  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
//

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <fstream.h>

#include "asn-incl.h"
#include "any.h"

main (int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <BER data file name>" << endl;
        cerr << "   Decodes the given AnyTestType BER data file" << endl;
        cerr << "   and re-encodes it to stdout" << endl;
        exit (1);
    }

    ifstream dataFile;
    // open the data file
    dataFile.open (argv[1]);

    if (!dataFile)
    {
        perror ("ifstream::open");
        exit (1);
    }

    // get size of the data file file
    dataFile.seekg (0, ios::end);
    int dataSize = dataFile.tellg();
    dataFile.seekg (0);

    // read data from file into contiguous block for a buffer
#if HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS
    char data[dataSize];
#else
    char *data = new char[dataSize];
    if (!data)
	return 1;
#endif /* HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS */
    dataFile.read (data, dataSize);
    dataFile.close();

    //
    // put the BER data read from the file
    // into buffer format, ready for reading from the
    // beginning
    //
    AsnBuf inputBuf;
    inputBuf.InstallData ((char*)data, dataSize);

    size_t decodedLen;
    AnyTestType att;

    if (!att.BDecPdu (inputBuf, decodedLen))
    {
        cerr << "ERROR - Decode routines failed, exiting..." << endl;
        exit (1);
    }

    cerr  << "decodedValue AnyTestType ::= " << att << endl << endl;

    //
    // allocate a new buffer and set up for writing to
    //
    AsnBuf  outputBuf;
#if HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS
    char outputData[dataSize + 512];
#else
    char *outputData = new char[dataSize + 512];
    if (!outputData)
	return 1;
#endif /* HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS */
    outputBuf.Init (outputData, dataSize+512);
    outputBuf.ResetInWriteRvsMode();

    size_t encodedLen;
    if (!att.BEncPdu (outputBuf, encodedLen))
    {
        cerr << "ERROR - Encode routines failed" << endl;
    }

    // write the BER value to cout
    outputBuf.ResetInReadMode();
    for ( ; encodedLen > 0; encodedLen--)
        cout.put (outputBuf.GetByte());

    return 0;
}
