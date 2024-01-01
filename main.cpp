#include <bits/stdc++.h>

using namespace std;

#define SHOW(...) std::cout << #__VA_ARGS__ << " == " << __VA_ARGS__ << '\n'

enum class RocketType
{
	ROCKET_AT = 0,
	ROCKET_AP = 1
};

struct Rocket
{
	RocketType type;
	float blastRadius;
};

template <typename T>
class Player
{
public:
	void Attack()
	{
		cout << "generic attack" << endl;
	}
};

template <>
class Player<Rocket>
{
	struct Rocket r;
public:
	void setRocketBlastRadius(float radius) { r.blastRadius = radius; }
	void setRocketType(RocketType type) { r.type = type; }
	void Attack()
	{
		cout << "rocket fire: " << endl;
		SHOW(r.blastRadius);
		SHOW((int)r.type);
	}
};


int main()
{
	Player<void> regularPlayer;
	regularPlayer.Attack();

	Player<Rocket> rocketPlayer;
	rocketPlayer.setRocketBlastRadius(2.3f);
	rocketPlayer.setRocketType(RocketType::ROCKET_AP);
	rocketPlayer.Attack();

	return 0;
}