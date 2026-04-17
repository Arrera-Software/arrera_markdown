import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    anchors.fill: parent
    Row {
        anchors.centerIn: parent
        spacing: 30
        Button {
            implicitWidth: 80
            implicitHeight: 80

            icon.source: "qrc:/icone_gui/add_light.png"
            icon.width: 40
            icon.height: 40

            highlighted: true
            Material.accent: Material.Indigo

            onClicked: main.create_document()
        }

        Button {
            implicitWidth: 80
            implicitHeight: 80
            icon.source: "qrc:/icone_gui/open_light.png"
            icon.width: 40
            icon.height: 40

            highlighted: true
            Material.accent: Material.Indigo

            onClicked: main.open_document_btn_welcome()
        }
    }
}
