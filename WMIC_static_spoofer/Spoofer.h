#pragma once
CHAR HDDSPOOF_BUFFER[MAX_HDDS][32] = { 0x20 };
CHAR HDDORG_BUFFER[MAX_HDDS][32] = { 0 };

typedef struct _VendorInfo
{
	char pad_0x0000[0x8];
	char Info[64];
} VendorInfo;

typedef struct _HDD_EXTENSION
{
	char pad_0x0000[0x60];
	VendorInfo* pVendorInfo;
	char pad_0x0068[0x8];
	char* pHDDSerial;
	char pad_0x0078[0x30];
} HDD_EXTENSION, *PHDD_EXTENSION;

typedef __int64(__fastcall *RaidUnitRegisterInterfaces)(PHDD_EXTENSION a1);
RaidUnitRegisterInterfaces pRegDevInt = NULL;

INT HDD_count = 0;

void SpoofHDD()
{
	UINT64 address = GetKernelAddress("storport.sys");

	pRegDevInt = address + RegDevIntOFF;

	PDEVICE_OBJECT pObject = NULL;
	PFILE_OBJECT pFileObj = NULL;

	UNICODE_STRING DestinationString;
	RtlInitUnicodeString(&DestinationString, L"\\Device\\RaidPort0");

	NTSTATUS status = IoGetDeviceObjectPointer(&DestinationString, FILE_READ_DATA, &pFileObj, &pObject);

	PDRIVER_OBJECT pDriver = pObject->DriverObject;

	PDEVICE_OBJECT pDevice = pDriver->DeviceObject;

	while (pDevice->NextDevice != NULL)
	{
		if (pDevice->DeviceType == FILE_DEVICE_DISK)
		{
			PHDD_EXTENSION pDeviceHDD = pDevice->DeviceExtension;

			CHAR HDDSPOOFED_TMP[32] = { 0x0 };
			randstring(&HDDSPOOFED_TMP, SERIAL_MAX_LENGTH - 1);

			//Can be optimised...
			for (int i = 1; i <= SERIAL_MAX_LENGTH + 1; i = i + 2)
			{
				memcpy(&HDDORG_BUFFER[HDD_count][i - 1], &pDeviceHDD->pHDDSerial[i], sizeof(CHAR));
				memcpy(&HDDORG_BUFFER[HDD_count][i], &pDeviceHDD->pHDDSerial[i - 1], sizeof(CHAR));

				memcpy(&HDDSPOOF_BUFFER[HDD_count][i - 1], &HDDSPOOFED_TMP[i], sizeof(CHAR));
				memcpy(&HDDSPOOF_BUFFER[HDD_count][i], &HDDSPOOFED_TMP[i - 1], sizeof(CHAR));
			}

			RtlStringCchPrintfA(pDeviceHDD->pHDDSerial, SERIAL_MAX_LENGTH + 1, "%s", &HDDSPOOFED_TMP);

			pRegDevInt(pDeviceHDD);

			HDD_count++;
		}

		pDevice = pDevice->NextDevice;
	}
}