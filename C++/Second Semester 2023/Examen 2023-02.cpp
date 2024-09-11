/*
Pregunta 1 (30 puntos)
Los profesores de la escuela de Informática dejan distintos tipos de caramelos (bombones, calugas,
media hora, etc.) en un frasco comunitarlo. El frasco es mágico: sólo puede sacarse de un caramelo
a la vez y siempre el último que se puso en el frasco. Cada lunes los profesores agregan dulces al frasco comunitario.
En base a lo anterior se pide:

a) (2 pts) Programe la estructura (definición y atributos) de la clase Frasco que tiene un
atributo stack<string> caramelos donde cada elemento representa el nombre del caramelo correspondiente.

b) (15 pts) Programe el método map<string, int> que_tiene_el_frasco(), que devuelve un map cuya llave es el nombre del
caramelo y su contenido la cantidad de dicho caramelo que hay en el frasco. Al terminar
este método, el stack<string> caramelos debe quedar igual que al inicio.

c) (10 pts) Programe el método map<string, int> anadir_caramelos(queue<string> caramelos), que recibe en una cola la
lista de caramelos que un profesor añade al frasco. El método devuelve un map como él
descrito en el punto (b), pero sólo para los caramelos que acaban de ser añadidos.

d) (3 pts) Programe el método string sacar_caramelo(), que saca un caramelo del frasco y devuelve el nombre del
caramelo que se obtuvo.
*/

#include <iostream>
#include <stack>

class Frasco
{
private:
    std::stack<std::string> caramelos;
};