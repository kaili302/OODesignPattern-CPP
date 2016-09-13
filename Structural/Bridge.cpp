/*
Bridge is one of my favorist oo design pattern. A really good example of abstraction :)

In brief, Bridge Design Pattern is a two layer abstraction.
The bridge pattern is meant to "decouple an abstraction from its implementation so that the two can vary independently". 
The bridge uses encapsulation, aggregation, and can use inheritance to separate responsibilities into different classes.

1. Bridge pattern story
The example of TV and Remote Control can demonstrate the two layers of abstraction. 
You have an interface for TV and an abstract class for remote control. 
As you know, it is not a good idea to make a concrete class for either of them, 
because other vendors may make different implementations.
*/

/*	bridge     */
#include <iostream>

class ITV {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void changeChanel(int chanel) = 0;
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

class SamsumgTV : public ITV{
public:
	virtual void on(){
		std::cout << "Samsumg TV is On" << std::endl;
    }

    virtual void off(){
    	std::cout << "Samsumg TV is Off" << std::endl;
    }

    virtual void changeChanel(int chanel){
		std::cout << "Samsumg TV is set to chanel : " << chanel << std::endl;
    }


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

int main(){
	SonyTV sonyTV;
	SamsumgTV samsumgTV;

	LogitechRemoteController remoteController;

	// pair to Sony TV
	remoteController.setTV(&sonyTV);
	remoteController.turnOnTV();
	remoteController.turnOffTV();

	// pair to Samsumg TV
	remoteController.setTV(&samsumgTV);
	remoteController.turnOnTV();
	remoteController.setChanel(32);
	remoteController.turnOffTV();
}




