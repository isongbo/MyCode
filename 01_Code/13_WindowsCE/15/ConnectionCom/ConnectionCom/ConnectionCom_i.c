/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 24 09:28:35 2008
 */
/* Compiler settings for .\ConnectionCom.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
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

const IID IID_IAdd = {0x7C20780D,0x056A,0x4B4C,{0xA0,0xCB,0x0E,0x11,0x0F,0x5C,0x68,0xCF}};


const IID LIBID_ConnectionComLib = {0x6C01534B,0x653C,0x435B,{0x8A,0x8A,0xC2,0x6B,0xC7,0x7D,0xA6,0x5F}};


const IID DIID__IAddEvents = {0x6D98CC76,0xF53F,0x4DC3,{0xA0,0xF1,0x69,0x15,0x15,0x0B,0xEF,0xED}};


const CLSID CLSID_Add = {0x16753E3A,0x3279,0x4704,{0xA0,0x5B,0x44,0xDA,0xA9,0x4A,0x5C,0x9C}};


#ifdef __cplusplus
}
#endif

