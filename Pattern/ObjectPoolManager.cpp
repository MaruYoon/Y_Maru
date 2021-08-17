#include "ObjectPoolManager.h"
#include "Prototype.h"
#include "Object.h"


ObjectpoolManager* ObjectpoolManager::Instance = nullptr;

ObjectpoolManager::ObjectpoolManager()
{
}

ObjectpoolManager::~ObjectpoolManager()
{
	Release();
}

void ObjectpoolManager::Initialize()
{

}

void ObjectpoolManager::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (DesableList.empty())
		{
			Object* pObj = Prototype::GetInstance()->FineObject("Object");

			if (pObj == nullptr)
				return;

			for (int i = 0; i < 5; ++i)
				DesableList.push_back(pObj->Clone());
		}

		//** 추가 생성된 오브젝트 하나를 선택.
		list<Object*>::iterator iter = DesableList.begin();

		//** 초기화 에 필요한 구문 작성.
		(*iter)->Initialize();

		//** 사용할 리스트에 추가.
		EnableList.push_back((*iter));

		//** 현재 리스트에서 삭제.
		DesableList.pop_front();
	}

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end();)
	{
		int iResult = (*iter)->Update();

		if (iResult == 1)
		{
			//** 현재 리스트에서 삭제.
			DesableList.push_back((*iter));

			//** 사용할 리스트에 추가.
			iter = EnableList.erase(iter);
		}
		else
			++iter;
	}
}

void ObjectpoolManager::Render()
{
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		(*iter)->Render();
	}

	//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (DesableList)
	string Buffer = "DesableList : " + to_string(DesableList.size());
	OutPut(10, 1, Buffer);
	Buffer.clear();

	//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (EnableList)
	Buffer = "EnableList : " + to_string(EnableList.size());
	OutPut(10, 2, Buffer);
}

void ObjectpoolManager::Release()
{
	//** DesableList 전제 삭제
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();

	//** EnableList 전제 삭제
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();
}

void ObjectpoolManager::OutPut(float _x, float _y, string _str)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}





