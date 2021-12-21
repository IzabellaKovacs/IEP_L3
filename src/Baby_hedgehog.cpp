#include "Hedgehog.cpp"
#include "Food.cpp"
#include "Lock.cpp"

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <mutex>
using namespace std;

class Baby_hedgehog : public Hedgehog{
    private:
        string gender;
        vector<Food> foods;

    public:
    Baby_hedgehog(){
        std::cout<<"Baby_hedgehog no-arg constructor called!!!"<<std::endl;
        this->gender = "None";
        this->foods = {};
    }

    Baby_hedgehog(string name, int age, string gender) : Hedgehog(name, age){
        std::cout<<"Baby_hedgehog constructor called!!!"<<std::endl;
        this->gender = gender;
    }

    Baby_hedgehog(const Baby_hedgehog &h) : Hedgehog(h){
        std::cout<<"Animal copy constructor called!!!"<<std::endl;
        this->gender = h.gender;
        this->foods = h.foods;
    }

    Baby_hedgehog& operator = (const Baby_hedgehog& h){
        if(this == &h){
            std::cout<<"Copy assign operator is called!!!"<<std::endl;
            return *this;
        }

        this->name = h.name;
        this->age = h.age;
        this->gender = h.gender;
        this->foods = h.foods;

        return *this;
    }

    ~Baby_hedgehog(){
        std::cout<<"Baby_hedgehog destructor called!!!"<<std::endl;
        foods.clear();
    }

    void addFood(Food &food){
        foods.push_back(food);
    }

    void printBabies(){
        cout<<name<<" who has "<<age<<" years old wich gender is "<<gender<<", is eating: ";

        for(Food f:foods){
            cout<<"- "<< f.getName()<<endl;
        }
    }
    string getName(){
        return name;
    }

    void eat(Food *f){
        unique_ptr<Food> food(f);
        std::cout<<this->name<<" eats "<<food->getName()<<std::endl;
    }

    void stole(Food *f, Baby_hedgehog *h){
        unique_ptr<Food> food(f);
        std::cout<<this->name<<" eats "<<food->getName()<<std::endl;

        unique_ptr<Food> food1 = move(food);
        std::cout<<this->name<<" food was stolen by "<<h->getName()<<std::endl;
        std::cout<<h->getName()<< "eats now "<<food1.get()->getName()<<std::endl;
    }


};