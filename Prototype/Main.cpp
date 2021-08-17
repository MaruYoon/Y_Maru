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
		cout << "������ ���� ��ü�� �����ϴ�. " << endl;

		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		Object* pTempObj = pObj->Clone();
		//push_back �� �ϱ� ���ؼ��� �ʱ�ȭ ������ ���ľ� ��

		pTempObj->Initialize();
		pTempObj->SetIndex(i + 1);

		ObjectList.push_back(pTempObj);
	}
}

int main(void)
{
	Prototype::GetInstance()->Initialize();

	InitObject("Object");

	//���
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		(*iter)->Render();
	}

	//����
	//�����͸� �����ϴ� �۾��� 
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	//�����̳ʸ� ���� �۾��� ���� ������ �Ǿ����
	ObjectList.clear();

	return 0;
}