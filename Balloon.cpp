#include "Balloon.h"
#include <DxLib.h>
#include "Input.h"
#include "globals.h"
#include "cmath"

namespace {
	const int gravity = 1; //重力
	const int amplitude = 5; //振れ幅（※大きくすると幅が狭くなる）
	const int period = 0.8f; //周期（※小さくすると、遅くなる）
	double angles = 0; //角度
	int move_x = GetPos().x; //移動後のX座標
	int move_y = GetPos().y; //移動後のY座標

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

	if (isJumping) {
		move_x = cos(angles*period) * amplitude;
		SetPos(Vector2D(GetPos().x-move_x, GetPos().y-angles));
		angles += 0.1;
	}


	if (GetPos().y < 0 + 10 || GetPos().y > WIN_HEIGHT || GetPos().x < 0 || GetPos().x > WIN_WIDTH) {
		pos_.x = WIN_WIDTH / 2;
		pos_.y = GROUND_HEIGTH;
		vel_.y = 0;
		move_x = GetPos().x;
		move_y = GetPos().y;
		angles = 0; //角度を0度に
		isJumping = false;
	}
}

void Balloon::Draw()
{
	const Vector2D& pos = GetPos();
	DrawCircle(pos.x, pos.y, 20, GetCharaColor(), true);
}