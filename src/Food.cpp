#include <iostream>
#include <string>
using namespace std;

class Food{
    private:
        string name;

    public:
    Food(){
        std::cout<<"Food no-arg constructor called!!!"<<std::endl;
        this->name = "None";
    }

    Food(string name){
        std::cout<<"Food constructor called!!!"<<std::endl;
        this->name = name;
    }

    Food(const Food &f){
        std::cout<<"Food copy constructor called!!!"<<std::endl;
        this->name = f.name;
    }

    Food& operator = (const Food& f){
        if(this == &f){
            std::cout<<"Copy assign operator is called!!!"<<std::endl;
            return *this;
        }

        this->name = f.name;

        return *this;
    }

    ~Food(){
        std::cout<<"Food destructor called!!!"<<std::endl;
    }

    void printFood(){
        std::cout<<name<<std::endl;
    }

    string getName(){
        return name;
    }

};