#ifndef ROT_TERRAIN_H
#define ROT_TERRAIN_H

#include "TankMgr.h"

class GameGL;

class Terrain
{
public:
	Terrain(GameGL* a_pGameGL);
	~Terrain(void);

	void Initialize();
	void Render();

	void Update();

	void InitializeTanks(TankMgr& a_TankMgr);
	void PlaceTanksOnGround(TankMgr& a_TankMgr);

	void CreateForeground();		// Colors the terrain based on the height values in m_TerrainContour

	const QRgb& GetForegroundColor(int x, int y) const	{ return m_ForegroundColor[ x + y * ScreenWidth];	};
	const QRgb& GetForegroundColor4ScreenCoords(const glm::vec2& posn) ;

	void AddCrater(const glm::vec2& a_Posn);
private:
	glm::vec2 Color4mScreen(const glm::vec2& posn);

	void GenerateTerrainContour();		//populates heightvalues for all the x coordinates in m_TerrainContour[]
	GLuint CreateAndBindTexture(QRgb colors[], const std::size_t& a_Width, const std::size_t& a_Height);

	void FlattenTerrainBelowTank( Tank* a_pTank );		// Flattens 20 pixels along X on the terrain

protected:
	GameGL* m_pGameGL;

	unsigned int m_TerrainContour[800];		// in screen coordinate system

	QRgb m_ForegroundColor[800 * 600];		// image's own coordinate system
	GLuint m_TexID;

	QImage m_TerrainImg;

};

#endif