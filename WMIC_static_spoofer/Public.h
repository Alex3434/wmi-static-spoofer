/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_WMICstaticspoofer,
    0x8f5b61b6,0x56a3,0x49e1,0x8e,0xcd,0xec,0x85,0x41,0x58,0x34,0x8f);
// {8f5b61b6-56a3-49e1-8ecd-ec854158348f}
