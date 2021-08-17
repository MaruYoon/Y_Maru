#include "..\Prototype\Object.h"
#include "..\Prototype\Object.h"
#include "..\Prototype\Object.h"
#include <iostream>
#include <string>

using namespace std;

/*

//#define
//����� �����ϰ� �����ϴ� ��ũ�� Ű����
//�����̸鼭 ���
//���ȭ �����ش�.
//�Լ� ó�� ����Ѵ�.
//��ó�����̱� ������ staticó�� �켱������ �ҷ��´�.



#define MAX 128

#define Output cout << "Hello World!!" << endl
//define�� �Լ� �� ���� ������ ����� �ν��ϱ� ������ ���� �����ݷ��� ������ �ʾƵ� ������ �����ϳ�
//���ǻ� �����ϰ� �������� �����ݷ��� ���δ�.

#define Output1(str) cout << str << endl
//�̷������� ����� �ȴ�.

#define Output2(x,y) cout << (x+y) << endl
//�̷��� ������ ���ڳ� string���� ������ �����ϴ�.




//#define Output2(x,y) {cout << (x+y) << endl;}
// 
//define�� �����ٷ� �����ϴ� ���� �Ұ��ϴ�
//�׷��� ������ �Ʒ�ó�� ��������\�� ����Ͽ� ���ٷ� �ν��ϰ� ���ش�.
//�������� �ڿ� ������Ⱑ ������ �ȵȴ�. 

#define void Output3(x,y) 	   \
{						   \
	cout << (x+y) << endl; \
}


*/

//Singleton
//Ÿ�Կ� �°� �̱����� ����ڴ�
#define DECLARE_SINGLETON(type)          \
static type** GetInstance()              \
{                                        \
    static type* pInstance = new type;   \
                                         \
    if (pInstance == NULL)               \
    pInstance = new type;                \
                                         \
    return &pInstance;                   \
                                         \
}                                        \
static void DestroyInstance()            \
{                                        \
     type** ppInstance = GetInstance();  \
                                         \
if ((*ppInstance) != NULL)               \
{                                        \
        delete *ppInstance;              \
		ppInstance = NULL;               \
	}                                    \
                                         \
                                         \
}

#define GETSINGLETON(type) (*type::GetInstance())
#define DESTROYSINGLETON(type) (*type::GetInstance())->DestroyInstance()


class _Object
{
public:
	DECLARE_SINGLETON(Object)

public:
	int Number;

public:
	void Output()
	{
		cout << "Hello" << endl;
	}

public:
	
	_Object(){}
	~_Object(){}
};



template <typename T>
inline void Safe_Release(T& _rObj)
{						            
	if (_rObj)			            
	{					            
		delete _rObj;		        
		_rObj = NULL;		        
	}					            
}

#define SAFE_DELETE(_Obj) { Safe_Release( _Obj);}














int main(void)
{
	/*
	Object* pObj = new Object;
	pObj->Output();

	SAFE_DELETE(pObj);

	delete pObj;
	pObj = NULL;

	pObj->Output();
	*/




	/*
	GETSINGLETON(Object)->Number = 10;
	GETSINGLETON(Object)->Output();

	cout << GETSINGLETON(Object)->Number << endl;

	DESTROYSINGLETON(Object);
	*/









	//�迭�� ���̴� �����̸鼭 ����� ������ �ʱⰪ ��� ����.
	//int Array[MAX];


	/*
	string str1 = "Hello ";
	string str2 = "World";

	Output;
	Output1("Hello World!!");
	Output2(10, 20);
	Output2(str1, str2);

	Output3(str1, str2);
	*/




	return 0;
}