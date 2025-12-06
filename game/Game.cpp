#include "Game.hpp"
#include "raylib.h"

void Game::Init()
{
	// Initialization code here
	player.Pos = Vector2{ 100.0f, 100.0f };
	
}

void Game::Update(float dt)
{
	// Update game logic here
	player.Update(dt);
}

void Game::Draw(float dt)
{
	DrawFPS(5,5);
	player.Draw();
}

void Game::Close()
{
	// Cleanup code here
}