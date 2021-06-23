#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct points
{
    int x;                                                   //Parting Snake Body through Struct.
    int y;
};
int gotoxy(int x, int y)
{
    COORD points;
    points.X = x;													//GOTO X,Y.
    points.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), points);
    return 0;
}

void Walls(int HEIGHT, int WIDTH)
{
    for (int h_index = 0; h_index < HEIGHT; h_index++)
    {
        cout << "#";
        for (int b_index = 0; b_index < WIDTH; b_index++)       //Generating Walls Function.
        {
            if (h_index == 0 || h_index == (HEIGHT - 1))
                cout << "#";
            else {
                cout << " ";
            }
        }
        cout << "#" << endl;
    }
}

void make_Snake(points* arr)
{
    arr[0].x = 21; arr[0].y = 13;						//Making of Snake Function.

}
int hurdles()
 {
	    int y=7,x=34;

	    for(int h=0;h<8;h++)
	    {
	    	gotoxy(x,y);
	    	cout<<"*";
	    	x++;
	    }
	    
	    x=12;                                           //Hurdels.
	    y=17;

	  
	    for(int h=0;h<8;h++)
	    {
	    	gotoxy(x,y);
	    	cout<<"*";
	    	x++;
	    }

}
void  display_Snake(points snake[], int score)
{
    int index;
    for (index = 0; index < score; index++)
    {
        gotoxy(snake[index].x, snake[index].y);
        if (index == 0)
            cout << "O";
        else
            cout << "*";

    }
}
void  remove_Snake(points snake[], int score)
{
    int index;
    for (index = 0; index < score; index++)                   //Removing Snake Function.
    {
        gotoxy(snake[index].x, snake[index].y);
        cout << " ";

    }
}

void generate_Fruit(int& Fruit_x, int& Fruit_y)
{
    Fruit_x = (rand() % 50) + 1;                                //Generating Food Function.
    Fruit_y = (rand() % 23) + 1;
    if((Fruit_x >= 34 && Fruit_x <= 41 && Fruit_y == 7))
    {
        Fruit_y++;
    }
    else if((Fruit_x >= 12 && Fruit_x <= 19 && Fruit_y == 17))
    {
        Fruit_y++;
    }
	gotoxy(Fruit_x, Fruit_y);
    cout << "&";
}

bool eat_Fruit(points arr[], int Fruit_x, int Fruit_y, int& score)
{
    if (arr[0].x == Fruit_x && arr[0].y == Fruit_y)
    {
        gotoxy(Fruit_x, Fruit_y);
        cout << " ";                                          //Eating of Food fumction.
        score = score + 1;
        return true;
    }
    else
        return false;

}
void UP_Move(struct points snake[], int score)
{
    int index;

    for (index = score; index > 0; index--)
    {
        snake[index].x = snake[index - 1].x;
        snake[index].y = snake[index - 1].y;                      //Moving UP Function.
    }
    snake[index].y = snake[index].y - 1;
}
void DOWN_Move(struct points snake[], int score)
{
    int index;

    for (index = score; index > 0; index--)
    {
        snake[index].x = snake[index - 1].x;                    //Moving DOWN Function.
        snake[index].y = snake[index - 1].y;
    }
    snake[index].y = snake[index].y + 1;
}
void RIGHT_Move(struct points snake[], int score)
{
    int index;
    for (index = score; index > 0; index--)
    {
        snake[index].x = snake[index - 1].x;                   //Moving RIGHT Function.
        snake[index].y = snake[index - 1].y;
    }
    snake[index].x = snake[index].x + 1;
}

void LEFT_Move(struct points snake[], int score)
{
    int index;
    for (index = score; index > 0; index--)
    {
        snake[index].x = snake[index - 1].x;                    //Moving LEFT Function.
        snake[index].y = snake[index - 1].y;
    }
    snake[index].x = snake[index].x - 1;
}
int opposite_Motion_Control(int ch,int check)
{
	if(check==72)
		{
        	if(ch!=80)
        	{
        		ch=check;
        		return ch;                                 //Opposite Movement Controll Function.
			}
		}
		else if(check==77)
		{
			if(ch!=75)
			{
				ch=check;
				return ch;
			}
		}
			else if(check==80)
		{
			if(ch!=72)
			{
				ch=check;
				return ch;
			}
		}
			else if(check==75)
		{
			if(ch!=77)
			{
				ch=check;
				return ch;
			}
		}

}
void control_Speed(int score,int &speed,int &count)
{
	if (score==2&&count==0)
        	{
			speed=speed-100;
			count++;
			}
        else if(score==4&&count==1)                                 //Controlling Speed Function.
        {
        	speed=speed-30;
        	count++;
    	}
		else if(score==6&&count==2)
		{
        	speed=speed-20;
        	count++;
		}
		else if(score==8&&count==3)
		{
        	speed=speed-20;
        	count++;
		}
}

