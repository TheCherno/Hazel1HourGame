#pragma once

#include "Player.h"

struct Pillar
{
	glm::vec3 TopPosition = { 0.0f, 10.0f, 0.0f };
	glm::vec2 TopScale = { 15.0f, 20.0f };

	glm::vec3 BottomPosition = { 10.0f, 10.0f, 0.0f};
	glm::vec2 BottomScale = { 15.0f, 20.0f };
};

class Level
{
public:
	void Init();

	void OnUpdate(Hazel::Timestep ts);
	void OnRender();

	void OnImGuiRender();
	
	bool IsGameOver() const { return m_GameOver; }
	void Reset();

	Player& GetPlayer() { return m_Player; }
private:
	void CreatePillar(int index, float offset);
	bool CollisionTest();

	void GameOver();
private:
	Player m_Player;

	bool m_GameOver = false;

	float m_PillarTarget = 30.0f;
	int m_PillarIndex = 0;
	glm::vec3 m_PillarHSV = { 0.0f, 0.8f, 0.8f };

	std::vector<Pillar> m_Pillars;

	Hazel::Ref<Hazel::Texture2D> m_TriangleTexture;
};