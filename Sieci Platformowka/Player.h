#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
#include "ResourceManager.h"
class SpriteBatch;
class Player
{
public:
	Player();
	~Player();

	void init(const glm::vec2 &pos, const glm::vec2 &size, const std::string &texturePath);
	void update(unsigned int frameTime);
	void draw(SpriteBatch &spriteBatch);

private:

	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec4 m_uvRect = glm::vec4(0,0,1,1);
	ColorRGBA8 m_color = ColorRGBA8(255,255,255,255);
	GLTexture m_texture;
};

