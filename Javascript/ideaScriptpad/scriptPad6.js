var cat = {
    name: "Shelly",
    breed: "Tabby",
    color: "orange",
    size: 2,
    hungry: 0,
    run: function() {
            console.log("Run cat! Run!");
        },
    walk: function() {
            console.log("Walk cat. Walk..");
        },
    eat: function() {
            console.log("NOMZ");
            if (this.hungry == 0) {
                console.log("I am full");
                this.hungry = 1;
            } else {
                console.log("Feed me more");
                this.hungry = 0;
            }
        }
};

console.log("My name is "+cat.name+" I am a "+cat.breed+" I weigh "+cat.size+"lbs "+"and my fur is "+cat.color+".");
cat.run();
cat.walk();
cat.eat();
cat.eat();
cat.eat();
cat.eat();
