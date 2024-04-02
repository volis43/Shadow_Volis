#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#pragma comment(lib, "IPHLPAPI.lib")

int main(int argc, char** argv)
{
    unsigned char* pszBuff = NULL;
    int nCount = 0;
    int idx = 0;
    int chPos = 0;
    nCount = RetriveLocalMacAddress(GAA_FLAG_INCLUDE_ALL_COMPARTMENTS, AF_UNSPEC, &pszBuff);

    for (idx = 0; idx < nCount; ++idx)
    {
        chPos = MAX_ADAPTER_ADDRESS_LENGTH * idx;
        printf("%02X-%02X-%02X-%02X-%02X-%02X\n",
            pszBuff[chPos], pszBuff[1 + chPos], pszBuff[2 + chPos], pszBuff[3 + chPos],
            pszBuff[4 + chPos], pszBuff[5 + chPos]);
    }
    HeapFree(GetProcessHeap(), 0x00, pszBuff);
    pszBuff = NULL;

    return 0;
}

int RetriveLocalMacAddress(ULONG ulFlags, ULONG ulFamily, unsigned char** pszAddress)
{
    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
    PIP_ADAPTER_ADDRESSES pAddresses = NULL;

    int nAddressCount = 0;
    DWORD dwRetVal = 0;
    ULONG ulBufLen = sizeof(IP_ADAPTER_ADDRESSES);
    HANDLE hHeap = NULL;

    hHeap = GetProcessHeap();
    pAddresses = (PIP_ADAPTER_ADDRESSES)HeapAlloc(hHeap, 0x00, ulBufLen);
    if (pAddresses == NULL) {
        return 0;
    }

    dwRetVal = GetAdaptersAddresses(ulFamily, ulFlags, NULL, pAddresses, &ulBufLen);
    if (dwRetVal == ERROR_BUFFER_OVERFLOW)
    {
        HeapFree(hHeap, 0x00, pAddresses);
        pAddresses = (PIP_ADAPTER_ADDRESSES)HeapAlloc(hHeap, 0x00, ulBufLen);
    }

    if (pAddresses == NULL) {
        return 0;
    }

    dwRetVal = GetAdaptersAddresses(ulFamily, ulFlags, NULL, pAddresses, &ulBufLen);
    if (dwRetVal == NO_ERROR)
    {
        pCurrAddresses = pAddresses;
        while (pCurrAddresses)
        {
            pCurrAddresses = pCurrAddresses->Next;
            ++nAddressCount;
        }

        *pszAddress = (unsigned char*)HeapAlloc(hHeap, 0x00, MAX_ADAPTER_ADDRESS_LENGTH * nAddressCount);
        pCurrAddresses = pAddresses;
        nAddressCount = 0;
        while (pCurrAddresses)
        {
            RtlCopyMemory(*pszAddress + (MAX_ADAPTER_ADDRESS_LENGTH * nAddressCount++),
                pCurrAddresses->PhysicalAddress,
                MAX_ADAPTER_ADDRESS_LENGTH);
            pCurrAddresses = pCurrAddresses->Next;
        }
    }

    if (pAddresses) {
        HeapFree(hHeap, 0x00, pAddresses);
        pAddresses = NULL;
    }
    return nAddressCount;
}