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
	//** Prototype ����
	Transform TransInfo;
	TransInfo.Position = Vector3(0.0f, 0.0f);

	PrototypeList["Object"] = new Object(TransInfo);
}

Object* Prototype::FineObject(string _str)
{
	//** map�� ������Ʈ�� �ִ��� Ȯ��. 
	map<string, Object*>::iterator iter = PrototypeList.find(_str);

	//** ã�� ������Ʈ�� ���ٸ� nullptr �� ��ȯ.
	if (iter == PrototypeList.end())
		return nullptr;

	//** �ƴ϶�� ã�� ������Ʈ�� ��ȯ.
	return iter->second;
}