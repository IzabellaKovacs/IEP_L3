#include <iostream>
#include <string>
using namespace std;

class Hedgehog{
    protected:
        string name;
        int age;

    public:
    Hedgehog(){        
        cout<<"Hedgehog no-arg constructor called!!!"<<endl;
        this->name = "None";
        this->age = 0;
    }

    Hedgehog(string name, int age){
        cout<<"Hedgehog constructor called!!!"<<endl;
        this->name = name;
        this->age = age;
    }

    Hedgehog(const Hedgehog &a){
        cout<<"Hedgehog copy constructor called!!!"<<endl;
        this->name = a.name;
        this->age = a.age;
    }

    ~Hedgehog(){
        cout<<"Hedgehog destructor called!!!"<<endl;
    }

    string printHedgehog(){
        return name + " " + std::to_string(age);
    }
};