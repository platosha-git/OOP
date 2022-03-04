QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    draw/qt_drawer.cpp \
    draw/qtgraphfactory.cpp \
    drawlabel.cpp \
    edge/edge.cpp \
    facade/facade_viewer.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/camera_manager.cpp \
    managers/render_manager.cpp \
    managers/scene_manager.cpp \
    managers/transform_manager.cpp \
    matrix/matrix_4x4.cpp \
    matrix/transform_matrix_4x4.cpp \
    objects/camera/camera.cpp \
    objects/model/mesh/mesh.cpp \
    objects/model/model.cpp \
    objects/object.cpp \
    objects/object_composite.cpp \
    point/point.cpp \
    scene/scene.cpp \
    upload/director_model.cpp \
    upload/file_loader.cpp \
    upload/model_builder.cpp \
    upload/upload_model.cpp \
    vector/vector_iterator.cpp \
    commands/addCameraCom.cpp \
    commands/addModelCom.cpp \
    commands/removeCameraCom.cpp \
    commands/removeModelCom.cpp \
    commands/renderCom.cpp \
    commands/setCameraCom.cpp \
    commands/transformCameraCom.cpp \
    commands/transformModelCom.cpp

HEADERS += \
    commands/command.h \
    draw/abstract_graph_factory.h \
    draw/base_drawer.h \
    draw/base_graphics.h \
    draw/qt_drawer.hpp \
    draw/qt_graphics.h \
    draw/qtgraphfactory.h \
    drawlabel.h \
    edge/edge.hpp \
    exceptions/exceptions.h \
    facade/facade_viewer.hpp \
    mainwindow.h \
    managers/camera_manager.hpp \
    managers/manager.h \
    managers/model_load_manager.hpp \
    managers/render_manager.hpp \
    managers/scene_manager.hpp \
    managers/transform_manager.hpp \
    managers/upload_manager.h \
    matrix/matrix_4x4.hpp \
    matrix/transform_matrix_4x4.hpp \
    objects/camera/camera.hpp \
    objects/invisible_object.h \
    objects/model/mesh/mesh.hpp \
    objects/model/model.hpp \
    objects/object.hpp \
    objects/object_composite.hpp \
    objects/visible_object.h \
    point/point.hpp \
    scene/scene.hpp \
    upload/base_loader.h \
    upload/base_model_builder.h \
    upload/director_model.hpp \
    upload/file_loader.hpp \
    upload/model_builder.hpp \
    upload/upload_model.hpp \
    vector/vector.h \
    vector/vector_base.h \
    vector/vector_iterator.hpp \
    visitor/visitor.h \
    commands/addCameraCom.h \
    commands/addModelCom.h \
    commands/removeCameraCom.h \
    commands/removeModelCom.h \
    commands/renderCom.h \
    commands/setCameraCom.h \
    commands/transformCameraCom.h \
    commands/transformModelCom.h \
    controller/controller.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
