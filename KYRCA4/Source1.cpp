#define _CRT_SECURE_NO_WARNINGS //gorod and kartinka_start (aDD) + main
#include "SDL.h" 
#include "math.h" 
#include "stdio.h" 
#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include <ctime> 
#include <conio.h> 
#include <SDL_ttf.h> 
//������ ���-�� ��������
struct Resyrs
{
	int gold; int eat; int metl;
};
//�������� �� �����
struct Stroenie
{
	int market; int kazarm; int krepoct; int mine;
};
//����� �� �����
typedef struct Voin
{
	int bronz; int serebr; int gold;
}voin;
//��������� ���������� ����
void kartinka_start_menu(SDL_Window* window, SDL_Renderer* &renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("FON1.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
//��������� �������� ����
void kartinka_start(SDL_Window* window, SDL_Renderer* &renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("Menu_game.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 2, 2, 2));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
/*�-� ��������� ���������� ��� ���������� ������ ����
��������� ����� k - ���-�� ������ �������*/
int znakomesto(int k)
{
	int a = 0;
	do
	{
		k = k / 10;
		a++;
	} while (k > 0);
	return a;
}
//������ ��������� ��� ������ ���������
void gorod(SDL_Renderer* &renderer)
{
	SDL_Rect cord = { 1130,516,141,43 };
	SDL_Surface *myImage = SDL_LoadBMP("Gorod.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_RenderCopy(renderer, texture, NULL, &cord);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
//��������� ���� �� ������� ����
//k-����� ��� ������, i-������� �����
void pokaz_4icel(SDL_Window*window, SDL_Renderer* &renderer, int k, int i)
{
	int a;
	int b;
	b = znakomesto(k);
	a = 6 - b;	
	char *text = new char[10];
	_itoa(k, text, 10);
	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 255,255,255 };
	SDL_Rect *rect = new SDL_Rect[15];
	//������
	rect[1] = { 1129 + 23 * a,79,23 * b,40 };
	//���
	rect[2] = { 1129 + 23 * a,199,23 * b,40 };
	//������
	rect[3] = { 1129 + 23 * a,317,23 * b,40 };
	//1-�����
	rect[4] = { 171 + 23 * a,641,23 * b,58 };
	//2-�����
	rect[5] = { 561 + 23 * a,641,23 * b,58 };
	//3-�����
	rect[6] = { 951 + 23 * a,641,23 * b,58 };
	//��������� �����
	rect[7] = { 300 + 20 * a,645,20 * b,45 };
	//��������� �����
	rect[8] = { 172 + 20 * a,645,20 * b,45 };
	//gorod nasel
	rect[9] = { 1130 + 23 * a,516,23 * b,40 };
	//Player_kol
	rect[10] = { 708 + 70 * a,248,70 * b,90 };
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, texture, NULL, &rect[i]);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(my_font);
	TTF_Quit();
}
//�-� ������� ���� �� ���������� x � y �������� t
void romb(SDL_Renderer*renderer, SDL_Rect rect, int t, int k)
{
	int r, g, b;
	switch (k)
	{
	case(1): {r = 255; g = 0; b = 0; break; }//�������
	case(2): {r = 0; g = 255; b = 0; break; }//�������
	case(3): {r = 0; g = 0; b = 255; break; }//�����
	case(4): {r = 255; g = 128; b = 0; break; }//���������
	case(5): {r = 255; g = 0; b = 170; break; }//�������
	case(6): {r = 170; g = 0; b = 255; break; }//����������
	case(7): {r = 255; g = 128; b = 255; break; }//������ �������
	case(8): {r = 128; g = 255; b = 255; break; }//���������
	case(9): {r = 255; g = 255; b = 128; break; }//������
	case(0): {r = 0; g = 0; b = 0; break; }//1
	default: {r = 128; g = 128; b = 128; break; }
	}
	SDL_SetRenderDrawColor(renderer, r, g, b, 0);
	for (int i = 0; i < t; i++)
	{
		SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.w, rect.h);
		rect.x++;
		rect.y++;
		rect = { rect.x,rect.y,rect.x + t,rect.y - t };
	}
}
//������� ������� ���� 
//t-���������� ������������ �����
void map_ren(SDL_Window* window, SDL_Renderer* renderer, int t, int colr[])
{
	FILE*tf;
	int map[1000][2];
	int kol;
	fopen_s(&tf, "map.txt", "r");
	fscanf_s(tf, "%d", &kol);
	for (int j = 1; j <= kol; j++)
	{
		fscanf_s(tf, "%d %d ", &map[j][0], &map[j][1]);
	}
	fclose(tf);
	for (int j = 1; j <= kol; j++)
	{
		SDL_Rect rect = { map[j][0] , map[j][1] , map[j][0] + t , map[j][1] - t };
		romb(renderer, rect, t, colr[j]);
	}
}
//������� ��������� ����� ����� 
void obvodka(SDL_Renderer* renderer, int x, int y, int t)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawLine(renderer, x, y, x + t, y - t);
	SDL_RenderDrawLine(renderer, x, y, x + t, y + t);
	SDL_RenderDrawLine(renderer, x + t, y - t, x + t + t, y);
	SDL_RenderDrawLine(renderer, x + t, y + t, x + t + t, y);
}
//��������� ���������, k-����� ������ r-���������
void ind_sost(SDL_Renderer* renderer, int k, int r)
{
	//���������� �����
	SDL_Rect *cord_color = new SDL_Rect[10];
	cord_color[1] = { 1169,385,8,8 };
	cord_color[2] = { 1169,414,8,8 };
	cord_color[3] = { 1169,442,8,8 };
	cord_color[7] = { 1169,471,8,8 };
	cord_color[9] = { 1169,498,8, 8 };
	cord_color[4] = { 1237,385,8,8 };
	cord_color[5] = { 1237,412,8,8 };
	cord_color[6] = { 1237,441,8,8 };
	cord_color[8] = { 1237,470,8,8 };
	if (r == 0)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st0.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (r == 1)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st1.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (r == 2)
	{
		SDL_Surface *myImage = SDL_LoadBMP("ind_st2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord_color[k]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
}
//������� ���� ��������
void Menu_obchenia(SDL_Renderer* renderer, int ap, int market, int kazarm, int krepost, int mine)
{
	SDL_Rect *cord = new SDL_Rect[20];
	cord[1] = { 20,580,1080,120 };
	cord[2] = { 116,570,187,140 };
	cord[3] = { 343,570,187,140 };
	cord[4] = { 570,570,187,140 };
	cord[5] = { 797,570,187,140 };
	cord[6] = { 697,570,187,140 };
	cord[7] = { 470,570,187,140 };
	cord[8] = { 243,570,187,140 };
	cord[9] = { 120,580,50,60 };
	cord[10] = { 120,640,50,60 };
	cord[11] = { 510,580,50,60 };
	cord[12] = { 510,640,50,60 };
	cord[13] = { 900,580,50,60 };
	cord[14] = { 900,640,50,60 };
	cord[15] = { 110,580,1080,120 };
	if (ap == 1)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_v_z.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 2)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_x_n.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 3)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_s_y.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 4)
	{
		if (market == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mark1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[2]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mark0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[2]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		if (krepost == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_krep1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[4]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_krep0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[4]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		if (mine == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mine1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[5]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mine0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[5]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		if (kazarm == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_kaz1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[3]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_kaz0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[3]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
	}
	if (ap == 5)
	{
		if (krepost == 3 || krepost == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_krep0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[7]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_krep1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[7]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		if (mine == 3 || mine == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mine0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[8]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_mine1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[8]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		if (kazarm == 3 || kazarm == 0)
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_kaz0.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[6]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
		else
		{
			SDL_Surface *myImage = SDL_LoadBMP("st_kaz1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[6]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
		}
	}
	if (ap == 6)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_nv.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
		int p = 0;
		if (kazarm == 0)
		{
			p = 1;
			SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[9]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
			SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
			SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
			SDL_RenderCopy(renderer, texture1, NULL, &cord[10]);
			SDL_FreeSurface(myImage1);
			SDL_DestroyTexture(texture1);
		}
		if (kazarm == 1 || p == 1)
		{
			p = 1;
			SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[11]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
			SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
			SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
			SDL_RenderCopy(renderer, texture1, NULL, &cord[12]);
			SDL_FreeSurface(myImage1);
			SDL_DestroyTexture(texture1);
		}
		if (kazarm == 2 || p == 1)
		{
			p = 1;
			SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[13]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
			SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
			SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
			SDL_RenderCopy(renderer, texture1, NULL, &cord[14]);
			SDL_FreeSurface(myImage1);
			SDL_DestroyTexture(texture1);
		}
	}
	if (ap == 7)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_x1.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[15]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);		
	}
	if (ap == 8)
	{
		SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
		SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
		SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
		SDL_RenderCopy(renderer, texture1, NULL, &cord[12]);
		SDL_FreeSurface(myImage1);
		SDL_DestroyTexture(texture1);
	}
	if (ap == 9)
	{
		SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
		SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
		SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
		SDL_RenderCopy(renderer, texture1, NULL, &cord[14]);
		SDL_FreeSurface(myImage1);
		SDL_DestroyTexture(texture1);
	}
	if (ap == 10)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[9]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 11)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[11]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 12)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Str_u.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[13]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 13)
	{
		SDL_Surface *myImage1 = SDL_LoadBMP("Str_d.bmp");
		SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
		SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
		SDL_RenderCopy(renderer, texture1, NULL, &cord[10]);
		SDL_FreeSurface(myImage1);
		SDL_DestroyTexture(texture1);
	}
	if (ap == 14)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_v_m.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 15)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_xod1.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 128, 128, 128));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 16)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_xod2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 128, 128, 128));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	if (ap == 17)
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_xod3.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 128, 128, 128));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[1]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
}
//������ ���������
void risovka_3danij(SDL_Renderer* renderer, int market, int kazarm, int krepost, int mine)
{
	SDL_Rect cord = { 959,0,161,560 };
	SDL_Surface *myImage = SDL_LoadBMP("Otdel_yr.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_RenderCopy(renderer, texture, NULL, &cord);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
	SDL_Rect cordmar = { 960,1,159,141 };
	SDL_Rect cordkazr = { 960,143,159,138 };
	SDL_Rect cordkrep = { 960,284,159,138 };
	SDL_Rect cordmine = { 960,421,159,138 };
	switch (market)
	{
	case(1): {SDL_Surface *myImage1 = SDL_LoadBMP("market.bmp");
		SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
		SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, myImage1);
		SDL_RenderCopy(renderer, texture1, NULL, &cordmar);
		SDL_FreeSurface(myImage1);
		SDL_DestroyTexture(texture1); break; }
	}
	switch (kazarm)
	{
	case(1): {SDL_Surface *myImage2 = SDL_LoadBMP("kazarma_1.bmp");
		SDL_SetColorKey(myImage2, SDL_TRUE, SDL_MapRGB(myImage2->format, 255, 255, 255));
		SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, myImage2);
		SDL_RenderCopy(renderer, texture2, NULL, &cordkazr);
		SDL_FreeSurface(myImage2);
		SDL_DestroyTexture(texture2); break; }
	case(2): {SDL_Surface *myImage2 = SDL_LoadBMP("kazarma_2.bmp");
		SDL_SetColorKey(myImage2, SDL_TRUE, SDL_MapRGB(myImage2->format, 255, 255, 255));
		SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, myImage2);
		SDL_RenderCopy(renderer, texture2, NULL, &cordkazr);
		SDL_FreeSurface(myImage2);
		SDL_DestroyTexture(texture2); break; }
	case(3): {SDL_Surface *myImage2 = SDL_LoadBMP("kazarma_3.bmp");
		SDL_SetColorKey(myImage2, SDL_TRUE, SDL_MapRGB(myImage2->format, 255, 255, 255));
		SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, myImage2);
		SDL_RenderCopy(renderer, texture2, NULL, &cordkazr);
		SDL_FreeSurface(myImage2);
		SDL_DestroyTexture(texture2); break; }
	}
	switch (krepost)
	{
	case(1): {SDL_Surface *myImage3 = SDL_LoadBMP("krepost_1.bmp");
		SDL_SetColorKey(myImage3, SDL_TRUE, SDL_MapRGB(myImage3->format, 255, 255, 255));
		SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, myImage3);
		SDL_RenderCopy(renderer, texture3, NULL, &cordkrep);
		SDL_FreeSurface(myImage3);
		SDL_DestroyTexture(texture3); break; }
	case(2): {SDL_Surface *myImage3 = SDL_LoadBMP("krepost_2.bmp");
		SDL_SetColorKey(myImage3, SDL_TRUE, SDL_MapRGB(myImage3->format, 255, 255, 255));
		SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, myImage3);
		SDL_RenderCopy(renderer, texture3, NULL, &cordkrep);
		SDL_FreeSurface(myImage3);
		SDL_DestroyTexture(texture3); break; }
	case(3): {SDL_Surface *myImage3 = SDL_LoadBMP("krepost_3.bmp");
		SDL_SetColorKey(myImage3, SDL_TRUE, SDL_MapRGB(myImage3->format, 255, 255, 255));
		SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, myImage3);
		SDL_RenderCopy(renderer, texture3, NULL, &cordkrep);
		SDL_FreeSurface(myImage3);
		SDL_DestroyTexture(texture3); break; }
	}
	switch (mine)
	{
	case(1): {SDL_Surface *myImage4 = SDL_LoadBMP("mine-1.bmp");
		SDL_SetColorKey(myImage4, SDL_TRUE, SDL_MapRGB(myImage4->format, 255, 255, 255));
		SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, myImage4);
		SDL_RenderCopy(renderer, texture4, NULL, &cordmine);
		SDL_FreeSurface(myImage4);
		SDL_DestroyTexture(texture4); break; }
	case(2): {SDL_Surface *myImage4 = SDL_LoadBMP("mine-2.bmp");
		SDL_SetColorKey(myImage4, SDL_TRUE, SDL_MapRGB(myImage4->format, 255, 255, 255));
		SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, myImage4);
		SDL_RenderCopy(renderer, texture4, NULL, &cordmine);
		SDL_FreeSurface(myImage4);
		SDL_DestroyTexture(texture4); break; }
	case(3): {SDL_Surface *myImage4 = SDL_LoadBMP("mine-3.bmp");
		SDL_SetColorKey(myImage4, SDL_TRUE, SDL_MapRGB(myImage4->format, 255, 255, 255));
		SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, myImage4);
		SDL_RenderCopy(renderer, texture4, NULL, &cordmine);
		SDL_FreeSurface(myImage4);
		SDL_DestroyTexture(texture4); break; }
	}
}
//x-���������� y-���������� a-����� ������ ����� p-������� ��� ���� ������ j-��� �����
void risovka_voin_wind(SDL_Renderer* renderer, int x, int y, int p, int a, int j)
{
	SDL_Rect *cord = new SDL_Rect[3];
	cord[0] = { x + 25,y - 35,50,50 };
	cord[1] = { x + 25,y - 25,50,50 };
	cord[2] = { x + 25,y - 15,50,50 };
	switch (a)
	{
	case(1):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_1_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_1_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_1_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(2):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_2_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_2_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_2_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(3):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_3_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_3_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_3_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(4):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_4_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_4_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_4_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(5):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_5_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_5_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_5_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(6):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_6_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_6_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_6_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(7):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_7_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_7_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_7_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(8):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_8_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_8_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_8_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(9):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_9_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_9_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_9_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	case(0):
	{
		switch (j)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_0_1.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_0_2.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("mv_0_3.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[p]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
		break;
	}
	}
}
//x-����� y-����� a-��������� ������� c-���� �������(1=g,0=r) t-����������
void strelka(SDL_Renderer* renderer, int x, int y, int a, int c, int t)
{
	SDL_Rect *cord = new SDL_Rect[4];
	cord[1] = { x,y - t,50,50 };
	cord[2] = { x + t,y - t,50,50 };
	cord[3] = { x + t,y,50,50 };
	cord[4] = { x,y,50,50 };
	if (c == 0)
	{
		switch (a)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_r11.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_r21.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_r22.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(4):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_r12.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
	}
	if (c == 1)
	{
		switch (a)
		{
		case(1):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_g11.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(2):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_g21.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(3):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_g22.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		case(4):
		{
			SDL_Surface *myImage = SDL_LoadBMP("str_g12.bmp");
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
			SDL_RenderCopy(renderer, texture, NULL, &cord[a]);
			SDL_FreeSurface(myImage);
			SDL_DestroyTexture(texture);
			break;
		}
		}
	}
}
void xod_voin(SDL_Renderer* renderer, int a)
{
	SDL_Rect *cord = new SDL_Rect[20];
	cord[16] = { 110,580,100,120 };
	cord[17] = { 500,580,100,120 };
	cord[18] = { 890,580,100,120 };
	switch (a)
	{
	case(1):
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_x2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[16]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	case(2):
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_x2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[17]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	case(3):
	{
		SDL_Surface *myImage = SDL_LoadBMP("Menu_x2.bmp");
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 255));
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
		SDL_RenderCopy(renderer, texture, NULL, &cord[18]);
		SDL_FreeSurface(myImage);
		SDL_DestroyTexture(texture);
	}
	}
}
void pauzz(SDL_Renderer* renderer)
{
	SDL_Rect cord = { 0,0,1280,720 };
	SDL_Surface *myImage = SDL_LoadBMP("Pause.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 255, 255));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_RenderCopy(renderer, texture, NULL, &cord);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
void kart1(SDL_Renderer* renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("FON2.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
void kart2(SDL_Renderer* renderer)
{
	SDL_Surface *myImage = SDL_LoadBMP("FON3.bmp");
	SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 0, 0, 0));
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, myImage);
	SDL_Rect rect = { 0,0,1280,720 };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(myImage);
	SDL_DestroyTexture(texture);
}
//0=back  1=load   2=new
int vibor_zagryzki(SDL_Renderer* renderer)
{
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_RenderClear(renderer);
		SDL_PollEvent(&event);
		kart1(renderer);
		SDL_RenderPresent(renderer);
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			//new
			if (event.button.x >= 332 && event.button.x <= 948 && event.button.y >= 143 && event.button.y <= 259)
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_Delay(200);
				}
				return 2;
			}
			//load
			if (event.button.x >= 236 && event.button.x <= 1043 && event.button.y >= 333 && event.button.y <= 445)
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_Delay(200);
				}
				return 1;
			}
			//back
			if (event.button.x >= 486 && event.button.x <= 801 && event.button.y >= 560 && event.button.y <= 678)
			{
				return 0;
			}
		}
	}
}
//0- back   <3-Player
int zagr_new(SDL_Window* window, SDL_Renderer* renderer, int Player)
{
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_RenderClear(renderer);
		SDL_PollEvent(&event);
		kart2(renderer);
		pokaz_4icel(window, renderer, Player, 10);
		SDL_RenderPresent(renderer);
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			//++
			if (event.button.x >= 962 && event.button.x <= 1156 && event.button.y >= 145 && event.button.y <= 246 && Player<10)
			{
				Player++;
			}
			//--
			if (event.button.x >= 962 && event.button.x <= 1156 && event.button.y >= 346 && event.button.y <= 447 && Player > 3)
			{
				Player--;
			}
			//back
			if (event.button.x >= 37 && event.button.x <= 337 && event.button.y >= 597 && event.button.y <= 687)
			{
				return 0;
			}
			//start
			if (event.button.x >= 901 && event.button.x <= 1238 && event.button.y >= 598 && event.button.y <= 682)
			{
				return Player;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_Delay(200);
		}
	}
}
int main(int argc, char** argv)
{
	///////////////////////////////////���� ������//////////////////////////////
	Resyrs price[4][4];
	//////////////////////////////////���� ��������+////////////////////////////
	Resyrs pice_market, pice_mine, pice_men;
	///////////////////////////////////////////////////////////////////////////+++++
	pice_market.eat = 10; pice_market.gold = 10; pice_market.metl = 10;
	pice_mine.eat = 10; pice_mine.gold = 10; pice_mine.metl = 10;
	pice_men.eat = 10; pice_men.gold = 10; pice_men.metl = 10;
	//////////////////////////////////���� ��������-////////////////////////////
	Resyrs pice_arm, pice_sost_voin;
	///////////////////////////////////////////////////////////////////////////----
	pice_arm.eat = 10; pice_arm.gold = 10; pice_arm.metl = 10;
	pice_sost_voin.eat = 10; pice_sost_voin.gold = 10; pice_sost_voin.metl = 10;
	////////////////���� ���������///////////////////
	///////////�������
	price[0][0].gold = 30;	price[0][0].eat = 20;	price[0][0].metl = 10;
	//////////�����
	price[0][1].gold = 10;	price[0][1].eat = 30;	price[0][1].metl = 10;
	//////////�����
	price[0][3].gold = 10;	price[0][3].eat = 30;	price[0][3].metl = 40;
	////////////��������
	price[0][2].gold = 50;	price[0][2].eat = 40;	price[0][2].metl = 50;
	///////////////���� 1-�� ���������///////////////
	/////////////�������
	price[1][0].gold = 20;  price[1][0].eat = 10;   price[1][0].metl = 20;
	////////////�����
	price[1][1].gold = 10;  price[1][1].eat = 30;   price[1][1].metl = 20;
	//////////////��������
	price[1][2].gold = 30;  price[1][2].eat = 40;   price[1][2].metl = 30;
	/////////////////���� 2- ���������///////////
	//////////////�������
	price[2][0].gold = 40;  price[2][0].eat = 10;   price[2][0].metl = 30;
	//////////�����
	price[2][1].gold = 10;  price[2][1].eat = 50;   price[2][1].metl = 10;
	//////��������
	price[2][2].gold = 50;  price[2][2].eat = 50;   price[2][2].metl = 50;
	////////////////////////////////////////���� ������//////////////////////////
	////////////1-�� ������//////////////
	price[3][1].gold = 1;  price[3][1].eat = 1;  price[3][1].metl = 1;
	////////////2-�� ������//////////////
	price[3][2].gold = 1;  price[3][2].eat = 1;  price[3][2].metl = 1;
	////////////3-�� ������//////////////
	price[3][3].gold = 1;  price[3][3].eat = 1;  price[3][3].metl = 1;
	/////////////////////////////////////////////////////////////////////////////
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"����", 7, 29, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
	SDL_Event event;
	//���������� ����� �����
	int t = 50;
	srand(time(NULL));
	int vibor_zagr = 3;
	//���������� �������
	int Player_kol = 10;
	int pick = 0;
	//���������� �����////////////////////////////////////////
	int map[1000][2];
	int kol;
	FILE*tf;
	fopen_s(&tf, "map.txt", "r");
	fscanf_s(tf, "%d", &kol);
	for (int i = 1; i <= kol; i++)
	{
		fscanf_s(tf, "%d %d ", &map[i][0], &map[i][1]);
	}
	fclose(tf);
	//���������� ������ �� �����
	voin Player_voin_map[101][11];
	voin Player_voin_xod[101][11];
	int coinvoin[3];
	int close = 0;
	int ap = 0;
	int sost = 0;
	int pause = 0;
	int xod[2]; xod[0] = 0; xod[1] = 0;
	int Player_sost[10][10];
	int colr[100];
	Resyrs Player_res[10];
	Stroenie Player_st[1000];
	int gor_nas[100];
	//������ ��������� ����////////////////////////////////////////////
	bool quit = false;
	while (!quit)
	{
		SDL_RenderClear(renderer);
		//��������� ���������� ����////////////////////////////
		kartinka_start_menu(window, renderer);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&event);		
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			//������
			if (event.button.x >= 426 && event.button.x <= 858 && event.button.y >= 173 && event.button.y <= 281)
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_Delay(200);
				}
				vibor_zagr = vibor_zagryzki(renderer);
			}			
			//������ ������////////////////////////////////////////////
			if (event.button.x >= 489 && event.button.x <= 798 && event.button.y >= 563 && event.button.y <= 675)
				quit = true;
		}
		if (vibor_zagr == 1 || vibor_zagr == 2)
		{
			if (vibor_zagr == 2)
			{
				Player_kol = zagr_new(window, renderer, Player_kol);
				//���������� �����
				//���������� ������ �� �����
				for (int i = 1; i <= kol; i++)
					for (int j = 0; j < Player_kol; j++)
					{
						Player_voin_map[i][j].bronz = 0;
						Player_voin_map[i][j].serebr = 0;
						Player_voin_map[i][j].gold = 0;
						Player_voin_xod[i][j].bronz = 0;
						Player_voin_xod[i][j].serebr = 0;
						Player_voin_xod[i][j].gold = 0;
					}
				//��������� ����� ��������///////////////////////////////////////////////
				//1-� ����� ����� ������, 2-� ����� � ����� ������ ������� ���������
				//0-�����������
				//1-�����
				//2-����
				for (int i = 0; i < Player_kol; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						Player_sost[i][j] = 0;
					}
				}
				//������� �������� ��� ������////////////////////////////////////////////////
				for (int i = 0; i < Player_kol; i++)
				{
					Player_res[i].gold = 1000;
					Player_res[i].eat = 1000;
					Player_res[i].metl = 1000;
				}
				//������ ��������////////////////////////////////////////////
				for (int i = 1; i <= kol; i++)
				{
					Player_st[i].kazarm = 0;//3-��
					Player_st[i].krepoct = 0;//3-��
					Player_st[i].market = 0;//1-��
					Player_st[i].mine = 0;//3-��
				}
				//����� �� �����				
				for (int i = 1; i <= kol; i++)
				{
					colr[i] = 10;
				}
				switch (Player_kol)
				{
				case(10): {colr[14] = 9; }
				case(9): {colr[5] = 8; }
				case(8): {colr[60] = 7; }
				case(7): {colr[50] = 6; }
				case(6): {colr[26] = 5; }
				case(5): {colr[30] = 4; }
				case(4): {colr[20] = 3; }
				case(3): {colr[10] = 2; }
				case(2): {colr[1] = 1; }
				case(1): {colr[34] = 0; }
				}
				//��������� ���������
				for (int i = 1; i <= kol; i++)
				{
					do
					{
						gor_nas[i] = rand();
					} while (gor_nas[i] > 300 || gor_nas[i] < 50);
				}
			}
			else
			{
				FILE* tex;
				fopen_s(&tex, "save-save", "r");
				fscanf_s(tex, "%d", &Player_kol);
				for (int i = 1; i <= kol; i++)
				{
					for (int j = 0; j < Player_kol; j++)
					{
						fscanf_s(tex, "%d", &Player_voin_map[i][j].bronz);
						fscanf_s(tex, "%d", &Player_voin_map[i][j].serebr);
						fscanf_s(tex, "%d", &Player_voin_map[i][j].gold);
					}
				}
				for (int i = 1; i <= kol; i++)
				{
					for (int j = 0; j < Player_kol; j++)
					{
						fscanf_s(tex, "%d", &Player_voin_xod[i][j].bronz);
						fscanf_s(tex, "%d", &Player_voin_xod[i][j].serebr);
						fscanf_s(tex, "%d", &Player_voin_xod[i][j].gold);
					}
				}
				for (int i = 0; i < Player_kol; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						fscanf_s(tex, "%d", &Player_sost[i][j]);
					}
				}
				for (int i = 0; i < Player_kol; i++)
				{
					fscanf_s(tex, "%d", &Player_res[i].eat);
					fscanf_s(tex, "%d", &Player_res[i].gold);
					fscanf_s(tex, "%d", &Player_res[i].metl);
				}
				for (int i = 1; i <= kol; i++)
				{
					fscanf_s(tex, "%d", &Player_st[i].kazarm);
					fscanf_s(tex, "%d", &Player_st[i].krepoct);
					fscanf_s(tex, "%d", &Player_st[i].market);
					fscanf_s(tex, "%d", &Player_st[i].mine);
				}
				for (int i = 1; i <= kol; i++)
				{
					fscanf_s(tex, "%d", &colr[i]);
				}
				for (int i = 1; i <= kol; i++)
				{
					fscanf_s(tex, "%d", &gor_nas[i]);
				}
				fclose(tex);
			}	
			//������� ����/////////////////////////////
			while (!quit)
				{
					while (!SDL_PollEvent(&event))
					{
						SDL_RenderClear(renderer);
						SDL_PollEvent(&event);
						//��������� ���� ��������������
						kartinka_start(window, renderer);
						//����� ����
						map_ren(window, renderer, t, colr);
						//��������� �������� �� �����
						pokaz_4icel(window, renderer, Player_res[0].gold, 1);
						pokaz_4icel(window, renderer, Player_res[0].eat, 2);
						pokaz_4icel(window, renderer, Player_res[0].metl, 3);
						//��������� ��������� � �� ��������
						for (int j = 1; j < 10; j++)
						{
							ind_sost(renderer, j, Player_sost[0][j]);
						}
						//�������������� � ������///////////////////////////
						if (event.type == SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								if (event.button.x >= 0 && event.button.x <= 1120 && event.button.y >= 0 && event.button.y <= 560)
								{
									close = 0;
									ap = 0;
									sost = 0;
								}
								//��������� ������ ����� ��� �������
								for (int j = 1; j <= kol; j++)
								{
									int zx, zy, zw, zh;
									int cx, cy, cw, ch;
									zx = map[j][0]; zy = map[j][1]; zw = map[j][0] + 2 * t; zh = map[j][1];
									cx = zx; cy = zy; cw = zw; ch = zh;
									for (int i = 0; i <= t; i++)
									{
										if ((event.button.x >= zx && event.button.x <= zw && event.button.y >= zy && event.button.y <= zh) || (event.button.x >= cx && event.button.x <= cw && event.button.y >= cy && event.button.y <= ch))
										{
											close = j;
											if (colr[j] == 0)
												ap = 1;
											if (colr[j] < 10 && colr[j] > 0)
											{
												sost = 5;
											}
										}
										zx++; zy--; zw--; zh--;
										cx++; cy++; cw--; ch++;
									}
								}
								//////////////////////////////////////
								if ((ap == 5) && (event.button.x >= 697 && event.button.x <= 884 && event.button.y >= 570 && event.button.y <= 710) && (Player_st[close].kazarm < 3) && (Player_st[close].kazarm > 0))//������� up	
								{
									if (Player_st[close].kazarm == 2 && (Player_res[0].gold >= price[2][0].gold && Player_res[0].eat >= price[2][0].eat && Player_res[0].metl >= price[2][0].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[2][0].gold;
										Player_res[0].eat = Player_res[0].eat - price[2][0].eat;
										Player_res[0].metl = Player_res[0].metl - price[2][0].metl;
										Player_st[close].kazarm++;
									}
									if (Player_st[close].kazarm == 1 && (Player_res[0].gold >= price[1][0].gold && Player_res[0].eat >= price[1][0].eat && Player_res[0].metl >= price[1][0].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[1][0].gold;
										Player_res[0].eat = Player_res[0].eat - price[1][0].eat;
										Player_res[0].metl = Player_res[0].metl - price[1][0].metl;
										Player_st[close].kazarm++;
									}
								}
								if ((ap == 5) && (event.button.x >= 470 && event.button.x <= 657 && event.button.y >= 570 && event.button.y <= 710) && (Player_st[close].krepoct < 3) && (Player_st[close].krepoct > 0))//�������� up
								{
									if (Player_st[close].krepoct == 2 && (Player_res[0].gold >= price[2][2].gold && Player_res[0].eat >= price[2][2].eat && Player_res[0].metl >= price[2][2].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[2][2].gold;
										Player_res[0].eat = Player_res[0].eat - price[2][2].eat;
										Player_res[0].metl = Player_res[0].metl - price[2][2].metl;
										Player_st[close].krepoct++;
									}
									if (Player_st[close].krepoct == 1 && (Player_res[0].gold >= price[1][2].gold && Player_res[0].eat >= price[1][2].eat && Player_res[0].metl >= price[1][2].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[1][2].gold;
										Player_res[0].eat = Player_res[0].eat - price[1][2].eat;
										Player_res[0].metl = Player_res[0].metl - price[1][2].metl;
										Player_st[close].krepoct++;
									}
								}
								if ((ap == 5) && (event.button.x >= 243 && event.button.x <= 430 && event.button.y >= 570 && event.button.y <= 710) && (Player_st[close].mine < 3) && (Player_st[close].mine > 0))//����� up
								{
									if (Player_st[close].mine == 2 && (Player_res[0].gold >= price[2][1].gold && Player_res[0].eat >= price[2][1].eat && Player_res[0].metl >= price[2][1].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[2][1].gold;
										Player_res[0].eat = Player_res[0].eat - price[2][1].eat;
										Player_res[0].metl = Player_res[0].metl - price[2][1].metl;
										Player_st[close].mine++;
									}
									if (Player_st[close].mine == 1 && (Player_res[0].gold >= price[1][1].gold && Player_res[0].eat >= price[1][1].eat && Player_res[0].metl >= price[1][1].metl))
									{
										Player_res[0].gold = Player_res[0].gold - price[1][1].gold;
										Player_res[0].eat = Player_res[0].eat - price[1][1].eat;
										Player_res[0].metl = Player_res[0].metl - price[1][1].metl;
										Player_st[close].mine++;
									}
								}
								if ((ap == 4) && (event.button.x >= 116 && event.button.x <= 303 && event.button.y >= 570 && event.button.y <= 710)
									&& (Player_res[0].gold >= price[0][3].gold && Player_res[0].eat >= price[0][3].eat && Player_res[0].metl >= price[0][3].metl))
								{
									Player_st[close].market = 1;//������ �����
									Player_res[0].gold = Player_res[0].gold - price[0][3].gold;
									Player_res[0].eat = Player_res[0].eat - price[0][3].eat;
									Player_res[0].metl = Player_res[0].metl - price[0][3].metl;
								}
								if ((ap == 4) && (event.button.x >= 343 && event.button.x <= 530 && event.button.y >= 570 && event.button.y <= 710)
									&& (Player_res[0].gold >= price[0][0].gold && Player_res[0].eat >= price[0][0].eat && Player_res[0].metl >= price[0][0].metl))
								{
									Player_st[close].kazarm = 1;//������ �������
									Player_res[0].gold = Player_res[0].gold - price[0][0].gold;
									Player_res[0].eat = Player_res[0].eat - price[0][0].eat;
									Player_res[0].metl = Player_res[0].metl - price[0][0].metl;
								}
								if ((ap == 4) && (event.button.x >= 570 && event.button.x <= 757 && event.button.y >= 570 && event.button.y <= 710)
									&& (Player_res[0].gold >= price[0][2].gold && Player_res[0].eat >= price[0][2].eat && Player_res[0].metl >= price[0][2].metl))
								{
									Player_st[close].krepoct = 1;//������ ��������
									Player_res[0].gold = Player_res[0].gold - price[0][2].gold;
									Player_res[0].eat = Player_res[0].eat - price[0][2].eat;
									Player_res[0].metl = Player_res[0].metl - price[0][2].metl;
								}
								if ((ap == 4) && (event.button.x >= 797 && event.button.x <= 984 && event.button.y >= 570 && event.button.y <= 710)
									&& (Player_res[0].gold >= price[0][1].gold && Player_res[0].eat >= price[0][1].eat && Player_res[0].metl >= price[0][1].metl))
								{
									Player_st[close].mine = 1;//������ �����
									Player_res[0].gold = Player_res[0].gold - price[0][1].gold;
									Player_res[0].eat = Player_res[0].eat - price[0][1].eat;
									Player_res[0].metl = Player_res[0].metl - price[0][1].metl;
								}
								//////////////////////////////////////////////////////
								if (ap == 6)
								{
									if (Player_st[close].kazarm > 0 && event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 580 && event.button.y < 640 &&
										(price[3][1].gold*coinvoin[1] + 1 <= Player_res[0].gold && price[3][1].eat*coinvoin[1] + 1 <= Player_res[0].eat && price[3][1].metl*coinvoin[1] + 1 <= Player_res[0].metl))//1g
									{
										coinvoin[1]++;
									}
									if (Player_st[close].kazarm > 0 && event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 640 && event.button.y <= 700 && coinvoin[1] > 0)//1r
									{
										coinvoin[1]--;
									}
									if (event.button.x >= 171 && event.button.x <= 321 && event.button.y >= 580 && event.button.y < 640 && gor_nas[close]>coinvoin[1])//���������� ������ �� ����� � ��������� ����
									{
										gor_nas[close] -= coinvoin[1];
										Player_voin_map[close][0].bronz = Player_voin_map[close][0].bronz + coinvoin[1];
										Player_res[0].gold = Player_res[0].gold - price[3][1].gold*coinvoin[1];
										Player_res[0].eat = Player_res[0].eat - price[3][1].eat*coinvoin[1];
										Player_res[0].metl = Player_res[0].metl - price[3][1].metl*coinvoin[1];
										coinvoin[1] = 0;
										coinvoin[2] = 0;
										coinvoin[3] = 0;
									}
									if (Player_st[close].kazarm > 1 && event.button.x >= 510 && event.button.x <= 560 && event.button.y >= 580 && event.button.y < 640 &&
										(price[3][2].gold*coinvoin[2] + 1 <= Player_res[0].gold && price[3][2].eat*coinvoin[2] + 1 <= Player_res[0].eat && price[3][2].metl*coinvoin[2] + 1 <= Player_res[0].metl))//2g
									{
										coinvoin[2]++;
									}
									if (Player_st[close].kazarm > 0 && event.button.x >= 510 && event.button.x <= 560 && event.button.y >= 640 && event.button.y <= 700 && coinvoin[2] > 0)//2r
									{
										coinvoin[2]--;
									}
									if (event.button.x >= 561 && event.button.x <= 711 && event.button.y >= 580 && event.button.y < 640 && gor_nas[close]>coinvoin[2])//���������� ������ �� ����� � ��������� ����
									{
										gor_nas[close] -= coinvoin[2];
										Player_voin_map[close][0].serebr = Player_voin_map[close][0].serebr + coinvoin[2];
										Player_res[0].gold = Player_res[0].gold - price[3][2].gold*coinvoin[2];
										Player_res[0].eat = Player_res[0].eat - price[3][2].eat*coinvoin[2];
										Player_res[0].metl = Player_res[0].metl - price[3][2].metl*coinvoin[2];
										coinvoin[1] = 0;
										coinvoin[2] = 0;
										coinvoin[3] = 0;
									}
									if (Player_st[close].kazarm > 2 && event.button.x >= 900 && event.button.x <= 950 && event.button.y >= 580 && event.button.y < 640 &&
										(price[3][3].gold*coinvoin[3] + 1 <= Player_res[0].gold && price[3][3].eat*coinvoin[3] + 1 <= Player_res[0].eat && price[3][3].metl*coinvoin[3] + 1 <= Player_res[0].metl))//2g
									{
										coinvoin[3]++;
									}
									if (Player_st[close].kazarm > 0 && event.button.x >= 900 && event.button.x <= 950 && event.button.y >= 640 && event.button.y <= 700 && coinvoin[3] > 0)//2r
									{
										coinvoin[3]--;
									}
									if (event.button.x >= 951 && event.button.x <= 1101 && event.button.y >= 580 && event.button.y < 640 && gor_nas[close]>coinvoin[3])//���������� ������ �� ����� � ��������� ����
									{
										gor_nas[close] -= coinvoin[3];
										Player_voin_map[close][0].gold = Player_voin_map[close][0].gold + coinvoin[3];
										Player_res[0].gold = Player_res[0].gold - price[3][3].gold*coinvoin[3];
										Player_res[0].eat = Player_res[0].eat - price[3][3].eat*coinvoin[3];
										Player_res[0].metl = Player_res[0].metl - price[3][3].metl*coinvoin[3];
										coinvoin[1] = 0;
										coinvoin[2] = 0;
										coinvoin[3] = 0;
									}
								}
								////////////////////////////////////////////////////
								if (ap == 7)
								{
									if (event.button.x >= 110 && event.button.x <= 210 && event.button.y >= 580 && event.button.y <= 700 && (Player_voin_map[close][0].bronz > 0))
									{
										ap = 15;
										coinvoin[1] = Player_voin_map[close][0].bronz;
									}
									if (event.button.x >= 500 && event.button.x <= 600 && event.button.y >= 580 && event.button.y <= 700 && (Player_voin_map[close][0].serebr > 0))
									{
										ap = 16;
										coinvoin[1] = Player_voin_map[close][0].serebr;
									}
									if (event.button.x >= 890 && event.button.x <= 990 && event.button.y >= 580 && event.button.y <= 700 && (Player_voin_map[close][0].gold > 0))
									{
										ap = 17;
										coinvoin[1] = Player_voin_map[close][0].gold;
									}
								}
								if (ap == 15 || ap == 16 || ap == 17)
								{
									if (event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 640 && event.button.y <= 700 && coinvoin[1] > 0)
									{
										coinvoin[1]--;
									}
									if (event.button.x >= 170 && event.button.x <= 428 && event.button.y >= 580 && event.button.y <= 640)
									{
										xod[0] = close;//���������
										ap = 18;
									}
									if (event.button.x >= 429 && event.button.x <= 499 && event.button.y >= 580 && event.button.y <= 700)
									{
										coinvoin[1] = coinvoin[1] / 2;
									}
									if (event.button.x >= 500 && event.button.x <= 570 && event.button.y >= 580 && event.button.y <= 700)
									{
										coinvoin[1] = coinvoin[1] / 3;
									}
									if (event.button.x >= 570 && event.button.x <= 641 && event.button.y >= 580 && event.button.y <= 700)
									{
										coinvoin[1] = coinvoin[1] / 4;
									}
									if (event.button.x >= 641 && event.button.x <= 712 && event.button.y >= 580 && event.button.y <= 700)
									{
										coinvoin[1] = (coinvoin[1] * 2) / 3;
									}
									if (ap == 15)
									{
										xod[1] = 1;
										if (event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 580 && event.button.y < 640 && coinvoin[1] < Player_voin_map[close][0].bronz)
										{
											coinvoin[1]++;
										}
									}
									if (ap == 16)
									{
										xod[1] = 2;
										if (event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 580 && event.button.y < 640 && coinvoin[1] < Player_voin_map[close][0].serebr)
										{
											coinvoin[1]++;
										}
									}
									if (ap == 17)
									{
										xod[1] = 3;
										if (event.button.x >= 120 && event.button.x <= 170 && event.button.y >= 580 && event.button.y < 640 && coinvoin[1] < Player_voin_map[close][0].gold)
										{
											coinvoin[1]++;
										}
									}
								}
								////////////////////////////////////////////////////
								if (sost != 0)
								{
									if (event.button.x >= 20 && event.button.x <= 540 && event.button.y >= 580 && event.button.y <= 700)//�����
									{
										Player_sost[0][colr[close]] = 1;
									}
									if (event.button.x >= 580 && event.button.x <= 1100 && event.button.y >= 580 && event.button.y <= 700)//���
									{
										Player_sost[0][colr[close]] = 2;
									}
								}
								if ((ap == 2) && (event.button.x >= 580 && event.button.x <= 1100 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 6;//������
									coinvoin[1] = 0;
									coinvoin[2] = 0;
									coinvoin[3] = 0;
								}
								if ((ap == 2) && (event.button.x >= 20 && event.button.x <= 540 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 7;//������
								}
								if ((ap == 3) && (event.button.x >= 20 && event.button.x <= 540 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 4;//�������
								}
								if ((ap == 3) && (event.button.x >= 580 && event.button.x <= 1100 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 5;//��������
								}
								if ((ap == 1) && (event.button.x >= 20 && event.button.x <= 540 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 2;//�����
								}
								if ((ap == 1) && (event.button.x >= 580 && event.button.x <= 1100 && event.button.y >= 580 && event.button.y <= 700))
								{
									ap = 3;//������
								}
							}
						}
						////////////////������� ������//////////////////////
						if (xod[0] != 0 && xod[0] != close)
						{
							if ((map[xod[0]][0] == map[close][0] - t && map[xod[0]][1] == map[close][1] + t) || (map[xod[0]][0] == map[close][0] + t && map[xod[0]][1] == map[close][1] + t) || (map[xod[0]][0] == map[close][0] - t && map[xod[0]][1] == map[close][1] - t) || (map[xod[0]][0] == map[close][0] + t && map[xod[0]][1] == map[close][1] - t))
							{
								if (xod[1] == 1) { Player_voin_xod[close][0].bronz += coinvoin[1]; Player_voin_map[xod[0]][0].bronz -= coinvoin[1]; }
								if (xod[1] == 2) { Player_voin_xod[close][0].serebr += coinvoin[1]; Player_voin_map[xod[0]][0].serebr -= coinvoin[1]; }
								if (xod[1] == 3) { Player_voin_xod[close][0].gold += coinvoin[1]; Player_voin_map[xod[0]][0].gold -= coinvoin[1]; }
							}
							xod[0] = 0;
						}
						///////////////������� �� ����� ��� ������ ����//////////////////////
						if ((ap == 7 || ap == 15 || ap == 16 || ap == 17 || ap == 18) && (Player_voin_map[close][0].bronz > 0 || Player_voin_map[close][0].serebr > 0 || Player_voin_map[close][0].gold > 0))
						{
							for (int i = 1; i <= kol; i++)
							{
								if (map[close][0] == map[i][0] - t && map[close][1] == map[i][1] + t)
								{
									if (colr[i] != 10 && colr[i] != 0)
									{
										if (Player_sost[0][colr[i]] == 1 || Player_sost[0][colr[i]] == 0)
										{
											strelka(renderer, map[close][0], map[close][1], 2, 0, t);
										}
										else
										{
											strelka(renderer, map[close][0], map[close][1], 2, 1, t);
										}
									}
									if (colr[i] == 10)
									{
										strelka(renderer, map[close][0], map[close][1], 2, 0, t);
									}
									if (colr[i] == 0)
									{
										strelka(renderer, map[close][0], map[close][1], 2, 1, t);
									}
								}
								if (map[close][0] == map[i][0] + t && map[close][1] == map[i][1] + t)
								{
									if (colr[i] != 10 && colr[i] != 0)
									{
										if (Player_sost[0][colr[i]] == 1 || Player_sost[0][colr[i]] == 0)
										{
											strelka(renderer, map[close][0], map[close][1], 1, 0, t);
										}
										else
										{
											strelka(renderer, map[close][0], map[close][1], 1, 1, t);
										}
									}
									if (colr[i] == 10)
									{
										strelka(renderer, map[close][0], map[close][1], 1, 0, t);
									}
									if (colr[i] == 0)
									{
										strelka(renderer, map[close][0], map[close][1], 1, 1, t);
									}
								}
								if (map[close][0] == map[i][0] - t && map[close][1] == map[i][1] - t)
								{
									if (colr[i] != 10 && colr[i] != 0)
									{
										if (Player_sost[0][colr[i]] == 1 || Player_sost[0][colr[i]] == 0)
										{
											strelka(renderer, map[close][0], map[close][1], 3, 0, t);
										}
										else
										{
											strelka(renderer, map[close][0], map[close][1], 3, 1, t);
										}
									}
									if (colr[i] == 10)
									{
										strelka(renderer, map[close][0], map[close][1], 3, 0, t);
									}
									if (colr[i] == 0)
									{
										strelka(renderer, map[close][0], map[close][1], 3, 1, t);
									}
								}
								if (map[close][0] == map[i][0] + t && map[close][1] == map[i][1] - t)
								{
									if (colr[i] != 10 && colr[i] != 0)
									{
										if (Player_sost[0][colr[i]] == 1 || Player_sost[0][colr[i]] == 0)
										{
											strelka(renderer, map[close][0], map[close][1], 4, 0, t);
										}
										else
										{
											strelka(renderer, map[close][0], map[close][1], 4, 1, t);
										}
									}
									if (colr[i] == 10)
									{
										strelka(renderer, map[close][0], map[close][1], 4, 0, t);
									}
									if (colr[i] == 0)
									{
										strelka(renderer, map[close][0], map[close][1], 4, 1, t);
									}
								}
							}
						}
						//��������� ����� �� �����
						for (int i = 1; i <= kol; i++)
						{
							for (int j = 0; j < Player_kol; j++)
							{
								int nom = 0;
								if (Player_voin_map[i][j].bronz > 0)
								{
									risovka_voin_wind(renderer, map[i][0], map[i][1], nom, j, 1);
									nom++;
								}
								if (Player_voin_map[i][j].serebr > 0)
								{
									risovka_voin_wind(renderer, map[i][0], map[i][1], nom, j, 2);
									nom++;
								}
								if (Player_voin_map[i][j].gold > 0)
								{
									risovka_voin_wind(renderer, map[i][0], map[i][1], nom, j, 3);
								}
							}
						}
						if (close != 0)
						{
							//����� ���������� ���������
							gorod(renderer);
							pokaz_4icel(window, renderer, gor_nas[close], 9);
							if (sost == 5)
								Menu_obchenia(renderer, 14, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
							//��������� ������� �������
							obvodka(renderer, map[close][0], map[close][1], t);
							//������ �� ������ ����////////////////
							Menu_obchenia(renderer, ap, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
							if (ap == 7)
							{////////////////����� ������������� ���� ������
								if (Player_voin_map[close][0].bronz == 0)
									xod_voin(renderer, 1);
								if (Player_voin_map[close][0].serebr == 0)
									xod_voin(renderer, 2);
								if (Player_voin_map[close][0].gold == 0)
									xod_voin(renderer, 3);
							}
							if (ap != 0)
								//������� ���������///////////////
								risovka_3danij(renderer, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
							if (ap == 6)
							{
								pokaz_4icel(window, renderer, coinvoin[1], 4);
								pokaz_4icel(window, renderer, coinvoin[2], 5);
								pokaz_4icel(window, renderer, coinvoin[3], 6);
								if (coinvoin[1] == 0)
								{
									Menu_obchenia(renderer, 13, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
								if (coinvoin[2] == 0)
								{
									Menu_obchenia(renderer, 8, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
								if (coinvoin[3] == 0)
								{
									Menu_obchenia(renderer, 9, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
								if (price[3][1].gold*coinvoin[1] + 1 > Player_res[0].gold || price[3][1].eat*coinvoin[1] + 1 > Player_res[0].eat || price[3][1].metl*coinvoin[1] + 1 > Player_res[0].metl)
								{
									Menu_obchenia(renderer, 10, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
								if (price[3][2].gold*coinvoin[2] + 1 > Player_res[0].gold || price[3][2].eat*coinvoin[2] + 1 > Player_res[0].eat || price[3][2].metl*coinvoin[2] + 1 > Player_res[0].metl)
								{
									Menu_obchenia(renderer, 11, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
								if (price[3][3].gold*coinvoin[3] + 1 > Player_res[0].gold || price[3][3].eat*coinvoin[3] + 1 > Player_res[0].eat || price[3][3].metl*coinvoin[3] + 1 > Player_res[0].metl)
								{
									Menu_obchenia(renderer, 12, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
								}
							}
							////////////////////��� ������� �������� �������
							if (ap == 15 || ap == 16 || ap == 17)
							{
								pokaz_4icel(window, renderer, coinvoin[1], 8);
								if (ap == 15)
								{
									pokaz_4icel(window, renderer, Player_voin_map[close][0].bronz, 7);
									if (coinvoin[1] == 0)
									{
										Menu_obchenia(renderer, 13, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
									if (coinvoin[1] == Player_voin_map[close][0].bronz)
									{
										Menu_obchenia(renderer, 10, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
								}
								if (ap == 16)
								{
									pokaz_4icel(window, renderer, Player_voin_map[close][0].serebr, 7);
									if (coinvoin[1] == 0)
									{
										Menu_obchenia(renderer, 13, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
									if (coinvoin[1] == Player_voin_map[close][0].serebr)
									{
										Menu_obchenia(renderer, 10, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
								}
								if (ap == 17)
								{
									pokaz_4icel(window, renderer, Player_voin_map[close][0].gold, 7);
									if (coinvoin[1] == 0)
									{
										Menu_obchenia(renderer, 13, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
									if (coinvoin[1] == Player_voin_map[close][0].gold)
									{
										Menu_obchenia(renderer, 10, Player_st[close].market, Player_st[close].kazarm, Player_st[close].krepoct, Player_st[close].mine);
									}
								}
							}
						}
						////////////////////////////////////////////pause/////////////////////////////////////////////////////						
						if (((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE)) || (pause == 1))
						{
							pause = 1; close = 0; ap = 0;
							pauzz(renderer);
							//����������
							if (event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= 350 && event.button.x <= 928 && event.button.y >= 100 && event.button.y < 208)
							{
								pause = 0;
							}
							//���������
							if (event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= 400 && event.button.x <= 878 && event.button.y >= 284 && event.button.y < 380)
							{
								FILE* tex;
								fopen_s(&tex, "save-save", "w");
								fprintf(tex, "%d ", Player_kol);
								for (int i = 1; i <= kol; i++)
								{
									for (int j = 0; j < Player_kol; j++)
									{
										fprintf(tex, "%d ", Player_voin_map[i][j].bronz);
										fprintf(tex, "%d ", Player_voin_map[i][j].serebr);
										fprintf(tex, "%d ", Player_voin_map[i][j].gold);
									}
								}
								for (int i = 1; i <= kol; i++)
								{
									for (int j = 0; j < Player_kol; j++)
									{
										fprintf(tex, "%d ", Player_voin_xod[i][j].bronz);
										fprintf(tex, "%d ", Player_voin_xod[i][j].serebr);
										fprintf(tex, "%d ", Player_voin_xod[i][j].gold);
									}
								}
								for (int i = 0; i < Player_kol; i++)
								{
									for (int j = 0; j < 10; j++)
									{
										fprintf(tex, "%d ", Player_sost[i][j]);
									}
								}
								for (int i = 0; i < Player_kol; i++)
								{
									fprintf(tex, "%d ", Player_res[i].eat);
									fprintf(tex, "%d ", Player_res[i].gold);
									fprintf(tex, "%d ", Player_res[i].metl);
								}
								for (int i = 1; i <= kol; i++)
								{
									fprintf(tex, "%d ", Player_st[i].kazarm);
									fprintf(tex, "%d ", Player_st[i].krepoct);
									fprintf(tex, "%d ", Player_st[i].market);
									fprintf(tex, "%d ", Player_st[i].mine);
								}
								for (int i = 1; i <= kol; i++)
								{
									fprintf(tex, "%d ", colr[i]);
								}
								for (int i = 1; i <= kol; i++)
								{
									fprintf(tex, "%d ", gor_nas[i]);
								}
								fclose(tex);
							}
							//�����
							if (event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= 486 && event.button.x <= 790 && event.button.y >= 553 && event.button.y < 637)
							{
								quit = true;
							}
						}
						//��������� ���//////////////////////////////////////////////////
						if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 1125 && event.button.x <= 1276 && event.button.y >= 566 && event.button.y <= 716) && pick==0)
						{
							//���� ���������� �����
							///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							int bot; int fan;
							for (int i = 1; i < Player_kol; i++)
							{
								bot = rand() % 2;
								if (bot == 1)////---
								{
									for (int j = 1; j <= kol; j++)
									{
										if ((colr[j] == i) && Player_res[i].eat - price[1][0].eat > 0 && Player_res[i].gold - price[1][0].gold*3 > 0 && Player_res[i].metl - price[1][0].metl > 0 && Player_st[j].kazarm == 1)
										{
											Player_st[j].kazarm = 2;
											Player_res[i].eat -= price[1][0].eat;
											Player_res[i].gold -= price[1][0].gold;
											Player_res[i].metl -= price[1][0].metl;
										}
										if ((colr[j] == i) && Player_res[i].eat - price[2][0].eat*2 > 0 && Player_res[i].gold*2 - price[2][0].gold > 0 && Player_res[i].metl*4 - price[2][0].metl > 0 && Player_st[j].kazarm == 2)
										{
											Player_st[j].kazarm = 3;
											Player_res[i].eat -= price[2][0].eat;
											Player_res[i].gold -= price[2][0].gold;
											Player_res[i].metl -= price[2][0].metl;
										}
										if ((colr[j] == i) && Player_res[i].eat - price[0][0].eat*2 > 0 && Player_res[i].gold*2 - price[0][0].gold > 0 && Player_res[i].metl - price[0][0].metl > 0 && Player_st[j].kazarm == 0)
										{
											Player_st[j].kazarm = 1;
											Player_res[i].eat -= price[0][0].eat;
											Player_res[i].gold -= price[0][0].gold;
											Player_res[i].metl -= price[0][0].metl;
										}
										if ((colr[j] == i) && Player_res[i].eat - price[2][2].eat * 4 > 0 && Player_res[i].gold * 4 - price[2][2].gold > 0 && Player_res[i].metl - price[2][2].metl > 0 && Player_st[j].krepoct == 2)
										{
											Player_st[j].krepoct = 1;
											Player_res[i].eat -= price[2][2].eat;
											Player_res[i].gold -= price[2][2].gold;
											Player_res[i].metl -= price[2][2].metl;
										}										
										if ((colr[j] == i) && Player_res[i].eat - price[1][2].eat * 3 > 0 && Player_res[i].gold *  - price[1][2].gold > 0 && Player_res[i].metl - price[1][2].metl > 0 && Player_st[j].krepoct == 1)
										{
											Player_st[j].krepoct = 2;
											Player_res[i].eat -= price[1][2].eat;
											Player_res[i].gold -= price[1][2].gold;
											Player_res[i].metl -= price[1][2].metl;
										}																				
										if ((colr[j] == i) && Player_res[i].eat - price[0][2].eat * 2 > 0 && Player_res[i].gold * 2 - price[0][2].gold > 0 && Player_res[i].metl - price[0][2].metl > 0 && Player_st[j].krepoct == 0)
										{
											Player_st[j].krepoct = 1;
											Player_res[i].eat -= price[0][2].eat;
											Player_res[i].gold -= price[0][2].gold;
											Player_res[i].metl -= price[0][2].metl;
										}										
										if ((colr[j] == i) && Player_st[j].kazarm == 1 && Player_res[i].eat - price[3][1].eat * 7 > 0 && Player_res[i].gold - price[3][1].gold * 9 > 0 && Player_res[i].metl - price[3][1].metl * 8 > 0)
										{
											Player_voin_map[j][i].bronz++;
											Player_res[i].eat -= price[3][1].eat;
											Player_res[i].gold -= price[3][1].gold;
											Player_res[i].metl -= price[3][1].metl;
											gor_nas[j]--;
										}
										if ((colr[j] == i) && Player_st[j].kazarm == 2 && Player_res[i].eat - price[3][2].eat * 12 > 0 && Player_res[i].gold - price[3][2].gold * 15 > 0 && Player_res[i].metl - price[3][2].metl * 8 > 0)
										{
											Player_voin_map[j][i].serebr++;
											Player_res[i].eat -= price[3][2].eat;
											Player_res[i].gold -= price[3][2].gold;
											Player_res[i].metl -= price[3][2].metl;
											gor_nas[j]--;
										}
										if ((colr[j] == i) && Player_st[j].kazarm == 3 && Player_res[i].eat - price[3][3].eat * 27 > 0 && Player_res[i].gold - price[3][3].gold * 29 > 0 && Player_res[i].metl - price[3][3].metl * 28 > 0)
										{
											Player_voin_map[j][i].gold++;
											Player_res[i].eat -= price[3][3].eat;
											Player_res[i].gold -= price[3][3].gold;
											Player_res[i].metl -= price[3][3].metl;
											gor_nas[j]--;
										}
									}
									for (int j = 0; j < Player_kol; j++)
									{
										fan = rand() % 3;
										if (fan == 1)
										{
											Player_sost[i][j] = 2;
										}
										else
										{
											Player_sost[i][j] = 1;
										}
									}
									for (int j = 1; j <= kol; j++)
									{
										fan = rand() % 4;
										for (int k = 1; k <= kol; k++)
										{
											if (colr[j] == i)
											{
												if (fan == 0 && map[j][0] == map[k][0] - t && map[j][1] == map[k][1] + t)
												{
													Player_voin_xod[k][i].bronz = Player_voin_map[j][i].bronz;
													Player_voin_xod[k][i].serebr = Player_voin_map[j][i].serebr;
													Player_voin_xod[k][i].gold = Player_voin_map[j][i].gold;
												}
												if (fan == 1 && map[j][0] == map[k][0] + t && map[j][1] == map[k][1] + t)
												{
													Player_voin_xod[k][i].bronz = Player_voin_map[j][i].bronz;
													Player_voin_xod[k][i].serebr = Player_voin_map[j][i].serebr;
													Player_voin_xod[k][i].gold = Player_voin_map[j][i].gold;
												}
												if (fan == 2 && map[j][0] == map[k][0] - t && map[j][1] == map[k][1] - t)
												{
													Player_voin_xod[k][i].bronz = Player_voin_map[j][i].bronz;
													Player_voin_xod[k][i].serebr = Player_voin_map[j][i].serebr;
													Player_voin_xod[k][i].gold = Player_voin_map[j][i].gold;
												}
												if (fan == 3 && map[j][0] == map[k][0] + t && map[j][1] == map[k][1] - t)
												{
													Player_voin_xod[k][i].bronz = Player_voin_map[j][i].bronz;
													Player_voin_xod[k][i].serebr = Player_voin_map[j][i].serebr;
													Player_voin_xod[k][i].gold = Player_voin_map[j][i].gold;
												}
											}
										}
									}
								}
								else//////////+++++
								{
								for (int j = 1; j <= kol; j++)
								{
									if ((colr[j] == i) && Player_res[i].eat - price[0][3].eat * 2 > 0 && Player_res[i].gold * 2 - price[0][3].gold > 0 && Player_res[i].metl - price[0][3].metl > 0 && Player_st[j].market == 0)
									{
										Player_st[j].market = 1;
										Player_res[i].eat -= price[0][3].eat;
										Player_res[i].gold -= price[0][3].gold;
										Player_res[i].metl -= price[0][3].metl;
									}
									if ((colr[j] == i) && Player_res[i].eat - price[2][1].eat * 13 > 0 && Player_res[i].gold * 12 - price[2][1].gold > 0 && Player_res[i].metl - price[2][1].metl > 0 && Player_st[j].mine == 2)
									{
										Player_st[j].mine = 3;
										Player_res[i].eat -= price[2][1].eat;
										Player_res[i].gold -= price[2][1].gold;
										Player_res[i].metl -= price[2][1].metl;
									}
									if ((colr[j] == i) && Player_res[i].eat - price[1][1].eat * 5 > 0 && Player_res[i].gold * 5 - price[1][1].gold > 0 && Player_res[i].metl - price[1][1].metl > 0 && Player_st[j].mine == 1)
									{
										Player_st[j].mine = 2;
										Player_res[i].eat -= price[1][1].eat;
										Player_res[i].gold -= price[1][1].gold;
										Player_res[i].metl -= price[1][1].metl;
									}
									if ((colr[j] == i) && Player_res[i].eat - price[0][1].eat * 2 > 0 && Player_res[i].gold * 2 - price[0][1].gold > 0 && Player_res[i].metl - price[0][1].metl > 0 && Player_st[j].mine == 0)
									{
										Player_st[j].mine = 1;
										Player_res[i].eat -= price[0][1].eat;
										Player_res[i].gold -= price[0][1].gold;
										Player_res[i].metl -= price[0][1].metl;
									}									
								}
								for (int j = 0; j < Player_kol; j++)
								{
									fan = rand() % 8;
									if (fan == 1)
									{
										Player_sost[i][j] = 1;
									}
									else
									{
										Player_sost[i][j] = 2;
									}
								}
								}
							}
							///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							close = 0;
							ap = 0;
							//���������� ������������ �������
							for (int i = 0; i < Player_kol; i++)
							{
								///////////+++++++
								for (int j = 1; j <= kol; j++)
								{
									if (colr[j] == i)
									{
										Player_res[i].gold += pice_men.gold;
										Player_res[i].eat += pice_men.eat;
										Player_res[i].metl += pice_men.metl;
										if (Player_st[j].market == 1)
										{
											Player_res[i].gold += pice_market.gold;
											Player_res[i].eat += pice_market.eat;
											Player_res[i].metl += pice_market.metl;
										}
										if (Player_st[j].mine == 1)
										{
											Player_res[i].gold += pice_mine.gold;
											Player_res[i].eat += pice_mine.eat;
											Player_res[i].metl += pice_mine.metl;
										}
										if (Player_st[j].mine == 2)
										{
											Player_res[i].gold += 2 * pice_mine.gold;
											Player_res[i].eat += 2 * pice_mine.eat;
											Player_res[i].metl += 2 * pice_mine.metl;
										}
										if (Player_st[j].mine == 3)
										{
											Player_res[i].gold += 3 * pice_mine.gold;
											Player_res[i].eat += 3 * pice_mine.eat;
											Player_res[i].metl += 3 * pice_mine.metl;
										}
									}
								}
								/////////////////----------
								for (int j = 1; j <= kol; j++)
								{
									Player_res[i].gold = Player_res[i].gold - ((Player_voin_map[j][i].bronz + Player_voin_map[j][i].serebr * 2 + Player_voin_map[j][i].gold * 3)*pice_arm.gold);
									Player_res[i].eat = Player_res[i].eat - ((Player_voin_map[j][i].bronz + Player_voin_map[j][i].serebr * 2 + Player_voin_map[j][i].gold * 3)*pice_arm.eat);
									Player_res[i].metl = Player_res[i].metl - ((Player_voin_map[j][i].bronz + Player_voin_map[j][i].serebr * 2 + Player_voin_map[j][i].gold * 3)*pice_arm.metl);
								}
								for (int j = 0; j < 10; j++)
								{
									if (Player_sost[i][j] == 2)
									{
										Player_res[i].gold -= pice_sost_voin.gold;
										Player_res[i].eat -= pice_sost_voin.eat;
										Player_res[i].metl -= pice_sost_voin.metl;
									}
								}
							}
							//��� ������ � �� ������������
							for (int i = 1; i <= kol; i++)
							{
								for (int j = 0; j < Player_kol; j++)
								{
									Player_voin_map[i][j].bronz += Player_voin_xod[i][j].bronz;
									Player_voin_map[i][j].serebr += Player_voin_xod[i][j].serebr;
									Player_voin_map[i][j].gold += Player_voin_xod[i][j].gold;
									Player_voin_xod[i][j].bronz = 0;
									Player_voin_xod[i][j].serebr = 0;
									Player_voin_xod[i][j].gold = 0;
								}
							}
							//�������� 
							for (int i = 1; i <= kol; i++)
							{
								for (int j = 0; j < Player_kol; j++)
								{
									for (int j1 = 0; j1 < Player_kol; j1++)
									{
										if (j != j1)
										{
											//////////////////////////////////////////////////
											if (Player_voin_map[i][j].bronz != 0 && Player_voin_map[i][j1].bronz != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].bronz * Player_st[i].krepoct >= Player_voin_map[i][j1].bronz)
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].bronz / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].bronz*Player_st[i].krepoct;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].bronz * Player_st[i].krepoct >= Player_voin_map[i][j].bronz)
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].bronz / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].bronz*Player_st[i].krepoct;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].bronz >= Player_voin_map[i][j1].bronz)
													{
														Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].bronz;
													}
													else
													{
														Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].bronz;
													}
												}
											}
											if (Player_voin_map[i][j].bronz != 0 && Player_voin_map[i][j1].serebr != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].bronz * Player_st[i].krepoct >= Player_voin_map[i][j1].serebr*2)
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].serebr*2 / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].bronz*Player_st[i].krepoct/2;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].serebr * Player_st[i].krepoct*2 >= Player_voin_map[i][j].bronz)
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].bronz / Player_st[i].krepoct/2;
														}
														else
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].serebr*Player_st[i].krepoct*2;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].bronz >= Player_voin_map[i][j1].serebr*2)
													{
														Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].serebr*2;
													}
													else
													{
														Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].bronz/2;
													}
												}
											}
											if (Player_voin_map[i][j].bronz != 0 && Player_voin_map[i][j1].gold != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].bronz * Player_st[i].krepoct >= Player_voin_map[i][j1].gold * 3)
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].gold * 3 / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].bronz*Player_st[i].krepoct / 3;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].gold * Player_st[i].krepoct * 3 >= Player_voin_map[i][j].bronz)
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].bronz / Player_st[i].krepoct / 3;
														}
														else
														{
															Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].gold*Player_st[i].krepoct * 3;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].bronz >= Player_voin_map[i][j1].gold * 3)
													{
														Player_voin_map[i][j].bronz -= Player_voin_map[i][j1].gold * 3;
													}
													else
													{
														Player_voin_map[i][j1].gold -= Player_voin_map[i][j].bronz / 3;
													}
												}
											}
											if (Player_voin_map[i][j].serebr != 0 && Player_voin_map[i][j1].bronz != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].serebr * Player_st[i].krepoct*2 >= Player_voin_map[i][j1].bronz)
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].bronz / Player_st[i].krepoct/2;
														}
														else
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].serebr*Player_st[i].krepoct*2;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].bronz * Player_st[i].krepoct >= Player_voin_map[i][j].serebr*2)
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].serebr*2 / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].bronz*Player_st[i].krepoct/2;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].serebr*2 >= Player_voin_map[i][j1].bronz)
													{
														Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].bronz/2;
													}
													else
													{
														Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].serebr*2;
													}
												}
											}
											if (Player_voin_map[i][j].serebr != 0 && Player_voin_map[i][j1].serebr != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].serebr * Player_st[i].krepoct >= Player_voin_map[i][j1].serebr)
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].serebr  / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].serebr*Player_st[i].krepoct ;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].serebr * Player_st[i].krepoct  >= Player_voin_map[i][j].serebr)
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].serebr / Player_st[i].krepoct ;
														}
														else
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].serebr*Player_st[i].krepoct ;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].serebr >= Player_voin_map[i][j1].serebr )
													{
														Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].serebr ;
													}
													else
													{
														Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].serebr ;
													}
												}
											}
											if (Player_voin_map[i][j].serebr != 0 && Player_voin_map[i][j1].gold != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].serebr*2 * Player_st[i].krepoct >= Player_voin_map[i][j1].gold * 3)
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].gold * 3 / Player_st[i].krepoct/2;
														}
														else
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].serebr*2*Player_st[i].krepoct / 3;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].gold * Player_st[i].krepoct * 3 >= Player_voin_map[i][j].serebr*2)
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].serebr*2 / Player_st[i].krepoct / 3;
														}
														else
														{
															Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].gold*Player_st[i].krepoct * 3/2;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].serebr*2 >= Player_voin_map[i][j1].gold * 3)
													{
														Player_voin_map[i][j].serebr -= Player_voin_map[i][j1].gold * 3/2;
													}
													else
													{
														Player_voin_map[i][j1].gold -= Player_voin_map[i][j].serebr*2 / 3;
													}
												}
											}
											if (Player_voin_map[i][j].gold != 0 && Player_voin_map[i][j1].bronz != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].gold*3 * Player_st[i].krepoct >= Player_voin_map[i][j1].bronz)
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].bronz / Player_st[i].krepoct/3;
														}
														else
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].gold*3*Player_st[i].krepoct;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].bronz * Player_st[i].krepoct >= Player_voin_map[i][j].gold*3)
														{
															Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].gold*3 / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].bronz*Player_st[i].krepoct/3;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].gold*3 >= Player_voin_map[i][j1].bronz)
													{
														Player_voin_map[i][j].gold -= Player_voin_map[i][j1].bronz/3;
													}
													else
													{
														Player_voin_map[i][j1].bronz -= Player_voin_map[i][j].gold*3;
													}
												}
											}
											if (Player_voin_map[i][j].gold != 0 && Player_voin_map[i][j1].serebr != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].gold*3 * Player_st[i].krepoct >= Player_voin_map[i][j1].serebr * 2)
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].serebr * 2 / Player_st[i].krepoct/3;
														}
														else
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].gold*3*Player_st[i].krepoct / 2;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].serebr * Player_st[i].krepoct * 2 >= Player_voin_map[i][j].gold*3)
														{
															Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].gold*3 / Player_st[i].krepoct / 2;
														}
														else
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].serebr*Player_st[i].krepoct * 2/3;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].gold*3 >= Player_voin_map[i][j1].serebr * 2)
													{
														Player_voin_map[i][j].gold -= Player_voin_map[i][j1].serebr * 2/3;
													}
													else
													{
														Player_voin_map[i][j1].serebr -= Player_voin_map[i][j].gold*3 / 2;
													}
												}
											}
											if (Player_voin_map[i][j].gold != 0 && Player_voin_map[i][j1].gold != 0)
											{
												if (colr[i] == j)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j].gold * Player_st[i].krepoct >= Player_voin_map[i][j1].gold )
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].gold / Player_st[i].krepoct;
														}
														else
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].gold*Player_st[i].krepoct ;
														}
													}
												}
												if (colr[i] == j1)
												{
													if (Player_st[i].krepoct != 0)
													{
														if (Player_voin_map[i][j1].gold * Player_st[i].krepoct  >= Player_voin_map[i][j].gold)
														{
															Player_voin_map[i][j1].gold -= Player_voin_map[i][j].gold / Player_st[i].krepoct ;
														}
														else
														{
															Player_voin_map[i][j].gold -= Player_voin_map[i][j1].gold*Player_st[i].krepoct ;
														}
													}
												}
												if (colr[i] != j1 && colr[i] != j)
												{
													if (Player_voin_map[i][j].gold >= Player_voin_map[i][j1].gold )
													{
														Player_voin_map[i][j].gold -= Player_voin_map[i][j1].gold ;
													}
													else
													{
														Player_voin_map[i][j1].gold -= Player_voin_map[i][j].gold ;
													}
												}
											}
											//////////////////////////////////////////////
										}
									}
								}
							}
							//���������� ������� �� ����������
							for (int i = 1; i <= kol; i++)
							{
								for (int j = 0; j < Player_kol; j++)
								{
									if (Player_voin_map[i][j].bronz > 0 || Player_voin_map[i][j].serebr > 0 || Player_voin_map[i][j].gold > 0)
									{
										colr[i] = j;
									}
								}
							}
							/////////��������� ���������
							for (int i = 0; i < Player_kol; i++)
							{
								for (int j = 0; j < Player_kol; j++)
								{
									if (Player_sost[i][j] == 2 && Player_sost[j][i] != 1)
									{
										Player_sost[j][i] = 2;
									}
									if (Player_sost[i][j] == 1)
									{
										Player_sost[j][i] = 1;
									}
								}
							}
							/////////////////����� ���������
							for (int i = 0; i < Player_kol; i++)
							{
								int lup = 0;
								for (int j = 1; j <= kol; j++)
								{
									if (colr[j] == i)
										lup++;
								}
								if (lup == 0)
								{
									Player_res[i].eat = 0;
									Player_res[i].gold = 0;
									Player_res[i].metl = 0;
									for (int j = 1; j <= kol; j++)
									{
										Player_voin_map[j][i].bronz = 0;
										Player_voin_map[j][i].serebr = 0;
										Player_voin_map[j][i].gold= 0;
										Player_voin_xod[j][i].bronz = 0;
										Player_voin_xod[j][i].gold = 0;
										Player_voin_xod[j][i].serebr = 0;
									}
									for (int j = 0; j < 10; j++)
									{
										Player_sost[i][j] = 0;
									}
								}
							}
						}
						SDL_RenderPresent(renderer);
						if (event.type == SDL_MOUSEBUTTONDOWN)
						{
							SDL_Delay(200);
							pick++;
						}
						if (event.type == SDL_MOUSEBUTTONUP)
						{
							pick = 0;
						}
						if (event.type == SDL_QUIT)
							quit = true;
					}
				}			
		}	
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;
	return 0;
}