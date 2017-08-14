#include <iostream>
#include <Windows.h>
#include <thread> 
#include <conio.h>
#include <iomanip>
#define RIGHT_4(a, x) mass[a.cell_4 + x] != '|' && mass[a.cell_4 + x] != '@'
#define RIGHT_1(a, x) mass[a.cell_1 + x] != '|' && mass[a.cell_1 + x] != '@'
#define RIGHT_3(a, x) mass[a.cell_3 + x] != '|' && mass[a.cell_3 + x] != '@'
#define RIGHT_2(a, x) mass[a.cell_2 + x] != '|' && mass[a.cell_2 + x] != '@'
#define LEFT_3(a, x) mass[a.cell_3 - x] != '|' && mass[a.cell_3 - x] != '@'
#define LEFT_1(a, x) mass[a.cell_1 - x] != '|' && mass[a.cell_1 - x] != '@'
#define LEFT_2(a, x) mass[a.cell_2 - x] != '|' && mass[a.cell_2 - x] != '@'
#define LEFT_4(a, x) mass[a.cell_4 - x] != '|' && mass[a.cell_4 - x] != '@'
#define DAWN_3(a) mass[a.cell_3 + chek_aut] != '-' && mass[a.cell_3 + chek_aut] != '@'
#define DAWN_4(a) mass[a.cell_4 + chek_aut] != '-' && mass[a.cell_4 + chek_aut] != '@' 
#define DAWN_2(a) mass[a.cell_2 + chek_aut] != '-' && mass[a.cell_2 + chek_aut] != '@'
#define DAWN_1(a) mass[a.cell_1 + chek_aut] != '-' && mass[a.cell_1 + chek_aut] != '@'
#define UP_3(a) mass[a.cell_3 - chek_aut] != '-' && mass[a.cell_3 - chek_aut] != '@'
#define UP_4(a) mass[a.cell_4 - chek_aut] != '-' && mass[a.cell_4 - chek_aut] != '@' 
#define UP_2(a) mass[a.cell_2 - chek_aut] != '-' && mass[a.cell_2 - chek_aut] != '@'
#define UP_1(a) mass[a.cell_1 - chek_aut] != '-' && mass[a.cell_1 - chek_aut] != '@'

using namespace::std;
const size_t K = 529, index = 30, chek_aut = 23, speed = 100;
bool _start = true;
int Korektor, korektor_next;
char Init_one_first_page(char[], size_t);
void Print_mass(char[], size_t);
char MOTION_square(char[], const size_t, size_t);
char MOTION_stick(char[], const size_t, size_t);
void Random(char[], const size_t);
inline bool IsKeyDown(char A){
	return (GetKeyState(A) & 0x8000) != 0;
}
struct Figure_size {
	int cell_1;
	int cell_2;
	int cell_3;
	int cell_4;
};
int main() {
	char mass[K] = { "rtertertyr" };
	Init_one_first_page(mass, K);
	Print_mass(mass, K);
	Random(mass, K);
	return 0;
}
char Init_one_first_page(char mass[], size_t K) {
	for (size_t i = 0; i < K; i += chek_aut) {
		for (size_t j = 0; j < K / chek_aut; j++) {
			mass[i + j] = (i == 0 || i == K - chek_aut) ? ('-') :
				 (j == 0 || j == 17 || j == chek_aut - 1) ? '|' : ' ';
		}
	}
	return mass[K];
}
void Print_mass(char mass[], size_t K) {
	system("cls");
	for (size_t i = 0; i < K; i += chek_aut) {
		for (size_t j = 0; j < K / chek_aut; j++) {
			cout << mass[i + j];
		}
		cout << endl;
	}
}
// УДАЛЯЕТ ЗАПОЛНЕННЫЙ РЯД
char Sweeping(char mass[], const size_t K) {// стерание полного ряда
	for (size_t i = 499; i >= chek_aut * 2; i -= chek_aut) {
		size_t Counter = 0;
		for (size_t j = 0; j <= 16; j++) {// проверка идет справо на лево
			if (mass[i - j] == '@') {
				Counter++;
				if (Counter == 16) { // слево на право
					for (size_t clean = i - j, Mobil = clean + 16; clean < Mobil; clean++) {
						mass[clean] = ' ';
						if (clean + 1 == Mobil)
							for(size_t _len = Mobil - 1; _len >= i - j; _len--) // проход вверх
								for (size_t h = _len; h > 170; h -= chek_aut) {
									   mass[h] = mass[h - chek_aut]; }}}}}}
	return mass[K];
}
// движение фигуры вправо
char MOTION_right(char mass[], const size_t K, Figure_size& figure) {
	mass[figure.cell_1] = ' ', mass[figure.cell_2] = ' ',
	mass[figure.cell_3] = ' ', mass[figure.cell_4] = ' ';
	figure.cell_1++, mass[figure.cell_1] = '@';
	figure.cell_2++, mass[figure.cell_2] = '@';
	figure.cell_3++, mass[figure.cell_3] = '@';
	figure.cell_4++, mass[figure.cell_4] = '@';
	Print_mass(mass, K);
	return mass[K]; figure;
}
// движение фигуры влево
char MOTION_left(char mass[], const size_t K, Figure_size& figure) {
	mass[figure.cell_1] = ' ', mass[figure.cell_2] = ' ',
	mass[figure.cell_3] = ' ', mass[figure.cell_4] = ' ';
	figure.cell_1--, mass[figure.cell_1] = '@';
	figure.cell_2--, mass[figure.cell_2] = '@';
	figure.cell_3--, mass[figure.cell_3] = '@';
	figure.cell_4--, mass[figure.cell_4] = '@';
	Print_mass(mass, K);
	return mass[K]; figure;
}
// движение фигуры вниз
char MOTION_dawn(char mass[], const size_t K, Figure_size& figure) {
	mass[figure.cell_1] = ' ', mass[figure.cell_2] = ' ',
	mass[figure.cell_3] = ' ', mass[figure.cell_4] = ' ';
	figure.cell_1 += chek_aut, mass[figure.cell_1] = '@';
	figure.cell_2 += chek_aut, mass[figure.cell_2] = '@';
	figure.cell_3 += chek_aut, mass[figure.cell_3] = '@';
	figure.cell_4 += chek_aut, mass[figure.cell_4] = '@';
		Print_mass(mass, K);
	return mass[K]; figure;
}


