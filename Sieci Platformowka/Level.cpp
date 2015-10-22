#include "Level.h"
#include "SpriteBatch.h"

Level::Level()
{
}


Level::~Level()
{
}

glm::vec2 Level::load(const std::string &filepath)
{
	// Texture path in file?
	m_texture = ResourceManager::getTexture("Assets/dude.png");

	// read finish line ?

	// read blocks from file
	m_levelData.emplace_back(glm::vec2(-10.0f), glm::vec2(100.0f, 5.0f));
	m_levelData.emplace_back(glm::vec2(30.0f), glm::vec2(50.0f, 25.0f));
	// read player position from file and return it
	return glm::vec2(0.0f);
}

void Level::draw(SpriteBatch& spriteBatch)
{
	for (auto& block : m_levelData)
	{
		spriteBatch.draw(glm::vec4(block.pos.x, block.pos.y, block.size.x, block.size.y), glm::vec4(0,0,1,1), m_texture.id, 0, m_color);
	}

}
