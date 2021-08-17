#include "Prototype.h"
#include "Object.h"

Prototype* Prototype::Instance = nullptr;

Prototype::Prototype()
{

}

Prototype::~Prototype()
{

}


void Prototype::Initialize()
{
	Transform TransInfo;
	TransInfo.Position = Vector3(0.0f, 0.0f);

	PrototypeList["Object"] = new Object(TransInfo);
}

Object* Prototype::FineObject(string _str)
{
	map<string, Object*>::iterator iter = PrototypeList.find(_str);

	if (iter == PrototypeList.end())
		return nullptr;

	return iter->second;
}


