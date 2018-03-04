#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <iostream>
#include <string>

#include <ArrowsIOEngine/GLTexture.h>
#include <ArrowsIOEngine/GLSLProgram.h>

#include <vector>
#include <ArrowsIoEngine/sprite.h>
#include <ArrowsIoEngine\window.h>

#include <ArrowsIoEngine\SpriteBatch.h>

#include <ArrowsIoEngine\ArrowsIoEngine.h>
#include <ArrowsIoEngine\Camera2D.h>

#include <ArrowsIoEngine\InputManager.h>
#include <ArrowsIoEngine\Timing.h>

#include "Bullet.h"
#include "Sockets.h"
#include "Player.h"
#include "Character.h"
#include "hearts.h"
#include <mutex>
enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame(int noOfPlayers, int currentIndex, const std::vector<Player>& players, socketClient* client);
	~MainGame();

	void run();


private:
	void initSystems();
	void initShaders();
	void processInput();
	void receiver();
	void gameLoop();
	void drawGame();

	void updateChars();
	void updateBullets();
	void updateHearts();
	//void upDownControl();
	//void rightLeftControl();

	ArrowsIoEngine::window _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	ArrowsIoEngine::GLSLProgram _colorProgram;
	ArrowsIoEngine::Camera2D _camera;

	ArrowsIoEngine::InputManager _inputManager;
	ArrowsIoEngine::FpsLimiter _fpsLimiter;

	ArrowsIoEngine::SpriteBatch _spriteBatch;

	std::vector<Bullet> _bullets;
	std::vector<hearts> _hearts;

	float _fps;
	float _maxFPS;
	float _time;

	glm::vec2 m_playerDim, m_bulletDim;
	std::vector<Character> m_chars;
	Character* m_mainPlayer;

	int m_noOfPlayers, m_currentIndex;
	std::string newBulls = "";
	int newBullCount = 0;
	std::vector<Player> m_players;

	std::mutex mtx;
	socketClient* socket;
	std::string data;

	glm::vec2 _heartPos;
	glm::vec2 _heartDim = glm::vec2(20.0f, 10.0f);
	GLuint _heartTexID, _redTexID, _grayTexID, _blueTexID, _wandTexID;

	glm::vec4 _uv = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	Color _color = { 255,255,255,255 };
};

