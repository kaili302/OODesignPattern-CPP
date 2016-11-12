#include <queue>
using namespace std;
enum class Status{
	idle = 0,
	up,
	down
};

class Elevator{
private:
	int m_currFloor;
	Status m_status;

public:
	void moveUp { 
		m_currFloor++;
	}

	void moveDown { 
		m_currFloor--;
	}

	void moveTo(int floor){
		while (floor != m_currFloor){
			if (floor < m_currFloor){
				m_status = Status::down;
				moveDown();
			}else{
				m_status = Status::up;
				moveUp();
			}
		}
		m_status = Status::idle;
	}
};

class RequestHandler{
private:
	Elevator elevator;
	queue<int> requestsQueue;

public:
	void callFromFloor(int floor){
		if (elevator.isMoving())
			requestsQueue.push(floor);
	}

	
};