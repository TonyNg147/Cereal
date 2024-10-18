import QtQuick

Repeater{
    id: boxRpt
	delegate: Rectangle{
        id: boxInstance
        required property var model
		required property int boxX
		required property int boxY
		required property string boxColor
		color: boxColor
		x: boxX
		y: boxY
		width: 100
		height: 100
        onXChanged: {
			boxInstance.model.boxX = x;
        }
        onYChanged: {
			boxInstance.model.boxY = y;
        }
        Drag.active: handler.held
		Drag.hotSpot.x: 0
		Drag.hotSpot.y: 0
        MouseArea{
            id: handler
            anchors.fill: parent
			drag.target: boxInstance
            property bool held: false
            onPressed: {
                handler.held = true;
            }
            onReleased: {
                handler.held = false;
            }
        }
    }
}
