#pragma once

#include "BaseApplication.h"



#include "BaseApplication.h"

// only needed for the camera picking
#include <glm/vec3.hpp>

class Camera;
class World;
class BaseNPC;

class GeneticsApplication : public BaseApplication {
public:

	GeneticsApplication();
	virtual ~GeneticsApplication();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

private:

	Camera*		m_camera;

	World*		m_pWorld;
};