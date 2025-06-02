#pragma once

#include<iostream>

class Animal {
public:
	virtual void makeSound() = 0; // 순수 가상 함수로, Animal 클래스를 상속받는 모든 클래스는 이 함수를 구현해야 합니다.
	virtual void move() = 0;  // 순수 가상 함수로, Animal 클래스를 상속받는 모든 클래스는 이 함수를 구현해야 합니다.
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
		std::cout << "The cow move." << std::endl; // 위 코드들은, Animal 클래스를 상속받아 각 동물의 소리와 움직임을 구현합니다.
    }
};

class Zoo {
private:
	Animal* animals[10];  // 동물 객체를 저장할 배열입니다. 최대 10마리의 동물을 저장할 수 있습니다.
	int animalCount = 0; // 현재 동물의 수를 저장하는 변수입니다.
public:
	void addAnimal(Animal* animal) { // 동물을 추가하는 함수입니다.
		if (animalCount < 10) // 동물 배열이 가득 차지 않았을 때만 추가합니다.
        {
			animals[animalCount++] = animal; // 동물 배열에 동물을 추가하고, 동물 수를 증가시킵니다.
        }
        else
        {
			std::cout << "Zoo is Full" << std::endl; // 동물원이 가득 찼을 때의 메시지 출력
        }

    }


    
    void performActions() 
    {
		for (int i = 0; i < animalCount; i++) // 동물의 수만큼 반복합니다.
        {
			animals[i]->makeSound(); // 각 동물의 소리를 냅니다.
			animals[i]->move(); // 각 동물의 움직임을 출력합니다.
		}
    }
 

    
    ~Zoo() 
    {
        for (int i = 0; i < animalCount; i++)    
        {
			delete animals[i];  // 메모리 확보를 위해 new로 생성된 동물 객체를 해제합니다.
        }
    }
};
