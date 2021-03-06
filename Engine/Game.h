/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "WorldObject.h"
#include "RetroContent.h"
#include <vector>
#include <thread>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void ProcessInput();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/

	std::vector<WorldObject> worldObjects;

	Vec2 cameraLoc;
	float cameraZoom;

	float relAngle = 0.0f; // 3.1415f / 1.0f;

	bool spaceIsPressed = false;
	bool spaceIsActive = true;

	bool mouseLeftIsPressed = false;
	bool mouseLeftIsActive = false;


	std::vector<bool> canDisplayVectors;
	std::vector<std::string> displayVectorsNames;
	std::vector<bool> activeSteeringForces;
	std::vector<Color> displayVectorsColors;

	bool crtlIsPressed = false;
	bool crtlIsActive = false;

	bool rightIsPressed = false;
	bool rightIsActive = false;

	bool leftIsPressed = false;
	bool leftIsActive = false;

	int currentViewedWorldObject = 0;
};