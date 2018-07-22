# include <Siv3D.hpp>

enum CallGroup
{
	CallGroup_Update,
	CallGroup_Draw,
};

enum CallPriority
{
	CallPriority_GunShot,		//最初に描画が行われる
	CallPriority_Enemy,	//その後に描画が行われるので、プレイヤーが隠れない
};

class GunShot : public Task
{
private:
	Vec2		m_Pos;
	Vec2		m_Size;
	TaskCall	m_Update;
	TaskCall	m_Draw;
	TaskLink	m_Send;
public:
	GunShot() : Task(TaskDestroyMode::Time, 1.0)
		, m_Pos(30, Random(260, 440))
		, m_Size(25, 20)
		, m_Update(this, &GunShot::Update, CallGroup_Update)
		, m_Draw(this, &GunShot::Draw, CallGroup_Draw, CallPriority_GunShot)
		, m_Send(this)
	{ }
	Rect getRect() const
	{
		return Rect(m_Pos.x, m_Pos.y, m_Size.x, m_Size.y);
	}
private:
	void Update()
	{
		m_Pos.x += 10;
	}
	void Draw()
	{
		Rect(m_Pos.x, m_Pos.y, m_Size.x, m_Size.y).draw();
	}
};

class Enemy : public Task
{
private:
	Vec2		m_Pos;
	int32		m_Speed;
	int32		m_Radius;
	int32		m_HP;
	TaskCall	m_Update;
	TaskCall	m_Draw;
public:
	Enemy() : Task()
		, m_Pos(600, 400), m_Speed(1)
		, m_Radius(30), m_HP(Random(2, 3))
		, m_Update(this, &Enemy::Update, CallGroup_Update)
		, m_Draw(this, &Enemy::Draw, CallGroup_Draw, CallPriority_Enemy)
	{ }
private:
	void Update()
	{
		if (m_Pos.y <= 260)
		{
			m_Speed = 1;
		}
		else if (m_Pos.y >= 460)
		{
			m_Speed = -1;
		}
		m_Pos.y += m_Speed;
		if (m_HP <= 0)
		{
			m_Update.SetCall(&Enemy::Death);
		}
		TaskLink::All::Call<GunShot>(this, &Enemy::HitCheck);
	}
	void Death()
	{
		--m_Radius;
		if (m_Radius <= 0)
		{
			Create<Enemy>();
			this->Destroy();
		}
	}
	void Draw()
	{
		Circle(m_Pos, m_Radius).draw();
	}
public:
	void HitCheck(GunShot& gunShot)
	{
		if (Circle(m_Pos, m_Radius).intersects(gunShot.getRect()))
		{
			--m_HP;
			gunShot.Destroy();
		}
	}
};


class Spark : public Task
{
private:
	Vec2 m_Pos;
	int32 m_Alpha;
	double m_Radius;
	TaskCall m_Update;
public:
	Spark(const Vec2& pos, const double& radius) : Task()
		, m_Pos(pos + RandomVec2(Circle(radius)))
		, m_Alpha(100), m_Radius(3.0)
		, m_Update(this, &Spark::Update)
	{ }
private:
	void Update()
	{
		m_Alpha -= 5;
		if (m_Alpha <= 0)
		{
			this->Destroy();
		}
		else
		{
			Circle(m_Pos, m_Radius).draw(Alpha(m_Alpha));
		}
	}
};

class Note : public Task
{
private:
	Vec2		m_Pos;		//座標
	double		m_Radius;	//描画半径
	int32		m_Alpha;	//不透明度
	double		m_RingSize;

	TaskCall	m_Update;	//更新設定

public:
	Note() : Task()
		, m_Pos(RandomVec2({ 30, 610 }, { 30, 210 }))
		, m_Radius(0.0), m_Alpha(100)
		, m_RingSize(30.0)
		, m_Update(this, &Note::Swell)
	{ }

private:
	void Swell()
	{
		//半径を拡大
		m_Radius += 0.5;
		//半径が32以上で更新関数切り替え
		if (m_RingSize + 2.0 <= m_Radius) m_Update.SetCall(&Note::Deflate);
		
		if (Input::MouseL.clicked && (m_Pos.distanceFrom(Mouse::Pos())) <= 30.0) 
		{
			if (m_Radius - m_RingSize >= -2.0)
			{
				m_Update.SetCall(&Note::Rupture);
			}
			else
			{
				m_Update.SetCall(&Note::Deflate);
			}
		}

		//描画
		Circle(m_Pos, m_RingSize).drawFrame(2.0, 0.0);
		Circle(m_Pos, m_Radius).draw(Alpha(m_Alpha));
	}

	void Deflate()
	{
		//不透明度を下げる
		m_Alpha -= 5;
		//完全透明で消去
		if (m_Alpha <= 0) this->Destroy();

		//描画
		else 
		{
			Circle(m_Pos, m_RingSize).drawFrame(2.0, 0.0, Alpha(m_Alpha));
			Circle(m_Pos, m_Radius).draw(Alpha(m_Alpha));
		}
	}

	void Rupture()
	{
		Creates<Spark>(100, m_Pos, m_Radius);
		Create<GunShot>();
		this->Destroy();
	}
};




//-------------------------------------------- 区切り --------------------------------------------//

void Main()
{
	int32 frameCount = 0;
	Create<Enemy>();
	
	while (System::Update())
	{
		//ノーツを生成
		if (++frameCount % 30 == 0) Create<Note>();

		TaskCall::All::Update();
		TaskCall::All::Update(CallGroup_Update);
		TaskCall::All::Update(CallGroup_Draw);
		Task::All::Update();
	}

	Task::All::Clear();
}