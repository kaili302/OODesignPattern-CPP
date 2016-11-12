/*
The key feature of Builder pattern is that it involves a step-by-step process to build something, i.e., every produce will follow the same process even though each step is different.
In the following example, we can define a drink builder called StarbucksBuilder which will build a Starbucks drink. StarbucksBuilder has several steps to build a Starbucks drink, such as buildSize() and buildDrink(). And finally return the drink built.

*/

#include <string>
#include <iostream>

class Starbucks{
private:
	std::string m_size;
	std::string m_drink;
public:
	Starbucks(){ }
	~Starbucks(){ }

	void setDrink(std::string drink){
		m_drink = drink;
	}

	void setSize(std::string size){
		m_size = size;
	}
};



class StarbucksBuilder{
protected:
	Starbucks* m_pStarbucks;
public:
	StarbucksBuilder(){}
	virtual ~StarbucksBuilder(){ 
		if (m_pStarbucks) delete m_pStarbucks;;
	}

	Starbucks* getStarbucks(){
		return m_pStarbucks;
	}

	void createStarbucks(){
		m_pStarbucks = new Starbucks{};
	}

	virtual void buildSize() = 0;

	virtual void buildDrink() = 0;
};


class TeaBuilder : public StarbucksBuilder{
public:
	TeaBuilder(){}

	virtual void buildSize(){
		m_pStarbucks->setSize("large");
		std::cout << "build large size " << std::endl;	
	}	

	virtual void buildDrink(){
		m_pStarbucks->setDrink("tea");	
		std::cout << "build tea" << std::endl;
	}	
};


class CoffeeBuilder : public StarbucksBuilder{
public:
	CoffeeBuilder(){}

	virtual void buildSize(){
		m_pStarbucks->setSize("medium");
		std::cout << "build medium size " << std::endl;	
	}	

	virtual void buildDrink(){
		m_pStarbucks->setDrink("coffee");	
		std::cout << "build coffee" << std::endl;
	}	
};


class Waiter{
private:
	StarbucksBuilder* m_pStarbucksBuilder;

public:
	void setStarbucksBuilder(StarbucksBuilder* pStarbucksBuilder){
		m_pStarbucksBuilder = pStarbucksBuilder;
	}

	void buildStarbucks(){
		m_pStarbucksBuilder->createStarbucks();
		m_pStarbucksBuilder->buildDrink();
		m_pStarbucksBuilder->buildSize();
	}
	
	Starbucks* getStarbucks(){
		std::cout << "Here is your starbucks drink!" << std::endl;
		return m_pStarbucksBuilder->getStarbucks();
	}
};



int main(){
	Waiter waiter;

	StarbucksBuilder* coffeeBuilder = new CoffeeBuilder{};

	waiter.setStarbucksBuilder(coffeeBuilder);
	waiter.buildStarbucks();

	waiter.getStarbucks();
}





















