#include "Balloon.h"
#include <DxLib.h>
#include "Input.h"
#include "globals.h"
#include "cmath"

namespace {
	const int gravity = 1; //重力
	const int amplitude = 20; //振れ幅（※大きくすると幅が狭くなる）
	const int period = 1.0f; //周期（※小さくすると、遅くなる）
}

Balloon::Balloon()
	:BaseChara() {
}

Balloon::Balloon(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::CIRLCE){
}

Balloon::~Balloon()
{
}

void Balloon::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
		isJumping = true;
	}

	static double angles = 0; //角度

	if (isJumping) {
		vel_.x = cos(angles * period) * amplitude;

		pos_.x = pos_.x - vel_.x;
		pos_.y = pos_.y - angles;
		angles += 0.1;
	}


	if (GetPos().y < 0 + 10 || GetPos().y > WIN_HEIGHT || GetPos().x < 0 || GetPos().x > WIN_WIDTH) {
		pos_.x = WIN_WIDTH / 2;
		pos_.y = GROUND_HEIGTH;
		vel_.x = 0;
		vel_.y = 0;
		angles = 0; //角度を0度に
		isJumping = false;
	}
}

void Balloon::Draw()
{
	const Vector2D& pos = GetPos();
	DrawCircle(pos.x, pos.y, 20, GetCharaColor(), true);
}