#include <iostream>
#include <string>

class Producto
{
protected:
    std::string nombre;
    int precio;
    std::string marca;
    int cantidad;

public:
    Producto(std::string nombre, int precio, std::string marca, int cantidad)
    {
        this->nombre = nombre;
        this->precio = precio;
        this->marca = marca;
        this->cantidad = cantidad;
    }
    void set_cantidad(int cantidad)
    {
        this->cantidad = cantidad;
    }
    std::string get_nombre()
    {
        return nombre;
    }
    int get_precio()
    {
        return precio;
    }
    std::string get_marca()
    {
        return marca;
    }
    int get_cantidad()
    {
        return cantidad;
    }
};

class Snacks : public Producto
{
private:
    int sellos;

public:
    Snacks(std::string nombre, int precio, std::string marca, int cantidad, int sellos) : Producto(nombre, precio, marca, cantidad)
    {
        this->sellos = sellos;
    }
};

class Masas : public Producto
{
protected:
    float cantidad_harina;

public:
    Masas(std::string nombre, int precio, std::string marca, int cantidad, float cantidad_harina) : Producto(nombre, precio, marca, cantidad)
    {
        this->cantidad_harina = cantidad_harina;
    }
};

class Dulces : public Producto
{
private:
    std::string sabor;

public:
    Dulces(std::string nombre, int precio, std::string marca, int cantidad, float sabor) : Producto(nombre, precio, marca, cantidad)
    {
        this->sabor = sabor;
    }
};

class Pan : public Masas
{
private:
    float cantidad_sodio;

public:
    Pan(std::string nombre, int precio, std::string marca, int cantidad, float cantidad_harina, float cantidad_sodio) : Masas(nombre, precio, marca, cantidad, cantidad_harina)
    {
        this->cantidad_sodio = cantidad_sodio;
    }
};

class Queque : public Masas
{
private:
    float cantidad_azucar;
    int chips_chocolate;

public:
    Queque(std::string nombre, int precio, std::string marca, int cantidad, float cantidad_harina, float cantidad_azucar, float chips_chocolate) : Masas(nombre, precio, marca, cantidad, cantidad_harina)
    {
        this->cantidad_azucar = cantidad_azucar;
        this->chips_chocolate = chips_chocolate;
    }
};

class Almacen
{
private:
    Producto *productos[50];

public:
    Almacen()
    {
        for (int i = 0; i < 50; i++)
        {
            productos[i] = nullptr;
        }
    }
    void agregar_producto(Producto &x)
    {
        for (int i = 0; i < 50; i++)
        {
            if (productos[i] == nullptr)
            {
                productos[i] = &x;
                break; // Me falto esto en el lab
            }
            else
            {
                std::cout << "El almacen esta lleno" << std::endl;
            }
        }
    }
    int total_ganancias()
    {
        int suma_total_ganancias = 0;
        for (int i = 0; i < 50; i++)
        {
            if (productos[i] != nullptr)
            {
                suma_total_ganancias += productos[i]->get_precio();
            }
        }
        return suma_total_ganancias;
    }
    int total_productos()
    {
        int suma_total_productos = 0;
        for (int i = 0; i < 50; i++)
        {
            if (productos[i] != nullptr)
            {
                suma_total_productos++;
            }
        }
        return suma_total_productos;
    }
    void encontrar_producto(std::string nombre_producto)
    {
        bool encontrado = false; // Variable para rastrear si se encontró el producto.

        for (int i = 0; i < 50; i++)
        {
            if (productos[i] != nullptr && productos[i]->get_nombre() == nombre_producto)
            { //
                // Si encontramos el producto, mostramos su información.
                std::cout << "El producto se encuentra en el almacen" << std::endl;
                std::cout << "Nombre de producto: " << productos[i]->get_nombre() << std::endl;
                std::cout << "Precio del producto: " << productos[i]->get_precio() << std::endl;
                std::cout << "Marca del producto: " << productos[i]->get_marca() << std::endl;
                std::cout << "Cantidad que hay del producto: " << productos[i]->get_cantidad() << std::endl;

                encontrado = true; // Marcamos que hemos encontrado el producto.
                break;             // Salimos del bucle, ya que no es necesario buscar más.
            }
        }

        if (!encontrado)
        {
            // Si no se encontró el producto después de recorrer todo el almacén.
            std::cout << "Producto no encontrado en el almacen" << std::endl;
        }
    }

    void eliminar_producto(int posicion)
    {
        productos[posicion] = nullptr;
    }
    void actualizar_producto(int posicion, int cantidad)
    {
        productos[posicion]->set_cantidad(cantidad);
    }
};

int main()
{
    std::cout << "-" << std::endl;
}