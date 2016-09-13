/*
This is the first design pattern that I used in pratice. When I developed an Android app with list view, the adapter is used to renderer any class to list view!


Adapter pattern is frequently used in modern Java frameworks.
It comes into place when you want to use an existing class, and its interface does not match the one you need, or you want to create a reusable class that cooperates with unrelated classes with incompatible interfaces.
1. Adapter pattern story
The Adapter idea can be demonstrated with the following simple example. The purpose of the sample problem is to adapt an orange as an apple.

*/

/* 
In following example, we get Walk and Draw two class completely different. 
And we will adapt the Walk class with Draw features
*/
#include <iostream>

class Draw{
public:
	virtual void draw(){
		std::cout << "drawing something" << std::endl;
	}
};


class Walk{
public:
	void walk(){
		std::cout << "walking along the sea" << std::endl;
	}
};


class DrawAdapter : public Draw{
private:
	Walk* m_pWalk;
public:
	void setWalk(Walk* pWalk){
		m_pWalk = pWalk;
	}
	virtual void draw(){
		m_pWalk->walk();
		std::cout << "And I'd like to draw the sea with my smart phone!" << std::endl;
	}
};

void drawTheClass(Draw* pDraw){
	pDraw->draw();
}

int main(){
	Walk walk;
	DrawAdapter drawAdapter;
	drawAdapter.setWalk(&walk);
	drawTheClass(&drawAdapter);
}