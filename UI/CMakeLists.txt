
qt_add_qml_module(UI STATIC
    URI "UI"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES main.qml BoxGenerator.qml
)

target_link_libraries(UI PUBLIC Qt6::Qml)