///* движение квадрата
Figure_size Square(size_t index, Figure_size& square) { 
	square.cell_1 = index;
	square.cell_2 = index + 1;
	square.cell_3 = index + chek_aut;
	square.cell_4 = index + chek_aut + 1;
	return  square;
}
// движение квадрата вправо
char MOTION_right_square(char mass[], const size_t K,
	                                  Figure_size& square) {
	if (RIGHT_4(square, 1) && RIGHT_2(square, 1)) {
		MOTION_right(mass, K, square);
	}
	return mass[K]; square;
}
// движение квадрата влево
char MOTION_left_square(char mass[], const size_t K, 
	                                 Figure_size& square) {
	if (LEFT_3(square, 1) && LEFT_1(square, 1)) {
		MOTION_left(mass, K, square);
	}
	return mass[K]; square;
}
// движение квадрата вниз
char MOTION_dawn_square(char mass[], const size_t K, 
	                      Figure_size& square, size_t index) {
	if (DAWN_3(square, 1) && DAWN_4(square, 1)) {
		MOTION_dawn(mass, K, square);
	}
	else {
		Random(mass, K);
	}
	return mass[K]; square;
}


char MOTION_square(char mass[], const size_t K, size_t index) {
	Figure_size square; size_t boobl = 0;
	Square(index, square);
	char Key;
	while (true) {
		Sweeping(mass, K);
		if (kbhit() != 0) {
			Key = _getch();
			switch (Key) {
			case('d'): MOTION_right_square(mass, K, square); break;
			case('a'): MOTION_left_square(mass, K, square);  break;
			case('D'): MOTION_right_square(mass, K, square); break;
			case('A'): MOTION_left_square(mass, K, square);  break;
			case('s'): boobl = 1; break;
			case('S'): boobl = 1; break;
			default: break;
			}
		}
		boobl == 1 ? boobl = 0 : Sleep(speed);
		MOTION_dawn_square(mass, K, square, index);
		if (IsKeyDown(VK_ESCAPE)) { break; }
	}
	return mass[K];
}

///** движение палки
Figure_size Stick(size_t index, Figure_size& stick) {
	stick.cell_1 = index;
	stick.cell_2 = index + chek_aut;
	stick.cell_3 = index + chek_aut * 2;
	stick.cell_4 = index + chek_aut * 3;
	return  stick;
}
//палка стоит и двигается в право
char MOTION_right_stick(char mass[], const size_t K,
	                                 Figure_size& stick) {
	if ( RIGHT_1(stick, 1)) {
		MOTION_right(mass, K, stick); 
	}
	return mass[K]; stick;
}

//палка стоит и двигается в влево
char MOTION_left_stick(char mass[], const size_t K,
	                                Figure_size& stick) {
	if (LEFT_4(stick, 1) && LEFT_3(stick, 1) &&
		LEFT_2(stick, 1) && LEFT_1(stick, 1))
	{
		MOTION_left(mass, K, stick); 
	}
	return mass[K]; stick;
}

// палка лежит и двигается вправо
char MOTION_right_stick_Lie(char mass[], const size_t K, 
	                                     Figure_size& stick) {
	if (RIGHT_1(stick, 1)) { 
		MOTION_right(mass, K, stick);
	}
	return mass[K]; stick;
}

// палка лежит и двигается влево 
char MOTION_left_stick_Lie(char mass[], const size_t K, 
	                                    Figure_size& stick) {
	if (LEFT_4(stick, 1)) { 
		MOTION_left(mass, K, stick); 
	}
	return mass[K]; stick;
}

// палка опускается стоя
char MOTION_dawn_stick_Standing(char mass[], const size_t K, 
	                            Figure_size& stick, size_t index) { 
	if (DAWN_4(stick, 1)) { 
		MOTION_dawn(mass, K, stick);
	}
    else { 
		Random(mass, K);
	}
	return mass[K]; stick;
}

// палка опускается  лежа
char MOTION_dawn_stick_Lie(char mass[], const size_t K,
	                            Figure_size& stick, size_t index) {
	if (DAWN_4(stick) && DAWN_3(stick) &&
		DAWN_2(stick) && DAWN_1(stick)) { 
		MOTION_dawn(mass, K, stick);
	}
	else {
		Random(mass, K); 
	}
	return mass[K]; stick;
}

// палка лажится
char TURN_stick_Lie(char mass[], const size_t K,
	                          Figure_size& stick, size_t& label) {
	if (RIGHT_4(stick, 1) && RIGHT_3(stick, 1) &&
		RIGHT_2(stick, 1) && RIGHT_1(stick, 1) && 
		RIGHT_4(stick, 2) && RIGHT_3(stick, 2) &&
		RIGHT_2(stick, 2) && RIGHT_1(stick, 2) && 
	    RIGHT_4(stick, 3) && RIGHT_3(stick, 3) && 
		RIGHT_2(stick, 3) && RIGHT_1(stick, 3) &&
	    RIGHT_4(stick, 4) && RIGHT_3(stick, 4) && 
		RIGHT_2(stick, 4) && RIGHT_1(stick, 4))
	   {
		mass[stick.cell_1] = ' ', stick.cell_1 += 72,
			                 mass[stick.cell_1] = '@';
		mass[stick.cell_2] = ' ', stick.cell_2 += 48, 
			                 mass[stick.cell_2] = '@';
		mass[stick.cell_3] = ' ', stick.cell_3 += 24, 
			                 mass[stick.cell_3] = '@';
		label++;
		Print_mass(mass, K);
	   }
	return   mass[K]; label, stick;
}

