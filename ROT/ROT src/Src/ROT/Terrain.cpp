#include "StdAfx.h"

#include "GameGL.h"
#include "Terrain.h"

#include "Tank.h"

#include "PhysicsMgr.h"

Terrain::Terrain(GameGL* a_pGameGL)
{
	m_pGameGL = a_pGameGL;

	GenerateTerrainContour();

	PhysicsMgrInstance().RegisterTerrain(this);
}

Terrain::~Terrain(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the terrain. </summary>
///
/// <remarks>	Priyank, 12/25/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::Initialize(void)
{
	m_TerrainImg = QImage(QString("./images/ground.png") );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Generates a terrain contour. </summary>
///
/// <remarks>	Priyank, 12/25/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::GenerateTerrainContour(void)
{
	 double rand1 = ( (rand()%100)/100.0 ) + 1;
     double rand2 = ( (rand()%100)/100.0 ) + 2;
     double rand3 = ( (rand()%100)/100.0 ) + 3;
 
	 float offset = ScreenHeight / 2;
     float peakheight = 100;
     float flatness = 70;
 
	 for (int x = 0; x < ScreenWidth; x++)
     {
         double height = peakheight / rand1 * sin((float)x / flatness * rand1 + rand1);
         height += peakheight / rand2 * sin((float)x / flatness * rand2 + rand2);
         height += peakheight / rand3 * sin((float)x / flatness * rand3 + rand3);
         height += offset;
		 m_TerrainContour[x] = (int)height;
     }

	 //for(std::size_t x = 0; x < ScreenWidth; x++)
		//m_TerrainContour[x] = 100;//-100 + ScreenHeight / 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates the foreground color for the terrain based on the terrainImg. </summary>
///
/// <remarks>	Priyank, 12/25/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::CreateForeground(void)
{
	int l_TerrainImgWidth = m_TerrainImg.width();
	int l_TerrainImgHeight = m_TerrainImg.height();

	for(std::size_t x = 0; x < ScreenWidth; x++) {
		for(std::size_t y = 0; y < ScreenHeight; y++) {
			if( y > m_TerrainContour[x] )
				m_ForegroundColor[x + (y * ScreenWidth)] = m_TerrainImg.pixel( x % l_TerrainImgWidth, y % l_TerrainImgHeight);
			else
				m_ForegroundColor[x + (y * ScreenWidth)] = Qt::transparent;
		}
	}

	//create a texture out of foreground colors if required
	m_TexID = CreateAndBindTexture(m_ForegroundColor, ScreenWidth, ScreenHeight);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates an and bind texture. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="colors">	The colors. </param>
/// <param name="a_Width">	Width of a. </param>
/// <param name="a_Height">	Height of a. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GLuint Terrain::CreateAndBindTexture(QRgb colors[], const std::size_t&a_Width, const std::size_t&a_Height)
{
	QImage img(a_Width, a_Height, QImage::Format_ARGB32);

	for(std::size_t x = 0; x < ScreenWidth; x++) {
		for(std::size_t y = 0; y < ScreenHeight; y++) {
			img.setPixel(x,y, colors[ x + (y * ScreenWidth)]);
		}
	}

	m_TexID = m_pGameGL->bindTexture(img, GL_TEXTURE_2D);

	return m_TexID;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Flatten terrain below tank (20 pixels). </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="a_pTank">	[in,out] If non-null, a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::FlattenTerrainBelowTank(Tank* a_pTank)
{
	for(int x = 0; x < a_pTank->GetWidth(); x++) {

		glm::vec2 colArrayPosn = Color4mScreen(a_pTank->GetPosn());

		//int k = a_pTank->GetPosn().x + x;
		int k = colArrayPosn.x + x;
		int posnX = colArrayPosn.x;

		if ( k >= 0 && k <= ScreenWidth ) {
			m_TerrainContour[ k ] = m_TerrainContour[ posnX ];
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Renders the Terrain. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::Render(void)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_TexID);

	float SW2 = m_pGameGL->width() * 0.5f; //ScreenWidth /2; 
	float SH2 = m_pGameGL->height() * 0.5f;//ScreenHeight /2;

	glPushMatrix();

		//drawing terrain
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);	glVertex2f(-SW2, -SH2);
			glTexCoord2f(1.0, 0.0);	glVertex2f(SW2, -SH2);
			glTexCoord2f(1.0, 1.0);	glVertex2f(SW2, SH2);
			glTexCoord2f(0.0, 1.0);	glVertex2f(-SW2, SH2);
		glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Posn in Color Array for a position on screen. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="posn">	The posn. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

glm::vec2 Terrain::Color4mScreen(const glm::vec2& a_ScreenPosn)
{
	int SW2 = ScreenWidth/2;
	int SH2 = ScreenHeight/2;

	glm::vec2 retPosn;

	retPosn.x = a_ScreenPosn.x + SW2;
	retPosn.y = a_ScreenPosn.y - SH2;

	retPosn.y *= -1;

	return retPosn;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets a foreground color 4 screen coords. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="posn">	The posn. </param>
///
/// <returns>	The foreground color 4 screen coords. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

const QRgb& Terrain::GetForegroundColor4ScreenCoords(const glm::vec2&posn)
{
	glm::vec2 colArrayPosn = Color4mScreen(posn);

	return m_ForegroundColor[ (int)colArrayPosn.x + ( (int)colArrayPosn.y * ScreenWidth)];
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Adds a crater. </summary>
///
/// <remarks>	Priyank, 12/30/2009. </remarks>
///
/// <param name="a_Posn">	a posn. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::AddCrater(const glm::vec2& a_Posn)
{
	int x = a_Posn.x;

	// transforming position in array m_TerrainContour's Coordinate system
	x += ScreenWidth/2;

	int width = 30;
	int th = 8;


	for(int k = x-width; k < x+width; k++) {
		if ( k >=0 && k < ScreenWidth) {
			//if( m_TerrainContour[k] 
			int val = width - abs(k - x ) ;
			val = (width - val) < th ? width : val;
			m_TerrainContour[k] = m_TerrainContour[k] + (val);		//make a circle
		}
	}

	CreateForeground();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the tanks by assigning them position and flattening terrain beneath them. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
///
/// <param name="m_TankMgr">	[in,out] manager for tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::InitializeTanks(TankMgr& a_TankMgr)
{
	//TankMgr::iterator it_Tanks;

	//int SH2 = ScreenHeight/2;
	//int SW2 = ScreenWidth/2;

	//int x = -SW2;

	//for( it_Tanks = a_TankMgr.begin(); it_Tanks != a_TankMgr.end(); it_Tanks++) {
	//	Tank* l_pTank = *it_Tanks;

	//	int posX = x;
	//	l_pTank->SetPosn( posX, -(m_TerrainContour[ posX + SW2 ] - SH2) ); //converts from TerrainContour array Y values to screen Coordinate system

	//	FlattenTerrainBelowTank(l_pTank);
	//	x += 250;

	//	// rounding x circularly
	//	if(x > SW2 * 2) {
	//		x -= SW2;

	//		x = -SW2 + x;
	//	}
	//}

	int SW2 = ScreenWidth/2;

	TankMgr::iterator it_Tanks;

	int x = -SW2;

	for( it_Tanks = a_TankMgr.begin(); it_Tanks != a_TankMgr.end(); it_Tanks++) {
		Tank* l_pTank = *it_Tanks;

		int posX = x;
		l_pTank->SetPosn( posX, 0 ); //converts from TerrainContour array Y values to screen Coordinate system

		x += 250;

		// rounding x circularly
		if(x > SW2 * 2) {
			x -= SW2;

			x = -SW2 + x;
		}
	}
	PlaceTanksOnGround(a_TankMgr );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Place tanks on ground. </summary>
///
/// <remarks>	Priyank, 1/31/2010. </remarks>
///
/// <param name="a_TankMgr">	[in,out] manager for a tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Terrain::PlaceTanksOnGround(TankMgr&a_TankMgr)
{
	TankMgr::iterator it_Tanks;

	int SH2 = ScreenHeight/2;
	int SW2 = ScreenWidth/2;

	for( it_Tanks = a_TankMgr.begin(); it_Tanks != a_TankMgr.end(); it_Tanks++) {
		Tank* l_pTank = *it_Tanks;

		int posX = l_pTank->GetPosn().x;
		l_pTank->SetPosn( posX, -(m_TerrainContour[ posX + SW2 ] - SH2) ); //converts from TerrainContour array Y values to screen Coordinate system

		FlattenTerrainBelowTank(l_pTank);
	}
}

