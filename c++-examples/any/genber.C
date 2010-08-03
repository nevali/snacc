// c++_examples/any/genber.C - builds an AnyTestType value and writes BER form
//            of the value to a file called "att.ber"
//
//  Shows how to build internal rep of lists and ANY values.
//
// MS 92
//
// $Header: /usr/app/odstb/CVS/snacc/c++-examples/any/genber.C,v 1.5 1995/07/24 15:33:34 rj Exp $
// $Log: genber.C,v $
// Revision 1.5  1995/07/24 15:33:34  rj
// changed `_' to `-' in file names.
//
// any-test.[hC] becomes any.[hC] due to to snacc's new file name generation scheme.
//
// check return value of new.
//
// Revision 1.4  1995/02/18  13:54:03  rj
// added #define HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS since not every C++ compiler provides them.
//
// Revision 1.3  1994/10/08  01:26:22  rj
// several \size_t'
//
// Revision 1.2  1994/08/31  08:56:30  rj
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
    ofstream outputFile;
    AsnBuf outputBuf;
    size_t encodedLen;
    size_t dataSize = 1024;
#if HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS
    char data[dataSize];
#else
    char *data = new char[dataSize];
    if (!data)
	return 1;
#endif /* HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS */
    AnyTestType att;
    TSeq1 ts1;
    TSeq2 ts2;
    AttrValue1 *atv1ptr;
    AttrValue2 *atv2ptr;
    AsnInt intVal;
    AsnBool boolVal;
    AsnOcts octsVal ("Hi Mom");
    OctsId octsIdVal = octsVal;
    AsnBits bitsVal;
    BitsId bitsIdVal (9);
    AsnReal realVal;

    // READ THIS!!!
    // you must be really careful when setting the
    // "value" field and "id" fields in an
    // ANY/ANY DEFINED BY type because "value" is a
    // "AsnType*" and will accept any
    // pointer value.  It will even encode
    // the wrong value without complaining if you
    // set "value" to the wrong object.

    atv1ptr = att.intMap.Append();
    atv1ptr->id = intId;
    intVal = -99;
    atv1ptr->anyDefBy.value = &intVal;

    atv1ptr = att.intMap.Append();
    atv1ptr->id = boolId;
    boolVal = true;
    atv1ptr->anyDefBy.value = &boolVal;

    atv1ptr = att.intMap.Append();
    atv1ptr->id = octsId;
    atv1ptr->anyDefBy.value = &octsIdVal;

    atv1ptr = att.intMap.Append();
    atv1ptr->id = bitsId;
    bitsIdVal.SetBit (0);
    bitsIdVal.ClrBit (1);
    bitsIdVal.SetBit (2);
    bitsIdVal.ClrBit (3);
    bitsIdVal.SetBit (4);
    bitsIdVal.ClrBit (5);
    bitsIdVal.SetBit (6);
    bitsIdVal.ClrBit (7);
    bitsIdVal.SetBit (8);
    bitsIdVal.ClrBit (9);
    atv1ptr->anyDefBy.value = &bitsIdVal;

    atv1ptr = att.intMap.Append();
    atv1ptr->id = realId;
    realVal = 108.3838;
    atv1ptr->anyDefBy.value = &realVal;

    // now do TSeq2 with same vals but use OID as identifier
    atv2ptr = att.oidMap.Append();
    atv2ptr->id = intOid;
    atv2ptr->anyDefBy.value = &intVal;

    atv2ptr = att.oidMap.Append();
    atv2ptr->id = boolOid;
    atv2ptr->anyDefBy.value = &boolVal;

    atv2ptr = att.oidMap.Append();
    atv2ptr->id = octsOid;
    atv2ptr->anyDefBy.value = &octsVal;

    atv2ptr = att.oidMap.Append();
    atv2ptr->id = bitsOid;
    bitsVal = bitsIdVal; // copy bits
    atv2ptr->anyDefBy.value = &bitsVal;

    atv2ptr = att.oidMap.Append();
    atv2ptr->id = realOid;
    atv2ptr->anyDefBy.value = &realVal;

    outputBuf.Init (data, dataSize);
    outputBuf.ResetInWriteRvsMode();

    if (!att.BEncPdu (outputBuf, encodedLen))
        cout << "failed encoding AnyTestType value" << endl;

    outputFile.open ("att.ber");
    if (!outputFile)
    {
        perror ("ofstream::open");
        exit (1);
    }

    outputBuf.ResetInReadMode();
    for ( ; encodedLen > 0; encodedLen--)
        outputFile.put (outputBuf.GetByte());


    cout << "Wrote the following BER AnyTestType value to att.ber." << endl;
    cout << "Test it with \"def\" and \"indef\"" << endl;
    cout << att << endl;

    return 0;
}
