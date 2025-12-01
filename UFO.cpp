#include "UFO.h"
#include <DxLib.h>
#include "globals.h"
#include <cmath>

UFO::UFO()
 : BaseChara(){
}

UFO::UFO(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::CIRLCE){
}

UFO::~UFO()
{
}

void UFO::Update()
{
	RepeatMoveLeftRight();
}

void UFO::Draw()
{
	const Vector2D& pos = GetPos();
	DrawCircle(pos.x, pos.y, 20, GetCharaColor(), true);
}

void UFO::RepeatMoveLeftRight()
{
	float dt = GetDeltaTime();
	Vector2D pos = GetPos();

	const float left = 0.0f;
	const float right = WIN_WIDTH - 20;

	static double a = 0; //Šp“x
	static int move_y = GetPos().y;

	move_y = sin(a * 1.2f) * 10; 
	SetPos(Vector2D(pos.x + a, pos.y + move_y));
	static int b = 1; //•„†
	a += 0.1 * b; //Šp“x‚ð•Ï‚¦‚Ä‚¢‚­
	if (pos.x > right) {
		SetPos(Vector2D(right, pos.y));
		SetVel(Vector2D(-GetVel().x, GetVel().y));
		move_y = GetPos().y;
		a = 0;
		b *= -1;
	}
	else if (pos.x < left) {
		SetPos(Vector2D(left, pos.y));
		SetVel(Vector2D(-GetVel().x, GetVel().y));
		move_y = GetPos().y;
		a = 0;
		b *= -1;
	}
}
