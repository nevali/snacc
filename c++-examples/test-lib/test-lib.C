// c++_examples/test_lib/test_lib.C
//
// $Header: /usr/app/odstb/CVS/snacc/c++-examples/test-lib/test-lib.C,v 1.5 1997/02/28 13:39:42 wan Exp $
// $Log: test-lib.C,v $
// Revision 1.5  1997/02/28 13:39:42  wan
// Modifications collected for new version 1.3: Bug fixes, tk4.2.
//
// Revision 1.4  1995/07/24 15:44:10  rj
// #error "..." instead of #error ...
//
// changed `_' to `-' in file names.
//
// function and file names adjusted.
//
// Revision 1.3  1995/02/18  16:40:08  rj
// utilize either isinf(3) or finite(3), whatever happens to be present.
//
// Revision 1.2  1994/08/31  08:56:35  rj
// first check-in. for a list of changes to the snacc-1.1 distribution please refer to the ChangeLog.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
#include "asn-incl.h"


int TestAsnBuffers();
int TestAsnTag();
int TestAsnLen();
int TestAsnBool();
int TestAsnInt();
int TestAsnReal();
int TestAsnOcts();
int TestAsnBits();
int TestAsnOid();
int TestAsnList();

const int bufSize = 256;

int main()
{
    int isErr = false;

    if (!TestAsnBuffers())
    {
        std::cout << "Failed buffer tests, no point in proceeding ... bye!" << std::endl;
        return 1;
    }

    if (!TestAsnTag())
    {
        std::cout << "Failed Tag test." << std::endl;
        isErr = true;
    }

    if (!TestAsnLen())
    {
        std::cout << "Failed Length test." << std::endl;
        isErr = true;
    }

    if (!TestAsnBool())
    {
        std::cout << "Failed BOOLEAN test." << std::endl;
        isErr = true;
    }


    if (!TestAsnInt())
    {
        std::cout << "Failed INTEGER test." << std::endl;
        isErr = true;
    }

    if (!TestAsnOcts())
    {
        std::cout << "Failed OCTET STRING test." << std::endl;
        isErr = true;
    }


    if (!TestAsnBits())
    {
        std::cout << "Failed BIT STRING test." << std::endl;
        isErr = true;
    }


    if (!TestAsnOid())
    {
        std::cout << "Failed OBJECT IDENTIFIER test." << std::endl;
        isErr = true;
    }


    if (!TestAsnReal())
    {
        std::cout << "Failed REAL test." << std::endl;
        isErr = true;
    }



    if (isErr)
    {
        std::cout << "There are errors in the primitive type encoding/decoding" << std::endl;
        std::cout << "library for this architecture.  Time for gdb..." << std::endl;
    }
    else
    {
        std::cout << "The primitive type encoding/decoding library passed simple tests." << std::endl;
        std::cout << "It should be safe to use..." << std::endl;
    }
    return isErr;
}


/*
 * returns true if passes encode/decode tests
 */
int
TestAsnBuffers()
{
    AsnBuf  b;
    char bufData[256];
    int i,j;
    int noErr = true;

    // initialize buffer
    b.Init (bufData, 256);
    b.ResetInWriteRvsMode();

    // write whole range of byte (0..255)
    // remember, write works in reverse
    for (i = 0; i < 256; i++)
        b.PutByteRvs (i);

    if (b.WriteError())
    {
        std::cout << "Error writing to buffer." << std::endl;
        noErr = false;
    }

    // read in values & verify
    b.ResetInReadMode();
    for (i = 255; i >= 0; i--)
        if (b.GetByte() != i)
        {
            std::cout << "Error verifying data written to buffer." << std::endl;
            noErr = false;
        }

    if (b.ReadError())
    {
        std::cout << "Error reading from buffer." << std::endl;
        noErr = false;
    }


    /* now make sure errors are detected */
    b.ResetInWriteRvsMode();

    for (i = 0; i < 257; i++) // write past end of buffer
        b.PutByteRvs (0);

    if (!b.WriteError())
    {
        std::cout << "Buffers failed to report buffer write overflow." << std::endl;
        noErr = false;
    }


    b.ResetInReadMode();
    for (i = 256; i >= 0; i--)  // read past end of buffer
        b.GetByte();

    if (!b.ReadError())
    {
        std::cout << "Buffers failed to report buffer read overflow." << std::endl;
        noErr = false;
    }

    return noErr;
}  /* TestAsnBuffers */



/*
 * returns true if passes encode/decode tests
 */
