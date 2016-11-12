#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

// deign a traffic light system
enum class Color{
	Green = 0,
	Red,
	Yellow
};

class TrafficLight{
protected:
	Color color;
	string name;
public:
	TrafficLight(string iname) : color{Color::Green}, name{iname}{}
	virtual void Yellow() = 0;
	virtual void Red() = 0;
	virtual void Green() = 0;
};

// up-down light and left-right light
class TrafficSystem{
protected:
	int yellowTime = 1;
	int greenTime = 5;

private:
	TrafficLight* pUDLight;
	TrafficLight* pLRLight;
	bool isUPDirected;

	void flipStatus(TrafficLight* pGreen, TrafficLight* pRed){
		pGreen->Yellow();
		keepStatus(yellowTime);
		pGreen->Red();
		pRed->Green();
	}

public:
	TrafficSystem() : isUPDirected{true}{}

	void setLights(TrafficLight* pUD, TrafficLight* pLR){
		pUDLight = pUD;
		pLRLight = pLR;
	}

	void keepStatus(int interval){
		this_thread::sleep_for(chrono::seconds(interval));
	}	

	void changeStatus(){
		if (isUPDirected){
			flipStatus(pUDLight, pLRLight);
			isUPDirected  = false;
		}else{
			flipStatus(pLRLight, pUDLight);
			isUPDirected  = true;
		}
	}

	virtual void start() = 0;
};


class MyTrafficLight : public TrafficLight{
public:
	MyTrafficLight (string iname) : TrafficLight{iname}{}
	virtual void Yellow(){
		color = Color::Yellow;
		cout << name << " status : Yellow" << endl;
	}
	virtual void Green(){
		color = Color::Green;
		cout << name << " status : Green" << endl;
	}
	virtual void Red(){
		color = Color::Red;
		cout << name << " status : Red" << endl;
	}
};

class MyTrafficSystem : public TrafficSystem{
public:
	MyTrafficSystem() : TrafficSystem{}{}
	virtual void start(){
		while (true){
			changeStatus();
			keepStatus(greenTime);
			cout << "I'm changing status now " << endl;
		}
	}
};

int main(){
	MyTrafficSystem ts;
	MyTrafficLight tl1{"up-down"};
	MyTrafficLight tl2{"left-right"};
	ts.setLights(&tl1, &tl2);
	ts.start();
}

