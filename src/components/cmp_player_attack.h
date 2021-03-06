#include "../../engine/lib_ecm/ecm.h"
#include <SFML/Graphics/Texture.hpp>
#include <audio_manager.h>

class PlayerAttackComponent : public Component
{
protected:
	std::weak_ptr<Entity> _player;

public:
	enum AttackType
	{
		DEFAULT,
		FIREBALL,
		ICICLE,
		SHOCK
	};

	struct Attack
	{
		AttackType type;
		int damage;
		float cooldown;
		sf::Vector2f spriteSize;
		std::string spriteSheet;
		int frameCount;
		int row;
		std::string sound;
	};

	Attack& getAttack(int);

	AttackType getAttackType() const;

	void update(double dt) override;
	void render() override;

	void fire();
	void changeAttack(AttackType at);

	explicit PlayerAttackComponent(Entity* p);
	PlayerAttackComponent() = delete;

private:
	float _cooldown;
	sf::Texture _spritesheet;
	sf::Vector2f _posOffset;
	float _speed;
	Attack _currentAttack;
	Attack _lastAttack;
	std::vector<Attack> _availableAttacks;

	void initAttacks();
};
