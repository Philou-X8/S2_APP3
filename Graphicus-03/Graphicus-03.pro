TEMPLATE     = vcapp
TARGET       = Graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h canevas.h carre.h cercle.h coordonnee.h
SOURCES     += Graphicus-03.cpp monInterface.cpp canevas.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets
