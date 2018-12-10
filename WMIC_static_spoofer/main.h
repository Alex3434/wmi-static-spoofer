#pragma once
#include <ntddk.h>
#include <wdf.h>
#include <intrin.h>
#include <stdlib.h>
#include <Ntstrsafe.h>

//Change that (Offsets are for Windows 10 16299.125)
#define	POOLTAG01 'ahIK'
#define RegDevIntOFF 0x12814 //RaidUnitRegisterInterfaces in storport.sys SIG: 48 89 5C 24 ? 55 56 57 48 83 EC 50
#define MAX_HDDS 10
#define SERIAL_MAX_LENGTH 15

#include "Util.h"
#include "Spoofer.h"

