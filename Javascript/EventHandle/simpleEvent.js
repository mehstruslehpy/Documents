window.onload = init();
function init() 
{
    var clicker1 = document.getElementById("button");
    clicker1.onclick = myFunc;
    var clicker2 = document.getElementById("textInput");
    clicker2.onkeypress = handleKey;
}

function myFunc()
{
    var outText = document.getElementById("changeme");
    var inText = document.getElementById("textInput");
    outText.innerHTML = inText.value;
}

function handleKey(e)
{
    var click = document.getElementById("button");
    if (e.keyCode === 13)
    {
        click.click();
        return false;
    }
} 
