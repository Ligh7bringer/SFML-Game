#include "fish_states.h"
#include "../components/cmp_enemy_physics.h"
#include "../components/cmp_animated_sprite.h"
#include "../../engine/lib_tile_level_loader/LevelSystem.h"

using namespace sf;

// ----- SWIMMING STATE -----
void SwimmingState::execute(Entity* owner, double dt) noexcept {
    const auto pos = owner->getPosition();

    auto physics = owner->GetCompatibleComponent<PhysicsComponent>()[0];
    auto anim = owner->get_components<AnimatedSpriteComponent>()[0];

    auto mov = _direction * (float)(dt * 100);
    mov.x += _direction.x * 16.f;

    if(LevelSystem::getTileAt(pos + mov) == '2' || LevelSystem::getTileAt(pos + mov) == '0'){
        _direction *= -1.f;
    }

    physics->impulse(_direction * (float)(dt*100));
    anim->setFacingRight(_direction.x > 0);

    if(length(_player->getPosition() - pos) < 250.f) {
        auto sm = owner->get_components<StateMachineComponent>()[0];
        sm->changeState("jumping");
    }
}

// ----- JUMPING STATE -----
void JumpingState::execute(Entity* owner, double dt) noexcept {
    auto anim = owner->get_components<AnimatedSpriteComponent>()[0];
    anim->setFacingRight(!(_direction.x > 0));
    auto pos = owner->getPosition();
    auto physics = owner->get_components<EnemyPhysicsComponent>()[0];
    if(physics->isGrounded()) {
        physics->teleport(Vector2f(pos.x, pos.y - 1.0f));
        physics->impulse(Vector2f(1.f * _direction.x, -10.f));
        _direction.x *= -1.f;
        physics->setGravityScale(1);
    }
}

