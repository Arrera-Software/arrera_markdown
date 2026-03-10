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
            onClicked: main.change_page_editor(1)
        }

        Button { // Tableau
            icon.source:"qrc:/icone_gui/tableau.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }
        /*


        Button { // H3
            icon.source:"qrc:/icone_gui/h3.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }

        Button { // B
            icon.source:"qrc:/icone_gui/gras.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }

        Button { // I
            icon.source:"qrc:/icone_gui/italic.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }

        Button { // S
            icon.source:"qrc:/icone_gui/souligner.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }

        Button { // >
            icon.source:"qrc:/icone_gui/left.png"
            Material.accent: Material.BlueGrey
            //onClicked: main.open_web_page("https://arrera-software.fr/")
        }
        */
    }
}
