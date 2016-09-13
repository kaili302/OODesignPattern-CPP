#include <iostream>
#include <string>

class President{
private:
    static President* m_pPresident;
    President(){}
    ~President(){ 
        if (m_pPresident) delete m_pPresident;
    }

public:
    static President* getInstance(){
        if(!m_pPresident) m_pPresident = new President(); 
        return m_pPresident;
    }
    void giveOrder(){
        std::cout << "go go go!" << std::endl;
    }    
};
President* President::m_pPresident = nullptr;


class Fruit{
public:
    virtual ~Fruit(){}
    virtual void print() = 0;
};

class Apple : public Fruit{
public:
    virtual void print(){
	std::cout << "Apple" << std::endl;
    }
    
};

class Orange : public Fruit{
public:
    virtual void print(){
	std::cout << "Orange" << std::endl;
    }
};

class FruitFactory{
public: 
    static Fruit* createFruit(std::string fruit){
	if (fruit == "apple") return new Apple();
	else if (fruit == "orange") return new Orange();
    }

};

class Drink{
protected:
    int m_size;
    std::string m_flavor;
public:
    virtual void setSize() = 0;
    virtual void setFlavor() = 0;
};

class TeaDrink : public Drink{
public:
    virtual void setSize(){
	std::cout << "set tea size : medium" << std::endl;
        m_size = 10;
    }

    virtual void setFlavor(){
	std::cout << "set tea flavor : sweet" << std::endl;
    }

    virtual void print(){
	std::cout << "take you tea" << std::endl;
    }
};

class DrinkBuilder{
protected:
    Drink* p_drink;
public:
    virtual void buildDrink() = 0;
    
    virtual void buildSize() = 0;

    virtual void buildFlavor() = 0;

    virtual Drink* getDrink() = 0;
};

class TeaDrinkBuilder : public DrinkBuilder{
public:
    virtual void buildDrink() {
	p_drink = new TeaDrink();
    }

    virtual void buildSize() {
	p_drink->setSize();
    }

    virtual void buildFlavor(){
	p_drink->setFlavor();
    }

    virtual Drink* getDrink(){
	return p_drink;
   }
};

// we can also create coffee buildr...

class Waiter{
private:
    DrinkBuilder* m_pDrinkBuilder;
public:
    void setDrinkBuilder(DrinkBuilder* pDrinkBuilder) {
	m_pDrinkBuilder = pDrinkBuilder;
    }

    void createDrink(){
	m_pDrinkBuilder->buildDrink();
     	m_pDrinkBuilder->buildSize();
	m_pDrinkBuilder->buildFlavor();
    }

    Drink* serveDrink(){
	return m_pDrinkBuilder->getDrink();
    }
};

/*	bridge     */
class ITV {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void changeChanel(int chanel) = 0;
};

class AbstractRemoteController{
protected:
    ITV* m_pTV;
public:
    virtual void setTV(ITV* pTV) = 0;
    virtual void turnOnTV() = 0;
    virtual void turnOffTV() = 0;
    virtual void setChanel(int chanel) = 0;
};

class SonyTV : public ITV{
public:
    virtual void on(){
	std::cout << "Sony TV is On" << std::endl;
    }

    virtual void off(){
    	std::cout << "Sony TV is Off" << std::endl;
    }

    virtual void changeChanel(int chanel){
	std::cout << "Sony TV is set to chanel : " << chanel << std::endl;
    }
};

class LogitechRemoteController : public AbstractRemoteController{
public:
    virtual void setTV(ITV* pTV){
	m_pTV = pTV;	
    }    

    virtual void turnOnTV(){
	m_pTV->on();	
    }

    virtual void turnOffTV(){
    	m_pTV->off();
    }

    virtual void setChanel(int chanel){
	m_pTV->changeChanel(chanel);
    }
};



/* adapter  */
class Draw{
public:
    virtual void draw(){
	std::cout << "I'm drawing" << std::endl;
    }
};

class Walk{
public:
    void walk(){
	std::cout << "I'm walking" << std::endl;
    }
};

// adapt walk to draw
class DrawAdapter : public Draw{
private:
    Walk* m_pWalk;
public:
    void setWalk(Walk* pWalk){
	m_pWalk = pWalk;
    }
    
    virtual void draw(){
	m_pWalk->walk();
	std::cout << "I'm drawing" << std::endl;
    }
};


int main(){
    President::getInstance()->giveOrder();
    Fruit* pApple = FruitFactory::createFruit("apple");
    pApple->print();

    Waiter waiter; 
    DrinkBuilder* drinkBuilder = new TeaDrinkBuilder;
    waiter.setDrinkBuilder(drinkBuilder);
    waiter.createDrink();
    waiter.serveDrink();

    SonyTV sonyTV;
    LogitechRemoteController rController;
    rController.setTV(&sonyTV);
    rController.turnOnTV();
    rController.setChanel(34);
    
    Walk walk;
    DrawAdapter drawAdapter;
    drawAdapter.setWalk(&walk);
    Draw* draw = &drawAdapter;
    draw->draw();
}



