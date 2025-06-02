#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Animals.h"
using namespace std;

int main() {
	Dog d;
	Cat c;
	Cow co;
	Zoo zoo;

	zoo.addAnimal(new Dog());
	zoo.addAnimal(new Cat());
	zoo.addAnimal(new Cow()); // Zoo에 Dog, Cat, Cow 객체를 추가

	zoo.performActions(); 

	return 0;
}


Animal* createRandomAnimal() // 랜덤으로 Animal 객체를 생성하는 함수
{
	int r = rand() % 3; // 0, 1, 2 중 하나의 값을 랜덤으로 생성

	if (r == 0)  // 0 일시 Dog를, 1일시 Cat를, 2일시 Cow를 생성
	{
		return new Dog();			
	}
	else if (r == 1)
	{
		return new Cat();
	}
	else
	{
		return new Cow();
	}
}




