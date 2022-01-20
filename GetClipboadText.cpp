// Get clipboard text data and put on stdout
// 
// @guyrllech 2022/01/20
//

#include <iostream>
#include <windows.h>

int main()
{
    if (OpenClipboard(NULL))
    {
        HANDLE hClipboardData = GetClipboardData(CF_TEXT);
        if (hClipboardData)
        {
            LPCSTR lpClipboardData = (LPCSTR)GlobalLock(hClipboardData);
            if (lpClipboardData)
            {
                std::wcout << lpClipboardData;
                GlobalUnlock(hClipboardData);
            }
        }
        CloseClipboard();
    }
    else
    {
        DWORD dwError = GetLastError();
        std::wcerr << "Failed to open clipboard : " << dwError;
    }
}
