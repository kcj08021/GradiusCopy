#include "pch.h"
#include "Radian.h"


float Radian::DTR(float Degree)
{
	float m_Radian = PI / 180 * Degree;
	return m_Radian;
}

float Radian::RTD(float Radian)
{
	float m_Degree = 180 / PI * Radian;
	return m_Degree;
}

float Radian::GetRadian(float standardx, float standardy, float targetx, float targety)
{
	float iX = targetx - standardx;
	float iY = targety - standardy;
	float iDistance = sqrtf(iX * iX + iY * iY);
	float iDegree = acosf(iX / iDistance);
	return iDegree;
}

float Radian::GetDistance(float StartX, float StartY, float EndX, float EndY)
{
	float x = EndX - StartX;
	float y = EndY - StartY;
	float m_Distance = sqrtf(x * x + y * y);
	return m_Distance;
}
