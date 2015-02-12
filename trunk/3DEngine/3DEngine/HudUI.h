#ifndef HUDUI_H
#define HUDUI_H

#include "Player.h"
#include "TextureManager.h"
#include "Billboard.h"

namespace Engine
{
	class HudUI
	{
	public:
		HudUI();
		void Draw();
		void Update();

	private:
		Billboard m_bill;
		TextureManager m_tex;
	};
}

#endif 