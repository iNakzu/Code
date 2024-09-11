#include <iostream>
#include <vector>

class Contact
{
private:
    std::string name;
    std::string phone;

public:
    Contact(std::string name, std::string phone)
    {
        this->name = name;
        this->phone = phone;
    }
    std::string get_name()
    {
        return name;
    }
};

class Agenda
{
private:
    std::vector<Contact *> contacts;

public:
    void search_contact(std::string name)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i]->get_name() == name)
            {
                std::cout << "El contacto se encuentra en la agenda" << std::endl;
                break;
            }
        }
        std::cout << "El contacto no se encuentra en la agenda" << std::endl;
    }
    void add_contact(Contact *contact)
    {
        contacts.push_back(contact);
        std::cout << "Contacto agregado con exito" << std::endl;
    }
    void delete_contact(std::string name)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i]->get_name() == name)
            {
                contacts.erase(contacts.begin() + i);
                std::cout << "El contacto se ha eliminado con exito" << std::endl;
                break;
            }
        }
        std::cout << "El contacto no se encuentra en la agenda" << std::endl;
    }
};

int main()
{
    Agenda *agenda = new Agenda();

    int option;
    bool mostrar_menu = true;
    std::cout << "----|Agenda de Contactos|----" << std::endl;
    do
    {
        if (mostrar_menu)
        {
            std::cout << "0.- Salir" << std::endl;
            std::cout << "1.- Busqueda de un contacto" << std::endl;
            std::cout << "2.- Insercion de un contacto" << std::endl;
            std::cout << "3.- Actualizacion de un contacto" << std::endl;
            std::cout << "4.- Eliminacion de un contacto" << std::endl;
        }
        std::cout << "Digite la opcion que necesite -> ";
        std::cin >> option;
        if (option == 1)
        {
            std::string name;
            std::cout << "Cual es el nombre que desea buscar: ";
            std::cin >> name;
            agenda->search_contact(name);
            mostrar_menu = false;
        }
        else if (option == 2)
        {
            std::string name;
            std::string phone;
            std::cout << "Cual es el nombre que desea agregar: ";
            std::cin >> name;
            do
            {
                std::cout << "Cual es el telefono que desea agregar (11 digitos): ";
                std::cin >> phone;
            } while (phone.length() != 11);
            agenda->add_contact(new Contact(name, phone));
            mostrar_menu = false;
        }
        else if (option == 3)
        {
            std::string name;
            std::string phone;
            std::cout << "Cual es el nombre que desea actualizar: ";
            std::cin >> name;
            do
            {
                std::cout << "Cual es el telefono que desea actualizar (11 digitos): ";
                std::cin >> phone;
            } while (phone.length() != 11);
            agenda->delete_contact(name);
            agenda->add_contact(new Contact(name, phone));
            mostrar_menu = false;
        }
        else if (option == 4)
        {
            std::string name;
            std::cout << "Cual es el nombre que desea eliminar: ";
            std::cin >> name;
            agenda->delete_contact(name);
            mostrar_menu = false;
        }
        else if (option == 0)
        {
            std::cout << "Gracias por usar la agenda" << std::endl;
        }
        else
        {
            std::cout << "Opcion no valida" << std::endl;
            mostrar_menu = true;
        }
    } while (option != 0);
}
