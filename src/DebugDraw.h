#pragma once

#include "StringConv.h"

UsingFrameworkNamespace
UsingGraphicsNamespace
using namespace msclr;
using namespace System::Drawing;

namespace BulletSharp
{
	class DebugDrawWrapper;

	public ref class DebugDraw
	{
	private:
		DebugDrawWrapper* _debugDraw;

	internal:
		DebugDraw(DebugDrawWrapper* debugDraw);

	public:
		DebugDraw();

		virtual void Draw3dText(Vector3 location, String^ textString);
		virtual void DrawAabb(Vector3 from, Vector3 to, BtColor color);
		virtual void DrawArc(Vector3 center, Vector3 normal, Vector3 axis, btScalar radiusA, btScalar radiusB,
			btScalar minAngle, btScalar maxAngle, BtColor color, bool drawSect, btScalar stepDegrees);
		virtual void DrawArc(Vector3 center, Vector3 normal, Vector3 axis, btScalar radiusA, btScalar radiusB,
			btScalar minAngle, btScalar maxAngle, BtColor color, bool drawSect);
		virtual void DrawBox(Vector3 bbMin, Vector3 bbMax, Matrix trans, BtColor color);
		virtual void DrawBox(Vector3 bbMin, Vector3 bbMax, BtColor color);
		virtual void DrawContactPoint(Vector3 pointOnB, Vector3 normalOnB, btScalar distance, int lifeTime, BtColor color);
		virtual void DrawLine(Vector3 from, Vector3 to, BtColor color) {};
		virtual void DrawLine(Vector3 from, Vector3 to, BtColor fromColor, BtColor toColor);
		virtual void DrawSphere(Vector3 p, btScalar radius, BtColor color);
		virtual void DrawSphere(btScalar radius, Matrix transform, BtColor color);
		virtual void DrawSpherePatch(Vector3 center, Vector3 up, Vector3 axis, btScalar radius, btScalar minTh, btScalar maxTh,
			btScalar minPs, btScalar maxPs, BtColor color, btScalar stepDegrees);
		virtual void DrawSpherePatch(Vector3 center, Vector3 up, Vector3 axis, btScalar radius, btScalar minTh, btScalar maxTh,
			btScalar minPs, btScalar maxPs, BtColor color);
		virtual void DrawTransform(Matrix transform, btScalar orthoLen);
		virtual void DrawTriangle(Vector3 v0, Vector3 v1, Vector3 v2, BtColor color, btScalar);
		virtual void DrawTriangle(Vector3 v0, Vector3 v1, Vector3 v2, Vector3, Vector3, Vector3, BtColor color, btScalar alpha);

		virtual void ReportErrorWarning(String^ warningString);

		property DebugDrawModes DebugMode
		{
			DebugDrawModes get();
			void set(DebugDrawModes value);
		}

	internal:
		property DebugDrawWrapper* UnmanagedPointer
		{
			DebugDrawWrapper* get();
			void set(DebugDrawWrapper* value);
		}
	};

	// Each DebugDraw instance has an unmanaged DebugDrawWrapper instance
	// that receives the drawing commands from Bullet and passes them on
	// to DebugDraw itself.

	class DebugDrawWrapper : public btIDebugDraw
	{
	private:
		auto_gcroot<DebugDraw^> _debugDraw;
		int m_debugMode;

	public:
		DebugDrawWrapper(DebugDraw^ debugDraw);

		virtual void draw3dText(const btVector3& location, const char* textString);
		virtual void drawAabb(const btVector3& from, const btVector3& to, const btVector3& color);
		virtual void drawArc(const btVector3& center, const btVector3& normal, const btVector3& axis,
			btScalar radiusA, btScalar radiusB, btScalar minAngle, btScalar maxAngle,
			const btVector3& color, bool drawSect, btScalar stepDegrees);
		virtual void drawArc(const btVector3& center, const btVector3& normal, const btVector3& axis,
			btScalar radiusA, btScalar radiusB, btScalar minAngle, btScalar maxAngle,
			const btVector3& color, bool drawSect);
		virtual void drawBox(const btVector3& bbMin, const btVector3& bbMax, const btTransform& trans, const btVector3& color);
		virtual void drawBox(const btVector3& bbMin, const btVector3& bbMax, const btVector3& color);
		virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);
		virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);
		virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);
		virtual void drawSphere(const btVector3& p, btScalar radius, const btVector3& color);
		virtual void drawSphere(btScalar radius, const btTransform& transform, const btVector3& color);
		virtual void drawSpherePatch(const btVector3& center, const btVector3& up, const btVector3& axis, btScalar radius,
			btScalar minTh, btScalar maxTh, btScalar minPs, btScalar maxPs, const btVector3& color, btScalar stepDegrees);
		virtual void drawSpherePatch(const btVector3& center, const btVector3& up, const btVector3& axis, btScalar radius,
			btScalar minTh, btScalar maxTh, btScalar minPs, btScalar maxPs, const btVector3& color);
		virtual void drawTransform(const btTransform& transform, btScalar orthoLen);
		virtual void drawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2, const btVector3& color, btScalar);
		virtual void drawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2,
			const btVector3&, const btVector3&, const btVector3&, const btVector3& color, btScalar alpha);

		//virtual void baseDraw3dText(const btVector3& location,const char* textString);
		virtual void baseDrawAabb(const btVector3& from, const btVector3& to, const btVector3& color);
		virtual void baseDrawArc(const btVector3& center, const btVector3& normal, const btVector3& axis,
			btScalar radiusA, btScalar radiusB, btScalar minAngle, btScalar maxAngle,
			const btVector3& color, bool drawSect, btScalar stepDegrees);
		virtual void baseDrawArc(const btVector3& center, const btVector3& normal, const btVector3& axis,
			btScalar radiusA, btScalar radiusB, btScalar minAngle, btScalar maxAngle,
			const btVector3& color, bool drawSect);
		virtual void baseDrawBox(const btVector3& bbMin, const btVector3& bbMax, const btTransform& trans, const btVector3& color);
		virtual void baseDrawBox(const btVector3& bbMin, const btVector3& bbMax, const btVector3& color);
		//virtual void baseDrawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);
		virtual void baseDrawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);
		virtual void baseDrawSphere(const btVector3& p, btScalar radius, const btVector3& color);
		virtual void baseDrawSphere(btScalar radius, const btTransform& transform, const btVector3& color);
		virtual void baseDrawSpherePatch(const btVector3& center, const btVector3& up, const btVector3& axis, btScalar radius,
			btScalar minTh, btScalar maxTh, btScalar minPs, btScalar maxPs, const btVector3& color, btScalar stepDegrees);
		virtual void baseDrawSpherePatch(const btVector3& center, const btVector3& up, const btVector3& axis, btScalar radius,
			btScalar minTh, btScalar maxTh, btScalar minPs, btScalar maxPs, const btVector3& color);
		virtual void baseDrawTransform(const btTransform& transform, btScalar orthoLen);
		virtual void baseDrawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2, const btVector3& color, btScalar);
		virtual void baseDrawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2,
			const btVector3&, const btVector3&, const btVector3&, const btVector3& color, btScalar alpha);

		virtual void reportErrorWarning(const char* warningString);
		//virtual void baseReportErrorWarning(const char* warningString);

		virtual void setDebugMode(int debugMode)
		{
			m_debugMode = debugMode;
		}
		virtual int	getDebugMode() const
		{
			return m_debugMode;
		}
	};
};
