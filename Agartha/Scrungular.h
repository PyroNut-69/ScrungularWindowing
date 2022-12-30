#pragma once
#include <windows.h>
#include <windowsx.h>
// i unironically have no clue how this is working, but it is rn

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int setWindow(HINSTANCE hInstance, WNDCLASSEX wc);

void createWindow(HINSTANCE lhInstance, HWND hWnd, int lnCmdShow, int width, int height, const wchar_t name[]);

void eventHandlerMaybeIdk(MSG msg);


// i dont think this is anything
/* stupid
int makeWindow(int W, int H, bool isItWidthBecauseIfItIsMakeItZeroOrFalse)
{
    int WH[2] = {W, H};
    if (isItWidthBecauseIfItIsMakeItZeroOrFalse == 0)
        return WH[0];
    else
        return H;
}
*/
