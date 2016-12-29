//comes from head first js book but I wanted to try it
//random would make this more fun
var eightball = {
    advice: ["Yes","No","Maybe","Not a chance","Frig off rick!"],
    index: 0,
    shake: function() {
        this.index = this.index + 1;
        if (this.index >= this.advice.length) {
            this.index = 0;
        }
    },
    look: function() {
        return this.advice[this.index];
    },
}
eightball.shake();
console.log(eightball.look());
eightball.shake();
console.log(eightball.look());
eightball.shake();
console.log(eightball.look());
eightball.shake();
console.log(eightball.look());
eightball.shake();
console.log(eightball.look());
eightball.shake();
console.log(eightball.look());
