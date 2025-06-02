#pragma once

#include<iostream>

class Animal {
public:
	virtual void makeSound() = 0; // 순수 가상 함수, Animal 클래스는 추상 클래스입니다.
	virtual void move() = 0; // 순수 가상 함수, Animal 클래스는 추상 클래스입니다.

};

class Dog : public Animal {
    public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
    void move() override {
        std::cout << "The dog move." << std::endl;
    }
};

class Cat : public Animal {
    public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
    void move() override {
        std::cout << "The cat move." << std::endl;
    }
};

class Cow : public Animal {
    public:
    void makeSound() override {
        std::cout << "Moo!" << std::endl;
    }
    void move() override {
        std::cout << "The cow move." << std::endl;
    }
};

class Zoo {
private:
    Animal* animals[10]; 
    int animalCount = 0;
public:
    void addAnimal(Animal* animal) {
        if (animalCount < 10)
        {
			animals[animalCount++] = animal;
        }
        else
        {
            std::cout << "Zoo is Full" << std::endl;
        }

    }


    
    void performActions() 
    {
        for (int i = 0; i < animalCount; i++)
        {
            animals[i]->makeSound();
            animals[i]->move();
		}
    }
 

    
    ~Zoo() 
    {
        for (int i = 0; i < animalCount; i++)
        {
            delete animals[i];
        }
    }
};
