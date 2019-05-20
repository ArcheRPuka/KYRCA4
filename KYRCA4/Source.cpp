//#define _CRT_SECURE_NO_WARNINGS 
//#define kol 8
//#include "SDL.h" 
//#include "math.h" 
//#include "stdio.h" 
//#include<stdio.h> 
//#include<stdlib.h> 
//#include<locale.h> 
//#include <ctime> 
//#include <conio.h> 
//#include <SDL_ttf.h> 
//typedef struct Color
//{
//	int r, g, b;
//}color;
////отрисовка стартового меню
//void kartinka_start_menu(SDL_Window* window, SDL_Renderer* &renderer)
//{
//	SDL_Surface *myImage = SDL_LoadBMP("FON1.bmp");
//	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//	SDL_Rect rect = { 0,0,1280,720 };
//	SDL_RenderCopy(renderer, texture, NULL, &rect);
//	SDL_FreeSurface(myImage);
//	SDL_DestroyTexture(texture);
//}
////отрисовка игрового меню
//void kartinka_start(SDL_Window* window, SDL_Renderer* &renderer)
//{
//	SDL_Surface *myImage = SDL_LoadBMP("Menu_game.bmp");
//	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//	SDL_Rect rect = { 0,0,1280,720 };
//	SDL_RenderCopy(renderer, texture, NULL, &rect);
//	SDL_FreeSurface(myImage);
//	SDL_DestroyTexture(texture);
//}
///*ф-я вычисляет знакоместо для коректного вывода цифр
//принимаем число k - кол-во любого ресурса*/
//int znakomesto(int k)
//{
//	int a = 0;
//	do
//	{
//		k = k / 10;
//		a++;
//	} while (k > 0);
//	return a;
//}
////отрисовка цифр на игровом меню
////k-число для показа, i-кодовый номер
//void pokaz_4icel(SDL_Window*window, SDL_Renderer* &renderer, int k, int i)
//{
//	int a;
//	int b;
//	b = znakomesto(k);
//	a = 6 - b;
//	char *text = new char[10];
//	_itoa(k, text, 10);
//	TTF_Init();
//	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
//	SDL_Color fore_color = { 0,0,0 };
//	SDL_Color back_color = { 255,255,255 };
//	SDL_Rect *rect = new SDL_Rect[3];
//	//золото
//	rect[1] = { 1129 + 23 * a,79,23 * b,40 };
//	//еда
//	rect[2] = { 1129 + 23 * a,199,23 * b,40 };
//	//металл
//	rect[3] = { 1129 + 23 * a,317,23 * b,40 };
//	SDL_Surface* textSurface = NULL;
//	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//	SDL_RenderCopy(renderer, texture, NULL, &rect[i]);
//	SDL_DestroyTexture(texture);
//	TTF_CloseFont(my_font);
//	TTF_Quit();
//}
//void random_romb_color(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rect, int t)
//{
//	SDL_SetRenderDrawColor(renderer, 125, 50, 100, 0);
//
//
//	for (int i = 0; i < t; i++)
//	{
//
//		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//		rect.x++;
//		rect.y++;
//		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//	}
//}
//void romb_color(SDL_Window* window, SDL_Renderer* renderer, int t)
//{
//	for (int i = 0; i < kol; i++)
//	{
//		int x[kol], y[kol];
//		x[i] = rand() % 1000; y[i] = rand() % 600;
//		SDL_Rect rect = { x[i],y[i],x[i] + t,y[i] - t };
//		random_romb_color(window, renderer, rect, t);
//	}
//}
//void romb1(SDL_Window* window, SDL_Renderer*renderer, SDL_Rect rect, int t, Color color[])
//{
//	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 0);
//	for (int i = 0; i < t; i++)
//	{
//
//		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//		rect.x++;
//		rect.y++;
//		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//	}
//}
////ф-я создает ромб из координаты x и y размером t
//void romb(SDL_Renderer*renderer, SDL_Rect rect, int t, int k)
//{
//	Color color[1] = { 255,0,0 };
//	Color color[2] = { 0,255,0 };
//	Color color[3] = { 0,0,255 };
//	Color color[4] = { 255,128,0 };
//	Color color[5] = { 255,0,128 };
//	Color color[6] = { 128,0,255 };
//	Color color[7] = { 255,128,255 };
//	Color color[8] = { 128,255,255 };
//	Color color[9] = { 255,255,128 };
//	Color color[10] = { 128, 50, 200 };//1
//	Color col;
//	switch (k)
//	{
//	case(1): {col.r = color[1].r; col.g = color[1].g; col.b = color[1].b; break; }
//	case(2): {col.r = color[2].r; col.g = color[2].g; col.b = color[2].b; break; }
//	case(3): {col.r = color[3].r; col.g = color[3].g; col.b = color[3].b; break; }
//	case(4): {col.r = color[4].r; col.g = color[4].g; col.b = color[4].b; break; }
//	case(5): {col.r = color[5].r; col.g = color[5].g; col.b = color[5].b; break; }
//	case(6): {col.r = color[6].r; col.g = color[6].g; col.b = color[6].b; break; }
//	case(7): {col.r = color[7].r; col.g = color[7].g; col.b = color[7].b; break; }
//	case(8): {col.r = color[8].r; col.g = color[8].g; col.b = color[8].b; break; }
//	case(9): {col.r = color[9].r; col.g = color[9].g; col.b = color[9].b; break; }
//	case(10): {col.r = color[10].r; col.g = color[10].g; col.b = color[10].b; break; }
//	default: {col.r = 128; col.g = 128; col.b = 128; break; }
//	}
//	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 0);
//	for (int i = 0; i < t; i++)
//	{
//		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
//		rect.x++;
//		rect.y++;
//		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
//	}
//}
////создает игровое поле 
////t-постоянное координатное число
//void map_ren(SDL_Window* window, SDL_Renderer* renderer, int t, Color color[])
//{
//
//	int map[1000][2];
//	FILE*tf;
//	int i;
//	fopen_s(&tf, "map.txt", "r");
//	fscanf_s(tf, "%d", &i);
//	for (int j = 1; j <= i; j++)
//	{
//		fscanf_s(tf, "%d %d ", &map[j][0], &map[j][1]);
//	}
//	fclose(tf);
//
//	for (int j = 1; j <= i; j++)
//	{
//
//		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
//		romb(renderer, rect, t);
//	}
//	int k = 0;
//	for (int j = rand() % 20; j <= i; j += 9)
//	{
//		k++;
//		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
//		if (k <= kol)
//			romb1(window, renderer, rect, t, &color[k - 1]);
//	}
//	int j = rand() % i;
//	SDL_Rect rect1 = { map[j][0],map[j][1],map[j][0] + t,map[j][1] - t };
//	random_romb_color(window, renderer, rect1, t);
//	SDL_RenderPresent(renderer);
//}
//void map_create(SDL_Window*window, SDL_Renderer*renderer, SDL_Rect rect, int x, int y, int t)
//{
//	int map[1000][2];
//	int i = 1;
//	int k = 0;
//	int p = 1;
//	map[i][0] = x;
//	map[i][1] = y;
//	SDL_Event event;
//	bool quit = false;
//	while (!quit)
//	{
//		for (int j = 1; j <= p; j++)
//		{
//			if (map[j][0] == x && map[j][1] == y)
//				k++;
//		}
//		if (k == 0)
//		{
//			i++;
//			map[i][0] = x;
//			map[i][1] = y;
//
//		}
//		k = 0;
//		SDL_PollEvent(&event);
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP) && (x > t) && (y > 2 * t))
//		{
//			p++;
//			x = x - t; y = y - t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN) && (x < 1120 - 2 * t) && (y < 560 - 2 * t))
//		{
//			p++;
//			x = x + t; y = y + t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT) && (x > t) && (y < 560 - 2 * t))
//		{
//			p++;
//			x = x - t; y = y + t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT) && (x < 1120 - 2 * t) && (y > 2 * t))
//		{
//			p++;
//			x = x + t; y = y - t;
//			SDL_Rect rect = { x,y,x + t,y - t };
//			romb(renderer, rect, t);
//			SDL_Delay(200);
//		}
//		SDL_RenderPresent(renderer);
//		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_1))
//			quit = true;
//	}
//	FILE*tf;
//	fopen_s(&tf, "map.txt", "w");
//	fprintf(tf, "%d\n", i);
//	for (int j = 1; j <= i; j++)
//	{
//		fprintf(tf, "%d %d\n ", map[j][0], map[j][1]);
//	}
//	fclose(tf);
//
//}
//
////обводит выбранный часть карты 
//void obvodka(SDL_Renderer* renderer, int x, int y, int t)
//{
//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//	SDL_RenderDrawLine(renderer, x, y, x + t, y - t);
//	SDL_RenderDrawLine(renderer, x, y, x + t, y + t);
//	SDL_RenderDrawLine(renderer, x + t, y - t, x + t + t, y);
//	SDL_RenderDrawLine(renderer, x + t, y + t, x + t + t, y);
//}
////индикатор состояния, k-номер игрока r-состояние
//void ind_sost(SDL_Renderer* renderer, int k, int r)
//{
//	//координаты точек
//	SDL_Rect *cord_color = new SDL_Rect[10];
//	cord_color[1] = { 1169,385,8,8 };
//	cord_color[2] = { 1169,414,8,8 };
//	cord_color[3] = { 1169,442,8,8 };
//	cord_color[4] = { 1169,471,8,8 };
//	cord_color[5] = { 1169,498,8, 8 };
//	cord_color[6] = { 1237,385,8,8 };
//	cord_color[7] = { 1237,412,8,8 };
//	cord_color[8] = { 1237,441,8,8 };
//	cord_color[9] = { 1237,470,8,8 };
//	if (r == 0)
//	{
//		SDL_Surface *myImage = SDL_LoadBMP("ind_st0.bmp");
//		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
//		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
//		SDL_FreeSurface(myImage);
//		SDL_DestroyTexture(texture);
//	}
//	if (r == 1)
//	{
//		SDL_Surface *myImage = SDL_LoadBMP("ind_st1.bmp");
//		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
//		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
//		SDL_FreeSurface(myImage);
//		SDL_DestroyTexture(texture);
//	}
//	if (r == 2)
//	{
//		SDL_Surface *myImage = SDL_LoadBMP("ind_st2.bmp");
//		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
//		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
//		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
//		SDL_FreeSurface(myImage);
//		SDL_DestroyTexture(texture);
//	}
//}
////хранит кол-во ресурсов
//struct Resyrs
//{
//	int gold; int eat; int metl;
//};
//int main(int argc, char** argv)
//
//{
//	int t = 50;
//	int x = 50, y = 100;
//	SDL_Rect rect = { x,y,x + t,y - t };
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow(u8"ИГРА", 7, 29, 1280, 720, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
//	SDL_Event event;
//	//массив стартовых чисел/////////////////////////////////
//	SDL_Rect *start = new SDL_Rect[2];
//	//координаты начать
//	start[0] = { 426,173,432,108 };
//	//координаты выход
//	start[1] = { 489,563,309,112 };
//	//постоянное коорд число
//	//массивы ресурсов////////////////////////////////////////////////
//	Resyrs Player_res[10];
//	for (int i = 0; i < 10; i++)
//	{
//		Player_res[i].gold = 10;
//		Player_res[i].eat = 10;
//		Player_res[i].metl = 10;
//	}
//	//массив построек////////////////////////////////////////////
//
//	//цвета клеток////////////////////////////////////////////////////
//
//	//состояние между игроками///////////////////////////////////////////////
//	//1-е число номер игрока, 2-е число с каким именно игроком состояние
//	//0-нейтральное
//	//1-войны
//	//2-мира
//	int Player_sost[10][10];
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			Player_sost[i][j] = 0;
//		}
//	}
//	//координаты карты////////////////////////////////////////
//	int map[1000][2];
//	int kole;
//	FILE*tf;
//	fopen_s(&tf, "map.txt", "r");
//	fscanf_s(tf, "%d", &kole);
//	for (int i = 1; i <= kole; i++)
//	{
//		fscanf_s(tf, "%d %d ", &map[i][0], &map[i][1]);
//	}
//	fclose(tf);
//
//	//начало отрисовки игры////////////////////////////////////////////
//	bool quit = false;
//	while (!quit)
//	{
//		//отрисовка заглавного меню////////////////////////////
//		kartinka_start_menu(window, renderer);
//		SDL_RenderPresent(renderer);
//		SDL_PollEvent(&event);
//		if (event.button.button == SDL_BUTTON_LEFT)
//		{
//
//
//			for (int i = 0; i < 2; i++)
//			{
//				if (event.button.x >= start[0].x && event.button.x <= start[0].x + start[0].w && event.button.y >= start[0].y && event.button.y <= start[0].y + start[0].h)
//				{
//					//игровой цикл/////////////////////////////
//					while (!quit)
//					{
//
//						//отрисовка меню взаимодействий
//						kartinka_start(window, renderer);
//						//карта игры
//						map_ren(window, renderer, t, color);
//						system("pause");
//						//отрисовка ресурсов на экран
//						pokaz_4icel(window, renderer, Player_res[0].gold, 1);
//						pokaz_4icel(window, renderer, Player_res[0].eat, 2);
//						pokaz_4icel(window, renderer, Player_res[0].metl, 3);
//						//отрисовка состояние с др игроками
//						for (int j = 1; j < 10; j++)
//						{
//							ind_sost(renderer, j, Player_sost[0][j]);
//						}
//						//постройки///////////////
//						SDL_RenderPresent(renderer);
//						//закончить ход//////////////////////////////////////////////////
//						if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 1125 && event.button.x <= 1276 && event.button.y >= 566 && event.button.y <= 716))
//						{
//							//цикл вычисления ботов
//						}
//						//выделение карты при нажатии
//						for (int j = 1; j <= kol; j++)
//						{
//							if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= map[j][0] && event.button.x <= map[j][0] + 2 * t&&event.button.y >= map[j][1] - t && event.button.y <= map[j][1] + t))
//							{
//								obvodka(renderer, map[j][0], map[j][1], t);
//								//кнопки на панели меню////////////////
//								//строить
//								//улучшить
//								//рекрутировать
//							}
//						}
//
//					}
//				}
//				//кнопка выхода////////////////////////////////////////////
//				if (event.button.x >= start[1].x && event.button.x <= start[1].x + start[1].w && event.button.y >= start[1].y && event.button.y <= start[1].y + start[1].h)
//					quit = true;
//			}
//		}
//
//		if (event.type == SDL_QUIT)
//			quit = true;
//	}
//
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit;
//	return 0;
//}