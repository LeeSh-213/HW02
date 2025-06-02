#pragma once

#include<iostream>

class Animal {
public:
	virtual void makeSound() = 0; // ���� ���� �Լ���, Animal Ŭ������ ��ӹ޴� ��� Ŭ������ �� �Լ��� �����ؾ� �մϴ�.
	virtual void move() = 0;  // ���� ���� �Լ���, Animal Ŭ������ ��ӹ޴� ��� Ŭ������ �� �Լ��� �����ؾ� �մϴ�.
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
		std::cout << "The cow move." << std::endl; // �� �ڵ����, Animal Ŭ������ ��ӹ޾� �� ������ �Ҹ��� �������� �����մϴ�.
    }
};

class Zoo {
private:
	Animal* animals[10];  // ���� ��ü�� ������ �迭�Դϴ�. �ִ� 10������ ������ ������ �� �ֽ��ϴ�.
	int animalCount = 0; // ���� ������ ���� �����ϴ� �����Դϴ�.
public:
	void addAnimal(Animal* animal) { // ������ �߰��ϴ� �Լ��Դϴ�.
		if (animalCount < 10) // ���� �迭�� ���� ���� �ʾ��� ���� �߰��մϴ�.
        {
			animals[animalCount++] = animal; // ���� �迭�� ������ �߰��ϰ�, ���� ���� ������ŵ�ϴ�.
        }
        else
        {
			std::cout << "Zoo is Full" << std::endl; // �������� ���� á�� ���� �޽��� ���
        }

    }


    
    void performActions() 
    {
		for (int i = 0; i < animalCount; i++) // ������ ����ŭ �ݺ��մϴ�.
        {
			animals[i]->makeSound(); // �� ������ �Ҹ��� ���ϴ�.
			animals[i]->move(); // �� ������ �������� ����մϴ�.
		}
    }
 

    
    ~Zoo() 
    {
        for (int i = 0; i < animalCount; i++)    
        {
			delete animals[i];  // �޸� Ȯ���� ���� new�� ������ ���� ��ü�� �����մϴ�.
        }
    }
};
