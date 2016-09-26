/*
Factory design pattern is used for creating an object based on different parameters. 
The example below is about creating juice in a factory. If we ask the factory for orange juice, the factory will produce orange juice; 
if we ask for apple juice, the factory will produce apple juice. Based on different parameters, the factory produce different stuff.
*/


#include <string>
#include <iostream>

class Juice{
public:
	Juice(){}
	virtual ~Juice(){}
	virtual void print() = 0;
};


class AppleJuice : public Juice{
public:
	AppleJuice(){}

	virtual void print(); 
};
void AppleJuice::print(){
	std::cout << "Apple Juice!" << std::endl;
}



class OrangeJuice : public Juice {
public:
	OrangeJuice(){}

	virtual void print(); 
};
void OrangeJuice::print(){
	std::cout << "Orange Juice!" << std::endl;	
}



class JuiceFactory{
private:
	static JuiceFactory* m_pFactory;
	JuiceFactory(){}
	~JuiceFactory(){
		if(m_pFactory) delete m_pFactory;
	}

public:
	static JuiceFactory* instance();
	Juice* makeJuice(std::string fruit);
};

JuiceFactory* JuiceFactory::m_pFactory = nullptr;

JuiceFactory* JuiceFactory::instance(){
	if (!m_pFactory) m_pFactory = new JuiceFactory{};
	return m_pFactory;
}

Juice* JuiceFactory::makeJuice(std::string fruit){
	if (fruit == "apple") {
		return new AppleJuice();
	}else if (fruit == "orange"){
		return new OrangeJuice();
	}else {
		return nullptr;
	}
}


int main(){
	// make orane juice
	Juice* pOrangeJuice = JuiceFactory::instance()->makeJuice("orange");
	Juice* pAppleJuice  = JuiceFactory::instance()->makeJuice("apple"); 

	pOrangeJuice->print();
	pAppleJuice->print();	

	delete pOrangeJuice;
	delete pAppleJuice;
}



























