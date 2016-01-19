TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    controlleurjeu.cpp \
    affichagejeu.cpp \
    partie.cpp \
    carte.cpp \
    case.cpp \
    objet.cpp \
    entite.cpp \
    creature.cpp \
    joueur.cpp \
    inventaire.cpp \
    conteneur.cpp \
    couleur.cpp

HEADERS += \
    controlleurjeu.h \
    affichagejeu.h \
    partie.h \
    carte.h \
    case.h \
    objet.h \
    entite.h \
    creature.h \
    joueur.h \
    inventaire.h \
    conteneur.h \
    couleur.h

INCLUDEPATH += \
    /usr/include/freetype2

LIBS += \
    -lGL \
    -lGLU \
    -lGLEW \
    -lglfw  \
    -lftgl   \
