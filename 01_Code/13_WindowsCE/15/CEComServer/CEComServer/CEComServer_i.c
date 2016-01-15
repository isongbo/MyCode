/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jan 23 17:19:35 2008
 */
/* Compiler settings for .\CEComServer.idl:
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

const IID IID_ISimple = {0x0F50BE04,0x1445,0x46EB,{0x94,0x8D,0xB5,0x28,0x32,0x06,0xAE,0x49}};


const IID LIBID_CEComServerLib = {0x5C3692C1,0x37B5,0x4988,{0x9E,0x70,0x5A,0x9F,0x3D,0xE0,0xB6,0x72}};


const CLSID CLSID_Simple = {0xA61EB607,0x9F7A,0x40B8,{0x88,0x72,0x41,0x90,0x8F,0x7C,0x8D,0xD9}};


#ifdef __cplusplus
}
#endif

