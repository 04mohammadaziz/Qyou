import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import QtQuick.Templates 2.12 as T
import QtQuick.Controls.impl 2.12

import ToDo 1.0

ColumnLayout {
    Frame {
        Layout.fillWidth: true

        ListView {
            implicitWidth: 250
            implicitHeight: 250
            anchors.fill: parent
            clip: true

            model: ToDoModel {
                list: toDoList
            }

            delegate: RowLayout {
                width: parent.width

                CheckBox {
                        id: control
                        checked: model.done
                        onClicked: model.done = checked
                        indicator: Rectangle {
                            implicitWidth: 26
                            implicitHeight: 26
                            x: control.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 3
                            border.color: "#002452"
                            color: control.checked ? "#002452" : "white"

                            Text {
                                width: 14
                                height: 14
                                x: 1
                                y: -2
                                text: "✔"
                                font.pointSize: 18
                                color: "lightblue"
                                visible: control.checked
                            }
                        }
                    }

                TextField {
                    text: model.description
                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }
            }
        }
    }

    RowLayout {
        Button {
            id: addElement
            text: qsTr("Add new item")
            onClicked: toDoList.appendItem()
            Layout.fillWidth: true

            contentItem: Text {
                text: addElement.text
                font: addElement.font
                opacity: enabled ? 1.0 : 0.3
                color: addElement.down ? "#002452" : (addElement.hovered ? "black" : "white")
            }

            background: Rectangle {
                color: parent.down ? "#002452" : (parent.hovered ? "lightblue" : "#002452")
            }
        }
        Button {
            id: remElement
            text: qsTr("Remove completed")
            onClicked: toDoList.removeCompletedItems()
            Layout.fillWidth: true

            contentItem: Text {
                text: remElement.text
                font: remElement.font
                opacity: enabled ? 1.0 : 0.3
                color: remElement.down ? "#002452" : (remElement.hovered ? "black" : "white")
            }

            background: Rectangle {
                color: parent.down ? "#002452" : (parent.hovered ? "lightblue" : "#002452")
            }
        }
    }
}
