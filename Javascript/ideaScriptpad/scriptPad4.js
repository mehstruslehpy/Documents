//sam is a dog

var samObj= {
	breed: "Schnauzer",
	size: 5,
	sound: "YORP",
	goodBad: "N",
	bark: function() 
	{
		alert(samObj.sound + "! I am a " + samObj.breed + ".");
	},

	test: function()
	{
		dogTest(samObj);
	},
};

var paulObj= {
	breed: "Great dane",
	size: 5,
	sound: "BRORK",
	goodBad: "Y",
	bark: function() 
	{
		alert(paulObj.sound + "! I am a " + paulObj.breed + ".");
	},

	test: function()
	{
		dogTest(paulObj);
	},
};


samObj.bark();
paulObj.bark();
samObj.test();
paulObj.test();

function dogTest(dog)
{
	if (dog.goodBad == "Y")
	{
		alert("GOOD DOG!");
	} else {
		alert("BAD DOG! :[");
	}
}
