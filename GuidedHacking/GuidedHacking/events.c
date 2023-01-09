
#pragma warning (disable: 4047 4311 4459)

#include "events.h"
#include "messages.h"
#include "data.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
	
	// DebugMessage("ImageLoaded: %ls \n", FullImageName->Buffer);
	//in this case statement:
	//the names of all executable files loaded into the process address space
	//when starting a new application are compared with the search string
	if (wcsstr(FullImageName->Buffer, L"\\Counter-Strike Global Offensive\\csgo\\bin\\client.dll"))//if (wcsstr(FullImageName->Buffer, L"\\exe file path\\name of target application"))
	{
		DbgPrint("Target_MFC_Application.exe found!\r\n");
		base_address_of_target_application = ImageInfo->ImageBase;
		targetProcessId = (ULONG)ProcessId;
		DbgPrint("Target_MFC_Application : %p\r\n", base_address_of_target_application);
		DbgPrint("ProcessId : %p\r\n", ProcessId);
	}
	return STATUS_SUCCESS;
}