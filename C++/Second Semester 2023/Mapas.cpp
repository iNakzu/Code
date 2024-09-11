#include <iostream>
#include <map> // <llave, valor> || <clave, contenido>

int main()
{
    std::map<std::string, int> mapa;

    mapa["Ignacio"] = 18;
    mapa["Matias"] = 13;
    mapa["Jorge"] = 51;
    mapa["Francisca"] = 19;
    mapa["Gabriel"] = 22;

    // std::cout << mapa["Ignacio"] << std::endl;
    // std::cout << mapa["Matias"] << std::endl;
    // std::cout << mapa["Jorge"] << std::endl;

    for (std::map<std::string, int>::iterator it = mapa.begin(); it != mapa.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    if (mapa.find("Ignacio") != mapa.end())
    {
        std::cout << "La llave existe dentro del mapa" << std::endl;
    }
    else
    {
        std::cout << "La llave no existe dentro del mapa" << std::endl;
    }
}