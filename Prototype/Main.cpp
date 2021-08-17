#include "Prototype.h"
#include "Object.h"

list<Object*> ObjectList;

void InitObject(string _Key)
{
	Object* pObj = Prototype::GetInstance()->FineObject(_Key);

	if (pObj == nullptr)
	{
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "복제할 원본 객체가 없습니다. " << endl;

		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		Object* pTempObj = pObj->Clone();
		//push_back 을 하기 위해서는 초기화 과정을 거쳐야 함

		pTempObj->Initialize();
		pTempObj->SetIndex(i + 1);

		ObjectList.push_back(pTempObj);
	}
}

int main(void)
{
	Prototype::GetInstance()->Initialize();

	InitObject("Object");

	//출력
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		(*iter)->Render();
	}

	//삭제
	//포인터를 해제하는 작업과 
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	//컨테이너를 비우는 작없이 같이 진행이 되어야함
	ObjectList.clear();

	return 0;
}