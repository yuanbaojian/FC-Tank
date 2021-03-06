#pragma once

/************ 单个坦克信息 *********
* 玩家坦克信息
* 敌机坦克信息
***********************************/
class TankInfo
{
public:
	TankInfo(byte enemy_kind, int enemy_level, bool notuse );	// enemy_kind [0-1]; enemy_level [0-4], notuse->区别玩家坦克
	TankInfo(byte player, byte level);							// player [0-1]; level [0-3]
	~TankInfo();

	IMAGE GetTankImage( byte dir, int index = 0 );		// index 两张不同动作的图片索引 [0-1]
private:
	IMAGE mTankImage[4][2];			// 四个方向,一个方向两张贴图实现坦克移动动作.
};

/************ 玩家坦克级别 **********/

class PlayerTank
{
public:
	PlayerTank(byte player);		// player [0-1]
	~PlayerTank();
	IMAGE GetTankImage( byte level, byte dir, bool moving = false );	// 
private:
	TankInfo* mTankInfo[4];			// 4 个级别坦克
	byte mMoveIndex : 1;		// 两张坦克图片组成一个动作的 下标索引
};

