#include "gamemanager.hpp"
#include "raylib.h"

using namespace Core;

void GameManager::CreatePoint() {
	Vector2 mpos = GetMousePosition();
	pvec.push_back(Objects::Point(mpos));
}

void GameManager::DrawPoints() {
	for (int i = 0; i < pvec.size(); i++) {
		DrawCircleV(pvec[i].pos, 15.0f, RED);
	}
}
 void GameManager::MovePoint() { 
	 for (int i = 0; i < pvec.size(); i++) {
		 if (CheckCollisionCircles(GetMousePosition(), 20, pvec[i].pos, 20)) {
			 pvec[i].pos = GetMousePosition();
		 }
	}
}

 void GameManager::DeleteAllPoints() {
	 pvec.clear();
 }

 void GameManager::DrawLines() {
	 if (pvec.size() >= 3) {
		 for (int i = 0; i < pvec.size() - 1; i++) {
			 DrawLineEx(pvec[i].pos, pvec[i + 1].pos, 3.0f, BLUE);

		 }
	 }
 }

Objects::Point GameManager::Lerp(Objects::Point pa, Objects::Point pb, float t) {
	return Objects::Point((pa.pos + (pb.pos - pa.pos) * t));
 }


void GameManager::DrawLerp() {
	if (pvec.size() >= 3) {
		std::vector<Objects::Point> curvePoints;
		for (float t = 0.0f; t <= 1; t += 0.005f) {
			std::vector<Objects::Point> startingPoints = pvec;
			std::vector<Objects::Point> newPoints;
			while (startingPoints.size() > 1) {
				for (int i = 0; i < startingPoints.size() - 1; i++) {
					newPoints.push_back(Lerp(startingPoints[i], startingPoints[i + 1], t));
				}
				startingPoints = newPoints;
				newPoints.clear();
			}
			curvePoints.push_back(startingPoints[0]);
		}
		for (int i = 0; i < curvePoints.size() - 1; i++) {
			DrawLineEx(curvePoints[i].pos, curvePoints[i + 1].pos, 3.0f, RED);
		}

	}
}

	