#include "MGame.h"
#include "VGame.h"
#include "CGame.h"
#include <iostream>
#include <string>
#include <conio.h>

int main() {
    bool exit = false;

    while(!exit){
        system("cls");
        VGame* display = new VGame();

        //Display Welcome Message
        display ->DisplayText("=======================================\n");
        display ->DisplayText("           -BUS PARKING GAME-          \n");
        display ->DisplayText("=======================================\n");
        display ->DisplayText("Selecciona un nivel (1, 2, 3) o 'Q' para salir:");

        char menuInput;
        std::cin >> menuInput;

        // WIN = 1, LOSE = 2, RESTART = 3, QUIT = 4, PLAYING = 5

        // Check menuInput
        if(tolower(menuInput) == 'q') {
            exit = true;
            continue;
        }

        // Check if menuInput is a number:
        if (menuInput >= '1' && menuInput <= '3') {
            int levelId = menuInput - '0';
            // Create string to access level
            std::string levelFile = "Level" + std::to_string(levelId) + ".txt";

            bool playing = true;
            while (playing){

                MGame* model = new MGame(levelId);
                model->loadLevel(levelFile);
                CGame controller(model, display);

                // Call play method an wait for the return value

                int result = controller.play();

                // Check if retulr value quits, restarts, wins or loses the game

                if (result == 4){
                    playing = false;
                    exit = true;
                }

                // To restart the level we continue with the loop, it will delete model and recreate from text file.
                else if (result == 3){}

                // check for win/lose condition
                else if (result == 1 || result == 2){
                    display->DisplayText("\nPresiona 'M' volver al menu\n");
                    char temp;
                    temp = _getch();
                    playing = false;
                }

                delete model;
            }

        }
        else {
            display->DisplayText("Nivel no valido, selecciona una opcion diferente: 1- Facil || 2- Medio || 3- Dificil");
            display->DisplayText("\nPresiona cualquier tecla para volver al menu\n");
            char temp;
            temp = _getch();
        }

    }
    return 0;
}