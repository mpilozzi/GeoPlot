#include "dropdown.h"

Dropdown::Dropdown(Target *tar)
{
    setTitle("Target Menu");

    QAction *actionClose;
    actionClose = new QAction("&Delete Target");
    addAction(actionClose);
	
    /*
    QAction *actionDuplicate;
    actionDuplicate = new QAction("&Duplicate Target");
    addAction(actionDuplicate);
	
	QAction *actionProperties;
	actionProperties = new QAction("&Target Properties");
	addAction(actionProperties);
    */
	
    connect(actionClose, SIGNAL(triggered()), tar, SLOT(destruct()));
}

