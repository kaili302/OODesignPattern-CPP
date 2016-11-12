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
    virtual void print() = 0;
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






class ITV{
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void setChanel(int chanel) = 0;
    virtual string toString() = 0;
};

class AbstractController{
protected:
    ITV* m_pTV;
public:
    virtual void setTV(ITV* pTV) = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void change(int chanel) = 0;
};


class SonyTV : public ITV{
public:
    virtual void on(){
        cout << "sony TV is ON" << endl;
    }
    virtual void off(){
        cout << "sony TV is OFF" << endl;
    }
    virtual void setChanel(int chanel){
        cout << "sony TV, set chanel : " << chanel << endl;
    }
    virtual string toString(){
        return "Sony TV";
    }
};

class XiaomiTV : public ITV{
public:
    virtual void on(){
        cout << "Xiaomi TV is ON" << endl;
    }
    virtual void off(){
        cout << "Xiaomi TV is OFF" << endl;
    }
    virtual void setChanel(int chanel){
        cout << "Xiaomi TV, set chanel : " << chanel << endl;
    }  
    virtual string toString(){
        return "Xiaomi TV";
    }
};


class LogitechController : public AbstractController{
public:
    virtual void setTV(ITV* pTV) { 
        cout << "Logitech Controller matches " << pTV->toString() << endl;
        m_pTV = pTV;
    }
    virtual void turnOn(){
        m_pTV->on();
    }
    virtual void turnOff(){
        m_pTV->off();
    }
    virtual void change(int chanel) {
        m_pTV->setChanel(chanel);
    }
};

class AppleController : public AbstractController{
public:
    virtual void setTV(ITV* pTV) { 
        cout << "Apple Controller matches " << pTV->toString() << endl;
        m_pTV = pTV;
    }
    virtual void turnOn(){
        m_pTV->on();
    }
    virtual void turnOff(){
        m_pTV->off();
    }
    virtual void change(int chanel) {
        m_pTV->setChanel(chanel);
    }
};



