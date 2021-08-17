#pragma once
#include "Headers.h"

class Object;
class Prototype
{
private:
	static Prototype* Instance;
public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype;
		return Instance;
	}
private:
	map<string, Object*>PrototypeList;
public:
	void Initialize();
	Object* FineObject(string _str);
private:
	Prototype();
public:
	~Prototype();


};

