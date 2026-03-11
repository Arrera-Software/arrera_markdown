import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item{
    ColumnLayout{

        anchors.fill: parent
        anchors.margins: 15
        spacing: 15

        Button {
            text:"Ajouter un espace"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.change_page_setting_space(2);
        }

        Button {
            text:"Supprimer un espace"
            Layout.alignment: Qt.AlignHCenter
            highlighted: true
            Material.accent: Material.BlueGrey
            Material.primary: Material.BlueGrey
            onClicked: main.change_page_setting_space(3);
        }
    }
}
