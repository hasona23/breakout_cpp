#include "breakout.hpp"


int main() {
    InitWindow(800, 600, "Hello, raylib!");
    SetTargetFPS(60);
	Entity paddle(1, "Paddle");
	paddle.Pos = { 350, 550 };
    paddle.Size = { 100,20 };
	Entity ball(2, "Ball");
    ball.Vel.x = 150;
    ball.Vel.y = 150;
	ball.Size = { 20,20 };
	ball.BounceOnWalls = true;

    std::vector<Vector2> bricks;
    int bricks_row = (800 / 200);
    int bricks_col = (100 / 20);
	
    bricks.reserve(bricks_col * bricks_row);
    std::cout << "SeedingBricks\n";
    for (size_t i = 0; i < bricks_row; i++)
    {
        for(size_t j = 0; j < bricks_col; j++)
        {
            bricks.push_back(Vector2{(float)i * BRICK_WIDTH, (float)j * BRICK_HEIGHT});
        }
    }
    std::cout << "Seed Done\n";
    while (!WindowShouldClose()) 
    {
        paddle.Vel.x = std::clamp(paddle.Vel.x ,-300.f,300.f);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        SetWindowTitle(std::format("BREAKOUT - FPS:{}",GetFPS()).c_str());
        float dt = GetFrameTime();
        float accelration = 400;
        if (IsKeyDown(KEY_D)) 
        {
            paddle.Vel.x += accelration * dt;
        }
        else if (IsKeyDown(KEY_A))
        {
            paddle.Vel.x -= accelration * dt;
        }
        else 
        {
			paddle.Vel.x = std::lerp(paddle.Vel.x, 0.0f, 0.1f);
			if (std::abs(paddle.Vel.x) < 0.5f)
                paddle.Vel.x = 0;
        }
		DrawText("Press A/D to move the paddle", 10, 10, 20, DARKGRAY);
        DrawText(std::format("VEL: {}",paddle.Vel.x).c_str(), 10, 10, 40, DARKGRAY);
        
		if (ball.CheckCollision(paddle))
        {
            ball.Vel.y *= -1;
        }
		for (int i = 0; i < bricks.size(); i++)
        {
            Vector2 brick_pos = bricks.at(i);
            Entity brick_entity(3, "Brick");
            brick_entity.Pos = brick_pos;
            brick_entity.Size = {BRICK_WIDTH, BRICK_HEIGHT};
            if (ball.CheckCollision(brick_entity))
            {
            
                ball.Vel.y *= -1;
                bricks.erase(bricks.begin() + i);
                break;
            }
        }
		paddle.Update(dt);
		ball.Update(dt);
        DrawText("Welcome to raylib!", 190, 200, 20, LIGHTGRAY);
        paddle.Draw();
        ball.Draw();
		draw_bricks(bricks);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
