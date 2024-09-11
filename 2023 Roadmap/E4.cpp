#include <iostream>
#include <string>

int main()
{
    // Crear una cadena
    std::string str = "Hello, World!";

    // Acceso a caracteres específicos
    char first_char = str[0];             // 'H'
    char last_char = str[str.size() - 1]; // '!'

    // Subcadenas
    std::string sub_str = str.substr(0, 5); // "Hello"

    // Longitud
    size_t len = str.length(); // 13

    // Concatenación
    std::string str2 = str + " How are you?"; // "Hello, World! How are you?"

    // Repetición
    std::string repeated_str = std::string(5, 'a'); // "aaaaa"

    // Recorrido
    for (char c : str)
    {
        std::cout << c << '\n';
    }

    // Conversión a mayúsculas
    for (char &c : str)
    {
        c = toupper(c);
    }

    // Conversión a minúsculas
    for (char &c : str)
    {
        c = tolower(c);
    }

    // Reemplazo
    size_t pos = str.find("World");
    if (pos != std::string::npos)
    {
        str.replace(pos, 5, "Universe"); // "Hello, Universe!"
    }

    // División (splitting) - C++ no tiene una función incorporada para esto, pero puedes usar std::getline o escribir tu propia función

    // Unión (joining) - C++ no tiene una función incorporada para esto, pero puedes usar un bucle for y concatenación

    // Interpolación - C++ no tiene una función incorporada para esto, pero puedes usar std::ostringstream

    // Verificación
    if (str == "Hello, World!")
    {
        std::cout << "The strings are equal.\n";
    }
    else
    {
        std::cout << "The strings are not equal.\n";
    }

    return 0;
}