int
TestAsnTag()
{
    AsnTag aTag1;
    AsnTag aTag2;
    int i, j;
    AsnLen len1;
    AsnLen len2;
    AsnTag tag;
    int noErr = true;
    ENV_TYPE env;
    AsnBuf  b;
    char bufData[256];
    long int val;
    BER_CLASS tagClass;
    BER_FORM form;
    BER_UNIV_CODE code;


    /* initialize buffer */
    b.Init (bufData, 256);

    /* encode a TRUE value and verify */
    tagClass = UNIV;
    form = PRIM;
    code = INTEGER_TAG_CODE;
    aTag1 = MAKE_TAG_ID (tagClass, form, code);

    for (i = 0; i < 2; i++)
    {
        b.ResetInWriteRvsMode();
        len1 = BEncTag1 (b, tagClass, form, code);

        if (b.WriteError())
        {
            noErr = false;
            std::cout << "Error encoding a Tag." << std::endl;
        }

        b.ResetInReadMode();

        aTag2 = 0;

        /* make sure no decode errors and that it decodes to same tag */
        len2 = 0;
        if ((val = setjmp (env)) == 0)
        {
            aTag2 = BDecTag (b, len2, env);
        }
        else
        {
            noErr = false;
            std::cout << "Error decoding a Tag - error number " << val << std::endl;
        }
        if (noErr && ((aTag2 != aTag1) || (len1 != len2)))
        {
            noErr = false;
            std::cout << "Error decoded Tag does not match encoded Tag." << std::endl;
        }
        /* set a new test tag value */
        tagClass = CNTX;
        form = CONS;
        code = (BER_UNIV_CODE) 29;
        aTag1 = MAKE_TAG_ID (tagClass, form, code);
    }
    return noErr;
}  /* TestAsnTag */


/*
 * returns true if passes encode/decode tests
 */
int
TestAsnLen()
{
    AsnLen aLen1;
    AsnLen aLen2;
    int i,j;
    AsnLen len1;
    AsnLen len2;
    AsnTag tag;
    int noErr = true;
    ENV_TYPE env;
    AsnBuf  b;
    char bufData[256];
    long int val;

    /* initialize buffer */
    b.Init (bufData, 256);


    /* encode a TRUE value and verify */
    aLen1 = 99999;
    for (i = 0; i < 2; i++)
    {
        b.ResetInWriteRvsMode();
        len1 = BEncDefLen (b, aLen1);

        if (b.WriteError())
        {
            noErr = false;
            std::cout <<  "Error encoding Length." << std::endl;
        }

        b.ResetInReadMode();

        aLen2 = 0;

        /* make sure no decode errors and that it decodes to true */
        len2 = 0;
        if ((val = setjmp (env)) == 0)
        {
            aLen2 = BDecLen (b, len2, env);
        }
        else
        {
            noErr = false;
            std::cout << "Error decoding Length - error number " << val << std::endl;
        }


        if (noErr && ((aLen2 != aLen1) || (len1 != len2)))
        {
            noErr = false;
            std::cout << "Error - decoded length does not match encoded length" << std::endl;
        }
        aLen1 = 2;
    }


    /* test indef len */
    b.ResetInWriteRvsMode();
    len1 = BEncIndefLen (b);

    if (b.WriteError())
    {
        noErr = false;
        std::cout << "Error encoding indefinite Length." << std::endl;
    }

    b.ResetInReadMode();

    aLen2 = 0;

    /* make sure no decode errors */
    len2 = 0;
    if ((val = setjmp (env)) == 0)
    {
        aLen2 = BDecLen (b, len2, env);
    }
    else
    {
        noErr = false;
        std::cout << "Error decoding Length - error number " << val << std::endl;
    }


    if (noErr && ((aLen2 != INDEFINITE_LEN) || (len1 != len2)))
    {
        noErr = false;
        std::cout << "Error - decoded length does not match encoded length" << std::endl;
    }

    /* test EOC */
    b.ResetInWriteRvsMode();
    len1 = BEncEoc (b);

    if (b.WriteError())
    {
        noErr = false;
        std::cout << "Error encoding indefinite Length." << std::endl;
    }

    b.ResetInReadMode();

    aLen2 = 0;

    /* make sure no decode errors */
    len2 = 0;
    if ((val = setjmp (env)) == 0)
    {
        BDecEoc (b, len2, env);
    }
    else
    {
        noErr = false;
        std::cout << "Error decoding Length - error number " <<  val << std::endl;
    }


    if (noErr && (len1 != len2))
    {
        noErr = false;
        std::cout << "Error - decoded EOC length error" << std::endl;
    }

    return noErr;
}  /* TestAsnLen */



/*
 * returns true if passes encode/decode tests
 */
