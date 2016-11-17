
var status = [];
function deepFindStatus(item){
    if(item.hasOwnProperty("bindStatus")){
        if(item.bindStatus !== "")
            status.push(item);
        return;
    }
    var itemChildren = item.children;

    var count = itemChildren.length;
    for(var i = 0; i < count; ++i){
        deepFindStatus(itemChildren[i]);
    }
}
