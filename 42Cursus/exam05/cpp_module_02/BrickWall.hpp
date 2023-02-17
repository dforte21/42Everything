#pragma once

#include "ATarget.hpp"

using namespace std;

class BrickWall : public ATarget{
	public:
		BrickWall();
		~BrickWall();

		virtual ATarget *clone() const;
};