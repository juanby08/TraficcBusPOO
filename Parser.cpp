#include "Parser.h"

// Función que recibe el texto del txt y devuelve el Enum color
Color Parser::stringToColor(string colorStr) {
    if (colorStr == "GREEN") return Color::Green;
    if (colorStr == "YELLOW") return Color::Yellow;
    if (colorStr == "BLUE") return Color::Blue;
    return Color::Red; // Retorno por defecto si hay un error
}

// Función que recibe el texto de dirección y devuelve el Enum
Direction Parser::stringToDirection(string dirStr) {
    if (dirStr == "U") return Direction::Up;
    if (dirStr == "D") return Direction::Down;
    if (dirStr == "L") return Direction::Left;
    return Direction::Right; // Retorno por defecto
}