void Movement_Snake(points snake[], int ch, int score,int speed)
{
    int UP = 72;
    int DOWN = 80;
    int LEFT = 75;
    int RIGHT = 77;

    if (ch == UP)
    {
        display_Snake(snake, score);
        Sleep(speed);
        remove_Snake(snake, score);
        UP_Move(snake, score);
        display_Snake(snake, score);
    }                                                        //Total Movement Controll.
    else if (ch == DOWN)
    {
        display_Snake(snake, score);
        Sleep(speed);
        remove_Snake(snake, score);
        DOWN_Move(snake, score);
        display_Snake(snake, score);
    }
    else if (ch == RIGHT)
    {
        display_Snake(snake, score);
        Sleep(speed);
        remove_Snake(snake, score);
        RIGHT_Move(snake, score);
        display_Snake(snake, score);
    }
    else if (ch == LEFT)
    {
        display_Snake(snake, score);
        Sleep(speed);
        remove_Snake(snake, score);
        LEFT_Move(snake, score);
        display_Snake(snake, score);
    }
}

int snake_End(points snake[], int score)
{
    //for walls touch snake end.
    if (snake[0].y > 23) //BOTTOM.
    {
        return 0;
    }
    else if (snake[0].y < 1)
    {
        return 0;
    }
    else if (snake[0].x > 50) // RIGHT.
    {                                                         //Game Over Function.
        return 0;
    }
    else if (snake[0].x < 1)
    {
        return 0;
    }
   

    for (int index = 1; index < score; index++) //for body touch snake end.
    {
        if (snake[0].x == snake[index].x && snake[0].y == snake[index].y)
        {
            return 0;
        }
    }

}

int hurdle1_end(points snake[])
{
    if(snake[0].x >= 34 && snake[0].x <= 41 && snake[0].y == 7)
    {
        return 0;
    }
}

int hurdle2_end(points snake[])
{
    if(snake[0].x >= 12 && snake[0].x <= 19 && snake[0].y == 17)
    {
        return 0;
    }
}
int main()
{
    int Fruit_x, Fruit_y;
    struct points snake[100];
    int count = 0;
    int check=77;
    int HEIGHT = 25;
    int WIDTH = 50;
    int ch = 72;
    bool Eat;
    int hurdel;
    bool gameOver = false;
    int score = 1;                                                  //MAIN BODY.
    int speed=200;
	
    make_Snake(&snake[0]); //Making of Snake body.
    Walls(HEIGHT, WIDTH); //Generating Walls.
    generate_Fruit(Fruit_x, Fruit_y);
    hurdles();
    while (!gameOver)
    {
        if (_kbhit())
        {
        	check = _getch();
            check = _getch();
        }

      	ch=opposite_Motion_Control(ch,check); //Controlling Opposite Motion.

		control_Speed(score,speed,count);//controlling Speed of Snake.

        Sleep(speed);

        if (Eat)
        {
            generate_Fruit(Fruit_x, Fruit_y);//Generating Food.
        }

        //movement conditions
        if (ch == 72)
        {
            //UP
            Movement_Snake(snake, ch, score,speed);
        }

        else if (ch == 80)
        {
            //DOWN
            Movement_Snake(snake, ch, score,speed);
        }
        else if (ch == 77)
        {
            //RIGHT
            Movement_Snake(snake, ch, score,speed);
        }
        else if (ch == 75)
        {
            //LEFT
            Movement_Snake(snake, ch, score,speed);
        }

        Eat = eat_Fruit(snake, Fruit_x, Fruit_y, score); //Eating Food.
        gotoxy(0, 25);
        cout << "score::" << score - 1; //Displaying Score.

        int s_end = snake_End(snake, score); //Game Over Conditions.
        if (s_end == 0)
        {
           gameOver =true;
            system("pause");
        }
       int snake_end = hurdle1_end(snake);
        if(snake_end == 0)
        {
		    gameOver =true;
		    system("pause"); 
        }
        int snake_end1 = hurdle2_end(snake);
        if(snake_end1 == 0)
        {
            gameOver =true;
            system("pause");
        }        
    }
}
