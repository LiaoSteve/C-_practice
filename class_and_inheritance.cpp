#include <iostream>
#include <vector>
//--- reference: https://www.youtube.com/watch?v=wN0x9eZLix4
class Employee
{
    private:

    protected:
        std::string name;
        std::string company;
        int age;
        
    public:
        Employee(std::string Name, std::string Company, int Age)
        {
            name = Name;
            company = Company;
            age = Age;
            printf("%s, %s, %d\n", name.c_str(), company.c_str(), age);
        }
        virtual void work()=0;
};

class Sales: public Employee
{
    private:
        std::string product;

    public:
        Sales(std::string Name, std::string Company, int Age, std::string Product)
            :Employee(Name, Company, Age)
        {
            product = Product;
        }
        void work()
        {
            printf("%s sell %s\n", name.c_str(), product.c_str());
        }
    
};

class Coder: public Employee
{
    private:
        std::string language;
        
    public:
        
        Coder(std::string Name, std::string Company, int Age, std::string Language)
            :Employee(Name, Company, Age)
        {
            language = Language;
        }
        void work()
        {
            printf("%s coding %s\n", name.c_str(), language.c_str());
        }
    
};

int main()
{
    // Employee e = Employee("steve", "google", 25);
    // Sales s = Sales("steve", "google", 25, "computer");
    // Coder c = Coder("steve", "google", 25, "c++");
    std::vector<Employee*> employees;
    employees.push_back(new Sales("kent", "pchome", 22, "computer"));
    employees.push_back(new Coder("steve", "google", 25, "c++"));

    for (auto& employee : employees)
    {
        employee->work();
    }
    return 0;
}