#include "Player.h"
#include "SpriteBatch.h"

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

void Player::update(float frameTime)
{

}

void Player::draw(SpriteBatch &spriteBatch)
{
	spriteBatch.draw(glm::vec4(m_pos.x, m_pos.y, m_size.x, m_size.y), m_uvRect, m_texture.id, 0, m_color);
}