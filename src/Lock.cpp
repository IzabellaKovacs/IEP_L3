#include <iostream>
#include <memory>
#include <mutex>
#include <string>
using namespace std;

mutex mtx;

int ct;
string s;

class Lock{

    public:
    Lock(){
        mtx.lock();
        cout<<"Lock constructor called!!!"<<endl;
    }

    Lock(const Lock&) = delete;

    Lock& operator=(const Lock&) = delete;
    
    ~Lock(){
        mtx.unlock();
        cout<<"Unlock destructor called!!!"<<endl;
    }
};

void readTurn(){
    Lock l;
    ct++;  
    cout<<ct<< ": "; 
    cin>>s;
}

void printTurn()
{
    Lock l;
    cout<<s<<endl;
}

      
