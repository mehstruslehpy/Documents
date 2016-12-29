//the functions we are testing
function validate1(phoneNumber)
{
    //check length
    if (phoneNumber.length !== 8)
    {
        return false;
    }
    //check each segment
    var first = phoneNumber.substring(0,3);
    var second = phoneNumber.substring(4);
    if (phoneNumber.charAt(3) !== "-" || isNaN(first) || isNaN(second)) 
    {   
        return false;
    }  
    return true;
}

//looks like a cluster
function validate2(phoneNumber)
{
    //check length
    if (phoneNumber.length !== 8)
    {
        return false;
    }
    for (var i = 0; i < phoneNumber.length; i++)
    {
        if (i == 3) 
        {
            if (phoneNumber.charAt(i) !== '-')
            {
                return false;
            }
        } else if (isNaN(phoneNumber.charAt(i))) {
            return false;
        }
    }
    return true;
}

window.onload = init();
function init()
{
    var click1 = document.getElementById("buttFunc1");
    click1.onclick = clickFunc1;
    var click1 = document.getElementById("textFunc1");
    click1.onkeypress = handleKey1;

    var click2 = document.getElementById("buttFunc2");
    click2.onclick = clickFunc2;
    var click2 = document.getElementById("textFunc2");
    click2.onkeypress = handleKey2;
}

function clickFunc1()
{
    //retrieve input
    inText = document.getElementById("textFunc1");
    //evaluate
    if (validate1(inText.value)) 
    {
       document.getElementById("func1").innerHTML = "FUNCTION ONE: GOOD";
       document.getElementById("func1").style.color = "green";  
    } else {
       document.getElementById("func1").innerHTML = "FUNCTION ONE: BAD";
       document.getElementById("func1").style.color = "red";  

    }
}

function handleKey1(e)
{
    var click = document.getElementById("buttFunc1");
    if (e.keyCode === 13)
    {
        click.click();
        return false;
    }
}

function clickFunc2()
{
    //retrieve input
    inText = document.getElementById("textFunc2");
    //evaluate
    if (validate1(inText.value)) 
    {
       document.getElementById("func2").innerHTML = "FUNCTION TWO: GOOD";
       document.getElementById("func2").style.color = "green";  
    } else {
       document.getElementById("func2").innerHTML = "FUNCTION TWO: BAD";
       document.getElementById("func2").style.color = "red";  

    }
}

function handleKey2(e)
{
    var click = document.getElementById("buttFunc2");
    if (e.keyCode === 13)
    {
        click.click();
        return false;
    }
}

