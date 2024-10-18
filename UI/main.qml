import QtQuick
import StorageImpl 1.0
import QtQuick.Controls
Window{
    id: mainRoot
    visible: true
    width: 700
    height: 600
	BoxGenerator{
		id: generator
		model: BoxModel
	}

	Button{
		width: 100
		height: 50
		text:"Spawn"
		anchors{
			bottom: parent.bottom
			bottomMargin: 20
			horizontalCenter: parent.horizontalCenter
		}

		onClicked:{
			BoxModel.createNewBox()
		}
	}
    
}
