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

var usedH = 1024;


var mainWindow = {
  "rect":new Rect(0, 0, usedH * aspectRatio, usedH),
};

var wRatio = mainWindow.rect.width / realW;
var hRatio = mainWindow.rect.height/ realH;
var scaleRatio = usedH / realH;

// item styles begin
var itemStyles = {
    "defaultFont":{"pixelSize":14 * scaleRatio},
    "defaultSize":{"width":60 * wRatio, "height":24 * hRatio},
    "ICLineEdit":{
        "border":{"width":1, "color":"black"},
        "disabled":{"bgColor":"gray","fontColor":"gainsboro"},
        "focused":{"bgColor":"#FF7C00", "fontColor":"white"},
        "lrMargin":2 * wRatio
    },
    "ICCheckBox":{
        "color":"transparent",
        "box":{"color":{"focused":"#FF7C00", "checked":"lightgreen", "normal":"white"},
               "border":{"width":1, "color":"black"}
        }
    },
    "ICComboBox":{
        "border":{"width":1, "color":"black"},
        "color":{"normal":{"bg":"white", "fc":"black"}, "disabled":{"bg":"gray", "fc":"gainsboro"}, "focused":{"bg":"#FF7C00", "fc":"black"}},
    },
    "ICGroupPage":{
        "border":{"width":1, "color":"white"},
        "color":"transparent",
        "titleLabel":{"color":"green"}
    },
    "ICTimeLineEdit":{
        "border":{"width":1, "color":"black"},
        "disabled":{"bgColor":"gray","fontColor":"gainsboro"},
        "focused":{"bgColor":"#FF7C00", "fontColor":"white"}
    },
    "ICVerSplitLine":{
        "width":1,
        "color":"white",
    },
    "ICHorSplitLine":{
        "height":1,
        "color":"white",
    }

}

// item styles end

var monitorSection = {
    "rect":new Rect(0, 0, mainWindow.rect.width, 217 * hRatio),
    "bg":"#8D8D8D",
    "header":{"rect":new Rect(0, 0, mainWindow.rect.width >> 1, 54 * hRatio),
        "bg":"#8D8D8D",
        "normalMonitorSection":{"normalMonitorTitleWidth":110 * wRatio,
        "normalMonitorTitleBG":"#00AE66",
        "normalMonitorTitleBorderColor":"white",
        "normalMonitorTitleFontPixelSize":24 * scaleRatio},
        "convenientMonitorSection":{"time":{"font":{"pixelSize":16 * scaleRatio}}, "title":{"font":{"pixelSize":20 * scaleRatio}}}
    },
}

var detailMenuSection = {
    "rect":new Rect(0, 0, mainWindow.rect.width, 38 * hRatio),
    "bg":"#AAA7A7",
    "menuItem":{"radius":38 * hRatio >> 2, "color":"#5558DF", "pressedColor":"#C2B485", "checkedColor":"#00AE66","borderColor":"white", "font":{"pixelSize":14 * scaleRatio}},

}

var touchControlSection = {
    "bg":"#709089",
    "rect":new Rect(0, 579, mainWindow.rect.width, 445 * hRatio),
    "functionMenuItem":{"font":{"pixelSize":18 * scaleRatio}},
    "immModeBG":{"rightMargin": 2 * wRatio, "topMargin": 2 * hRatio},
    "touchKeyboard":{"btnSize":47 * scaleRatio, "btnBG":"#CCA0D2", "spacing": 2 * wRatio, "topMargin":20 * wRatio, "leftMargin": 4 * wRatio,  "font":{"pixelSize":18 * scaleRatio}},
    "touchNavKeyboard":{"btnSize":43 * scaleRatio},
    "pageMenuKeyboard":{"btnWidth":60 * wRatio, "btnHeight": 50 * hRatio, "btnBG":"#B5D268", "pressedColor":"#C2B485", "checkedColor":"#00AE66","borderColor":"#AAA7A7"},
    "optionalKeyboard":{"btnSize": 50 * scaleRatio, "labelHeight": 22 * hRatio, "btnSpacing": 2 * wRatio, "groupSpacing": 30 * wRatio, "rightMargin":6 * wRatio, "labelBG":"#578726", "btnBG":"#84953B"},
    "manageKeyboard":{"spacing":4 * scaleRatio},
    "modeSwicherContainer":{"btnWidth":73 * wRatio, "btnHeight":36 * hRatio, "btnBG":"#8FCD65"},


};

var recordManagementPage = {
    "bg" : "white"
}