int
TestAsnBool()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnBool aBool1;
    AsnBool aBool2;
    int j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    // initialize a small buffer
    b.Init (bufData, bufSize);
    b.ResetInWriteRvsMode();

    // encode a true value and verify
    aBool1 = true;

    if (!aBool1.BEncPdu (b, len1))
    {
        noErr = false;
        std::cout << "Error encoding TRUE BOOLEAN value." << std::endl;
    }

    b.ResetInReadMode();

    aBool2 = false; // set to opposite of expected value

    // make sure no decode errors and that it decodes to true
    if (!aBool2.BDecPdu (b, len2) || !aBool2 || (len1 != len2))
    {
        noErr = false;
        std::cout << "Error decoding TRUE BOOLEAN value." << std::endl;
    }

    // now encode a false value and verify
    b.ResetInWriteRvsMode();
    aBool1 = false;

    if (!aBool1.BEncPdu (b, len1))
    {
        noErr = false;
        std::cout << "Error encoding FALSE BOOLEAN value." << std::endl;
    }

    b.ResetInReadMode();

    aBool2 = true; // set to opposite of expected value

    // make sure no decode errors and that it decodes to false
    if (!aBool2.BDecPdu (b, len2) || aBool2 || (len1 != len2))
    {
        noErr = false;
        std::cout << "Error decoding FALSE BOOLEAN value." << std::endl;
    }

    return noErr;
}  /* TestAsnBool */


/*
 * returns true if passes encode/decode tests
 */
int
TestAsnInt()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnInt a1;
    AsnInt a2;
    int i,j, sign;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    // initialize a small buffer
    b.Init (bufData, bufSize);

    //
    // Encode a range of integers: negative & positive in
    //  the 1 to sizeof (long int) range
    //

    sign = 1;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < sizeof (long int); i++)
        {
            b.ResetInWriteRvsMode();

            a1 = sign * (17 << (i * 8)); // 17 is a random choice
            if (!a1.BEncPdu (b, len1))
            {
                noErr = false;
                std::cout << "Error encoding INTEGER value " << a1 << "." << std::endl;
            }

            b.ResetInReadMode();
            a2 = 0;

            // make sure no decode errors and that it decodes to the correc val
            if (!a2.BDecPdu (b, len2) || (a2 != a1) || (len1 != len2))
            {
                noErr = false;
                std::cout << "Error decoding INTEGER value " << a1 << "." << std::endl;
            }
        }
        sign = -1;
    }

    return noErr;

} /* TestAsnInt */


/*
 * returns true if passes encode/decode tests
 */
int
TestAsnOcts()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnOcts a1;
    AsnOcts a2;
    int i,j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    // initialize a small buffer
    b.Init (bufData, bufSize);

    a1 = "Hello Gumby?";
    for (j = 0; j < 2; j++)
    {
        b.ResetInWriteRvsMode();

        if (!a1.BEncPdu (b, len1))
        {
            noErr = false;
            std::cout << "Error encoding OCTET STRING value " << a1 << "." << std::endl;
        }

        b.ResetInReadMode();

        // make sure no decode errors and that it decodes to the correc val
        if (!a2.BDecPdu (b, len2) || (a2 != a1) || (len1 != len2))
        {
            noErr = false;
            std::cout << "Error decoding OCTET STRING value " << a1 << "." << std::endl;
        }
        a1 = ""; // try an empty string
    }

    return noErr;

} /* TestAsnOcts */



/*
 * returns true if passes encode/decode tests
 */
int
TestAsnBits()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnBits a1 (32);
    AsnBits a2 (32);
    short bitsToSet[32] = { 0, 1, 0, 0, 1, 1, 0, 1,
                            0, 1, 0, 0, 1, 1, 0, 1,
                            0, 1, 0, 0, 1, 1, 0, 1,
                            0, 1, 0, 0, 1, 1, 0, 1 };
    int i,j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    // initialize a small buffer
    b.Init (bufData, bufSize);


    // set some bits
    for (i = 0; i < 32; i++)
    {
        if (bitsToSet[i])
            a1.SetBit (i);
        else
            a1.ClrBit (i);

    }

    b.ResetInWriteRvsMode();
    if (!a1.BEncPdu (b, len1))
    {
        noErr = false;
        std::cout << "Error encoding BIT STRING value " << a1 << "." << std::endl;
    }

    b.ResetInReadMode();

    // make sure no decode errors and that it decodes to the correc val
    if (!a2.BDecPdu (b, len2) || (a2 != a1) || (len1 != len2))
    {
        noErr = false;
        std::cout << "Error decoding BIT STRING value " << a1 << "." << std::endl;
    }


    return noErr;

} /* TestAsnBits */



