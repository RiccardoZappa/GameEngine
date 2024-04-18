#pragma once


namespace GameEngine
{
	class CGameEngine
	{
	public:
		CGameEngine();
		~CGameEngine();

		bool Initialize();
		void RunLoop();
		void ShutDown();
	};
	
}