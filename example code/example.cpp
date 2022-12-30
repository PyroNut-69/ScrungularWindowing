#include <iostream>
#include <Agartha/Scrungular.h> 

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, // this is the instance of the window
    HINSTANCE hPrevInstance, // this is the previous instance of the window (its useless but legacy code)
    LPSTR lpCmdLine, // i dont know
    int nCmdShow) // int for showing command line (i dont know how to make it work
{
    // the handle for the window, filled by a function in scrungular
    HWND hWnd{};
    // this struct holds information for the window class, this is needed for scrungular
    WNDCLASSEX wc{};
    // this struct holds Windows event messages for scrungular to access
    MSG msg = {0};

    // set the window with the instance and the window class thing before creatomg it
    setWindow(hInstance, wc);

    // create window with instance, window handle, showcmd thing, width, height and window title
    // you need to put funny capital L in front of string
    createWindow(hInstance, hWnd, nCmdShow, 500, 400, L"deez nuts");

    // enter game loop:
    while (true)
    {
        // call the event handler with the msg thing to get callbacks
        eventHandlerMaybeIdk(msg);
    }

    // return this part of the WM_QUIT message to Windows
    // you need this at the end for some reason i dont remember
    return msg.wParam;
}

