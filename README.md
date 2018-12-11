# wmi-static-spoofer

## Description:
Fakes the serialnumber for HDDs/diskdrives from kernelmode without hooking anything. The driver can be fully unloaded after changing the serialnumber.

- It's more like a PoC, there are many things to optimise
- It generates a random serial with a fixed length that can be changed in the [main.h](https://github.com/Alex3434/wmi-static-spoofer/blob/master/WMIC_static_spoofer/main.h) file
- The offsets for the spoofer can also be changed in the [main.h](https://github.com/Alex3434/wmi-static-spoofer/blob/master/WMIC_static_spoofer/main.h) file
- This does **NOT** counter all the ways for getting the serialnumber! I will make a writeup on that later.
- It also changes the registry entries to the faked serial via a internal kernel function

## Supported/Tested

Only tested on Windows 10 16299.125
