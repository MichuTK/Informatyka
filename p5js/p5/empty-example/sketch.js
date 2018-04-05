szerokosc = 640;
wysokosc = 480;

ileKw = prompt("Podaj ilość punktów: ", 100);
ileKw = parseInt(ileKw)
r = prompt("Podaj promień koła: ", 100);
ileKo = 0;

function getRnd(min, max) {
	return Math.random() * (max - min) + min;
}

lx = [];
ly = [];

for (i = 0; i < ileKw; i++){
	x = Math.floor(getRnd(-r, r));
	y = Math.floor(getRnd(-r, r));
	// console.log(x);
	// console.log(y);
	lx[i] = x;
	ly[i] = y;
	if (x*x + y*y <= r*r){
		ileKo++;
	}
}

console.log(lx);
pi = 4 * ileKo / ileKw;
alert("Liczba Pi: " + pi);


function setup() {
  createCanvas(szerokosc, wysokosc);
	background('#fff');
	stroke('#000');
	ellipse(szerokosc / 2, wysokosc / 2, 2 * r, 2 * r);
	line(szerokosc / 2, 0, szerokosc / 2, wysokosc); // oś y
	line(0, wysokosc / 2, szerokosc, wysokosc / 2); // oś x
}

x_offset = szerokosc / 2;
y_offset = wysokosc / 2;

function draw() {
  for (i = 0; i < ileKw; i++){
		if(lx[i]*lx[i] + ly[i]*ly[i] <= r*r){
			stroke('#f00');
		} else {
			stroke('#000');
		}
		point(lx[i] + x_offset, ly[i] + y_offset);
	}
}
