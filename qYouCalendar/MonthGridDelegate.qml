import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ColumnLayout{
    id: root

    required property bool today
    required property int year
    required property int month
    required property int day

    required property int visibleMonth

    Material.theme: today ? Material.Dark : undefined
    Label {
        id: dayText




        horizontalAlignment: Text.AlignHCenter
        topPadding: 4
        opacity: month === root.visibleMonth ? 1 : 0
        text: day

        Layout.fillWidth: true

        Rectangle {
            width: height
            height: Math.max(dayText.implicitWidth, dayText.implicitHeight)
            radius: width / 2
            color: Material.primary
            anchors.centerIn: dayText
            anchors.verticalCenterOffset: dayText.height - dayText.baselineOffset
            z: -1
            visible: root.today
            MouseArea{
                cursorShape: Qt.PointingHandCursor
            }
        }
    }

    ListView {
        spacing: 1
        clip: true

        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.topMargin: 4

        delegate: ItemDelegate {
            id: itemDelegate
            width: parent.width
            text: name
            font.pixelSize: Qt.application.font.pixelSize * 0.8
            leftPadding: 4
            rightPadding: 4
            topPadding: 4
            bottomPadding: 4

            required property string name

            Material.theme: Material.Dark

            background: Rectangle {
                color: itemDelegate.Material.primary
                radius: 3
            }
        }

    }

}
