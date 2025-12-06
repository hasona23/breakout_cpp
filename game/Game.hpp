#include "Zap.hpp"
#include "entities/Player.hpp"
class Game : public Zap::GameCore
{

public:
	using GameCore::GameCore; // Inherit constructor
private:
	Player player;
private:
	void Init() override;
	void Update(float dt) override;
	void Draw(float dt) override;
	void Close() override;
};