import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    anchors.fill: parent

    Button {
        text: "Retour a l'acceuil"
        highlighted: true
        Material.accent: Material.BlueGrey
        Material.primary: Material.Indigo
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10
        anchors.bottom: parent.bottom
        height: 40
        onClicked: main.back_setting()
    }
}
