#pragma once
#include "c:\qt\4.6.0-vc\qt\src\gui\kernel\qwidget.h"

#include <QList>
//#include <Phonon/MediaSource>

//#include <Phonon/MediaObject>
//#include <Phonon/AudioOutput>
//#include <Phonon/MediaSource>

//#include <Phonon/VolumeSlider>

class QSpinBox;

class OptionsWidget :
	public QWidget
{
public:
	OptionsWidget(QWidget* parent = 0);
	~OptionsWidget(void);

	// Access the SpinBox
	QSpinBox* &GetSpinBox(void) 		{ return(m_pSpinBox);	};

protected:
	//QPushButton
	//Phonon::MediaObject* m_pMediaObject;
	//Phonon::AudioOutput* m_pAudioOutput;
	//QList< Phonon::MediaSource> m_pMediaSources;

	//Phonon::VolumeSlider *m_pVolumeSlider;

	QSpinBox* m_pSpinBox;

};