/*
 * returns true if passes encode/decode tests
 */
int
TestAsnOid()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnOid a1 (0,1,2,3,4,5,6);
    AsnOid a2;
    AsnOid a3 (2,38,29,40,200,10,4000);
    int i,j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    // initialize a small buffer
    b.Init (bufData, bufSize);

    for (i = 0; i < 2; i++)
    {
        b.ResetInWriteRvsMode();

        if (!a1.BEncPdu (b, len1))
        {
            noErr = false;
            std::cout << "Error encoding OBJECT IDENTIFIER value " << a1 << "." << std::endl;
        }

        b.ResetInReadMode();

        // make sure no decode errors and that it decodes to the correc val
        if (!a2.BDecPdu (b, len2) || (a2 != a1) || (len1 != len2))
        {
            noErr = false;
            std::cout << "Error decoding OBJECT IDENTIFIER value " << a1 << "." << std::endl;
        }

        a1 = a3;
    }
    return noErr;

} /* TestAsnOid */

/*
 * returns true if passes encode/decode tests
 *
 * NOT USED - nuked template design.
 */
/*
int
TestAsnList()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnList<AsnInt> intList1;
    AsnList<AsnInt> intList2;
    AsnList<AsnBool> boolList1;
    AsnList<AsnBool> boolList2;
    int i,j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;

    b.Init (bufData, bufSize);

    b.ResetInWriteRvsMode();

    if (!intList1.BEncPdu (b, len1))
    {
        noErr = false;
        std::cout << "Error encoding SEQUENCE OF value " << intList1 << "." << std::endl;
    }

    b.ResetInReadMode();

    if (!intList2.BDecPdu (b, len2) || (len1 != len2))
    {
        noErr = false;
        std::cout << "Error decoding SEQUENCE OF value " << intList1 << "." << std::endl;
    }
    std::cout << "intlist 1 = "  <<  intList1 << std::endl;
    std::cout << "intlist 2 = "  <<  intList1 << std::endl;


    if (!boolList1.BEncPdu (b, len1))
    {
        noErr = false;
        std::cout << "Error encoding SEQUENCE OF value " << boolList1 << "." << std::endl;
    }

    b.ResetInReadMode();

    if (!boolList2.BDecPdu (b, len2) ||  (len1 != len2))
    {
        noErr = false;
        std::cout << "Error decoding SEQUENCE OF value " << boolList1 << "." << std::endl;
    }
    std::cout << "boolList 1 = "  <<  boolList1 << std::endl;
    std::cout << "boolList 2 = "  <<  boolList1 << std::endl;

    return noErr;

}  TestAsnList */



/*
 * returns true if passes encode/decode tests
 */
int
TestAsnReal()
{
    AsnBuf  b;
    char bufData[bufSize];
    AsnReal  a2;
    AsnReal  a[] = { 0.0, 0.8, -22.484848, PLUS_INFINITY, MINUS_INFINITY};
    int i,j;
    AsnLen len1;
    AsnLen len2;
    int noErr = true;


    /*
     * if you do not have the ieee_functions in your math lib,
     * this will not link.  Comment it out and cross you fingers.
     * (or check/set the +/-infinity values for you architecture)
     */
#if HAVE_ISINF
    if ((!isinf ((double)PLUS_INFINITY)) || (!isinf ((double)MINUS_INFINITY)))
#else
#if HAVE_FINITE
    if ((finite ((double)PLUS_INFINITY)) || (finite ((double)MINUS_INFINITY)))
#else
  #error "oops: you've got neither isinf(3) nor finite(3)?!"
#endif
#endif
    {
        std::cout << "WARNING: PLUS_INFINITY and MINUS_INFINITY in .../c++-lib/src/asn-real.C are" << std::endl;
        std::cout << "not correct for this architecture.  Modify the AsnPlusInfinity() routine." << std::endl;
    }


    // initialize a small buffer
    b.Init (bufData, bufSize);

    for (i = 0; i < 5; i++)
    {
        b.ResetInWriteRvsMode();

        if (!a[i].BEncPdu (b, len1))
        {
            noErr = false;
            std::cout << "Error encoding REAL value " << a[i] << "." << std::endl;
        }

        b.ResetInReadMode();

        // make sure no decode errors and that it decodes to the correc val
        if (!a2.BDecPdu (b, len2) || (a2 != a[i]) || (len1 != len2))
        {
            noErr = false;
            std::cout << "Error decoding REAL value " << a[i] << "." << std::endl;
        }
    }

    return noErr;

} /* TestAsnReal */
