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
            onClicked: main.insert_table()
        }

        Button { // Code
            icon.source:"qrc:/icone_gui/code.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("`")
        }

        Button { // Ligne
            icon.source:"qrc:/icone_gui/ligne.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("---")
        }

        Button { // >
            icon.source:"qrc:/icone_gui/left.png"
            Material.accent: Material.BlueGrey
            onClicked: main.change_page_editor(3)
        }
    }
}
