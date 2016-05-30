#pragma once

#include "BaseApplication.h"
#include "UtilityNPC.h"
// only needed for the camera picking
#include <glm/vec3.hpp>
#include <vector>

class Camera;
class World;
class BaseNPC;

class UtilitySystemApplication : public BaseApplication {
public:

	UtilitySystemApplication();
	virtual ~UtilitySystemApplication();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	std::vector<BaseNPC> newRobot;

private:

	Camera*		m_camera;


	World*		m_pWorld;
	BaseNPC*	m_pNPC;
	UtilityNPC* m_pUtNPC;
};