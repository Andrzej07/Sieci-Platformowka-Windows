#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
#include "ResourceManager.h"
#include "InputManager.h"
class SpriteBatch;
class Level;
class Player
{
public:
	Player();
	~Player();

	void init(const glm::vec2 &pos, const glm::vec2 &size, const std::string &texturePath);
	void update(float frameTime, const Level& level, InputManager* inputManager);
	void draw(SpriteBatch &spriteBatch);

	glm::vec2 getPosition() const { return m_pos; }
private:
	//InputManager m_inputManager;

	bool m_isJumping = true;
	glm::vec2 m_acceleration = glm::vec2(15.5f, 5.0f); // running and jumping accel
	glm::vec2 m_velocity = glm::vec2(0);
	glm::vec2 m_maxVelocity = m_acceleration * 3.0f;

	glm::vec2 m_pos;  // bottom left corner
	glm::vec2 m_size;
	glm::vec4 m_uvRect = glm::vec4(0,0,1,1);
	ColorRGBA8 m_color = ColorRGBA8(255,0,0,255);
	GLTexture m_texture;
};

