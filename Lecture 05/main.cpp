//����� �� & ��
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
		name = "����";			
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
		cout << "�� : (�� ���ڱ�..." << actor->name << "��(��) ���� �ʹ� ������....)\n\n";
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	void Flirting(Actor * actor)
	{
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "�� : " << actor->name << "... ���濡��... ���԰���??\n\n";		
	}

	void Fuckyou(Actor* actor)
	{
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "�� : (��..." << actor->name << "...��������...\n\n";
		this_thread::sleep_for(std::chrono::milliseconds(1000));		
	}
};

class Seok : public Actor
{
public:
	Seok() {
		name = "����";
	}
	
	void Run() {}
};

class Su : public Actor
{
public:
	Su()
	{
		name = "��";
	}
	 void Run() {}
};

int main() //Thread0 PD : ������ (main)
{
	Actor* h = new Hoon();
	
	h->Start(???);
	 
	this_thread::sleep_for(std::chrono::milliseconds(1000));
	delete(h);
	
	return 0;
}




