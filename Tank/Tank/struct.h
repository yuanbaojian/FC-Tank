#pragma once

#define TOTAL_ENEMY_NUMBER	20
#define SHOWING_STAR	true		// 正在显示四角星
#define STOP_SHOW_STAR	false		// 四角星显示结束

struct BulletStruct
{
	int x, y;					// 子弹坐标, 根据不同方向指定不同的位置代表 x,y, 指定 x=SHOOTABLE_X 的时候可以发射子弹
	int dir;					// 子弹方向
	int speed[4];				// 子弹速度, 根据坦克级别给予不同速度系数. 每次移动不能超过4个像素点!! 不然会跨越 4*4 的格子!!检测bug

	/* 如果玩家击中敌机,设置该值为敌机的id, GameControl 循环内检测该值, 然后删除该敌机
	* 如果是敌机击中玩家, 设置该值为玩家id, 游戏循环内再检测该值处理玩家数据*/
	int mKillId;				// 记录子弹击中的敌机/玩家 id

	static IMAGE mBulletImage[4];		// 图片
	static int mBulletSize[4][2];		// {{4,3},{3,4},{4,3},{3,4}} 尺寸: 上下-3*4 / 左右-4*3
	static int devto_tank[4][2];		// 规定子弹的坐标相对于tank中心点的偏移量
	static int devto_head[4][2];		// 规定子弹图片左上角相对于弹头坐标的偏移量;上下方向弹头坐标在弹头的右边;左右则在弹头的上面那个点
	static int bomb_center_dev[4][2];	// 爆炸中心相对于子弹头的偏移量
};

struct BombStruct
{
	static IMAGE mBombImage[3];				// 子弹爆炸图
	int mBombX, mBombY;						// 爆炸点中心坐标
	bool canBomb;							// 是否开始显示爆炸图片 flag
	int counter;						// 取模计数器, 多少次循环更换一张图片
};

class BlastStruct
{
public:
	BlastStruct();
	~BlastStruct() {}

	static IMAGE image[5];
	int blastx, blasty;			// 中心坐标, 32*32
	bool canBlast;
	int counter;				// 计数多少次换一张图片
};

class StarClass
{
public:
	StarClass();
	static IMAGE mStarImage[4];	// 四角星图片, 有玩家赋值
	int mStarIndexDev;			// 索引的变化量, -1, 1  -1是star由小变大, 1 是star由大变小
	byte mStarIndex : 2;		// 四角星下标索引变化规律 0-1-2-3-2-1-0-1-2-3-...
	int mStarCounter;			// 计数,多少次变更一次图像
	bool mIsOuted;				// 四角星消失的时候坦克出现, 停止播放四角星闪烁图

	// Enemy 专用! Player 用不到
	int mTankOutAfterCounter;	// 一个随机计数之后, 四角星开始闪烁,坦克出现
};

// 玩家坦克出现的时候显示的闪烁环状保护圈
class RingClass
{
public:
	RingClass();
	void ShowRing(const HDC&, int centerx, int centery);		// 
	static IMAGE image[2];
	bool canshow;			// 是否可以显示环状
	int index_counter;		// 变化下标索引
};