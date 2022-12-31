/*
    SCRUNGULAR - built in agartha

    this is supposed to be a scuffed way of gaining window creation capabilities
    through win32, to be used with directx, although you could probably somehow
    use other api's like opengl or vulkan but this will most likely stay Windows only
    unless i start taking fentanyl. this is the worst win32 wrapper library there
    will ever be amd that is an achievement in my eyes.

    i dont know what im doing

    - DestinyDonut
*/
// when giving distributing library change the include to the one below instead of "Scrungular.h"
#include <Agartha/Scrungular.h> 

// this is used for dev reasons
//#include "Scrungular.h"
//#include <d3d9.h>

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch (message)
    {
        // this message is read when the window is closed
    case WM_DESTROY:
    {
        // close the application entirely
        PostQuitMessage(0);
        return 0;
    } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}


int setWindow(HINSTANCE hInstance, WNDCLASSEX wc)
{
    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = L"WindowClass1";

    // register the window class
    RegisterClassEx(&wc);
    return 0;
    // TODO: if no worky -> make program fail
}


// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam);

void createWindow(HINSTANCE lhInstance, HWND hWnd, int lnCmdShow, int width, int height, const wchar_t name[])
{
    // create the window and use the result as the handle
    hWnd = CreateWindowEx(NULL,
        L"WindowClass1",    // name of the window class
        name,   // title of the window
        WS_OVERLAPPEDWINDOW,    // window style
        600,    // x-position of the window
        300,    // y-position of the window
        width,    // width of the window
        height,    // height of the window
        NULL,    // we have no parent window, NULL
        NULL,    // we aren't using menus, NULL
        lhInstance,    // application handle
        NULL);    // used with multiple windows, NULL

    // display the window on the screen
    ShowWindow(hWnd, lnCmdShow);
}

void eventHandlerMaybeIdk(MSG msg)
{
    while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        // Translate the message and dispatch it to WindowProc()
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        // exit program if user presses x
        if (msg.message == WM_QUIT)
            exit(-1);
    } 
}