#include "main.h"



VOID Unload(
	_In_ struct _DRIVER_OBJECT *DriverObject
)
{

}

NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject, 
	_In_ PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = Unload;

	SpoofHDD();

	return STATUS_SUCCESS;
}

