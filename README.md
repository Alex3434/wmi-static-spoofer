# wmi-static-spoofer

## Motivation:

The initial motivation is bypassing HWID detection methods used by intrusive software like anti-cheats, etc. or licensing restrictions implemented in software. The concept is not new but other solutions require a loaded driver at all times and a kernel hook with possible instabilities. This project only uses direct memory manipulation and makes it possible to fake the serials without hooking a function or having a loaded kernel module at all times.

## Description:
Fakes the serialnumber for HDDs/diskdrives from kernelmode without hooking anything. The driver can be fully unloaded after changing the serialnumber.

- It's more like a PoC, there are many things to optimise
- It generates a random serial with a fixed length that can be changed in the [main.h](https://github.com/Alex3434/wmi-static-spoofer/blob/master/WMIC_static_spoofer/main.h) file
- The offsets for the spoofer can also be changed in the [main.h](https://github.com/Alex3434/wmi-static-spoofer/blob/master/WMIC_static_spoofer/main.h) file
- This does **NOT** counter all the ways for getting the serialnumber! I will make a writeup on that later.
- It also changes the registry entries to the faked serial via a internal kernel function

## Pictures:

Before:<br>
<img src="https://i.imgur.com/0ZAaPBb.png"/>

After:<br>
<img src="https://i.imgur.com/TwBKMRe.png"/>

## Supported/Testing

Only tested on Windows 10 16299.125<br>
For testing add: **disk.EnableUUID="true"** to your VMware .vmx file to enable serialnumbers for your HDD
