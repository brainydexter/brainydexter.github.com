#include "OptionsWidget.h"

#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>

OptionsWidget::OptionsWidget(QWidget* parent)
{
	//m_pAudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	//m_pMediaObject = new Phonon::MediaObject(this);
	
	//Phonon::createPath( m_pMediaObject, m_pAudioOutput );

	//m_pMediaObject->setCurrentSource(Phonon::MediaSource("./FX/fires.wav"));

	//m_pVolumeSlider = new Phonon::VolumeSlider(this);
	//m_pVolumeSlider->setAudioOutput(m_pAudioOutput);

	//m_pMediaObject->play();
	QGridLayout* layout = new QGridLayout();

	//layout->sizeHint();
	//layout->setSizeConstraint(QLayout::SetFixedSize);
	this->setLayout( layout);

	m_pSpinBox = new QSpinBox(this);
	m_pSpinBox->setValue( 3 );
	m_pSpinBox->setMinimum(1);
	m_pSpinBox->setMaximum(3);
	m_pSpinBox->setWrapping(true);

	layout->addWidget(new QLabel("Game Options"),0,0, Qt::AlignHCenter);
	layout->addWidget(new QLabel("Number of Computer players: "), 2, 0, Qt::AlignHCenter);
	layout->addWidget(m_pSpinBox, 2, 1, Qt::AlignHCenter );
	
	layout->setColumnStretch(0, 100 );
	layout->setRowMinimumHeight(1, 50 );
	layout->setRowMinimumHeight(3, 400 );
	//layout->addSpacerItem(new QSpacerItem(this->width(), this->height() * 0.8));
	
}

OptionsWidget::~OptionsWidget(void)
{
}
