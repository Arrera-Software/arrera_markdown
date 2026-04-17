import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material

Item {
    RowLayout{
        Layout.fillWidth: true

        Button { // <
            icon.source:"qrc:/icone_gui/right.png"
            Material.accent: Material.Indigo
            highlighted: true
            onClicked: main.change_page_editor(2)
        }

        Button { // Exporter
            icon.source:"qrc:/icone_gui/export_dark.png"
            Material.accent: Material.Indigo
            highlighted: true
            onClicked: main.export_document()
        }

        Button { // Imprimer
            icon.source:"qrc:/icone_gui/print_dark.png"
            Material.accent: Material.Indigo
            highlighted: true
            onClicked: main.print_document()
        }
    }
}
