w = 640;
h = 480;

n = 50;
x = y = 0;
lx = [0];
ly = [0];

function getRnd(min, max) {
	return Math.random() * (max - min) + min;
}

przesuniecie = 25;

for (i = 0; i < n; i++){
	rad = Math.floor(getRnd(0, 360) * Math.PI / 180);
	x = x + Math.cos(rad) * przesuniecie;
	y = y + Math.sin(rad) * przesuniecie;
	lx[i+1] = x;
	ly[i+1] = y;
}

console.log(lx);

function setup() {
  createCanvas(w, h);
	background('#fff');
	stroke('#000');
	line(w / 2, 0, w / 2, h); // oś y
	line(0, h / 2, w, h / 2); // oś x
}


x_offset = w / 2;
y_offset = h / 2;

function draw() {
	for (i = 0; i < n; i++){
		stroke(getRnd(0, 255), getRnd(0, 255), getRnd(0, 255));
		ellipse(lx[i] + x_offset, ly[i] + y_offset, 5, 5);
		line(lx[i] + x_offset, ly[i] + y_offset, lx[i+1] + x_offset, ly[i+1] + y_offset);
		stroke('#f00');
		line(0 + x_offset, 0 + y_offset, lx[n] + x_offset, ly[n] + y_offset);
	}
}
