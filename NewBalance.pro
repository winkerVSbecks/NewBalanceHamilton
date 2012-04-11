HEADERS += ShoeWidget890.hpp
HEADERS += ShoeWidget1080.hpp
HEADERS += ShoeWidgetRoad.hpp
HEADERS += ShoeWidgetTrail.hpp
HEADERS += ShoeWidgetAtheletes.hpp
HEADERS += CustomSliderWidget.hpp
HEADERS += FormWidgetPurchase.hpp
HEADERS += FormWidgetTry.hpp
HEADERS += Global.hpp
HEADERS += ImageWithClose.hpp
HEADERS += AnimatorWidget.hpp

SOURCES += CustomSliderWidget.cpp
SOURCES += ShoeWidget890.cpp
SOURCES += ShoeWidget1080.cpp
SOURCES += ShoeWidgetRoad.cpp
SOURCES += ShoeWidgetTrail.cpp
SOURCES += ShoeWidgetAtheletes.cpp
SOURCES += FormWidgetPurchase.cpp
SOURCES += FormWidgetTry.cpp
SOURCES += Global.cpp
SOURCES += ImageWithClose.cpp
SOURCES += AnimatorWidget.cpp
SOURCES += Main.cpp

#include "ShoeWidget890.hpp"
#include "ShoeWidget1080.hpp"
#include "ShoeWidgetRoad.hpp"
#include "ShoeWidgetTrail.hpp"
#include "FormWidgetTry.hpp"
#include "FormWidgetPurchase.hpp"

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += sdl
}

macx {
  LIBS += -framework Patterns
  LIBS += -framework Nimble 
  LIBS += -framework Radiant
  LIBS += -framework Valuable
  LIBS += -framework Luminous
  LIBS += -framework Poetic
  LIBS += -framework Resonant
  LIBS += -framework Screenplay
  LIBS += -framework VideoDisplay
  LIBS += -framework MultiTouch
  LIBS += -framework Fluffy
  LIBS += -framework MultiWidgets
  LIBS += -framework ThreadedRendering 
  LIBS += -lGLEW

  LIBS += -framework Cocoa
}

linux-* {
  LIBS += -lMultiWidgets -lThreadedRendering
}

win* {

  INCLUDEPATH += $$(CORNERSTONE_ROOT)\\include

  LIBS += -L$$(CORNERSTONE_ROOT)\\lib
  
  LIBS += -lPatterns
  LIBS += -lNimble 
  LIBS += -lRadiant
  LIBS += -lValuable
  LIBS += -lLuminous
  LIBS += -lPoetic
  LIBS += -lResonant
  LIBS += -lScreenplay
  LIBS += -lVideoDisplay
  LIBS += -lMultiTouch
  LIBS += -lFluffy
  LIBS += -lMultiWidgets
  LIBS += -lThreadedRendering 
  
  CONFIG += console
}


