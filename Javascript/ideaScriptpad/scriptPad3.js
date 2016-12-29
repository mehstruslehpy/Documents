var i = 0;
var dogs = ["sally", "herman", "tom"];
dogs[3] = "joseph";

bork("dag");
while (i != 4)
{
bork(dogs[i])
i = i + 1
}

function bork(name) 
{
	console.log(name + " Says Bork Brokerino!");
}

console.log("Dogs in array " + dogs.length);
