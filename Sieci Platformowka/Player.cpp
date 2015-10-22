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
	// For testing
	if (inputManager->isKeyPressed(SDLK_w))
	{
		//m_pos.y += m_acceleration.y;
		m_velocity.y += m_acceleration.y*10;
	}
	else if (inputManager->isKeyDown(SDLK_s))
	{
		m_pos.y -= m_acceleration.y/3;
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
//	if (inputManager->isKeyPressed(SDLK_w) && isGrounded)
//		m_velocity += glm::vec2(0, m_acceleration.y);
	//if (inputManager->isKeyDown(SDLK_s))
	
	// Check for collisions
	bool isGrounded = false;
	enum { LEFT, RIGHT, TOP, BOTTOM };

	// Check for collisions
	float playerRight = m_pos.x + m_size.x;
	float playerTop = m_pos.y + m_size.y;
	for (auto& block : *levelData)
	{
		float collisionDepth[4] = { 0.f, 0.f, 0.f, 0.0f };
		bool collided[4] = { 0, 0, 0, 0 };
		float blockRight = block.pos.x + block.size.x;
		float blockTop = block.pos.y + block.size.y;

		if (m_pos.x < block.pos.x && playerRight > block.pos.x)
		{
			collisionDepth[RIGHT] = playerRight - block.pos.x;
			if (collisionDepth[RIGHT] > m_size.x) collisionDepth[RIGHT] = 0.0f;
			collided[RIGHT] = true;
		}
		if (block.pos.x < m_pos.x && blockRight > m_pos.x)
		{
			collisionDepth[LEFT] = blockRight - m_pos.x;
			if (collisionDepth[LEFT] > m_size.x) collisionDepth[LEFT] = 0.0f;
			collided[LEFT] = true;
		}
		if (m_pos.y < block.pos.y && playerTop > block.pos.y)
		{
			collisionDepth[TOP] = playerTop - block.pos.y;
			if (collisionDepth[TOP] > m_size.y) collisionDepth[TOP] = 0.0f;
			collided[TOP] = true;
		}
		if (block.pos.y < m_pos.y && blockTop > m_pos.y)
		{
			collisionDepth[BOTTOM] = blockTop - m_pos.y;
			if (collisionDepth[BOTTOM] > m_size.y) collisionDepth[BOTTOM] = 0.0f;
			collided[BOTTOM] = true;
		}

		if (collisionDepth[BOTTOM] && (collided[LEFT] || collided[RIGHT]))
		{
			isGrounded = true;
			if (m_velocity.y < 0)
				m_velocity.y = 0.0f;
			m_pos.y += collisionDepth[BOTTOM] - 0.01f;
		}
		if (collisionDepth[LEFT] && (collided[TOP] || collided[BOTTOM]))
		{
			m_velocity.x = 0.0f;
		//	m_pos.x += collisionDepth[LEFT];
		}
		if (collisionDepth[RIGHT] && (collided[TOP] || collided[BOTTOM]))
		{
			m_velocity.x = 0.0f;
			m_pos.x -= collisionDepth[RIGHT] + 0.01f;
		}
	//	if (collided[BOTTOM])
	//	if (collisionDepth[LEFT] + collisionDepth[BOTTOM] + collisionDepth[TOP] + collisionDepth[RIGHT] > 0)
	//		printf("LEFT %f   RIGHT %f   TOP %f   BOTTOM %f\n", collisionDepth[LEFT], collisionDepth[RIGHT], collisionDepth[TOP], collisionDepth[BOTTOM]);
	}

	// Gravity
	if (!isGrounded)
	{
		const float GRAVITY_POWA = 1.5f;
		m_velocity -= glm::vec2(0, GRAVITY_POWA);
	}


	// Update position
	m_pos += frameTime * m_velocity;
}

void Player::draw(SpriteBatch &spriteBatch)
{
	spriteBatch.draw(glm::vec4(m_pos.x, m_pos.y, m_size.x, m_size.y), m_uvRect, m_texture.id, 0, m_color);
}