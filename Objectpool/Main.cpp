#include <iostream>
#include <Windows.h>
#include <list>

using namespace std;


struct Object
{
	int Key;
	int Value;


	Object() : Key(0), Value(0) {}

	Object(int _Key, int _Value)
		: Key(_Key), Value(_Value) {}
};

bool check = false;
int Count = 0;

int main(void)
{
	// ���� ����� ������Ʈ(������ �� ������Ʈ ����Ʈ)
	list<Object*>EnableList;

	//����� ��ģ ������Ʈ ����Ʈ(������ ���� ����)
	list<Object*>DesableList;

	while (true)
	{
		system("cls");
		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		//�Է��� �Ǿ��ٸ�
		if (check)
		{//DesableList �� ������ ������Ʈ�� �ִ��� Ȯ�� �ϰ� ���ٸ�
			if (DesableList.empty())
			{//5���� ������Ʈ�� �߰� ������ ��
				for (int i = 0; i < 5; ++i)
				{
					DesableList.push_back(
						new Object(Count++, 0));
				}
			}

			//�߰� ������ ������Ʈ �ϳ��� ����
			list<Object*>::iterator iter = DesableList.begin();

			//�ʱ�ȭ�� ����
			(*iter)->Value = 0;

			//����� ����Ʈ�� �߰�
			EnableList.push_back((*iter));

			//���� ����Ʈ���� ����
			DesableList.pop_front();

		}


		//Render
		cout << "EnableList" << endl;

		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();/*�������� �Ʒ���*/)
		{
			//Value �� ����
			(*iter)->Value++;

			//���
			cout << (*iter)->Key << " : " << (*iter)->Value << endl;

			//��µ� ������Ʈ�� Value ���� ���� �̻��� �ȴٸ�
			if ((*iter)->Value >= 50)
			{
				//���� ����Ʈ���� DesableList �� �Űܳ���
				DesableList.push_back((*iter));

				//���� ����Ʈ���� ����
				iter = EnableList.erase(iter);
			}
			else
				//������Ʈ�� �������� ������ ������Ŵ
				++iter;
		}


		for (list<Object*>::iterator iter = DesableList.begin();
			iter != DesableList.end(); ++iter)
		{

			//���
			cout << (*iter)->Key << endl;

		}
		Sleep(50);
	}


	for (list<Object*>::iterator iter = DesableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete(*iter);
		(*iter) = NULL;
	}
	EnableList.clear();


	for (list<Object*>::iterator iter = EnableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete(*iter);
		(*iter) = NULL;
	}
	DesableList.clear();


	/*
	for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
		iter != ObjectPoolList.end(); ++iter)
	{
		ObjectPoolList = (new ObjectPool(i,0,false));
	}





	ObjectPool*  Array[128] = { NULL };

	for (int i = 0; i < 128; ++i)
	{
		Array[i] = new ObjectPool;

		Array[i]->Active = false;
		Array[i]->Key = i;
		Array[i]->Value = 0;
	}


	while (true)
	{
		system("cls");

		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;


		if (check)
		{
			list< ObjectPool*>::iterator iter = ObjectPoolList.begin();

			if (ObjectPoolList.empty())
			{

			}

				if (!(*iter)->Active)
				{
					Array[i]->Active = true;
					Array[i]->Value = 0;
					break;
				}

			}

		}


		for (int i = 0; i < 128; ++i)
		{
			if (Array[i])
			{
				cout << Array[i]->Key << "  :  " << Array[i]->Value << endl<< endl;

				if (Array[i]->Value >= 50)
				{
					Array[i]->Active = false;
				}
			}
		}
		Sleep(50);
	}


	for (int i = 0; i < 128; ++i)
	{
		delete Array[i];
		Array[i] = NULL;
	}




	 /*
	 C (��������) ���� C++(��ü����)���� �ٲ����, C#(++++)�� ��ȭ�Ѵ�.

	 ������ ��� : C, C++
	 �ڵ��� ��� : C#

	 C�� C++��(������ ���) �����ͷ� �ּҸ� ���� ������ �� �ֱ� ������ �ٸ� ���鿡 ���� ���� ����� ���.
	 �޸� ������ ȿ�����̴�.

	 ��ü ���� (OOP)�� Ư¡
	 1) ��������
	 2) �߻�ȭ
	 3) ĸ��ȭ
	 4) ���
	 5) ������

	 �߻�ȭ �ؿ� �������� �ְ� ������ ����� ����� �ȴ�.
	 �������� ������ ������ Object�� �����Ϳ� ����� �ϳ��� ���� ĸ��ȭ �ϸ�,
	 ������ �����Ѵ�.

	 ��ü������ ���� JAVA�� ��ǥ���̴�.

	 c#�� static �� �⺻���� �Ѵ�. (���α׷��� ���̰� ����� ������� �׸�ŭ�� ȿ���� �����ش�.)

	 ObjectPool�� �޸��� ���ϸ� �������� �����⸦ ������ �ʴ� ����� ������ �����̴�.

	 C#�� ��������� ���̴� ������ ��� ��������� �������� �ϰ������� ������ �ϴµ�
	 ������ ������ �޸𸮿� ���� ū ���ϸ� �������ֱ� ������ ������ ������ִ�.
	*/




	return 0;
}




