var howManyTimes 
var userIn = prompt("Random = 1, Users choice = 2");

while (userIn != 1 && userIn != 2)
{
	prompt("Random = 1, Users choice = 2");
}

if (userIn == 2) {
	howManyTimes = prompt("How many times?");
} else {
	howManyTimes = Math.floor(Math.random() * 5);
}

while (howManyTimes != 0)
{
        alert("Hey!")
        howManyTimes -= 1;
        console.log("Hello webdev dude.");
}

setTimeout(wakeUpUser, 5000);
function wakeUpUser()
{
        alert("Stop being so lazy! Go and be productive!");
}
