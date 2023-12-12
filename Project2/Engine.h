#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"


class Engine
{
private:
	// The texture holder
	TextureHolder th;
	// create a particle system
	ParticleSystem m_PS;
	// Thomas and his friend, Bob
	Thomas m_Thomas;
	Bob m_Bob;
	// A class to manage all the levels
	LevelManager m_LM;
	// Create a SoundManager
	SoundManager m_SM;
	// The Hud
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;
	//Tiles info
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	// The force pushing the characters down
	const int GRAVITY = 300;
	// A regular RenderWindow
	sf::RenderWindow m_Window;
	// The main Views
	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;
	// Three views for the background
	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HudView;
	// Declare a sprite and a Texture
	// for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;
	// Declare a shader for the background
	sf::Shader m_RippleShader;

	// Is the game currently playing?
	bool m_Playing = false;
	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;
	// Start in full screen (not split) mode
	bool m_SplitScreen = false;
	// Time left in the current level (seconds)
	float m_TimeRemaining = 100;
	sf::Time m_GameTimeTotal;
	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;
	// The vertex array for the level tiles
	sf::VertexArray m_VALevel;
	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;
	// Texture for the level tiles
	sf::Texture m_TextureTiles;


	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	// Load a new level
	void loadLevel();
	//Collision Check
	bool detectCollisions(PlayableCharacter& character);
	// Make a vector of the best places to emit sounds from
	void populateEmitters(std::vector <sf::Vector2f>& vSoundEmitters,int** arrayLevel);
	// A vector of Vector2f for the fire emitter locations
	std::vector <sf::Vector2f> m_FireEmitters;


public:
	// The Engine constructor
	Engine();
	// Run will call all the private functions
	void run();
};


