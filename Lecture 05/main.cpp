//¸ñ¿äµå¶ó¸¶ ¼® & ÈÆ
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>

using namespace std;

class Actor
{
public:	
	string name;
	thread th;
	mutex heart;
	
	Actor() {}
	virtual void Start(Actor* actor) {}
	virtual void Run(Actor* actor) {}
};


class Hoon : public Actor
{
public:
	void(Hoon::*RunPointer)(Actor* actor);

	Hoon()
	{
		name = "ÈÆÀÌ";			
	}

	void Start(Actor* actor)
	{
		RunPointer = &Hoon::Run;
		th = thread(RunPointer, this, actor);
		th.join();
	}

	void Run(Actor* actor) {
		FallinLove(actor);
		Flirting(actor); 
		Fuckyou(actor);
	}

	void FallinLove(Actor *actor)
	{
		this_thread::sleep_for(std::chrono::milliseconds(1000));		
		cout << "ÈÆ : (³ª °©ÀÚ±â..." << actor->name << "À»(¸¦) º¸´Ï ³Ê¹« ¼³·»´Ù....)\n\n";
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	void Flirting(Actor * actor)
	{
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "ÈÆ : " << actor->name << "... ³»¹æ¿¡¼­... ¶ó¸é¸Ô°í°¥·¡??\n\n";		
	}

	void Fuckyou(Actor* actor)
	{
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "ÈÆ : (¾Æ..." << actor->name << "...Á¤¶³¾îÁ®...\n\n";
		this_thread::sleep_for(std::chrono::milliseconds(1000));		
	}
};

class Seok : public Actor
{
public:
	Seok() {
		name = "¼®ÀÌ";
	}
	
	void Run() {}
};

class Su : public Actor
{
public:
	Su()
	{
		name = "¼ö";
	}
	 void Run() {}
};

int main() //Thread0 PD : ÀÌÀº¼® (main)
{
	Actor* h = new Hoon();
	
	h->Start(???);
	 
	this_thread::sleep_for(std::chrono::milliseconds(1000));
	delete(h);
	
	return 0;
}




