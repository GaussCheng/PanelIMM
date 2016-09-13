.pragma library


function FuncPageManager(){
    this.normalMonitorSectionCreatedPages = {};
    this.normalMonitorPagesContainer = null;
    this.detailPagesContainer = null;
    this.init = function(normalMonitorPagesContainer, detailPagesContainer){
        this.normalMonitorPagesContainer = normalMonitorPagesContainer;
        this.detailPagesContainer = detailPagesContainer;
    };
    this.showNormalMonitorPage = function(component){
        if(!this.normalMonitorSectionCreatedPages.hasOwnProperty(component)){
            var comp = Qt.createComponent("monitorpages/" + component);
            if(comp.status == 3 /*Component.Error*/){
                console.log(comp.errorString());
                return;
            }

            var co = comp.createObject(this.normalMonitorPagesContainer);
            this.normalMonitorSectionCreatedPages[component] = this.normalMonitorPagesContainer.addPage(co);
        }
        this.normalMonitorPagesContainer.setCurrentIndex(this.normalMonitorSectionCreatedPages[component]);
    }
}

var funcPageManager = new FuncPageManager();
