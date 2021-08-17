#include "ObjectPoolManager.h"
#include "Prototype.h"

int main(void)
{
	Prototype::GetInstance()->Initialize();
	ObjectpoolManager::GetInstance()->Initialize();
	

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			ObjectpoolManager::GetInstance()->Update();
			ObjectpoolManager::GetInstance()->Render();
		}
	}

	return 0;
}