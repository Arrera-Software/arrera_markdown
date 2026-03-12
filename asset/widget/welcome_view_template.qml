import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.folderlistmodel 2.15
import QtQuick.Controls.Material 2.15

Rectangle {
    id: root
    anchors.fill: parent

    property string templatePath: "file:///Users/baptistep/Desktop/test_template"

    FolderListModel {
        id: folderModel
        folder: root.templatePath
        nameFilters: ["*.amd"]
        showDirs: false
    }

    GridView {
        id: grid
        anchors.fill: parent
        anchors.margins: 24
        cellWidth: 200
        cellHeight: 220
        model: folderModel
        clip: true

        delegate: Item {
            width: grid.cellWidth
            height: grid.cellHeight

            Button {
                id: btn
                anchors.fill: parent
                anchors.margins: 12
                hoverEnabled: true

                property string cleanName: model.fileName ? model.fileName.replace(".amd", "") : "Sans nom"

                contentItem: Column {
                    spacing: 16
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: (parent.height - height) / 2

                    Rectangle {
                        width: 70
                        height: 70
                        radius: 20
                        color: btn.hovered ? "#2375f7" : "#5c97f7"
                        anchors.horizontalCenter: parent.horizontalCenter

                        Image {
                            source: "qrc:/icone_gui/code.png"
                            anchors.centerIn: parent
                            width: 35
                            height: 35
                            fillMode: Image.PreserveAspectFit
                        }
                    }

                    Text {
                        text: btn.cleanName
                        font.bold: true
                        font.pixelSize: 15
                        color: "#000000"
                        width: btn.width - 20
                        horizontalAlignment: Text.AlignHCenter
                        elide: Text.ElideRight
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                background: Rectangle {
                    radius: 28
                    color: btn.down ? "#E2E2E6" : (btn.hovered ? "#FFFFFF" : "#F3F3F7")
                    border.color: btn.hovered ? "#005AC1" : "transparent"
                    border.width: btn.hovered ? 2 : 0
                }

                onClicked: console.log("Fichier cliqué : " + model.fileUrl)
            }
        }
    }
}
