// breakout.h : Include file for standard system include files,
// or project specific include files.

#pragma once
namespace Zap
{
	class GameCore
	{
	public:
		void Run();
		GameCore(const char* title, int width, int height);
		~GameCore();
	private:
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;
		virtual void Init() = 0;
		virtual void Close() = 0;
	};
}