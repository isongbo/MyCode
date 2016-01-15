/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 24 11:22:16 2008
 */
/* Compiler settings for .\MyCEActiveX.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_MyCEActiveXLib = {0x9778890F,0xD6D3,0x4CAC,{0x8F,0x75,0xC4,0x86,0xCA,0xA5,0x19,0xB1}};


const IID DIID__DMyCEActiveX = {0x8EFBAF8F,0x968F,0x48DD,{0xA8,0xAC,0x88,0x2F,0xE4,0x57,0x97,0x2B}};


const IID DIID__DMyCEActiveXEvents = {0x7245A74E,0x5F56,0x4EF0,{0xA1,0x90,0x6E,0xD5,0x17,0xFE,0xB6,0x01}};


const CLSID CLSID_MyCEActiveX = {0xEB53D4D7,0x35CF,0x4CE3,{0x8A,0x04,0x97,0x6E,0x59,0xEB,0x35,0x9F}};


#ifdef __cplusplus
}
#endif

