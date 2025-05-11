#pragma once
#include <iostream>
using namespace std; 
template <typename T>
class Resource
{
protected:
    T quantity;    
    int price; 
public:
    Resource() 
    { 
        price = 0; 
        quantity = 0; 
    }   
    void incrementQuantity(T i)
    {
        quantity += i; 
    }

    void setQuantity(T amount) 
    {
        quantity = amount;
    }
    T getQ() const
    {
        return quantity; 
    }

    virtual void consume()
    {
        --quantity; 
    }
    virtual void attain()
    {
        ++quantity; 
    }
    int getPrice()
    { 
        return price;
    }
    virtual void Display() const = 0;
};

template <typename T>
class stone : public Resource<T> {
public: 
    stone()
    {
        this->price = 35; 
    }
    void consume() override 
    {
        this->quantity -= 5;
    }
    void attain()  override 
    {
        this->quantity += 5;
    }
    void Display() const override
    {
        cout << "\n\tSTONE: " << this->quantity ;
    }
   
};

template <typename T>
class iron : public Resource<T> {
public: 
    iron()
    {
        this->price = 50;
    }
    void consume() override
    {
        this->quantity -= 3; 
    }
    void attain()  override 
    {
        this->quantity += 3; 
    }
    void Display() const override 
    {
        cout << "\n\tIRON: " << this->quantity ;
    }
    
};

template <typename T>
class wood : public Resource<T> {
public: 
    wood()
    {
        this->price = 20;
    }
   
    void consume() override 
    {
        this->quantity -= 10;
    }
    void attain()  override 
    { 
        this->quantity += 10;
    }
    void Display() const override 
    {
        cout << "\n\tWOOD: " << this->quantity ;
    }
};
