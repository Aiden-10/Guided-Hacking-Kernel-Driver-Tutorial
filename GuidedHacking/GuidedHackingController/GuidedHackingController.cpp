#include <time.h>

#include <iostream>

#include "kernelinterface.hpp"
#include "offsets.hpp"








int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\guidedhacking");

    ULONG address = Driver.GetClientAddress();
    ULONG processid = Driver.GetProcessId();





    std::cout << "Hello F@ggot!\n";

	std::cout << "CSGO id: " << processid << std::endl;
	std::cout << "Found client.dll ClientBase: 0x" << std::uppercase
		<< std::hex << address << std::endl;


    uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address + hazedumper::signatures::dwLocalPlayer, sizeof(uint32_t));
    uint32_t pGlowObjectManager = Driver.ReadVirtualMemory<uint32_t>(processid, address + hazedumper::signatures::dwGlowObjectManager, sizeof(uint32_t));
    uint32_t pEntityList = Driver.ReadVirtualMemory<uint32_t>(processid, address + hazedumper::signatures::dwEntityList, sizeof(uint32_t));

    while (true) {
        















        Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, 0.f, sizeof(0.f));
        if (GetAsyncKeyState(VK_F9)) {
            Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_iDefaultFOV, 1.5f, sizeof(0.f));
            //Driver.WriteVirtualMemory(processid, localPlayerAddress + hazedumper::netvars::m_iFOV, 6.0f, sizeof(-1.0f));


        }

        if (GetAsyncKeyState(VK_LEFT) & 0x8000)//left arrow
        {
            std::cout << "Left Arrow Pressed\n";
            Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_iObserverMode, 1, sizeof(0.f));
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) //right arrow
        {
            std::cout << "Right Arrow Pressed\n";
            Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_iObserverMode, 0, sizeof(0.f));
        }


        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::signatures::dwViewMatrix, 1.0, sizeof(0.f));
        }

    }
}


