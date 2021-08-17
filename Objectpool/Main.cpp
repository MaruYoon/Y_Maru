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
	// 실제 사용한 오브젝트(랜더링 될 오브젝트 리스트)
	list<Object*>EnableList;

	//사용을 마친 오브젝트 리스트(랜더링 되지 않음)
	list<Object*>DesableList;

	while (true)
	{
		system("cls");
		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		//입력이 되었다면
		if (check)
		{//DesableList 에 여분의 오브젝트가 있는지 확인 하고 없다면
			if (DesableList.empty())
			{//5개의 오브젝트를 추가 생성한 후
				for (int i = 0; i < 5; ++i)
				{
					DesableList.push_back(
						new Object(Count++, 0));
				}
			}

			//추가 생성된 오브젝트 하나를 선택
			list<Object*>::iterator iter = DesableList.begin();

			//초기화를 진행
			(*iter)->Value = 0;

			//사용할 리스트에 추가
			EnableList.push_back((*iter));

			//현재 리스트에서 삭제
			DesableList.pop_front();

		}


		//Render
		cout << "EnableList" << endl;

		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();/*증감문은 아래로*/)
		{
			//Value 값 증가
			(*iter)->Value++;

			//출력
			cout << (*iter)->Key << " : " << (*iter)->Value << endl;

			//출력된 오브젝트의 Value 값이 일정 이상이 된다면
			if ((*iter)->Value >= 50)
			{
				//현재 리스트에서 DesableList 로 옮겨놓고
				DesableList.push_back((*iter));

				//현재 리스트에서 삭제
				iter = EnableList.erase(iter);
			}
			else
				//오브젝트가 삭제되지 않을때 증가시킴
				++iter;
		}


		for (list<Object*>::iterator iter = DesableList.begin();
			iter != DesableList.end(); ++iter)
		{

			//출력
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
	 C (절차지향) 에서 C++(객체지향)으로 바뀌었고, C#(++++)로 진화한다.

	 수동적 언어 : C, C++
	 자동적 언어 : C#

	 C와 C++은(수동형 언어) 포인터로 주소만 들고와 참조할 수 있기 때문에 다른 언어들에 비해 적은 비용이 든다.
	 메모리 관리가 효율적이다.

	 객체 지향 (OOP)의 특징
	 1) 정보은닉
	 2) 추상화
	 3) 캡슐화
	 4) 상속
	 5) 다형성

	 추상화 밑에 다형성이 있고 서로의 관계는 상속이 된다.
	 다형성을 가지는 각개의 Object는 데이터와 기능을 하나로 묶인 캡슐화 하며,
	 정보를 은닉한다.

	 객체지향적 언어는 JAVA가 대표적이다.

	 c#은 static 을 기본으로 한다. (프로그램이 무겁고 비용이 비싸지만 그만큼의 효율을 보여준다.)

	 ObjectPool은 메모리의 부하를 가져오는 쓰레기를 만들지 않는 방식의 디자인 패턴이다.

	 C#은 쓰레기들이 모이는 가비지 라는 저장공간이 가득차면 일괄적으로 삭제를 하는데
	 생성과 삭제는 메모리에 가장 큰 부하를 가져다주기 때문에 게임이 멈출수있다.
	*/




	return 0;
}




