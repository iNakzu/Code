#include <iostream>
using std::string;

class abstract_employee
{
    virtual void ask_for_promotion() = 0;
};

class employee : abstract_employee
{
    string company; // Las clases vienen por default en private
    int age;

protected:
    string name;

public:
    void set_name(string name) // Setter
    {
        this->name = name;
    }
    string get_name() // Getter
    {
        return name;
    }
    void set_company(string company)
    {
        this->company = company;
    }
    string get_company()
    {
        return company;
    }
    void set_age(int age)
    {
        if (age >= 18)
            this->age = age;
    }
    int get_age()
    {
        return age;
    }

    void introduce_yourself() // Funcion para presentarse
    {
        std::cout << "Hello my name is " << name << std::endl;
        std::cout << "I work in " << company << std::endl;
        std::cout << "I am " << age << " years old" << std::endl;
    }
    employee(string name, string company, int age)
    {
        this->name = name;
        this->company = company;
        this->age = age;
    }
    void ask_for_promotion()
    {
        if (age > 30)
        {
            std::cout << name << " got promoted!" << std::endl;
        }
        else
        {
            std::cout << "Sorry " << name << ", not promotion for u" << std::endl;
        }
    };
    virtual void work()
    {
        std::cout << name << " is checking email, task backlog, perfoming task..." << std::endl;
    };
};

class developer : public employee
{
public:
    string fav_programming_language;
    developer(string name, string company, int age, string language) : employee(name, company, age)
    {
        fav_programming_language = language;
    }
    void fix_bug()
    {
        std::cout << name << " fixed bug using " << fav_programming_language << std::endl;
    }
    void work()
    {
        std::cout << name << " is writing " << fav_programming_language << std::endl;
    };
};

class teacher : public employee
{
public:
    string subject;
    void prepare_lesson()
    {
        std::cout << name << " is preparing the " << subject << " lesson" << std::endl;
    }
    teacher(string name, string company, int age, string subject) : employee(name, company, age)
    {
        this->subject = subject;
    }
    void work()
    {
        std::cout << name << " is teaching " << subject << std::endl;
    };
};

int main()
{
    developer d1 = developer("Ignacio", "YT", 18, "C++");
    teacher t1 = teacher("Jack", "School", 35, "History");
    employee *e1 = &d1;
    e1->work();
}