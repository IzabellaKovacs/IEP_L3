#include "src/Baby_hedgehog.cpp"

#include <iostream>
#include <memory>
#include <thread>
using namespace std;

void start_mutex(){
    thread t1(readSmh);
    thread t2(readSmh);
    thread t3(readSmh);
  
    t1.join();
    t2.join();
    t3.join();
}

void declareMom(){
    Hedgehog hedgie("Pokee", 3);
    cout<<hedgie.printHedgehog()<<endl;
}

void unique_pointer(){
    declareMom();
    Baby_hedgehog baby("Mike", 2, "male");
    Food *food = new Food("Boiled eggs");
    baby.eat(food);

    cout<<endl;

    Baby_hedgehog baby2("Milky-Way", 0, "female");
    Food *food2 = new Food("Boiled eggs");
    baby.stole(food2, &baby2);
}

void shared_pointer(){
    shared_ptr<Food> food = make_shared<Food>("salami");

    {
        shared_ptr<Food> food2 = make_shared<Food>();
        food2 = food;

        shared_ptr<Food> food3(food);

        cout<<food.use_count()<<" hedgies are eating " <<food2.get()->getName()<<endl;
    }
}

int main(){
   unique_pointer();
   cout<<endl;
   shared_pointer();
   cout<<endl;
   start_mutex();

   return 0;
}