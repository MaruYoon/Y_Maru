#include "..\Prototype\Object.h"
#include "..\Prototype\Object.h"
#include "..\Prototype\Object.h"
#include <iostream>
#include <string>

using namespace std;

/*

//#define
//기능을 지정하고 저장하는 메크로 키워드
//정수이면서 상수
//상수화 시켜준다.
//함수 처럼 사용한다.
//전처리기이기 때문에 static처럼 우선순위로 불러온다.



#define MAX 128

#define Output cout << "Hello World!!" << endl
//define은 함수 명 뒤의 모든것을 상수로 인식하기 때문에 끝에 세미콜론을 붙이지 않아도 실행이 가능하나
//편의상 제외하고 본문에서 세미콜론을 붙인다.

#define Output1(str) cout << str << endl
//이런식으로 사용이 된다.

#define Output2(x,y) cout << (x+y) << endl
//이러한 결합을 숫자나 string으로 적용이 가능하다.




//#define Output2(x,y) {cout << (x+y) << endl;}
// 
//define은 여러줄로 정의하는 것이 불가하다
//그렇기 때문에 아래처럼 역슬러시\를 사용하여 한줄로 인식하게 해준다.
//역슬러쉬 뒤에 띄워쓰기가 있으면 안된다. 

#define void Output3(x,y) 	   \
{						   \
	cout << (x+y) << endl; \
}


*/

//Singleton
//타입에 맞게 싱글톤을 만들겠다
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









	//배열의 길이는 정수이면서 상수일 때에만 초기값 사용 가능.
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