#include "Player.h"
#include "SpriteBatch.h"
#include "Level.h"
#include <SDL\SDL_keycode.h>
Player::Player()
{
}


Player::~Player()
{
}

void Player::init(const glm::vec2 &pos, const glm::vec2 &size, const std::string &texturePath)
{
	m_pos = pos;
	m_size = size;
	m_texture = ResourceManager::getTexture(texturePath);
}

void Player::update(float frameTime, const Level& level, InputManager* inputManager)
{
	const std::vector<Block> *levelData = &level.getLevelData();
	bool isGrounded = true;

	// Gravity
	if (!isGrounded)
	{
		const float GRAVITY_POWA = 5.0f;
		m_velocity -= glm::vec2(0, GRAVITY_POWA);
	}

	// Update velocity based on input
	if (inputManager->isKeyDown(SDLK_a))
	{
		m_velocity -= glm::vec2(m_acceleration.x, 0);
		if (m_velocity.x < -m_maxVelocity.x)
			m_velocity.x = -m_maxVelocity.x;

	}
	else if (inputManager->isKeyDown(SDLK_d))
	{
		m_velocity += glm::vec2(m_acceleration.x, 0);
		if (m_velocity.x > m_maxVelocity.x)
			m_velocity.x = m_maxVelocity.x;
	}
	else
	{
		// Dampen movement if not pressing keys
		if (m_velocity.x > 0 && m_velocity.x > m_acceleration.x)
			m_velocity -= glm::vec2(m_acceleration.x, 0);
		else if (m_velocity.x < 0 && m_velocity.x < m_acceleration.x)
			m_velocity += glm::vec2(m_acceleration.x, 0);
		else
			m_velocity = glm::vec2(0, m_velocity.y);
	}
//	if (inputManager->isKeyDown(SDLK_w))
//		m_velocity += glm::vec2(0, m_acceleration.y);
	//if (inputManager->isKeyDown(SDLK_s))
	//	camera.setPosition(cameraPos - glm::vec2(0, cameraSpeed));

	// Check for collisions

	// Update position
	m_pos += frameTime * m_velocity;
}

void Player::draw(SpriteBatch &spriteBatch)
{
	spriteBatch.draw(glm::vec4(m_pos.x, m_pos.y, m_size.x, m_size.y), m_uvRect, m_texture.id, 0, m_color);
}