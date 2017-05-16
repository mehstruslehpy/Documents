




/*
     FILE ARCHIVED ON 3:42:39 Sep 12, 2008 AND RETRIEVED FROM THE
     INTERNET ARCHIVE ON 17:12:41 Apr 9, 2017.
     JAVASCRIPT APPENDED BY WAYBACK MACHINE, COPYRIGHT INTERNET ARCHIVE.

     ALL OTHER CONTENT MAY ALSO BE PROTECTED BY COPYRIGHT (17 U.S.C.
     SECTION 108(a)(3)).
*/
_qoptions={tags:"508.964.10049"};_qacct="p-fdwEfW0hIeH9U";window.setTimeout('if(itxtLES)itxtLES("/web/20080912034239/http://edge.quantserve.com/quant.js", 100);');
if(!document.itxtInProg){
document.itxtInProg=1;var bvie=navigator.appVersion.indexOf('MSIE')>=0&&navigator.appVersion.indexOf('Opera')<0,gIAS='';
function itxtLES(u){var e=document.createElement('script');e.src=u;e.type='text/javascript';var b=document.getElementsByTagName('body')[0];b.insertBefore(e, b.firstChild);}
function itxtDSB(u){try{if(navigator.appVersion.indexOf('MSIE')>=0 && ('complete'!=document.readyState)){document.write('<s'+'cript language="javascript" src="'+u+'"></s'+'cript>');}else itxtLES(u);}catch(e){}};
function itxtBegin(){
var itxturl='/web/20080912034239/http://fortunecity.us.intellitxt.com/v3/door.jsp?ts='+(new Date()).getTime()+'&pagecl='+itxtbtl()+'&enc='+itxtGCE()+'&fv='+gDFVS()+'&ipid=10049';
void (function() {
top.gSEID=0;top.gSEST='';
var _SE = {
DRf:document.referrer,
SrchEngs:
{
yahoo:[1,'p'], altavista:[2,'q'], google:[3,'q'],
eureka:[4,'q'], lycos:[5,'query'], hotbot:[6,'MT'],
infoseek:[7,'qt'], webcrawler:[8,'searchText'], excite:[9,'search'],
aol:[10,'query'], mamma:[11,'query'], ask:[12,'q'],
sensis:[13,'find='], live:[14,'q']
}
};
var parseSTs=function(sQry,sQSD) {
sQry = sQry.replace(/%20/g, "+");
var i;var sC;var sPrv='+';var sFlat='';
var r=new RegExp("[&|?]"+sQSD+"=\+?([^&]*)");
oT=(r.exec(sQry));
if (oT===null)return '';
sQry=oT[oT.length-1];
for (i=0;i<sQry.length;i++) {
sC=sQry.charAt(i);
if (!(sC==='+'&&sPrv==='+'))sFlat+=sC==='+'?'%20':sC;
sPrv=sC;
}
sQry=sFlat;
return sFlat;
}
var parseSLDs = function(sU) {
var sQ, sU, sT, r, oT, D, i, iD;
r=/(^https?:\/\/)([^\/]+)(.*)/gi;
oT=r.exec(sU);
if (oT==null || oT.length<2)return;
sU=oT[2];
sT=oT.length>=4?oT[3].replace(/\./g, "%2E"):'';
D = sU.split('.');
iD = D.length;
if (iD<2){return;}
for (i=0;i<iD-1;i++){
if (_SE.SrchEngs[D[i]]) {
sQ=_SE.SrchEngs[D[i]][1];
r=new RegExp('.\\'+sQ+'=');
if (sQ==='*'||sQ===''){
top.gSEID=_SE.SrchEngs[D[i]][0];
top.gSEST='';
}else if (r.test(_SE.DRf)){
top.gSEID=_SE.SrchEngs[D[i]][0];
top.gSEST=parseSTs(sT,_SE.SrchEngs[D[i]][1]);
}
break;
}
}
}
parseSLDs(_SE.DRf); 
}()
);
itxturl+='&seid='+top.gSEID+'&sest='+top.gSEST;
itxtDSB(itxturl);
}
itxtDSB('/web/20080912034239/http://images.intellitxt.com/ast/js/vm/begin_200808181841.js');
}
