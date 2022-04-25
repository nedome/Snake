#include <iostream>
#include <random>
#include <conio.h>


using namespace std;




struct snakePart {
	int x, y;
	snakePart* next;
	snakePart* prev;
};


void printField(char** field, int  fieldHeight, int fieldWidth) {
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}

}

void clearField(char** field, int fieldHeight, int fieldWidth) {
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldHeight; j++) {
			field[i][j] = ' ';
		}
	}
}


void setFigures(char** field, int fieldHeight, int fieldWidth, snakePart* snake) {

}


int main() {

	setlocale(LC_ALL, "ENGLISH");

	int filedWidth, fieldHeright;
	do {
		system("cls");
		cout << "Choose a wildth: ";
		cin >> filedWidth;
		cout << "Choose a height ";
		cin >> fieldHeright;
	} while ((filedWidth <= 2) or (fieldHeright <= 2));

	char** field = new char* [fieldHeright];
	for (int i = 0; i < fieldHeright; i++) {
		field[i] = new char[filedWidth];
	}

	clearField(field, fieldHeright, filedWidth);


	system("cls");


	for (int i = 0; i < fieldHeright; i++) {
		for (int j = 0; j < fieldHeright; j++) {
			cout << field[i][j];
		}
		cout << endl;


	}

	snakePart snake;
	snakePart* snakeHead = &snake;

	snake.x = rand() % filedWidth;
	snake.y = rand() % fieldHeright;
	snake.next = NULL;
	snake.prev = NULL;

	bool alive = true;
	char symbol;   //считываем с клавиатуры

	int currentLength = 0;

	int appleX, appleY;


	while (alive) {

		symbol = _getch();
		if ((symbol == 'w') or (symbol == 'W')) {

			snake.y -= 1;
			if (snake.y < 0) snake.y = fieldHeright - 1;
		}

	
			if ((symbol == 's') or (symbol == 'S')) {
				snake.y = (snake.y + 1) % fieldHeright;
			}

			if ((symbol == 'a') or (symbol == 'A')) {
				snake.x -= 1;
				if (snake.x < 0) snake.x = filedWidth - 1;
			}

			if ((symbol == 'd') or (symbol == 'D')) {
				snake.x = (snake.x + 1) % filedWidth;
			}


			snakePart* snakeCurrent = snakeHead;

			currentLength = 0;

			clearField(field, fieldHeright, filedWidth);

			while (snakeCurrent != NULL) {

				
				if (currentLength == 0) field[snakeCurrent->y][snakeCurrent->x] = 'O';
				else field[snakeCurrent->y][snakeCurrent->x] = '@';


				currentLength++;
				snakeCurrent = snakeCurrent->next;



			}

			system("cls");

			printField(field, fieldHeright, filedWidth);

		}



		return 0;
	}


	//Relese 0.0.1-alpha
