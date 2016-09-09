.pragma library

function Rect(x,y,w,h){
    this.x = x;
    this.y = y;
    this.width = w;
    this.height = h;
}

var aspectRatio = 0.75;

//var mainWindow = {
//  "rect":new Rect(0, 0, 768, 1024),
//};

var realW = 768;
var realH = 1024;

var usedH = 768;

var mainWindow = {
  "rect":new Rect(0, 0, usedH * aspectRatio, usedH),
};

var wRatio = mainWindow.rect.width / realW;
var hRatio = mainWindow.rect.height/ realH;
var scaleRatio = usedH / realH;

var touchControlSection = {
    "bg":"#AAA7A7",
    "rect":new Rect(0, 579, mainWindow.rect.width, 445 * hRatio),
    "immModeBG":{"rightMargin": 4 * wRatio, "topMargin": 2 * hRatio},
    "touchKeyboard":{"btnSize":47 * scaleRatio, "btnBG":"#CCA0D2", "spacing": 6 * wRatio, "bottomMargin":6 * wRatio, "rightMargin": 6 * wRatio},
    "optionalKeyboard":{"btnSize": 50 * scaleRatio, "labelHeight": 22 * hRatio, "btnSpacing": 2 * wRatio, "groupSpacing": 30 * wRatio, "leftMargin":6 * wRatio},
};
