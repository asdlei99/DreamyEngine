////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#pragma once

// graphicsclass는 이 어플리키에션의 모든 그래픽 기능이 이 객체안에 캡슐화되어 있다.
// 나중에 모든 그래픽 객체들을 담을것이다. -> 여기서 그래픽 객체들을 또 클래스로 묶으면..?

//////////////
// INCLUDES //
//////////////
#pragma once
#include "D3DClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
#include "ShaderManagerClass.h"
#include "LightClass.h"
#include "ImageClass.h"
#include "TextClass.h"
#include "FrustumClass.h"
#include "ModelManagerClass.h"
#include "RTTTextureClass.h"
#include "TerrainClass.h"
#include "TerrainShaderClass.h"
#include "SkyClass.h"
#include "FBXModel.h"
#include "WaterClass.h"




/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
//수직 동기화(fps고정)
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	bool Loading(int, int, HWND);

	void Shutdown();
	bool Frame(int, int, float, D3DXVECTOR3, D3DXVECTOR3, int, int);// + 카메라 회전
	bool Render(bool);


	bool RenderMainScene();
	bool RenderLoadingScene();

	//Picking 검사
	void TestIntersection(int, int, int, int);
	bool RaySphereIntersect(D3DXVECTOR3 rayOrigin, D3DXVECTOR3 rayDirection, float radius);
public:
	bool F1pressed;
	D3DXMATRIX baseViewMatrix; //글꼴이 항상 같은 위치에 출력되게
	D3DXMATRIX minimapMatrix; // 미니맵 


private:

	//RTT기능을 사용할 수 있게 두 종류의 렌더링 함수를 생성한다.
	//렌더링이 두 번 일어나도록 분리했다.(첫번째는 텍스처에, 그 다음 일반 백버퍼에 그리는것)
	bool RenderToTexture();
	bool RenderRTTScene();
	bool RenderRunningScene(bool);
	bool RenderRefractionToTexture(bool); // 호수 굴절 텍스처
	bool RenderReflectionToTexture(); // 호수 반사 텍스처


private:
	bool sibal = true;

	D3DClass* m_D3D; 
	
	CameraClass* m_Camera;
	CameraClass* m_minimapCamera;

	ShaderManagerClass* m_Shader;
	LightClass* m_Light;

	ModelClass* m_Model_Plane;
	ModelClass* m_Model_Plane2;

	ModelClass* m_Model_Cube;

	ModelClass* m_Model_Cube3;

	ModelClass* m_Model_Mirror;

	ModelClass* m_Model_Circle;
	ModelManagerClass* m_Model_CircleList;

	ImageClass* m_2D_Love;
	ImageClass* m_Loading;
	ImageClass* m_CrossHair;
	ImageClass* m_Cursor;

	TextClass* m_Title;

	FrustumClass* m_Frustum;


	RTTTextureClass* m_RTTTexture;
	
	TerrainClass* m_Terrain;
	TerrainShaderClass* m_TerrainShader;


	SkyClass* m_Sky;
	SkyClass* m_Cloud;

	D3DXVECTOR3 CharacterPos;
	D3DXVECTOR3 CharacterRot;
	int MousePosX, MousePosY;

	FBXModel* m_fbx;

	//호수
	RTTTextureClass* m_RefractionTexture; //*m_ReflectionTexture;
	WaterClass* m_Water;
	TerrainClass* m_WaterTerrain;
	TerrainShaderClass* m_WaterTerrainShader;



};

