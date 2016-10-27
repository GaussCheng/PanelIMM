.pragma library

function showPageHelper(container, pageMap, component, prefix, newFun){
    if(!pageMap.hasOwnProperty(component)){
        var comp = Qt.createComponent(prefix + component);
        if(comp.status == 3 /*Component.Error*/){
            console.log(comp.errorString());
            return;
        }
        var co = comp.createObject(container, {"width":container.width, "height":container.height});
        pageMap[component] = container.addPage(co);
        if(newFun){
            newFun(co);
        }
    }
    container.setCurrentIndex(pageMap[component]);
    return container.currentPage();
}

function FuncPageManager(){
    this.normalMonitorSectionCreatedPages = {};
    this.createdDetailPages = {};
    this.normalMonitorPagesContainer = null;
    this.detailPagesContainer = null;
    this.mainWindow = null;
    var gMW;
    this.init = function(normalMonitorPagesContainer, detailPagesContainer, mainWindow){
        this.normalMonitorPagesContainer = normalMonitorPagesContainer;
        this.detailPagesContainer = detailPagesContainer;
        this.mainWindow = mainWindow;
        gMW = mainWindow;
    };
    this.showNormalMonitorPage = function(component){
        showPageHelper(this.normalMonitorPagesContainer,
                       this.normalMonitorSectionCreatedPages,
                       component, "monitorpages/");
    };
    this.showDetailPage = function(component){
        var page = showPageHelper(this.detailPagesContainer, this.createdDetailPages,
                       component, "settingpages/", function(p){
                           p.editorFocusChanged.connect(function(now){
                               gMW.changeTip(now.tip);
                           });
                       });

        return page;
    }
}

function ConvenientMonitorManager(){
    this.pageMap = {};
    this.pageContainer = null;
    this.init = function(container){
      this.pageContainer = container;
    };
    this.showMonitor = function(component){
        showPageHelper(this.pageContainer,
                       this.pageMap,
                       component, "monitorpages/");
    }
}



var funcPageManager = new FuncPageManager();
var convenientMonitorManager = new ConvenientMonitorManager();
var mainWindow;
