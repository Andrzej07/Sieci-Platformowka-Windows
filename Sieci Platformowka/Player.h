#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
#include "ResourceManager.h"
#include "InputManager.h"
class SpriteBatch;
class Level;
struct Block;
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
	bool intersects(const Block& block);
	bool hitsTopOf(const Block& block);
	bool hitsRightOf(const Block& block);
	bool hitsLeftOf(const Block& block);
	bool hitsBottomOf(const Block& block);
	void pushOffY(const Block& block);
	void pushOffX(const Block& block);
	float XOverlap(const Block& block);
	float YOverlap(const Block& block);
	void resolveCollisions(const Level& level, bool& isGrounded);

	bool m_isJumping = true;
	glm::vec2 m_acceleration = glm::vec2(16.5f, 5.0f); // running and jumping accel
	glm::vec2 m_velocity = glm::vec2(0);
	glm::vec2 m_maxVelocity = m_acceleration * 3.0f;

	glm::vec2 m_pos;  // bottom left corner
	glm::vec2 m_size;
	glm::vec4 m_uvRect = glm::vec4(0,0,1,1);
	ColorRGBA8 m_color = ColorRGBA8(255,0,0,255);
	GLTexture m_texture;
};

