#include "bird_states.h"
#include "../Log.h"
#include "../components/cmp_ai_steering.h"
#include "../components/cmp_animated_sprite.h"
#include "../components/cmp_cleanup.h"
#include "../components/cmp_enemy_physics.h"
#include "texture_manager.h"

/*
* Behaviour of the flying cloud.
*/

using namespace sf;

// ----- Flying state -----
void FlyingbirdState::execute(Entity* owner, double dt) noexcept
{
	if(_setup)
	{
		auto anim = owner->get_components<AnimatedSpriteComponent>()[0];
		anim->setSpritesheet(TextureManager::getTexture("lightning.png"));
		anim->setNumberOfFrames(11);
		_setup = false;
		owner->addComponent<CleanUpComponent>(8.0f);
	}
	auto physics = owner->GetCompatibleComponent<PhysicsComponent>()[0];
	auto steer = owner->get_components<SteeringComponent>()[0];

	physics->impulse(Vector2f(steer->getOutput().xdirection, 0) * (float)(dt));
}
