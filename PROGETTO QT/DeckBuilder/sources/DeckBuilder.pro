######################################################################
# Automatically generated by qmake (3.1) Wed May 24 16:05:46 2023
######################################################################

TEMPLATE = app
TARGET = sources
INCLUDEPATH += .
QT += widgets

# Input
HEADERS += \
    Cards/AbstractCard.h \
    Cards/Album.h \
    Cards/IConstVisitor.h \
    Cards/IVisitor.h \
    Cards/Magia.h \
    Cards/Mazzo.h \
    Cards/Mostro.h \
    Cards/Segreto.h \
    \
    Engine/FilterVisitor.h \
    Engine/Memory.h \
    Engine/Query.h \
    Engine/ResultSet.h \
    Engine/Sorting.h \
    \
    view/ClassSelectionWidget.h \
    view/HomeWidget.h \
    view/MainWindow.h \
    view/LookupWidget.h \
    view/RecapWidget.h \
    view/ResultsWidget.h \
    view/SearchWidget.h \
    \
    Cards/DataMapper/JsonFile.h \
    Cards/JSONConverter/IReader.h \
    Cards/JSONConverter/Json.h \
    Cards/JSONConverter/JsonVisitor.h \
    Cards/JSONConverter/Reader.h \
    Cards/Repository/JsonRepository.h \
    \
    view/CardLayout/Box.h \
    view/CardLayout/CardVisualizer.h \
    view/ResultLayout/Grid.h \
    view/ResultLayout/IResultLayoutStrategy.h \
    \
    Vector_template.h \

SOURCES += \
    Cards/AbstractCard.cpp \
    Cards/Album.cpp \
    Cards/Magia.cpp \
    Cards/Mazzo.cpp \
    Cards/Mostro.cpp \
    Cards/Segreto.cpp \
    \
    Engine/FilterVisitor.cpp \
    Engine/Memory.cpp \
    Engine/Query.cpp \
    Engine/ResultSet.cpp \
    Engine/Sorting.cpp \
    \
    view/ClassSelectionWidget.cpp \
    view/HomeWidget.cpp \
    view/LookupWidget.cpp \
    view/MainWindow.cpp \
    view/RecapWidget.cpp \
    view/ResultsWidget.cpp \
    view/SearchWidget.cpp \
    \
    Cards/DataMapper/JsonFile.cpp \
    \
    Cards/JSONConverter/Json.cpp \
    Cards/JSONConverter/JsonVisitor.cpp \
    Cards/JSONConverter/Reader.cpp \
    \
    Cards/Repository/JsonRepository.cpp \
    \
    view/CardLayout/Box.cpp \
    \
    view/ResultLayout/Grid.cpp \
    \
    main.cpp \