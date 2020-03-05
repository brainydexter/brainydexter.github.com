#pragma once
#include "c:\qt\4.6.0-vc\qt\src\gui\kernel\qwidget.h"

class QLabel;
class QPushButton;

class MenuWidget :
	public QWidget
{
public:
	MenuWidget(QWidget* parent = 0);
	~MenuWidget(void);

	// Access the Label
	QLabel* &GetLabel(void)						{ return(m_pLabel);				}

	// Access the Play_Button
	QPushButton* &GetPlay_Button(void) 			{ return(m_pPlay_Button);		}

	// Access the Options_Button
	QPushButton* &GetOptions_Button(void) 		{ return(m_pOptions_Button);	}

	// Access the Help_Button
	QPushButton* &GetHelp_Button(void) 			{ return(m_pHelp_Button);		}

	// Access the Quit_Button
	QPushButton* &GetQuit_Button(void) 			{ return(m_pQuit_Button);		}


	// Access the Resume_Play_Button
	QPushButton* &GetResume_Play_Button(void) 	{ return(m_pResume_Play_Button);}


protected:
	QLabel* m_pLabel;
	QPushButton* m_pResume_Play_Button;
	QPushButton* m_pPlay_Button;
	QPushButton* m_pOptions_Button;
	QPushButton* m_pHelp_Button;
	QPushButton* m_pQuit_Button;
};
