#pragma once
#include <ntifs.h>

// IOCTL is where you declare codes that you will use to asign or send towards your driver and you id the code and you do something in regard to the code

#define IO_GET_CLIENTADDRESS CTL_CODE(FILE_DEVICE_UNKNOWN, 0x666, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define IO_READ_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x667, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define IO_WRITE_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x668, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define IO_REQUEST_PROCESSID CTL_CODE(FILE_DEVICE_UNKNOWN, 0x669, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

NTSTATUS IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp); // handles communcation codes and anything

NTSTATUS CloseCall(PDEVICE_OBJECT DeviceObject, PIRP Irp); // Close call is called when the communcation is established from the user mode application is terminated/closed

NTSTATUS CreateCall(PDEVICE_OBJECT DeviceObject, PIRP Irp); // Create call is called when communcation is created

typedef struct _KERNEL_READ_REQUEST {
	ULONG ProcessId; // specify any process you want to read and write
	ULONG Address;
	PVOID pBuff;
	ULONG Size;

} KERENEL_READ_REQUEST, * PKERNEL_READ_REQUEST;

typedef struct _KERNEL_WRITE_REQUEST {
	ULONG ProcessId;
	ULONG Address;
	PVOID pBuff;
	ULONG Size;

} KERENEL_WRITE_REQUEST, * PKERNEL_WRITE_REQUEST;

