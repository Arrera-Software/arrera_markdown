import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    anchors.fill: parent

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10

        Button {
            text: "Ajouter"
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            Layout.alignment: Qt.AlignVCenter
            onClicked: main.add_workspace();
        }

        Item {
            Layout.fillWidth: true
        }

        Button {
            text: "Annuler"
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            Layout.alignment: Qt.AlignVCenter
            onClicked: main.change_page_setting_space(1);
        }
    }
}
