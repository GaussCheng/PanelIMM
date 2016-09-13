import QtQuick 1.1

Rectangle {
    property alias title: titleLabel.text
    property alias titleBG: titleLabel.color
    property Component content: null
    Column{
        id:content
        ICLabel{
            id:titleLabel
        }


    }

}
