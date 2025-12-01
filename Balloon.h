#pragma once
#include "BaseChara.h"
class Balloon :
    public BaseChara
{
private:
    bool isJumping = false;
public:
    Balloon();
    Balloon(const Vector2D& pos, const Vector2D& vel,
        unsigned int color);
    ~Balloon();
    void Update() override; //オーバーライド
    void Draw() override; //オーバーライド

    void LaunchBallon();
};

