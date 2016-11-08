.pragma library

function cloneObject(ob) {
    return JSON.parse(JSON.stringify(ob));
}

function getRandomNum(Min,Max)
{
    var Range = Max - Min;
    var Rand = Math.random();
    return(Min + Math.round(Rand * Range));
}

function nowDate(fmt){
    return formatDate(new Date(), fmt);
}

function formatDate(date, fmt)
{ //author: meizz
    var o = {
        "M+" : date.getMonth()+1,                 //月份
        "d+" : date.getDate(),                    //日
        "h+" : date.getHours(),                   //小时
        "m+" : date.getMinutes(),                 //分
        "s+" : date.getSeconds(),                 //秒
        "q+" : Math.floor((date.getMonth()+3)/3), //季度
        "S"  : date.getMilliseconds()             //毫秒
    };
    if(/(y+)/.test(fmt))
        fmt=fmt.replace(RegExp.$1, (date.getFullYear()+"").substr(4 - RegExp.$1.length));
    for(var k in o)
        if(new RegExp("("+ k +")").test(fmt))
            fmt = fmt.replace(RegExp.$1, (RegExp.$1.length==1) ? (o[k]) : (("00"+ o[k]).substr((""+ o[k]).length)));
    return fmt;
}

function isDateTimeValid(yy,MM,dd,hh,mm,ss){
    var strDate1 = yy + "/" + MM + "/" + dd + " " + hh + ":" + mm + ":" + ss;
    var date1 = new Date(yy,MM - 1,dd,hh,mm,ss);
    var strDate2 = formatDate(date1, "yyyy/M/d h:m:s");
    return strDate1 === strDate2;
}

function getValueFromBrackets(str){
    var begin = str.indexOf('[') + 1;
    var end = str.indexOf(']');
    return str.slice(begin, end);
}

function deepFindEditableItems(root, itemMat){
    if(root.isEditable){
        var row;
        var found = false;
        var tmpPos0, rootPos, tmpPosj;
        for(var i = 0, len = itemMat.length; i < len; ++i){
            row = itemMat[i];
            tmpPos0 = row[0].screenPos();
            rootPos = root.screenPos();
            if(Math.abs(tmpPos0.y - rootPos.y) <= 10){
                for(var j = 0, rowLen = row.length; j < rowLen; ++j){
                    tmpPosj = row[j].screenPos();
                    if(rootPos.x < tmpPosj.x){
                        row.splice(j, 0, root);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    row.push(root);
                    found = true;
                    break;
                }
            }else if(rootPos.y < tmpPos0.y){
                itemMat.splice(i, 0, [root]);
                found = true;
                break;
            }
        }
        if(!found){
            itemMat.push([root]);
        }
        found = false;
    }
    var clds = root.children;
    for(var c = 0, clen = clds.length; c < clen; ++c){
        deepFindEditableItems(clds[c], itemMat);
    }
}

function generatePageKeyNav(root){
    var ret = [];
    deepFindEditableItems(root, ret);
    var row = [];
    var tryL;
    var k, kL;
    for(var i = 0, rowLen = ret.length; i < rowLen; ++i){
        row = ret[i];
        for(var j = 0, colLen = row.length; j < colLen; ++j){
            row[j].navL = row[(j - 1 + row.length) % row.length];
            row[j].navR = row[(j + 1) % row.length];
            tryL = (i - 1 + ret.length) % ret.length;
            while(tryL != i){
                var f = false;
                for(k = 0, kL = ret[tryL].length; k < kL; ++k){
                    if(Math.abs(ret[tryL][k].screenPos().x - row[j].screenPos().x) <= 10){
                        row[j].navU = ret[tryL][k];
                        f = true;
                        break;
                    }
                }
                if(f)
                    break;
                tryL = (tryL - 1 + ret.length) % ret.length;
            };
            tryL = (i + 1) % ret.length;
            while(tryL != i){
                for(k = 0, kL = ret[tryL].length; k < kL; ++k){
                    if(Math.abs(ret[tryL][k].screenPos().x - row[j].screenPos().x) <= 10){
                        row[j].navD = ret[tryL][k];
                        f = true;
                        break;
                    }
                }
                if(f)
                    break;
                tryL = (tryL + 1) % ret.length;
            };
            //            row[j].navU = ret[(i - 1 + ret.length) % ret.length]
        }
    }
    if(ret.length > 0)
        ret[0][0].focus = true;
    return ret;
}
