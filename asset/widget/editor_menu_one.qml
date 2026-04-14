import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material


Item {

    RowLayout{
        Layout.fillWidth: true

        Button { // H1
            icon.source:"qrc:/icone_gui/h1.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("#")
        }

        Button { // h2
            icon.source:"qrc:/icone_gui/h2.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("##")
        }

        Button { // H3
            icon.source:"qrc:/icone_gui/h3.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("###")
        }

        Button { // B
            icon.source:"qrc:/icone_gui/gras.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("**")
        }

        Button { // I
            icon.source:"qrc:/icone_gui/italic.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("_")
        }

        Button { // S
            icon.source:"qrc:/icone_gui/souligner.png"
            Material.accent: Material.BlueGrey
            onClicked: main.insert_one_text("++")
        }

        Button { // >
            icon.source:"qrc:/icone_gui/left.png"
            Material.accent: Material.BlueGrey
            onClicked: main.change_page_editor(2)
        }
    }
}
