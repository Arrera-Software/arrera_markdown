import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    implicitWidth: 200
    implicitHeight: 600

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 15

        Button {
            icon.source: "qrc:/icone_gui/add_light.png"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.create_document()
        }

        Button {
            icon.source: "qrc:/icone_gui/space_light.png"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.view_espace()
        }

        Button {
            icon.source: "qrc:/icone_gui/template_light.png"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.view_template()
        }


        Item {
            Layout.fillHeight: true
        }

        Button {
            icon.source:"qrc:/icone_gui/settings_light.png"
            Layout.fillWidth: true
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.view_setting()
        }
    }
}
