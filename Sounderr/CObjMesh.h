#pragma once

#include <GL\glew.h>
#include <string>
#include <fstream>
#include <vector>


using namespace std;


// struktura opisujaca pojedynczy wierzcholek
struct VERTEX
{
	D3DXVECTOR3   position;
	D3DXVECTOR3   normal;
	D3DXVECTOR2 texcoord;
};


// uzywamy pozycji wierzcholka, wektora normalnego i tekstury
#define VERTEX_FVF (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)


// klasa pojedynczego modelu
class CObjMesh
{
public:
	CObjMesh();
	~CObjMesh();


	void Create(IDirect3DDevice9* _pDevice, string _strPath);


	vector< D3DXVECTOR3 >   Positions;
	vector< D3DXVECTOR2 >   TexCoords;
	vector< D3DXVECTOR3 >   Normals;
	vector< VERTEX >      m_Vertices;
	vector< DWORD >         m_Indices;

	void Render();
	void Destroy();


private:
	void LoadGeometryFromObj(string _strPath);


	IDirect3DDevice9      *m_pDevice;
	ID3DXMesh            *m_pMesh;
	IDirect3DTexture9      *m_pTexture;


	VERTEX   *pVertices;
	WORD   *pIndices;


}; #pragma once
