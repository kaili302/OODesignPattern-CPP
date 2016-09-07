/*
Singleton.cpp
Singleton pattern is one of the most commonly used patterns. It is used to control the number of objects created by preventing external instantiation and modification. 
This concept can be generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects, such as:
1. private constructor - no other class can instantiate a new object.
2. private reference - no external modification.
3. public static method is the only place that can get an object.


The Story for Singleton
Here is a simple use case. A country can have only one president. So whenever a president is needed, the only president should be returned 
instead of creating a new one. The getPresident() method will make sure there is always only one president created.
*/
#include <iostream>
#include <string>

/** .hpp */
class President{
private:
	static President m_president;
	President () {}

public:
	static President& getPresident();

	void giveOrder();
};

/* .cpp */
President President::m_president{};

President& President::getPresident(){
	return m_president;
}

void President::giveOrder(){
	std::cout << "Protect our country!" << std::endl;
}



/* main */
int main(){
	President::getPresident().giveOrder();
}



