var howManyTimes = 0; 
var userIn = prompt("Random = 1, Users choice = 2");
var usrMsg = prompt("Enter a message");

while (userIn != 1 && userIn != 2)
{
	userIn  = prompt("Random = 1, Users choice = 2");
	userMsg = prompt("Enter a message");
}

if (userIn == 2) {
	howManyTimes = prompt("How many times?");
} else {
	howManyTimes = Math.floor(Math.random() * 5);
}

userOutput(howManyTimes, usrMsg);

setTimeout(wakeUpUser, 5000);

function wakeUpUser()
{
        alert("Stop being so lazy! Go and be productive!");
}

function userOutput(times, message) 
{
	while (times != 0)
	{
		alert("Msg:" + times + " " + message);
		times = times - 1;
	}
}
