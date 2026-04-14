import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material

Item {
    RowLayout{
        Layout.fillWidth: true

        Button { // <
            icon.source:"qrc:/icone_gui/right.png"
            Material.accent: Material.BlueGrey
            onClicked: main.change_page_editor(2)
        }

        Button { // Exporter
            //icon.source:"qrc:/icone_gui/tableau.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }

        Button { // Imprimer
            //icon.source:"qrc:/icone_gui/code.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }
    }
}
