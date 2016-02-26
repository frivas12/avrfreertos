/*
Copyright 2011 Niels Brouwers

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.#include <string.h>
*/

/* MAX3421E register/bit names and bitmasks */

#ifndef _MAX3421Econstants_h_
#define _MAX3421Econstants_h_

#ifdef __cplusplus
extern "C" {
#endif

// VBUS states
typedef enum
{
	SE0  =   0x00,
	SE1   =  0x01,
	FSHOST = 0x02,
	LSHOST = 0x03
} vbusState_t;

/* USBIRQ Bits - Register 13 */
#define bmVBUSIRQ   0x40    //b6
#define bmNOVBUSIRQ 0x20    //b5
#define bmOSCOKIRQ  0x01    //b0

/* USBIEN Bits - Register 14 */
#define bmVBUSIE    0x40    //b6
#define bmNOVBUSIE  0x20    //b5
#define bmOSCOKIE   0x01    //b0

/* USBCTL Bits - Register 15 */
#define bmCHIPRES   0x20    //b5
#define bmPWRDOWN   0x10    //b4

/* CPUCTL Bits - Register 16 */
#define bmPUSLEWID1 0x80    //b7
#define bmPULSEWID0 0x40    //b6
#define bmIE        0x01    //b0

/* PINCTL Bits - Register 17 */
#define bmFDUPSPI   0x10    //b4
#define bmINTLEVEL  0x08    //b3
#define bmPOSINT    0x04    //b2
#define bmGPXB      0x02    //b1
#define bmGPXA      0x01    //b0

// GPX pin selections
#define GPX_OPERATE 0x00
#define GPX_VBDET   0x01
#define GPX_BUSACT  0x02
#define GPX_SOF     0x03

/* HIRQ Bits - Register 25 */
#define bmBUSEVENTIRQ   0x01   // indicates BUS Reset Done or BUS Resume
#define bmRWUIRQ        0x02
#define bmRCVDAVIRQ     0x04
#define bmSNDBAVIRQ     0x08
#define bmSUSDNIRQ      0x10
#define bmCONDETIRQ     0x20
#define bmFRAMEIRQ      0x40
#define bmHXFRDNIRQ     0x80

/* HIEN Bits - Register 26 */
#define bmBUSEVENTIE    0x01
#define bmRWUIE         0x02
#define bmRCVDAVIE      0x04
#define bmSNDBAVIE      0x08
#define bmSUSDNIE       0x10
#define bmCONDETIE      0x20
#define bmFRAMEIE       0x40
#define bmHXFRDNIE      0x80

/* MODE Bits - Register 27 */
#define bmHOST          0x01
#define bmLOWSPEED      0x02
#define bmHUBPRE        0x04
#define bmSOFKAENAB     0x08
#define bmSEPIRQ        0x10
#define bmDELAYISO      0x20
#define bmDMPULLDN      0x40
#define bmDPPULLDN      0x80

/* HCTL Bits - Register 29 */
#define bmBUSRST        0x01
#define bmFRMRST        0x02
#define bmSAMPLEBUS     0x04
#define bmSIGRSM        0x08
#define bmRCVTOG0       0x10
#define bmRCVTOG1       0x20
#define bmSNDTOG0       0x40
#define bmSNDTOG1       0x80

/* Host transfer token values for writing the HXFR register - Register 30   */
/* OR this bit field with the end point number in bits 3:0                  */
#define tokSETUP  0x10  // HS=0, ISO=0, OUTNIN=0, SETUP=1
#define tokIN     0x00  // HS=0, ISO=0, OUTNIN=0, SETUP=0
#define tokOUT    0x20  // HS=0, ISO=0, OUTNIN=1, SETUP=0
#define tokINHS   0x80  // HS=1, ISO=0, OUTNIN=0, SETUP=0
#define tokOUTHS  0xA0  // HS=1, ISO=0, OUTNIN=1, SETUP=0
#define tokISOIN  0x40  // HS=0, ISO=1, OUTNIN=0, SETUP=0
#define tokISOOUT 0x60  // HS=0, ISO=1, OUTNIN=1, SETUP=0

/* HRSL Bits - Register 31 */
#define bmSE0       0x00    //SE0 - disconnect state
#define bmRCVTOGRD  0x10
#define bmSNDTOGRD  0x20
#define bmKSTATUS   0x40
#define bmJSTATUS   0x80
#define bmSE1       0xC0    //SE1 - illegal state

/* Host error result codes, the 4 LSB's in the HRSL register - Register 31  */
#define hrSUCCESS   0x00	// Successful Transfer
#define hrBUSY      0x01	// SIE is busy, transfer pending
#define hrBADREQ    0x02	// Bad value in HXFR reg
#define hrUNDEF     0x03	// (reserved)
#define hrNAK       0x04	// Peripheral returned NAK
#define hrSTALL     0x05	// Peripheral returned STALL
#define hrTOGERR    0x06	// Toggle error/ISO over/under run
#define hrWRONGPID  0x07	// Received the wrong PID
#define hrBADBC     0x08	// Bad byte count
#define hrPIDERR    0x09	// Receive PID is corrupted
#define hrPKTERR    0x0A	// Packet error (stuff, EOP)
#define hrCRCERR    0x0B	// CRC error
#define hrKERR      0x0C	// K-state instead of response
#define hrJERR      0x0D	// J-state instead of response
#define hrTIMEOUT   0x0E	// Device did not respond in time
#define hrBABBLE    0x0F	// Device talked too long

#define MODE_FS_HOST    (bmDPPULLDN|bmDMPULLDN|bmSOFKAENAB|bmHOST)
#define MODE_LS_HOST    (bmDPPULLDN|bmDMPULLDN|bmSOFKAENAB|bmLOWSPEED|bmHOST)

#ifdef __cplusplus
}
#endif

#endif //_MAX3421Econstants_h_
