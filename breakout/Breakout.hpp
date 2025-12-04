// breakout.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "raylib.h"
#include "Entities.hpp"
#include "stdio.h"
#include <vector>
#include <algorithm>
// TODO: Reference additional headers your program requires here.
const float BRICK_WIDTH = 200;
const float BRICK_HEIGHT = 20;

void draw_bricks(std::vector<Vector2> &bricks)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		DrawRectangleV(bricks.at(i), {BRICK_WIDTH - 10, BRICK_HEIGHT - 10}, i%2 == 0?DARKGREEN:DARKBLUE);
	}
}