// палка становится
char TURN_stick_Standing(char mass[], const size_t K, 
	                            Figure_size& stick, size_t& label) {
	if (LEFT_4(stick, chek_aut) && LEFT_3(stick, chek_aut) &&
		LEFT_2(stick, chek_aut) && LEFT_1(stick, chek_aut) &&
		LEFT_4(stick, chek_aut * 2) && LEFT_3(stick, chek_aut * 2) &&
		LEFT_2(stick, chek_aut * 2) && LEFT_1(stick, chek_aut * 2) && 
	    LEFT_4(stick, chek_aut * 3) && LEFT_3(stick, chek_aut * 3) &&
		LEFT_2(stick, chek_aut * 3) && LEFT_1(stick, chek_aut * 3) &&
	    LEFT_4(stick, chek_aut * 2) && LEFT_3(stick, chek_aut * 2) && 
		LEFT_2(stick, chek_aut * 2) && LEFT_1(stick, chek_aut * 2)) 
	   {
	    mass[stick.cell_1] = ' ', stick.cell_1 -= 72,
			                 mass[stick.cell_1] = '@';
		mass[stick.cell_2] = ' ', stick.cell_2 -= 48,
			                 mass[stick.cell_2] = '@';
		mass[stick.cell_3] = ' ', stick.cell_3 -= 24,
			                 mass[stick.cell_3] = '@';
		Print_mass(mass, K);
		label = 0;
		}
	return mass[K]; label, stick;
}
char MOTION_stick(char mass[], const size_t K, size_t index) {
	Figure_size stick; 
	size_t acceleration = 0, label = 0;
	Stick(index, stick);
	char Key;
	while (true) {
		Sweeping(mass, K);
		if (kbhit() != 0) {
			Key = _getch();
			switch (Key) {
			case('d'): label == 1 ? MOTION_right_stick_Lie(mass, K, stick) : 
				       MOTION_right_stick(mass, K, stick);
				       break;
			case('a'): label == 1 ? MOTION_left_stick_Lie(mass, K, stick)  : 
				       MOTION_left_stick(mass, K, stick);  
				       break;
			case('D'): label == 1 ? MOTION_right_stick_Lie(mass, K, stick) : 
				       MOTION_right_stick(mass, K, stick); 
				       break;
			case('A'): label == 1 ? MOTION_left_stick_Lie(mass, K, stick)  :
				       MOTION_left_stick(mass, K, stick);  
					   break;
			case('s'): acceleration++; break;
			case('S'): acceleration++; break;
			case('g'): if (label == 0) { 
				       TURN_stick_Lie(mass, K, stick, label); 
				       break; }
				else { TURN_stick_Standing(mass, K, stick, label);
					   break; }
			case('G'): if (label == 0) {
				       TURN_stick_Lie(mass, K, stick, label); 
					   break; }
			    else { TURN_stick_Standing(mass, K, stick, label); 
					   break; }
			default:   break;
			}
		}
		acceleration == 1 ? acceleration = 0 : Sleep(speed);
		label == 1 ? MOTION_dawn_stick_Lie(mass, K, stick, index):
			         MOTION_dawn_stick_Standing(mass, K, stick, index);
		if (IsKeyDown(VK_ESCAPE)) { 
			break; }
	}
	return mass[K];
}
///*** движение буквы Г
Figure_size Letter_G(size_t index, Figure_size& letter_G) {
	letter_G.cell_1 = index;
	letter_G.cell_2 = index + 1;
	letter_G.cell_3 = index + chek_aut;
	letter_G.cell_4 = index + chek_aut * 2;
	return  letter_G;
}
//буква Г стоит и двигается в право
char MOTION_right_letter_G(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (RIGHT_4(letter_G, 1) && RIGHT_3(letter_G, 1) &&
		                       RIGHT_2(letter_G, 1)) { 
		MOTION_right(mass, K, letter_G);
	}
	return mass[K]; letter_G;
}
//буква Г стоит и двигается в влево
char MOTION_left_letter_G(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (LEFT_4(letter_G, 1) && LEFT_3(letter_G, 1) && 
		                      LEFT_1(letter_G, 1)) { 
		MOTION_left(mass, K, letter_G); }
	return mass[K]; letter_G;
}
//буква Г лежит вправо и двигается вправо
char MOTION_right_letter_G_Lie_right(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (RIGHT_1(letter_G, 1) && RIGHT_2(letter_G, 1)) { 
		MOTION_right(mass, K, letter_G); }
	return mass[K]; letter_G;
}
//буква Г лежит вправо и двигается влево
char MOTION_left_letter_G_Lie_left(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (LEFT_4(letter_G, 1) && LEFT_2(letter_G, 1)) {
		MOTION_left(mass, K, letter_G); }
	return mass[K]; letter_G;
}
//буква Г стоит вверхголовой и двигается вправо
char MOTION_right_letter_G_Headsup(char mass[], const size_t K, 
	                                         Figure_size& letter_G) {
	if (RIGHT_4(letter_G, 1) && RIGHT_3(letter_G, 1) && 
		                       RIGHT_1(letter_G, 1)) { 
		MOTION_right(mass, K, letter_G); }
	return mass[K]; letter_G;
}
//буква Г стоит вверхголовой и двигается влево
char MOTION_left_letter_G_Headsup(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (LEFT_4(letter_G, 1) && LEFT_3(letter_G, 1) && 
		                      LEFT_2(letter_G, 1)) {
		MOTION_left(mass, K, letter_G); }
	return mass[K]; letter_G;
}
//буква Г лежит влево и двигается вправо
char MOTION_right_letter_G_Lie_left(char mass[], const size_t K, 
	                                         Figure_size& letter_G) {
	if (RIGHT_4(letter_G, 1) && RIGHT_2(letter_G, 1)) { 
		MOTION_right(mass, K, letter_G); 
	}
	return mass[K]; letter_G;
}
//буква Г лежит влево и двигается влево
char MOTION_left_letter_G_Lie_right(char mass[], const size_t K,
	                                         Figure_size& letter_G) {
	if (LEFT_2(letter_G, 1) && LEFT_1(letter_G, 1)) {
	    MOTION_left(mass, K, letter_G); 
	}
	return mass[K]; letter_G;
}
// буква Г опускается стоя
char MOTION_dawn_letter_G_Standing(char mass[], const size_t K, 
	                                        Figure_size& letter_G) { 
	if (DAWN_4(letter_G, 1) && DAWN_2(letter_G, 1)) { 
		MOTION_dawn(mass, K, letter_G);
	}
	else { Random(mass, K); }
	return mass[K]; letter_G;
}
// буква Г лежит вправо опускается 
char MOTION_dawn_letter_G_Lie_right(char mass[], const size_t K, 
	                                        Figure_size& letter_G) {
	if (DAWN_4(letter_G) && DAWN_3(letter_G) && DAWN_2(letter_G)) {
		MOTION_dawn(mass, K, letter_G);
	}
	else { Random(mass, K); }
	return mass[K]; letter_G;
}
// буква Г лежит вверхголовой опускается 
char MOTION_dawn_letter_G_Lie_Headsup(char mass[], const size_t K, 
	                                        Figure_size& letter_G) {
	if (DAWN_1(letter_G) && DAWN_2(letter_G)) {
		MOTION_dawn(mass, K, letter_G); 
	}
	else { Random(mass, K); }
	return mass[K]; letter_G;
}
// буква Г лежит влево опускается 
char MOTION_dawn_letter_G_Lie_left(char mass[], const size_t K, 
	                                        Figure_size& letter_G) {
	if (DAWN_4(letter_G) && DAWN_3(letter_G) && DAWN_1(letter_G)) {
		MOTION_dawn(mass, K, letter_G);
	}
	else { Random(mass, K); }
	return mass[K]; letter_G;
}
// буква Г лажится вправо 
char TURN_letter_G_Lie_right(char mass[], const size_t K, 
	                          Figure_size& latter_G, size_t& label){
	if (RIGHT_4(latter_G, 1) && LEFT_4(latter_G, 1) && 
		RIGHT_3(latter_G, 1) && LEFT_3(latter_G, 1)) {
		mass[latter_G.cell_1] = ' ', mass[latter_G.cell_2] = ' ',
			                         mass[latter_G.cell_4] = ' ';
		latter_G.cell_1 += 24, mass[latter_G.cell_1] = '@';
	    latter_G.cell_2 += 46, mass[latter_G.cell_2] = '@';
	    latter_G.cell_4 -= 24, mass[latter_G.cell_4] = '@';
		label++;
	   Print_mass(mass, K);
	}
	return mass[K]; label, latter_G;
}
// буква Г  лажится вверх головой
char TURN_letter_G_Headsup(char mass[], const size_t K,
	                         Figure_size& latter_G, size_t& label) {
	if (UP_4(latter_G) && UP_3(latter_G) &&
		DAWN_3(latter_G) && DAWN_3(latter_G)) {
		mass[latter_G.cell_1] = ' ', mass[latter_G.cell_2] = ' ',
			                         mass[latter_G.cell_4] = ' ';
		latter_G.cell_1 += 22, mass[latter_G.cell_1] = '@';
		latter_G.cell_2 -= 2,  mass[latter_G.cell_2] = '@';
		latter_G.cell_4 -= 22, mass[latter_G.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, latter_G;
}
// буква Г лажится влево 
char TURN_letter_G_Lie_left(char mass[], const size_t K,
	                        Figure_size& latter_G ,size_t& label) {
	if (RIGHT_4(latter_G, 1) && LEFT_4(latter_G, 1) &&
		RIGHT_3(latter_G, 1) && LEFT_3(latter_G, 1)) {
		mass[latter_G.cell_1] = ' ', mass[latter_G.cell_2] = ' ',
			                         mass[latter_G.cell_4] = ' ';
		latter_G.cell_1 -= 24, mass[latter_G.cell_1] = '@';
		latter_G.cell_2 -= 46, mass[latter_G.cell_2] = '@';
		latter_G.cell_4 += 24, mass[latter_G.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, latter_G;
}
// буква Г становится прямо
char TURN_letter_G_Standing(char mass[], const size_t K, 
	                        Figure_size& latter_G, size_t& label) {
	if (  UP_4(latter_G) &&   UP_3(latter_G) &&
		DAWN_3(latter_G) && DAWN_3(latter_G)) {
		mass[latter_G.cell_1] = ' ', mass[latter_G.cell_2] = ' ',
			                         mass[latter_G.cell_4] = ' ';
		latter_G.cell_1 -= 22, mass[latter_G.cell_1] = '@';
		latter_G.cell_2 += 2,  mass[latter_G.cell_2] = '@';
		latter_G.cell_4 += 22, mass[latter_G.cell_4] = '@';
		label = 0;
		Print_mass(mass, K);
	}
	return mass[K]; label, latter_G;
}
char MOTION_latter_G(char mass[], const size_t K, size_t index) {
	Figure_size latter_G;
	size_t acceleration = 0, label = 0;
	Letter_G(index, latter_G);
	char Key;
	while (true) {
		Sweeping(mass, K);
		if (kbhit() != 0) {
			Key = _getch();
			switch (Key) {
			case('a'):switch (label) {
			 case(0):MOTION_left_letter_G(mass, K, latter_G); 
				    break;
			 case(1):MOTION_left_letter_G_Lie_left(mass, K, latter_G);
				    break;
			 case(2):MOTION_left_letter_G_Headsup(mass, K, latter_G);
				    break;
			 case(3):MOTION_left_letter_G_Lie_right(mass, K, latter_G);
				    break;
			 default:break;
			}
			case('A'):switch (label) {
			 case(0):if (Key != 'a') {
				       MOTION_left_letter_G(mass, K, latter_G); } 
					break;
			 case(1):if (Key != 'a') {
				       MOTION_left_letter_G_Lie_left(mass, K, latter_G); }
					break;
			 case(2):if (Key != 'a') { 
				       MOTION_left_letter_G_Headsup(mass, K, latter_G); }
					break;
			 case(3):if (Key != 'a') { 
				       MOTION_left_letter_G_Lie_right(mass, K, latter_G); } 
					break;
			 default:break;
			}
			case('d'):switch (label) {
			 case(0):if (Key != 'a'&& Key != 'A') {
				       MOTION_right_letter_G(mass, K, latter_G); }
					break;
			 case(1):if (Key != 'a'&& Key != 'A') {
				       MOTION_right_letter_G_Lie_right(mass, K, latter_G); }
					break;
			 case(2):if (Key != 'a'&& Key != 'A') {
				       MOTION_right_letter_G_Headsup(mass, K, latter_G); }
					break;
			 case(3):if (Key != 'a'&& Key != 'A') {
				       MOTION_right_letter_G_Lie_left(mass, K, latter_G); } 
					 break;
			 default:break;
			}
			case('D'):switch (label) {
			 case(0):if (Key != 'a' && Key != 'd'&& Key != 'A') {
				       MOTION_right_letter_G(mass, K, latter_G); }
					break;
			 case(1):if (Key != 'a' && Key != 'd'&& Key != 'A') {
				       MOTION_right_letter_G_Lie_right(mass, K, latter_G); } 
					 break;
			 case(2):if (Key != 'a' && Key != 'd'&& Key != 'A') {
				       MOTION_right_letter_G_Headsup(mass, K, latter_G); } 
					 break;
			 case(3):if (Key != 'a' && Key != 'd'&& Key != 'A') {
				       MOTION_right_letter_G_Lie_left(mass, K, latter_G); } 
					 break;
			 default:break;
			}
			
			case('s'):if (Key != 'a' && Key != 'd'&& Key != 'A'&& Key != 'D') {
				        acceleration++; } 
					  break;
			case('S'):if (Key != 'a' && Key != 'd'&& Key != 'A'&& Key != 'D') {
				        acceleration++; } 
					  break;
			case('g'):switch (label) {
			 case(0):TURN_letter_G_Lie_right(mass, K, latter_G, label);
				     break;
			 case(1):TURN_letter_G_Headsup(mass, K, latter_G, label);
				     break;
			 case(2):TURN_letter_G_Lie_left(mass, K, latter_G, label); 
				     break;
			 case(3):TURN_letter_G_Standing(mass, K, latter_G, label);
				     break;
			 default:break;
			}
			case('G'):switch (label) {
			 case(0):if (Key != 'g') { 
				       TURN_letter_G_Lie_right(mass, K, latter_G, label); } 
					 break;
			 case(1):if (Key != 'g') {
				       TURN_letter_G_Headsup(mass, K, latter_G, label); }
					 break;
			 case(2):if (Key != 'g') { 
				       TURN_letter_G_Lie_left(mass, K, latter_G, label); }
					 break;
			 case(3):if (Key != 'g') { 
				       TURN_letter_G_Standing(mass, K, latter_G, label); }
					 break;
			 default:break;
			}
			default: break;
			}
		}
		acceleration == 1 ? acceleration = 0 : Sleep(speed);
		switch (label) {
		case(0):MOTION_dawn_letter_G_Standing(mass, K, latter_G); 
			    break;
		case(1):MOTION_dawn_letter_G_Lie_right(mass, K, latter_G); 
			    break;
		case(2):MOTION_dawn_letter_G_Lie_Headsup(mass, K, latter_G);
			    break;
		case(3):MOTION_dawn_letter_G_Lie_left(mass, K, latter_G);
			    break;
		default:break;
		}
		if (IsKeyDown(VK_ESCAPE)) { break; }
	}
	return mass[K];
}

///****Движение _|_ штуки
Figure_size Thing(size_t index, Figure_size& thing) {
	thing.cell_1 = index;
	thing.cell_2 = index + chek_aut - 1;
	thing.cell_3 = index + chek_aut;
	thing.cell_4 = index + chek_aut + 1;
	return  thing;
}
//_|_ штука стоит и двигается в право
char MOTION_right_thing(char mass[], const size_t K, 
	                                 Figure_size& thing) {
	if (RIGHT_4(thing, 1) && RIGHT_1(thing, 1)) {
		MOTION_right(mass, K, thing); 
	}
	return mass[K]; thing;
}
//_|_ штука стоит и двигается в влево
char MOTION_left_thing(char mass[], const size_t K, 
	                                Figure_size& thing) {
	if (LEFT_2(thing, 1) && LEFT_1(thing, 1)) { 
		MOTION_left(mass, K, thing); 
	}
	return mass[K]; thing;
}
//_|_ штука лежит вправо и двигается вправо
char MOTION_right_thing_Lie_right(char mass[], const size_t K, 
	                                       Figure_size& thing) {
	if (RIGHT_1(thing, 1) && RIGHT_2(thing, 1) && 
		                     RIGHT_4(thing, 1)) {
		MOTION_right(mass, K, thing);
	}
	return mass[K]; thing;
}
//_|_ штука вправо и двигается влево
char MOTION_left_thing_Lie_left(char mass[], const size_t K,
	                                         Figure_size& thing) {
	if (LEFT_4(thing, 1) && LEFT_2(thing, 1) && 
		                    LEFT_3(thing, 1)) {
		MOTION_left(mass, K, thing);
	}
	return mass[K]; thing;
}
//_|_ штука стоит вверхголовой и двигается вправо
char MOTION_right_thing_Headsup(char mass[], const size_t K,
	                                         Figure_size& thing) {
	if (RIGHT_2(thing, 1) && RIGHT_1(thing, 1)) {
		MOTION_right(mass, K, thing); 
	}
	return mass[K]; thing;
}
//_|_ штука стоит вверхголовой и двигается влево
char MOTION_left_thing_Headsup(char mass[], const size_t K, 
	                                         Figure_size& thing) {
	if (LEFT_4(thing, 1) && LEFT_1(thing, 1)) {
		MOTION_left(mass, K, thing); }
	return mass[K]; thing;
}
//_|_ штука лежит влево и двигается вправо
char MOTION_right_thing_Lie_left(char mass[], const size_t K, 
	                                         Figure_size& thing) {
	if (RIGHT_4(thing, 1) && RIGHT_2(thing, 1) && 
		                     RIGHT_3(thing, 1)) {
		MOTION_right(mass, K, thing); }
	return mass[K]; thing;
}
//_|_ штука лежит влево и двигается влево
char MOTION_left_thing_Lie_right(char mass[], const size_t K,
	                                         Figure_size& thing) {
	if (LEFT_2(thing, 1) && LEFT_1(thing, 1) && 
		                   RIGHT_4(thing, 1)) { 
		MOTION_left(mass, K, thing); }
	return mass[K]; thing;
}
//_|_ штука опускается стоя
char MOTION_dawn_thing_Standing(char mass[], const size_t K, 
	                                        Figure_size& thing) { 
	if (DAWN_4(thing) && DAWN_3(thing) &&
		                 DAWN_2(thing)) { 
		MOTION_dawn(mass, K, thing);
	}
	else { Random(mass, K); }
	return mass[K]; thing;
}
//_|_ штука лежит вправо опускается 
char MOTION_dawn_thing_Lie_right(char mass[], const size_t K,
	                                        Figure_size& thing) {
	if (DAWN_4(thing) && DAWN_1(thing)) { 
		 MOTION_dawn(mass, K, thing); 
	}
	else { Random(mass, K); }
	return mass[K]; thing;
}
//_|_ штука лежит вверхголовой опускается 
char MOTION_dawn_thing_Lie_Headsup(char mass[], const size_t K,
	                                        Figure_size& thing) {
	if (DAWN_1(thing) && DAWN_2(thing) &&
		                 DAWN_4(thing)) {
		MOTION_dawn(mass, K, thing);
	}
	else { Random(mass, K); }
	return mass[K]; thing;
}
//_|_ штука лежит влево опускается
char MOTION_dawn_thing_Lie_left(char mass[], const size_t K,
	                                     Figure_size& thing) { 
	if (DAWN_2(thing) && DAWN_1(thing)) {
		 MOTION_dawn(mass, K, thing); 
	 }
	else { Random(mass, K); }
	return mass[K]; thing;
}
//_|_ штука лажится вправо 
char TURN_thing_Lie_right(char mass[], const size_t K,
	                      Figure_size& thing, size_t& label) {
	if (DAWN_4(thing) && DAWN_3(thing) && UP_2(thing)) {
		mass[thing.cell_2] = ' ';
		thing.cell_1 += 24, mass[thing.cell_1] = '@';
		thing.cell_2 -= 22, mass[thing.cell_2] = '@';
		thing.cell_4 += 22, mass[thing.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, thing;
}
//_|_ штука  лажится вверх головой
char TURN_thing_Headsup(char mass[], const size_t K, 
	                     Figure_size& thing, size_t& label) {
	if (LEFT_4(thing, 1) && RIGHT_2(thing, 1) &&
		                     LEFT_3(thing, 1)) {
		mass[thing.cell_2] = ' ';
		thing.cell_1 += 22, mass[thing.cell_1] = '@';
		thing.cell_2 += 24, mass[thing.cell_2] = '@';
		thing.cell_4 -= 24, mass[thing.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, thing;
}
//_|_ штука лажится влево 
char TURN_thing_Lie_left(char mass[], const size_t K, 
	                     Figure_size& thing, size_t& label) {
	if (UP_4(thing) && DAWN_2(thing) && UP_3(thing)) {
		mass[thing.cell_2] = ' ';
		thing.cell_1 -= 24, mass[thing.cell_1] = '@';
		thing.cell_2 += 22, mass[thing.cell_2] = '@';
		thing.cell_4 -= 22, mass[thing.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, thing;
}
char TURN_thing_Standing(char mass[], const size_t K, Figure_size& thing, size_t& label) {//_|_ штука становится прямо
	if (RIGHT_4(thing, 1) && RIGHT_3(thing, 1) && LEFT_2(thing, 1)) {
		mass[thing.cell_2] = ' ';
		thing.cell_1 -= 22, mass[thing.cell_1] = '@';
		thing.cell_2 -= 24, mass[thing.cell_2] = '@';
		thing.cell_4 += 24, mass[thing.cell_4] = '@';
		label = 0;
		Print_mass(mass, K);
	}
	return mass[K]; label, thing;
}
char MOTION_thing(char mass[], const size_t K, size_t index) {
	Figure_size thing;
	size_t acceleration = 0, label = 0;
	Thing(index, thing);
	char Key;
	while (true) {
		Sweeping(mass, K);
		if (kbhit() != 0) {
			Key = _getch();
			switch (Key) {
			case('a'):switch (label) {
			 case(0):MOTION_left_thing(mass, K, thing);
				     break;
			 case(1):MOTION_left_thing_Lie_left(mass, K, thing); 
				     break;
			 case(2):MOTION_left_thing_Headsup(mass, K, thing); 
				     break;
			 case(3):MOTION_left_thing_Lie_right(mass, K, thing); 
				    break;
			 default:break;
			}
			case('A'):switch (label) {
			 case(0):if (Key != 'a') { 
				       MOTION_left_thing(mass, K, thing); }
					   break;
			 case(1):if (Key != 'a') {
				       MOTION_left_thing_Lie_left(mass, K, thing); }
					   break;
			case(2):if (Key != 'a') { 
				       MOTION_left_thing_Headsup(mass, K, thing); } 
					   break;
			case(3):if (Key != 'a') { MOTION_left_thing_Lie_right(mass, K, thing); } break;
			default:break;
			}
			case('d'):switch (label) {
			 case(0):if (Key != 'a'&& Key != 'A') { 
				       MOTION_right_thing(mass, K, thing); } 
					     break;
			 case(1):if (Key != 'a'&& Key != 'A') {
				       MOTION_right_thing_Lie_right(mass, K, thing); }
					    break;
			 case(2):if (Key != 'a'&& Key != 'A') { 
				       MOTION_right_thing_Headsup(mass, K, thing); }
					    break;
			 case(3):if (Key != 'a'&& Key != 'A') { 
				       MOTION_right_thing_Lie_left(mass, K, thing); } 
					   break;
			 default:break;
			}
			case('D'):switch (label) {
			 case(0):if (Key != 'a' && Key != 'd'&& Key != 'A') {
				       MOTION_right_thing(mass, K, thing); } 
					   break;
			 case(1):if (Key != 'a' && Key != 'd'&& Key != 'A') { 
				       MOTION_right_thing_Lie_right(mass, K, thing); } 
					   break;
			 case(2):if (Key != 'a' && Key != 'd'&& Key != 'A') { 
				       MOTION_right_thing_Headsup(mass, K, thing); } 
					 break;
			 case(3):if (Key != 'a' && Key != 'd'&& Key != 'A') { 
				       MOTION_right_thing_Lie_left(mass, K, thing); } 
					 break;
			 default:break;
			}

			case('s'):if (Key != 'a' && Key != 'd'&& Key != 'A'&& 
				          Key != 'D') {
				          acceleration++; }
					  break;
			case('S'):if (Key != 'a' && Key != 'd'&& Key != 'A'&&
				          Key != 'D') { 
				          acceleration++; }
					  break;
			case('g'):switch (label) {
			 case(0):TURN_thing_Lie_right(mass, K, thing, label);
				     break;
			 case(1):TURN_thing_Headsup(mass, K, thing, label);
				     break;
			 case(2):TURN_thing_Lie_left(mass, K, thing, label);
				     break;
			 case(3):TURN_thing_Standing(mass, K, thing, label);
				     break;
			 default:break;
			}
			case('G'):switch (label) {
			 case(0):if (Key != 'g') {
				      TURN_thing_Lie_right(mass, K, thing, label); } 
					  break;
			 case(1):if (Key != 'g') { 
				     TURN_thing_Headsup(mass, K, thing, label); } 
					  break;
			 case(2):if (Key != 'g') {
				     TURN_thing_Lie_left(mass, K, thing, label); }
					  break;
			 case(3):if (Key != 'g') {
				     TURN_thing_Standing(mass, K, thing, label); }
					break;
			 default:break;
			}
			default: break;
			}
		}
		acceleration == 1 ? acceleration = 0 : Sleep(speed);
		switch (label) {
		case(0):MOTION_dawn_thing_Standing(mass, K, thing);
			break;
		case(1):MOTION_dawn_thing_Lie_right(mass, K, thing);
			break;
		case(2):MOTION_dawn_thing_Lie_Headsup(mass, K, thing);
			break;
		case(3):MOTION_dawn_thing_Lie_left(mass, K, thing);
			break;
		default:break;
		}
		if (IsKeyDown(VK_ESCAPE)) { break; }
	}
	return mass[K];
}
///*****Движение _-- закарючки
Figure_size _Scribble(size_t index, Figure_size& Scribble) {
	Scribble.cell_1 = index;
	Scribble.cell_2 = index + chek_aut ;
	Scribble.cell_3 = index + chek_aut + 1;
	Scribble.cell_4 = index + chek_aut * 2 + 1;
	return  Scribble;
} 
//_-- закарючка стоит и двигается в право
char MOTION_Scribble_right(char mass[], const size_t K,
	                                    Figure_size& Scribble) {
	if (RIGHT_4(Scribble, 1) && RIGHT_1(Scribble, 1) && 
		RIGHT_3(Scribble, 1)) { 
		MOTION_right(mass, K, Scribble);
	}
	return mass[K]; Scribble;
}
//_-- закарючка стоит и двигается в влево
char MOTION_Scribble_left(char mass[], const size_t K,
	                                    Figure_size& Scribble) {
	if (LEFT_2(Scribble, 1) && LEFT_1(Scribble, 1) && 
		                       LEFT_2(Scribble, 1)) { 
		MOTION_left(mass, K, Scribble); 
	}
	return mass[K]; Scribble;
}
//_-- закарючка лежит вправо и двигается вправо
char MOTION_right_Scribble_Lie_right(char mass[], const size_t K, 
	                                              Figure_size& Scribble) {
	if (RIGHT_1(Scribble, 1) && RIGHT_3(Scribble, 1)) { 
		             MOTION_right(mass, K, Scribble);
	}
	return mass[K]; Scribble;
}
//_-- закарючка вправо и двигается влево
char MOTION_left_Scribble_Lie_left(char mass[], const size_t K, 
	                                            Figure_size& Scribble) {
	if (LEFT_4(Scribble, 1) && LEFT_2(Scribble, 1) ) {
		            MOTION_left(mass, K, Scribble); }
	return mass[K]; Scribble;
}
//_-- закарючка опускается стоя
char MOTION_dawn_Scribble_Standing(char mass[], const size_t K, 
	                                            Figure_size& Scribble) { 
	if (DAWN_4(Scribble) && DAWN_2(Scribble)) {
		      MOTION_dawn(mass, K, Scribble); }
	else { Random(mass, K); }
	return mass[K]; Scribble;
}
//_-- закарючка лежит вправо опускается 
char MOTION_dawn_Scribble_Lie_right(char mass[], 
	                 const size_t K, Figure_size& Scribble) {
	if (DAWN_4(Scribble) && DAWN_1(Scribble) && DAWN_3(Scribble)) {
		                          MOTION_dawn(mass, K, Scribble); }
	else { Random(mass, K); }
	return mass[K]; Scribble;
}
//_-- закарючка лажится вправо 
char TURN_Scribble_Lie_right(char mass[], const size_t K,
	                        Figure_size& Scribble, size_t& label) {
	if (RIGHT_1(Scribble, 1) && RIGHT_1(Scribble, 2) && 
		                        LEFT_4(Scribble, 1)) {
		mass[Scribble.cell_1] = ' ', mass[Scribble.cell_4] = ' ';
		Scribble.cell_1 += 2, mass[Scribble.cell_1] = '@';
		Scribble.cell_2 -= 22, mass[Scribble.cell_2] = '@';
		Scribble.cell_4 -= 24, mass[Scribble.cell_4] = '@';
		label++;
		Print_mass(mass, K);
	}
	return mass[K]; label, Scribble;
}
//_-- закарючка становится прямо
char TURN_Scribble_Standing(char mass[], const size_t K, 
	                        Figure_size& Scribble, size_t& label) {
	if (DAWN_4(Scribble, 1) && DAWN_3(Scribble, 1) && 
		                       LEFT_2(Scribble, 1)) {
		mass[Scribble.cell_2] = ' ', mass[Scribble.cell_1] = ' ';
		Scribble.cell_1 -= 2, mass[Scribble.cell_1] = '@';
		Scribble.cell_2 += 22 , mass[Scribble.cell_2] = '@';
		Scribble.cell_4 += 24, mass[Scribble.cell_4] = '@';
		label = 0;
		Print_mass(mass, K);
	}
	return mass[K]; label, Scribble;
}
char MOTION_Scribble(char mass[], const size_t K, size_t index) {
	Figure_size Scribble;
	size_t acceleration = 0, label = 0;
	_Scribble(index, Scribble);
	char Key;
	while (true) {
		Sweeping(mass, K); 
		if (kbhit() != 0) {
			Key = _getch();
			switch (Key) {
			case('d'): label == 1 ? MOTION_right_Scribble_Lie_right(mass, K, Scribble) :
				       MOTION_Scribble_right(mass, K, Scribble);
				       break;
			case('a'): label == 1 ? MOTION_left_Scribble_Lie_left(mass, K, Scribble) :
				       MOTION_Scribble_left(mass, K, Scribble);  
				       break;
			case('D'): label == 1 ? MOTION_right_Scribble_Lie_right(mass, K, Scribble) :
				       MOTION_Scribble_right(mass, K, Scribble);
				       break;
			case('A'): label == 1 ? MOTION_left_Scribble_Lie_left(mass, K, Scribble) : 
				       MOTION_Scribble_left(mass, K, Scribble);  
				       break;
			case('s'): acceleration++;
				       break;
			case('S'): acceleration++;
				       break;
			case('g'): if (label == 0) { 
				         TURN_Scribble_Lie_right(mass, K, Scribble, label); 
				       break; }
					   else { TURN_Scribble_Standing(mass, K, Scribble, label); 
					   break; }
			case('G'): if (label == 0) { 
				         TURN_Scribble_Lie_right(mass, K, Scribble, label); 
					   break; }
					   else { TURN_Scribble_Standing(mass, K, Scribble, label);
					   break; }
			default: break;
			}
		}
		acceleration == 1 ? acceleration = 0 : Sleep(speed);
		label == 1 ? MOTION_dawn_Scribble_Lie_right(mass, K, Scribble) :
			         MOTION_dawn_Scribble_Standing(mass, K, Scribble);
		if (IsKeyDown(VK_ESCAPE)) { break; }
	}
	return mass[K];
}
//стирает фигуру
char Sweep_consol(char mass[], const size_t K) {
	mass[65] = ' ', mass[66] = ' ',
	mass[67] = ' ', mass[88] = ' ';
	mass[89] = ' ', mass[90] = ' ', 
	mass[111] = ' ', mass[112] = ' ';
	mass[113] = ' ', mass[134] = ' ',
	mass[135] = ' ', mass[136] = ' ';
	return mass[K];
}
//  рисует фигуру в окне
int RANDOM_START(char mass[], const size_t K, int& Korektor, int& Selector) {
	switch (Selector) {
	case(0):Sweep_consol(mass, K), mass[66] = '@', mass[89] = '@',
		    mass[112] = '@', mass[135] = '@', Korektor = 0; 
		    break;
	case(1):Sweep_consol(mass, K), mass[65] = '@', mass[66] = '@', 
		    mass[88] = '@', mass[89] = '@', Korektor = 1;  
		    break;
	case(2):Sweep_consol(mass, K), mass[66] = '@', mass[67] = '@',
		    mass[89] = '@', mass[112] = '@', Korektor = 2; 
		    break;
	case(3):Sweep_consol(mass, K), mass[88] = '@', mass[66] = '@',
		    mass[89] = '@', mass[90] = '@', Korektor = 3; 
		    break;
	case(4):Sweep_consol(mass, K), mass[65] = '@', mass[88] = '@',
		    mass[89] = '@', mass[112] = '@', Korektor = 4; 
		    break;
	default:
		break;
	}
	return Korektor;
}
void Random(char mass[], const size_t K ) {//  выбор фигуры
	srand(time(0));
	if (_start == true) {
		int Selector = rand() % 5;
		RANDOM_START(mass, K, Korektor, Selector);// первый выбор
		Selector = rand() % 5;
		_start = false;
		switch (Selector) {
		case(0):MOTION_stick(mass, K, index); break;
		case(1):MOTION_square(mass, K, index); break;
		case(2):MOTION_latter_G(mass, K, index); break;
		case(3):MOTION_thing(mass, K, index); break;
		case(4):MOTION_Scribble(mass, K, index); break;
		default:
			break;
		}
	}
	else {
		korektor_next = Korektor;
		int Selector = rand() % 5;
		RANDOM_START(mass, K, Korektor, Selector);// все остольные
		switch (korektor_next) {
		case(0):MOTION_stick(mass, K, index); break;
		case(1):MOTION_square(mass, K, index); break;
		case(2):MOTION_latter_G(mass, K, index); break;
		case(3):MOTION_thing(mass, K, index); break;
		case(4):MOTION_Scribble(mass, K, index); break;
		default:
			break;
		}
	}
}