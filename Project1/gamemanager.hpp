#pragma once
#include "point.hpp"
#include "raymath.h"
#include <vector>
namespace Core {

class GameManager {
public:
	std::vector<Objects::Point> pvec; 
	enum gameStates {
		NORMAL,
		EDIT
	};
	enum gameStates currentState; 
	void DrawPoints(); 
	void CreatePoint();
	void MovePoint();
	void DeleteAllPoints(); 
	void DrawLines();
	Objects::Point Lerp(Objects::Point pa, Objects::Point pb, float t);
	void DrawLerp();

private:

};


} 