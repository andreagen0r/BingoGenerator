import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Window {
  width: 600
  height: 750
  visible: true
  title: "Gerador de Bingo"

  RowLayout {
    id: controls
    anchors.top: parent.top
    anchors.margins: 12
    anchors.horizontalCenter: parent.horizontalCenter
    z: 10

    SpinBox {
      id: spbx
      editable: true
      from: 1
      to: 1000
      value: 100
    }

    Button {
      text: `Gerar ${spbx.value} Cartelas`
      onClicked: {
        BingoGenerator.startGeneration(spbx.value);
      }
    }
    Text {
      text: "Processando: " + (BingoGenerator.currentCardIndex)
    }
  }

  Rectangle {
    id: bingoCard
    width: 500
    height: 600
    color: "white"
    anchors.centerIn: parent

    border.color: "black"
    border.width: 4

    ColumnLayout {
      anchors.fill: parent
      spacing: 0

      Rectangle {
        Layout.fillWidth: true
        Layout.preferredHeight: 100
        color: "#cccccc"
        border.color: "black"
        border.width: 2

        RowLayout {
          anchors.fill: parent
          spacing: 0
          Repeater {
            model: ["B", "O", "D", "A", "S"]
            Rectangle {
              required property list<string> modelData

              Layout.fillWidth: true
              Layout.fillHeight: true
              color: "transparent"
              Text {
                anchors.centerIn: parent
                text: parent.modelData
                font.pixelSize: 60
                font.bold: true
                font.family: "Arial"
              }
            }
          }
        }
      }

      GridLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        columns: 5
        rowSpacing: 0
        columnSpacing: 0

        Repeater {
          model: 25

          Rectangle {
            required property int index

            Layout.fillWidth: true
            Layout.fillHeight: true
            border.color: "black"
            border.width: 1

            readonly property bool isCenter: index === 12
            readonly property int textIndex: index > 12 ? index - 1 : index

            Text {
              visible: !parent.isCenter
              anchors.fill: parent
              anchors.margins: 10
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              text: (BingoGenerator.currentWords.length > 0 && !parent.isCenter)
                    ? BingoGenerator.currentWords[parent.textIndex] : ""
              font.pixelSize: 16
              wrapMode: Text.WordWrap
              width: parent.width * 0.9
              fontSizeMode: Text.Fit
            }

            Rectangle {
              visible: parent.isCenter
              anchors.fill: parent
              color: "black"

              Image {
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: Qt.resolvedUrl("center.svg")
              }
            }
          }
        }
      }
    }
  }

  Connections {
    target: BingoGenerator

    function onCurrentWordsChanged() {
      saveTimer.start();
    }

    function onGenerationFinished() {
      console.log("Geração completa!");
    }
  }

  Timer {
    id: saveTimer
    interval: 100 // 100ms para renderizar
    repeat: false
    onTriggered: {
      let filename = "images/cartela_" + (BingoGenerator.currentCardIndex + 1) + ".png";

      bingoCard.grabToImage(function (result) {
        if (result.saveToFile(filename)) {
          BingoGenerator.reportImageSaved();
        } else {
          console.error("Falha ao salvar " + filename);
        }
      }, Qt.size(1030, 1240)); // Definir resolução de saída maior que a tela
    }
  }
}
