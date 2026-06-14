//#include "Game.h"
#include "CGame.h"
#include <iostream>

using namespace std;

// Constructor
CGame::CGame(MGame* level, VGame* display)
    : win(false), level(level), display(display) {}

// Obtener el handle de la consola para leer eventos de teclado
HANDLE CGame::getConsoleHandle() const {
    HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    if (consoleInputHandle == INVALID_HANDLE_VALUE) {
        return consoleInputHandle;
    }
    
    // Obtener el modo actual de la consola
    DWORD consoleMode = 0;
    if (!GetConsoleMode(consoleInputHandle, &consoleMode)) { 
        return consoleInputHandle;
    }

    // Deshabilitar entrada por línea y eco, habilitar eventos de ventana/ratón
    consoleMode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    consoleMode |= (ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    SetConsoleMode(consoleInputHandle, consoleMode);

    return consoleInputHandle;
}

// Leer teclado y retornar string
string CGame::readUserInput() const {
    HANDLE consoleInputHandle = getConsoleHandle(); 
    INPUT_RECORD inputRecord; 
    DWORD eventsRead;

    while (true) {
        // Leer un evento de la consola
        ReadConsoleInput(consoleInputHandle, &inputRecord, 1, &eventsRead);

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {

            // Se extrae el código de la tecla y se convierte en texto
            WORD virtualKeyCode = inputRecord.Event.KeyEvent.wVirtualKeyCode;
            switch (virtualKeyCode) {
                case VK_UP: return "UP";
                case VK_DOWN: return "DOWN";
                case VK_LEFT: return "LEFT";
                case VK_RIGHT: return "RIGHT";
                case VK_SPACE: return "SPACE";
                case VK_ESCAPE: return "ESC";
                case VK_RETURN: return "ENTER"; 
            }
        }
    }
    return "";
}

void CGame::play() {
    // usar 'auto&' cuando se recorre los vectores.
}

// Verificar si un vehículo sube pasajeros en la parada
bool CGame::boarding() {
    return false;
}


