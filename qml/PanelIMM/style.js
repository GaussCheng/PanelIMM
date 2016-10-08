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

var monitorSection = {
    "rect":new Rect(0, 0, mainWindow.rect.width, 217 * hRatio),
    "bg":"#8D8D8D",
    "header":{"rect":new Rect(0, 0, mainWindow.rect.width >> 1, 54 * hRatio),
        "bg":"#858385",
        "normalMonitorSection":{"normalMonitorTitleWidth":110 * wRatio,
        "normalMonitorTitleBG":"#00AE66",
        "normalMonitorTitleBorderColor":"#AAA7A7",
        "normalMonitorTitleFontPixelSize":24 * scaleRatio},
        "convenientMonitorSection":{"time":{"font":{"pixelSize":16 * scaleRatio}}}
    },
}

var detailMenuSection = {
    "rect":new Rect(0, 0, mainWindow.rect.width, 38 * hRatio),
    "bg":"#AAA7A7",
    "menuItem":{"radius":38 * hRatio >> 2, "color":"#3FC3E4", "pressedColor":"#C2B485", "checkedColor":"#00AE66","borderColor":"white", "font":{"pixelSize":14 * scaleRatio}},

}

var touchControlSection = {
    "bg":"#AAA7A7",
    "rect":new Rect(0, 579, mainWindow.rect.width, 445 * hRatio),
    "immModeBG":{"rightMargin": 2 * wRatio, "topMargin": 2 * hRatio},
    "touchKeyboard":{"btnSize":47 * scaleRatio, "btnBG":"#CCA0D2", "spacing": 2 * wRatio, "topMargin":20 * wRatio, "leftMargin": 4 * wRatio},
    "touchNavKeyboard":{"btnSize":43 * scaleRatio},
    "pageMenuKeyboard":{"btnWidth":60 * wRatio, "btnHeight": 50 * hRatio, "btnBG":"#B5D268", "pressedColor":"#C2B485", "checkedColor":"#00AE66","borderColor":"#AAA7A7"},
    "optionalKeyboard":{"btnSize": 50 * scaleRatio, "labelHeight": 22 * hRatio, "btnSpacing": 2 * wRatio, "groupSpacing": 30 * wRatio, "rightMargin":6 * wRatio},
    "manageKeyboard":{"spacing":4 * scaleRatio},
    "modeSwicherContainer":{"btnWidth":73 * wRatio, "btnHeight":36 * hRatio},
};

var recordManagementPage = {
    "bg" : "white"
}
