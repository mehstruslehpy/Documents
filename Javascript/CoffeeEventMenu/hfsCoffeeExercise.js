//created 22 Dec 2016 by mehstruslehpy

//coffee constructor
function Coffee(roast, ounces)
{
    //members
    this.roast = roast;
    this.ounces = ounces;

    //methods
    this.getSize = function() 
    {
        if (this.ounces === 8)
        {
            return "Small";
        }
        else if (this.ounces === 12)
        {
            return "Medium";
        }
        else if (this.ounces === 16)
        {
            return "Large";
        }
        else if (this.ounces === 32)
        {
            return "X-Large";
        }
        else
        {
            return "*Custom size*";
        }
    };

    this.toString = function() 
    {
        return (this.getSize() + " " + this.roast + " Roast Coffee");
    };
    
    this.getPrice = function()
    {
        var str = "";
        var sizeMod = 0;
        var typeMod = 0;
        //calculate the size modifier
        if (this.ounces <= 8) 
        {
            sizeMod = 1;
        }
        else if (this.ounces > 8 && this.ounces <= 12)
        {
            sizeMod = 2;
        }
        else if (this.ounces > 12 && this.ounces <= 16)
        {
            sizeMod = 3;
        }
        else if (this.ounces > 16 && this.ounces <= 32)
        {
            sizeMod = 4;
        }
        //calculate the type modifier based on this.roasts value
        str = this.roast;
        if (str.toUpperCase() === "DARK ROAST" || str.toUpperCase() === "DARK")
        {
            typeMod = 1;
        }
        else if (str.toUpperCase() === "MEDIUM ROAST" || str.toUpperCase === "MEDIUM") 
        {
            typeMod = 2;
        }
        else if ( str.toUpperCase === "LIGHT ROAST" || str.toUpperCase() === "LIGHT")
        {
            typeMod = 3;
        }
        else 
        {   // user made a custom selection
            typeMod = 4;
        }
        //calculate price and tax assuming 7.5% is tax
        var price = typeMod + sizeMod;
        var tax = 0.075;
        var totalPrice = price + (tax * price);
        return totalPrice;
    }
}

window.onload = init();
function init() 
{
    var clicker1 = document.getElementById("button");
    clicker1.onclick = myFunc;
    var clicker2 = document.getElementById("roast");
    clicker2.onkeypress = handleKey;
    var clicker3 = document.getElementById("size");
    clicker3.onkeypress = handleKey;
}

function myFunc()
{
    var outText = document.getElementById("orderSummary");
    var roastText = document.getElementById("roast");
    var sizeText = document.getElementById("size");
    var newOrder = new Coffee(roastText.value, Number(sizeText.value));
    outText.innerHTML = "Order: " + newOrder.toString();
    outText = document.getElementById("priceSummary");
    outText.innerHTML = "price: $" + parseFloat(newOrder.getPrice());
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
 console.log("created 22 dec 2016 by mehstruhslehpy I can be found on github by the same name");
