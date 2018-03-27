//     ileKw = int(input("Podaj ilość losowanych punktów: "))
//     ileKo = 0
//     r = 1

//     for i in range(ileKw):
//         x = random.random()
//         y = random.random()
//         if x**2 + y**2 <= r**2:
//             ileKo += 1

//     pi = 4 * ileKo / ileKw
//     print("Wartość PI: ", pi)
ileKw = prompt("Podaj ilość punktów: ", 100);
ileKo = 0;
r = prompt("Podaj promień koła: ", 100);

function getRnd(min, max) {
	return Math.random() * (max - min) + min;
}

for (i = 0; i < ileKw; i++){
	x = Math.floor(getRnd(-r, r));
	y = getRnd(-r, r);
	// console.log(x);
	if (x*x + y*y <= r*r){
		ileKo++;
	}
}

console.log("Liczba Pi: " + (4 * ileKo / ileKw))

function setup() {
  // put setup code here
}

function draw() {
  // put drawing code here
}