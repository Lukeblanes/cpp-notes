#include <iostream>

// casting is not usually enforced in c++
// dynamic casting is a safety net for 
// when we want to do a specific type
// of casting

// there are two types of cast
// the c type cast, which is like this. (int)a

// in c++, we have multiple ways of casting

// dynamic cast does some validation to ensure
// the cast is valid

// since the dynamic cost is done at runtime
// it has an additional performance cost

// dynamic cast is usually done in an inheritance
//  hierarchy. Dynamic cast is used to cast
// from a base class to a derived or viceversa

// derived class to base class is an easy cast
// and can be done with dynamic cast or static cast.

// casting from a base class to a derived is trickier


class Entity
{
public:
	// Added function add vtable to class
	// and make it polymorphic
	virtual void makePolymorphic() {}
};

class Player: public Entity 
{
};

class Enemy: public Entity 
{
};

int main()
{
	// this implicitly has two types, Entity and Player
	// Player* player = new Player();

	// so i can change it to 
	Entity* player1 = new Player();

	// or do 
	Enemy * enemy = new Enemy();
	Entity* e = enemy;
	
	// If i try to cast from entity to player, we're gonna get an error
	// Player* p_err = e;

	// we can't do this because they're different types

	// we can solve it by doing a c-style cast
	
	Player* p_dangerous = (Player*)e;

	// the c++ way of doing a static cast is like this
	Player* p_static = static_cast<Player*>(e);

	// Here's the dynamic cast
	Player* p_dynamic_fail = dynamic_cast<Player*>(e);
	if (p_dynamic_fail)
		std::cout << "Casted from entity_enemy to player\n";

	Player* p_dynamic_work = dynamic_cast<Player*>(player1);
	if (p_dynamic_work)
		std::cout << "Casted from entity_player to player\n";


	// the cast from enemy to Entity and then to player should fail
	// so it returns Null

	// the cast from player to Entity and back to player returns a valid entity

	// this is done by using Runtime Type Information (RTTI)

	// RTTI is something that can be enabled or disabled by the compiler
	// gcc has it on by default

	// It should be taken into account that using RTTI has an overhead.
}

