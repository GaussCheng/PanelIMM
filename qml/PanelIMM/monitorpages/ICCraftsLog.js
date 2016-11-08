.pragma library

Qt.include("../../utils/Storage.js")
Qt.include("../../utils/utils.js")
Qt.include("../../utils/stringhelper.js")

function CraftsItem(id, injEnd, injTime, holdEnd, chargeEnd, omEnd, cycleTime, logTime){
    this.id = id;
    this.logTime = logTime;
    this.injEnd = injEnd;
    this.injTime = injTime;
    this.holdEnd = holdEnd;
    this.chargeEnd = chargeEnd;
    this.omEnd = omEnd;
    this.cycleTime = cycleTime;
}

function CraftsLog(){
    this.logs = [];
    this.monitors = [];
    this.maxLog = 500;
    var db = getDatabase();
    //    var logs = this.logs;
    var manager = this;
    db.transaction(function(tx){
        tx.executeSql('CREATE TABLE IF NOT EXISTS craftsLog(id PK INTEGER NOT NULL, injEnd REAL, injTime REAL, holdEnd REAL, chargeEnd REAL, omEnd REAL, cycleTime REAL,logTime TEXT)');
    });
    this.getLogs = function(){
        var ret = [];
        db.transaction(function(tx){
            var rs = tx.executeSql('SELECT * FROM craftsLog ORDER BY id DESC');
            var log;
            for(var i = 0; i < rs.rows.length; ++i){
                log = rs.rows.item(i);
                ret.push(new CraftsItem(log.id, log.injEnd, log.injTime, log.holdEnd, log.chargeEnd,log.omEnd, log.cycleTime, log.logTime));
            }
        }
        );
        return ret;
    };

    this.addLog = function(injEnd, injTime, holdEnd, chargeEnd, omEnd, cycleTime){
        var retItem;
        db.transaction(function(tx){
            var rs = tx.executeSql('SELECT MIN(id), MAX(id) FROM craftsLog');
            var toAddID = 0;
            var cMax = rs.rows.item(0)["MAX(id)"];
            var cMin = rs.rows.item(0)["MIN(id)"]
            var isNew = false;
            if(cMax < this.maxLog){
                toAddID = cMax + 1;
                isNew = true;
            }else{
                toAddID = cMin;
                isNew = false;
            }
            retItem = new CraftsItem(toAddID, injEnd, injTime, holdEnd, chargeEnd, omEnd, cycleTime, nowDate("hh:mm:ss"));
            if(isNew)
                tx.executeSql(icStrformat("INSERT INTO craftsLog VALUES({0}, {1}, {2}, {3}, {4}, {5}, {6}, '{7}')",
                                          toAddID, injEnd, injTime, holdEnd, chargeEnd, omEnd, cycleTime, retItem.logTime));
            else
                tx.executeSql(icStrformat("UPDATE craftsLog SET id={0}, injEnd={1}, injTime={2}, holdEnd={3}, chargeEnd={4}, omEnd={5}, cycleTime={6}, logTime='{7}' WHERE id={8}",
                                          toAddID,injEnd, injTime, holdEnd, chargeEnd, omEnd, cycleTime, retItem.logTime, cMin));
        });
        return retItem;
    };
}

var craftsLog = new CraftsLog();
