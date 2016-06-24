#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
typedef int col[3];
const float DEG2RAD = 3.14189/180;
float dx5=0, dy5=0, ax4=350, ay4=450;
GLfloat ax,ay,bx,by,cx,cy,dx,dy,ex,ey,w1_ax,w1_ay,w1_bx,w1_by,w1_cx,w1_cy,w1_dx,w1_dy;
float incx=1;
float r = 100.0;
float r_s1 = 200.0;
float r1 = 30.0;
float r_bush = 10.0;
float r_slope1 = 50.0;
float r_hut = 20.0;
float r_chair = 33.25;
int i,j,k,l;
int frameNumber = 0;
int a=0;
int current_frame=0;
void draw_circle(float theta1,float theta2,float radius1,float radius2,float x,float y)
{
	glBegin(GL_POLYGON);
	for(int i=theta1;i<=theta2;i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*radius1+x,sin(degInRad)*radius2+y);
	}
	glEnd();
}
void draw_triangle(float vx1,float vy1, float vx2,float vy2, float vx3,float vy3)
{
	glBegin(GL_POLYGON);
		glVertex2f(vx1,vy1);
		glVertex2f(vx2,vy2);
		glVertex2f(vx3,vy3);
	glEnd();

}
void draw_quad(float vx1,float vy1, float vx2,float vy2, float vx3,float vy3, float vx4,float vy4)
{
	glBegin(GL_POLYGON);
	glVertex2f(vx1,vy1);
	glVertex2f(vx2,vy2);
	glVertex2f(vx3,vy3);
	glVertex2f(vx4,vy4);
	glEnd();
}
/*------------------------------------frame0 starts-----------------------------------------*/
void output( int x, int y,const char *text)
  {
      glColor3f(0,0,0);
      glPushMatrix();
      glTranslatef(x, y, 0);
      glScalef(1/5.5, 1/5.5, 1/5.5);
      for (const char* p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
      glPopMatrix();

  }
void display0() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();
  glColor3f(1.0,0.5,0.5);
  draw_quad(0,0,0,500,700,500,700,0);
  glColor3f(1,0,0);
	output(225, 450, "The French Revolution");

  glColor3f(0.7,0.7,0.7);
	output(265, 400, "SUBMITTED BY");

	glColor3f(0.8,0.6,0.9);
	output(100, 320, "Randhir Singh");
	output(100, 270, "Shreya Sinha");

	glColor3f(0.8,0.6,0.9);
	output(450, 320, "1DS12CS077");
	output(450, 270, "1DS12CS094");

	glColor3f(0.5,0.5,0.5);
	output(200, 100, " Press 'c' to continue");

  glFlush();
}
/*------------------------------------frame0 ends-------------------------------------------*/
void create_partiton()
{
  glColor3f(0.0,0.0,0.0);
  glLineWidth(4.0);
  glBegin(GL_LINE_STRIP);
		glVertex2f(250,500);
		glVertex2f(250,105);
		glVertex2f(275,93.75);
		glVertex2f(275,50);
		glVertex2f(500,0);
  glEnd();
  glLineWidth(1.0);
}

void make_left_background(float x,float y)
{
  glColor3f(0.2,0.1,0.2);
	draw_quad(x,y+100,x,y+500,x+250,y+500,x+250,y+100);

	/*---stage 3----*/
	glColor3f(1.0,0.2,0.0);
	draw_quad(x,y,x,y+100,x+500,y+100,x+500,y);

	/*---stage 2----*/
	glColor3f(1.0,0.3,0.0);
	draw_circle(217,326,r_s1,r_s1,x+131,y+233);

	/*---stage 1----*/
	glColor3f(1.0,0.5,0.0);
	draw_circle(220,320,r_s1,r_s1,x+130.0,y+265.0);
}

void make_chair_king(float x, float y)
{
	//leg3
	glColor3f(1.0,1.0,0.0);
	draw_circle(0,180,r_hut,r_hut,x,y+83);
	draw_quad(x-5.5,y+87.5,x+7,y+87.5,x+7,y+162.5,x-5.5,y+162.5);

	/*---Chair back---*/
	glColor3f(1.0,1.0,0.0);
	for(i=0;i<2;i++)
	{
	draw_circle(0,360,r_hut,r_hut,x+i*147,y+333);
	draw_quad(x-5.5+i*146.5,y+217.5,x+7+i*147,y+217.5,x+7+i*147,y+332.5,x-5.5+i*146.5,y+332.5);
	draw_quad(x-5.5+i*146.5,y+352,x+7+i*147,y+352,x+7+i*147,y+383,x-5.5+i*146.5,y+383);
	}
	draw_quad(x-5.5,y+383,x+7,y+383,x+74,y+433,x+74,y+446);
	draw_quad(x+141,y+383,x+154,y+383,x+74,y+446,x+74,y+433);

	/*---chair hands---*/
	for(i=0;i<2;i++)
	{
	glColor3f(0.0,0.0,1.0);
	draw_quad(x+50+i*160,y+198.5,x-5.5+i*160,y+245,x-16+i*160,y+178.5,x+30+i*160,y+178.5);
	draw_circle(80,270,r_chair,r_chair,x-10+i*160,y+212.5);

	glBegin(GL_POLYGON);
	glVertex2f(x-12.5+i*160,y+178.5);
	glVertex2f(x-12.5+i*160,y+162.5);
	glVertex2f(x+7+i*160,y+141);
	glVertex2f(x+50+i*160,y+141);
	glVertex2f(x+50+i*160,y+178.5);
	glEnd();
	}
	//king left leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.2);
	glVertex2f(x+80,y+200);
	glVertex2f(x+120,y+175);
	glVertex2f(x+110,y+75);
	glVertex2f(x+95,y+75);
	glVertex2f(x+90,y+155);
	glVertex2f(x+30,y+200);
	glEnd();
	//king left leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.2);
	glVertex2f(105,225);
	glVertex2f(145,200);
	glVertex2f(135,100);
	glVertex2f(120,100);
	glVertex2f(115,180);
	glVertex2f(55,225);
	glEnd();
	for(i=0;i<2;i++)
	{
	/*---chair leg 1&2(front)----*/
	glColor3f(1.0,1.0,0.0);
	draw_circle(0,180,r_hut,r_hut,x+200-i*150,y+83);
	draw_quad(x+194.5-i*150,y+87.5,x+207-i*150,y+87.5,x+207-i*150,y+162.5,x+194.5-i*150,y+162.5);
	draw_circle(0,360,r_hut,r_hut,x+200-i*150,y+180);
	}
	/*-----------KING-----------*/
	//king hair right
	glColor3f(0.0,0.0,0.0);
	draw_circle(-65,65,x-5,y-5,x+87,y+330);
	//face
	glColor3f(1.0,0.9,0.7);
	draw_circle(0,360,x-5,y,x+80,y+325);
	//eyes
	glColor3f(0.0,0.0,0.0);
	for(int j=0;j<2;j++)
	{
	glBegin(GL_LINES);
	glLineWidth(5);
	for(int i=180;i<=360;i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*5+x+75+j*15,sin(degInRad)*5+y+325);
	}
	glEnd();
	}
	glLineWidth(1);
	//mouth
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glLineWidth(5);
	for(int i=180;i<=360;i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*5+x+82,sin(degInRad)*5+y+313);
	}
	glEnd();
	//king hair
	glColor3f(0.0,0.0,0.0);
	draw_circle(-65,45,x-5,y-5,x+47,y+330);
	draw_circle(0,360,x-20,y-17,x+54,y+320.5);
	draw_circle(45,135,x-5,y,x+80,y+325);
	//crown
	glColor3f(1.0,1.0,0.0);
	for(int i=0;i<5;i++)
	{
	draw_triangle(x+60 +i *8,y+338,x+60 +i *8,y+358,x+70 +i *8,y+342);
	}
	draw_circle(237,308,40,40,x+80,y+375);

	//king upper body
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.9);
	glVertex2f(x+80,y+300);
	glVertex2f(x+115,y+285);
	glVertex2f(x+165,y+238.5);
	glVertex2f(x+50,y+185);
	glVertex2f(x+20,y+218.5);
	glVertex2f(x+35,y+275);
	glVertex2f(x+80,y+300);
	glEnd();

	//right leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.2);
	glVertex2f(x+130,y+200);
	glVertex2f(x+170,y+175);
	glVertex2f(x+150,y+75);
	glVertex2f(x+135,y+75);
	glVertex2f(x+130,y+155);
	glVertex2f(x+100,y+200);
	glEnd();


	//tummy
	glColor3f(0.5,0.7,0.9);
	draw_circle(0,360,40,40,x+100,x+215);
	glColor3f(0.5,0.5,0.9);
	draw_circle(0,360,39,39,x+98,x+213);

	//left hand
	draw_circle(-190,270,r_slope1,r_slope1,x+70,x+232);

	//left shoulder
	glColor3f(0.5,0.5,0.9);
	draw_triangle(x+80,y+300,x+35,y+275,x+20,y+218.5);

	//cuff chicken
	//draw_triangle(x+69,y+180,x+74,y+193,x+29,y+210);
	//right shoulder
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.9);
	glVertex2f(105,325);
	glVertex2f(140,310);
	glVertex2f(190,263.5);
	glEnd();
	draw_circle(-10,90,40,30,155.0,250);
	glColor3f(0.5,0.7,0.9);
	draw_circle(170,270,40,30,195.0,273.5);
	glColor3f(0.5,0.5,0.9);
	draw_circle(170,270,40,30,197.0,275.5);

	//wine glass
	glColor3f(1.0,1.0,1.0);
	draw_circle(180,360,12,32,197.0,315.5);
	glColor3f(1.0,0.0,0.0);
	draw_circle(180,360,10,30,197.0,315.5);

	glColor3f(0.0,0.0,1.0);
	draw_quad(195,258,200,258,200,286,195,286);
	draw_quad(195,258,190,254,206,254,200,258);

	//wine hand
	glColor3f(1.0,0.9,0.7);
	draw_quad(180,268,181,276,200,276,197,263);

	//collar
	for(int i =0 ;i<3;i++)
	{
	glColor3f(1.0,0.5,1.0);
	draw_triangle(105,325,95+i*10,305,103+i*10,305);
	}
	//shoes
	glColor3f(0.0,0.0,0.0);
	draw_circle(-60,240,20,10,170.0,90.5);
	draw_circle(-60,240,20,10,130.0,90.5);

}
void make_chicken(float x,float y)
{
	//chicken
	glColor3f(1.0,0.0,0.0);
	draw_circle(0,360,20,25,x+82.5,y+225);

	//handle
	glColor3f(1.0,1.0,0.8);
	draw_quad(x+80,y+173,x+85,y+173,x+85,y+201,x+80,y+201);

	draw_circle(0,360,5,5,x+80,y+205);
	draw_circle(0,360,5,5,x+85,y+205);
	draw_circle(0,360,5,5,x+80,y+175);
	draw_circle(0,360,5,5,x+85,y+175);
	//bite
	glColor3f(0.5,0.5,0.9);
	draw_circle(0,360,5,5,x+65,y+235);
	draw_circle(0,360,5,5,x+70,y+243);

	//chicken hand
	glColor3f(1.0,0.9,0.7);
	draw_quad(x+70,y+183,x+71,y+191,x+90,y+191,x+87,y+178);
}

void make_castle()
{
	for(i=0;i<3;i++)
	{
		j=62.5;
		k=0;

		if(i==1)
		{
			j=37.5;k=25;
			//cone top
			glColor3f(0.0,0.0,0.0);
			draw_triangle(287.5,375,312.5,425,337.5,375);
		}
		else
		{
			//cone top
			glColor3f(0.0,0.0,0.0);
			draw_triangle(275+i*j,450+i*6.25,250+i*j,400,300+i*j,400);
		}
		glColor3f(0.5,0.5,0.5);
		if(i==1)
			glColor3f(0.5,0.5,0.2);
		draw_quad(250+i*j,400-k,250+i*j,200,300+i*j,200,300+i*j,400-k);

		//cone bottom
		glColor3f(0.0,0.0,0.0);
		draw_circle(-106,-74,r,r,275.0+i*j,496.0-i*k);
	}

	/*---FLAGS---*/
	//flag stick
	for(i=0;i<3;i++)
	{
		j=62.5;
		k=-6.25;
		l=-15;
		glBegin(GL_LINES);
		glLineWidth(0.0);
		if(i==1)
		{
			j=37.5;
			k=25;
			l=25;
		}
		glVertex2f(275+i*j,445-i*k);
		glVertex2f(275+i*j,487.5-i*l);
		glEnd();
	}
	//flag red
	glColor3f(1.0,0.0,0.0);
	draw_triangle(275,462,275,487.5,300,475);
	draw_triangle(312.5,437.5,312.5,462.5,337.5,450);
	draw_triangle(400,475,400,500,425,487.5);

	/*---MIDDLE WALL---*/
	ax = 250;
	ay = 337.5;
	by = 350;
	cx = 262.5;

	//designed walls
	for(i=0;i<5;i++)
	{
		glColor3f(0.2,0.3,0.0);
		draw_quad(ax + i*25 , ay,ax + i*25 , by,cx + i*25 , by,cx + i*25 , ay);
	}
	//body below designed walls
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.3,0.2);
		glVertex2f(375,337.5);
		glVertex2f(375,275);
		glVertex2f(375,200);
		glVertex2f(250,200);
		glVertex2f(250,337.5);
	glEnd();

	/*---SECOND MIDDLE WALL---*/
	ax = 375;
	ay = 362.5;
	cx = 387.5;
	cy = 375;
	ex = 400;

	//designed walls
	glBegin(GL_LINE_STRIP);
	glColor3f(0.2,0.3,0.0);
	for(int i=0;i<2;i++)
	{
		glVertex2f(ax + i*25 , ay);
		glVertex2f(ax + i*25 , ax);
		glVertex2f(cx + i*25 , cy);
		glVertex2f(cx + i*25 , ay);
		glVertex2f(ex + i*25 , ay);
	}
	glVertex2f(425 , 362.5);
	glVertex2f(425 , 375);
	glEnd();

	/*---WINDOWS---*/
	w1_ax = 300;
	w1_ay = 312.5;
	w1_by = 325;
	//boxes of window
	for(int i=0;i<3;i++)
		for(int j = 0;j<2;j++)
		{
			glColor3f(0.0,0.0,1.0);
			draw_quad(w1_ax + j*12.5 , w1_ay - i*12.5,w1_ax + j*12.5 , w1_by - i*12.5,w1_ay + j*12.5 , w1_by - i*12.5,w1_ay + j*12.5 , w1_ay - i*12.5);
		}

	w1_ax = 300;
	w1_ay = 262.5;
	w1_by = 275;
	w1_cx = 312.5;
	//window boxes
	for(int i=0;i<2;i++)
		for(int j = 0;j<2;j++)
		{
			glColor3f(0.0,0.0,1.0);
			draw_quad(w1_ax + j*12.5 , w1_ay - i*12.5,w1_ax + j*12.5 , w1_by - i*12.5,w1_cx + j*12.5 , w1_by - i*12.5,w1_cx + j*12.5 , w1_ay - i*12.5);
		}

		//window border
		for(int i=0;i<2;i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(300,287.5-i*37.5);
			glVertex2f(300,325-i*50);
			glVertex2f(325,325-i*50);
			glVertex2f(325,287.5-i*37.5);
			glEnd();

			//window middle vertical line
			glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(312.5,325-i*75);
			glVertex2f(312.5,287.5-i*12.5);
			glEnd();
		}

		//window horizontal lines
		for(int i =0;i<2;i++)
		{
			glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(300,312.5 - i*12.5);
			glVertex2f(325,312.5 - i*12.5);
			glEnd();
		}

		glBegin(GL_LINES);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(300,262.5);
			glVertex2f(325,262.5);
			glEnd();

	/*---DOOR---*/
	//door quad part
	draw_quad(300,200,300,232.5,350,232.5,350,200);
	//door top curve
	draw_circle(34,146,r1,r1,325.0,216.0);

	//door front door quad
	glBegin(GL_LINE_STRIP);
	glColor3f(0.1,0.2,0.6);
	glVertex2f(312.5,200);
	glVertex2f(312.5,237.5);
	glVertex2f(337.5,237.5);
	glVertex2f(337.5,200);
	glEnd();
	//front door partitions
	for(int i=0;i<3;i++)
		{
			glBegin(GL_LINES);
			//glColor3f(0.0,0.0,0.0);
			glVertex2f(312.5,231.5 - i*12.5);
			glVertex2f(337.5,231.5 - i*12.5);
			glEnd();
		}

}
void make_bushes()
{
	/*--BUSHES--*/
	glColor3f(0.2,0.7,0.2);
	draw_circle(0,360,r_bush,r_bush,312.5,194.5);
	draw_circle(0,360,r_bush,r_bush,329.5,196.5);
	draw_circle(0,360,r_bush,r_bush,344.5,199.5);
	draw_circle(0,360,r_bush,r_bush,359.5,203.5);
	draw_circle(0,360,r_bush,r_bush,370.5,213.5);
	draw_circle(0,360,r_bush,r_bush,377.5,228.5);
	draw_circle(0,360,r_bush,r_bush,384.5,244.5);
	draw_circle(0,360,r_bush,r_bush,396.5,232.5);
	draw_circle(0,360,r_bush,r_bush,401.5,216.5);
	draw_circle(0,360,r_bush,r_bush,409.5,203.5);
	draw_circle(0,360,r_bush,r_bush,424.5,199.5);

	draw_triangle(410,200,365,200,386,238);
}

void make_floor()
{
	glColor3f(0.2,1.0,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(250,200);
		glVertex2f(400,200);
		glVertex2f(700,100);
		glVertex2f(700,0);
		glVertex2f(500,0);
		glVertex2f(275,50);
		glVertex2f(307,73.75);
		glVertex2f(250,105);
		glEnd();

		draw_circle(0,180,110,110,450,100);
		draw_circle(0,360,150,150,650,100);




}
void make_hut()
{
	//hut
	/*--HUT--*/
	glColor3f(1.0,0.0,0.0);
	draw_quad(0,0,20,0,20,25,0,25);
	//hut door
	glColor3f(0.0,0.0,1.0);
	draw_quad(5,0,15,0,15,10,5,10);

	/*--HUT top*/
	glColor3f(0.0,0.0,0.0);
	draw_circle(0,180,r_hut,r_hut,10,20);
}
void make_women_one()
{
	//hair
	glColor3f(0.0,0.0,0.0);
	draw_circle(-40,220,20,20,310,152);
	//girl1 face
	glColor3f(1.0,0.9,0.7);
	draw_circle(0,360,15,20,310,148);

	for(int i=0;i<2;i++){
		glColor3f(0,0,0);
  	draw_circle(0,360,2,2,303+i*13,155);
	}

	glColor3f(1,0,0);
	draw_circle(-10,190,4,3.5,310,138);

	//hand
	glColor3f(1.0,0.9,0.7);
	draw_quad(303,128.75,258,122.5,256,120.5,288,122.5);

	//pitch fork
	glColor3f(0.0,0.0,0.0);
	draw_quad(260,100,260,160,264,160,264,100);
	//frock bottom
	glColor3f(0.4,0.5,0.9);
	draw_quad(307,100,280,50,340,35,313,100);

	//frock top
	glColor3f(0.9,0.5,0.9);
	draw_quad(310,87.5,310,100,303,128.75,288,122.5);

	//skin
	glColor3f(1.0,0.9,0.7);
	draw_triangle(310,100,303,128.75,317,128.75);

	glColor3f(0.9,0.5,0.9);
	draw_quad(310,87.5,310,100,317,128.75,332,122.5);
}

void make_people(float x,float y,col color_p)
{
  //hair
  glColor3f(0,0,0);
  draw_circle(0,360,18,22,x,y+62);
  //face
  glColor3f(1.0,0.9,0.7);
  draw_circle(0,360,17,20,x,y+60);

	//eyes
	for(int i=0;i<2;i++){
		glColor3f(0,0,0);
  	draw_circle(0,360,2,2,x-7+i*13,y+65);
	}

	glColor3f(1,0,0);
	draw_circle(-10,190,4,3.5,x,y+50);

  //pant
  glColor3f(0,0,0);
  draw_circle(0,360,10,40,x,y-55);
  //upperbody
	printf("%d\t%d\t%d\t",color_p[0],color_p[1],color_p[2]);
	glColor3f(color_p[0],color_p[1],color_p[2]);
  draw_circle(0,360,20,40,x,y);

  //arm
  glColor3f(1.0,0.9,0.7);
  glBegin(GL_POLYGON);
  glVertex2f(x+15,y+22);
  glVertex2f(x+80,y+30);
  glVertex2f(x+15,y+16);
  glEnd();

  //stick
  glLineWidth(5);
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+80,y+110);
  glVertex2f(x+70,y-40);
  glEnd();

  //hand
	glColor3f(1.0,0.9,0.7);
  glBegin(GL_POLYGON);
  glVertex2f(x+65,y+27);
  glVertex2f(x+78,y+35);
  glVertex2f(x+78,y+25);
  glEnd();
}
void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 360 / 13, 0, 0, 1 ); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(50, 0);
		glEnd();
	}
	draw_circle(0,360,r1,r1,0,0);
	glColor3f(0,0,0);
}
void display1()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

	make_left_background(0,0);
	make_chair_king(25,25);

	glPushMatrix();
	glTranslated(25 ,25 +13*(frameNumber % 150) / 50.0, 0);
	make_chicken(0,0);
	glPopMatrix();

	/*--SKY--*/
	glColor3f(0.0,1.0,1.0);
	draw_quad(250,200,700,100,700,500,250,500);

	/*--SUN--*/

	glPushMatrix();
	float x_sun=440;
	float y_sun=440;
	if(frameNumber %600!=599)
	{
		 x_sun = 670.0-7*(frameNumber %600 ) / 20.0 ;
		 y_sun = 200 +7*(frameNumber %600 ) / 20.0 ;
	}

	glTranslated(x_sun,y_sun, 0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();


	make_castle();
	make_bushes();
	make_floor();

	glPushMatrix();
  glTranslated(560,210,0);
  glScaled(2,2,1);
  make_hut();
  glPopMatrix();

	glPushMatrix();
  glTranslated(620,240,0);
  glScaled(1,1,1);
  make_hut();
  glPopMatrix();

	col color_p[3][3] = {{{1,0,0},{0,1,1},{1,1,0}},
  {{0,0,1},{1,1,0},{0,0,1}},
  {{1,0,1},{0,1,1},{1,0,0}}};

	glPushMatrix();
	glTranslated(340,100,0);
	glScaled(1,1,1);
	make_people(0,0,color_p[2][2]);
	glPopMatrix();

  for(int i=0;i<3;i++){
	 for(int j=0;j<=2;j++){
	  glPushMatrix();
	  glTranslated(450+i*45-j*50,110-i*10-j*20,0);
		glScaled(1,1,1);
	  make_people(0,0,color_p[i][j]);
	  glPopMatrix();
	 }
	a=0;
  }
	//
	// for(i=0;i<=4;i++)
	// {
	// for(j=0;j<=2;j++)
	// {
	//
	// 	glPushMatrix();
	// 	glTranslated(450+i*45-j*50,110-i*10-j*20,0);
	// 	glScaled(1,1,1);
	// 	make_people(0,0,color[i][j-1]);
	// 	glPopMatrix();
	//
	// }a=0;}


	make_women_one();

	glPushMatrix();
	glTranslated(360,70,0);
	glScaled(0.8,0.8,1);
	make_people(0,0,color_p[1][2]);
	glPopMatrix();



  glColor3f(1.0,0.2,0.0);
  draw_triangle(275,50,275,0,500,0);


	create_partiton();
  glFlush();
	glutSwapBuffers();
}
/*-----------------------------------frame1 over---------------------------------*/

#define deg2grad 3.14/180.0
GLfloat cloudx = 50;
GLfloat colorSun = 0.8;
int inc = 0;
int blink = 0;
void createDoorWithArc(int doorWidth, int doorHeight, int x, int y){
  glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	int doorRadius = doorWidth/2;
	for (int i = 0; i <= 180; ++i){
			glVertex2f(doorRadius*cos(i*deg2grad)+x, doorRadius*sin(i*deg2grad)+y+doorHeight);
	}
	glVertex2f(x-doorWidth/2,y+doorHeight);
	glVertex2f(x-doorWidth/2,y);
	glVertex2f(x+doorWidth/2,y);
	glVertex2f(x+doorWidth/2,y+doorHeight);

	glEnd();
}

void createDoor(int doorWidth, int doorHeight, int x, int y){
  glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(x-doorWidth/2,y+doorHeight);
	glVertex2f(x-doorWidth/2,y);
	glVertex2f(x+doorWidth/2,y);
	glVertex2f(x+doorWidth/2,y+doorHeight);
	glEnd();
}

void createCircle(int radius, int x, int y){
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y);
  }
  glEnd();
}

void createClouds(GLfloat radius, GLfloat x, GLfloat y){
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y);
  }
  glEnd();
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x+25, radius*cos(i*deg2grad)+y-10);
  }
  glEnd();
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x+25, radius*cos(i*deg2grad)+y+13);
  }
  glEnd();
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x+60, radius*cos(i*deg2grad)+y+20);
  }
  glEnd();
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x+60, radius*cos(i*deg2grad)+y-6);
  }
  glEnd();
}


void makeHorizontalOval(GLfloat radius, GLfloat bend, GLfloat x, GLfloat y){
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x, (radius/bend)*cos(i*deg2grad)+y);
  }
  glEnd();
}

void makeVerticalOval(GLfloat radius, GLfloat bend, GLfloat x, GLfloat y){
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; ++i){
    glVertex2f((radius/bend)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y);
  }
  glEnd();
}

void changeBlink(){
  if(rand()%297==0){
    blink = 1;
  }else{
    blink = 0;
  }
}
void makeFace(int x, int y){
      glColor3f(0.2,0.3,0.8);
      glLineWidth(1.0);
      glBegin(GL_POLYGON);
      glVertex2f(x-6,y-20);
      // glVertex2f(x-6,y-30);
      glVertex2f(x-25,y-35);
      glVertex2f(x-25,y-75);
      glVertex2f(x+25,y-75);
      glVertex2f(x+25,y-35);
      // glVertex2f(x+6,y-30);
      glVertex2f(x+6,y-20);
      glEnd();
      //hair color
      glColor3f(0.4,0.8,0.6);
      makeHorizontalOval(25,1.5,x,y+13);
      //head - skin
      glColor3f(1,0.9,0.9);
      makeVerticalOval(25,1.6,x,y);
      if(blink == 0){
        // making eyes
        glColor3f(0,0,0);
        glPointSize(4.0);
        glBegin(GL_POINTS);
        glVertex2f(x-5,y+5);
        glVertex2f(x+5,y+5);
        glEnd();
      }
      changeBlink();
}
void makeText(char* text, int x, int y){
  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(1/5.5, 1/5.5, 1/5.5);
  for (char* p = text; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}
void display2(void){


		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(1.5);
    glLineWidth(1.0);
		//Making doors/windows

    // Making clouds
    glColor3f(0.53,0.89,0.98);
    createClouds(23,cloudx,450);

    // creating fills

    // building

    // castle
    glColor3f(0.96,0.87,0.7);

    glBegin(GL_POLYGON);
    glVertex2f(200,200);
    glVertex2f(200,338);
    glVertex2f(325,338);
    glVertex2f(325,200);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(250,300);
    glVertex2f(250,388);
    glVertex2f(275,388);
    glVertex2f(275,300);
    glEnd();

    // red tops
    glColor3f(0.8,0.36,0.36);

    glBegin(GL_POLYGON);
    glVertex2f(188,325);
    glVertex2f(200,350);
    glVertex2f(250,350);
    glVertex2f(250,325);
    glVertex2f(188,325);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(238,388);
    glVertex2f(263,425);
    glVertex2f(288,388);
    glVertex2f(238,388);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(269,363);
    glVertex2f(263,338);
    glVertex2f(325,338);
    glVertex2f(325,363);
    glVertex2f(269,363);
    glEnd();

    // Church
    glColor3f(0.76,0.75,0.75);

    glBegin(GL_POLYGON);
    glVertex2f(0,175);
    glVertex2f(0,275);
    glVertex2f(38,375);
    glVertex2f(75,275);
    glVertex2f(75,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(75,300);
    glVertex2f(113,400);
    glVertex2f(150,300);
    glVertex2f(150,175);
    glVertex2f(75,175);
    glEnd();




    // Creating outlines
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    glVertex2f(0,275);
    glVertex2f(38,375);

    glVertex2f(38,375);
    glVertex2f(75,275);

    glVertex2f(75,275);
    glVertex2f(75,300);

    glVertex2f(75,300);
    glVertex2f(113,400);

    glVertex2f(113,400);
    glVertex2f(150,300);

    glVertex2f(150,300);
    glVertex2f(150,200);

    glVertex2f(75,275);
    glVertex2f(75,250);


    // The castle

    // Commenting out the bridge
    // glVertex2f(150,263);
    // glVertex2f(200,288);
    //
    // glVertex2f(150, 250);
    // glVertex2f(200,275);

    glVertex2f(200,200);
    glVertex2f(200,325);

    glVertex2f(188,325);
    glVertex2f(250,325);

    glVertex2f(188,325);
    glVertex2f(200,350);

    glVertex2f(200,350);
    glVertex2f(250,350);

    glVertex2f(250,300);
    glVertex2f(250,388);

    glVertex2f(238,388);
    glVertex2f(288,388);

    glVertex2f(238,388);
    glVertex2f(263,425);

    glVertex2f(263,425);
    glVertex2f(288,388);

    glVertex2f(275,388);
    glVertex2f(275,363);

    glVertex2f(263,338);
    glVertex2f(325,338);

    glVertex2f(263,338);
    glVertex2f(269,363);

    glVertex2f(269,363);
    glVertex2f(325,363);

    glVertex2f(275,338);
    glVertex2f(275,300);

    glVertex2f(263,300);
    glVertex2f(325,300);

    glVertex2f(225,250);
    glVertex2f(325,250);

    glEnd();
    createDoorWithArc(13,16,294,300);
    createDoorWithArc(13,16,310,250);
    createDoorWithArc(13,16,285,250);
    createDoorWithArc(13,16,260,250);
    createDoor(10,10,215,310);
    createDoor(10,10,235,310);

    glLineWidth(2.0);

    glBegin(GL_LINES);

    glVertex2f(325,200);
    glVertex2f(325,500);

    // making crosses
    glVertex2f(38,375);
    glVertex2f(38,413);

    glVertex2f(25,400);
    glVertex2f(50,400);

    glVertex2f(113,400);
    glVertex2f(113,438);

    glVertex2f(100,425);
    glVertex2f(125,425);

    glEnd();

    // Bigger crosses
    glLineWidth(5.0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);

    // making crosses
    glVertex2f(38,225);
    glVertex2f(38,300);

    glVertex2f(25,275);
    glVertex2f(50,275);

    glVertex2f(113,275);
    glVertex2f(113,350);

    glVertex2f(100,325);
    glVertex2f(125,325);

    glEnd();

    glColor3f(1,colorSun,0);
    createCircle(23,188,450);

    // Preventing cloud to show up the other side
    glColor3f(.91,.981,1);
    glBegin(GL_POLYGON);
    glVertex2f(325,500);
    glVertex2f(325,200);
    glVertex2f(500,200);
    glVertex2f(500,500);
    glEnd();

    makeFace(370,250);
    makeFace(420,230);
    makeFace(480,260);
    makeFace(350,138);
    makeFace(400,150);
    makeFace(450,120);

    makeText("Enlightenment", 340, 450);
    makeText("Liberty", 340, 400);
    makeText("Equality", 340, 370);
    makeText("Fraternity", 340, 340);

    // KING

    int xc = 220, yc = 165;

    //crown
    glColor3f(0.73,0.1,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(xc-25,yc+5);
    glVertex2f(xc-40,yc+40);
    glVertex2f(xc-22,yc+30);
    glVertex2f(xc-25,yc+55);
    glVertex2f(xc-8,yc+41);
    glVertex2f(xc-2,yc+60);
    glVertex2f(xc+12,yc+38);
    glVertex2f(xc+27,yc+57);
    glVertex2f(xc+30,yc+35);
    glVertex2f(xc+44,yc+42);
    glVertex2f(xc+23,yc+5);
    glEnd();


    glColor3f(0.8,0.12,0.48);
    glBegin(GL_POLYGON);
    glVertex2f(205,145);
    glVertex2f(175,130);
    glVertex2f(175,50);
    glVertex2f(270,50);
    glVertex2f(270,130);
    glVertex2f(240,145);
    glEnd();
    makeVerticalOval(40,2.5,175,90);
    makeVerticalOval(40,2.5,270,90);
    // skin color
    glColor3f(1,0.83,0.75);
    createCircle(30,xc,yc);
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    int radius = 10;
    glVertex2f(xc, yc-10);
    for (int i = 70; i < 250; ++i){
      glVertex2f(radius*sin(i*deg2grad)+xc, (radius/1.5)*cos(i*deg2grad)+yc-10);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(xc+10, yc+10);
    for (int i = 230; i < 360; i++){
      glVertex2f((radius)*sin(i*deg2grad)+xc+10, (radius/2.0)*cos(i*deg2grad)+yc+10);
    }
    for (int i = 0; i < 50; ++i){
      glVertex2f((radius)*sin(i*deg2grad)+xc+10, (radius/2.0)*cos(i*deg2grad)+yc+10);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(xc-10, yc+10);
    for (int i = 230; i < 360; i++){
      glVertex2f((radius)*sin(i*deg2grad)+xc-10, (radius/2.0)*cos(i*deg2grad)+yc+10);
    }
    for (int i = 0; i < 50; ++i){
      glVertex2f((radius)*sin(i*deg2grad)+xc-10, (radius/2.0)*cos(i*deg2grad)+yc+10);
    }
    glEnd();

    // POPE


    // hair
    glColor3f(0.3,0.3,0.3);
    makeHorizontalOval(30,1.5,75,180);
    glBegin(GL_POLYGON);
    glVertex2f(45,180);
    glVertex2f(105,180);
    glVertex2f(105,160);
    glVertex2f(45,160);
    glEnd();
    makeHorizontalOval(10,1.5,50,160);
    makeHorizontalOval(10,1.5,100,160);

    //dress
    glColor3f(0.2,0.4,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(75,140);
    glVertex2f(30,120);
    glVertex2f(30,50);
    glVertex2f(120,50);
    glVertex2f(120,120);
    glEnd();
    makeVerticalOval(35,3.5,30,85);
    makeVerticalOval(35,3.5,120,85);

    glColor3f(1,0.72,0.07);
    makeHorizontalOval(35,2.5,75,140);

    // skin
    glColor3f(1,0.83,0.75);
    makeHorizontalOval(20,1.5,75,150);
    makeHorizontalOval(20,1.5,75,180);
    glBegin(GL_POLYGON);
    glVertex2f(55,150);
    glVertex2f(95,150);
    glVertex2f(95,180);
    glVertex2f(55,180);
    glEnd();

    //eyes
    glColor3f(0,0,0);
    glPointSize(1.2);
    glBegin(GL_POINTS);
    for (int i = 90; i < 270; i++){
      glVertex2f((5)*sin(i*deg2grad)+65, (5)*cos(i*deg2grad)+170);
    }
    glEnd();
    glBegin(GL_POINTS);
    for (int i = 90; i < 270; i++){
      glVertex2f((5)*sin(i*deg2grad)+85, (5)*cos(i*deg2grad)+170);
    }
    glEnd();
    glBegin(GL_POINTS);
    for (int i = 90; i < 270; i++){
      glVertex2f((10)*sin(i*deg2grad)+75, (10)*cos(i*deg2grad)+155);
    }
    glEnd();

    // crosses
    glColor3f(1,1,1);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(70,90);
    glVertex2f(90,90);
    glVertex2f(80,100);
    glVertex2f(80,70);
    glEnd();

    glLineWidth(1.0);
    makeText("Clergy(0.5%)", 10, 10);
    makeText("Nobility(1.5%)", 170, 10);
    makeText("Others(98%)", 340, 10);


    glFlush();
}




/*-----------------------------------frame2 over---------------------------------*/
void create_partiton3()
{
  glColor3f(0.0,0.0,0.0);
  glLineWidth(4.0);
  glBegin(GL_LINES);
  glVertex2f(0,250);
  glVertex2f(350,250);
  glVertex2f(350,250);
  glVertex2f(350,500);
  glEnd();
  glLineWidth(1.0);
}

void make_left_soldier(float x,float y)
{
  //glColor3f(1.0,0.9,0.7);
  //face
  glColor3f(0.0,0.0,0.0);
  draw_circle(45,270,17,20,x,y+60);

  glColor3f(1.0,0.9,0.7);
  draw_circle(-90,45,17,20,x,y+60);
//legs
  glColor3f(0,0,0);
  glLineWidth(14);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x-7,y-35);
  glVertex2f(x-17,y-85);
  glEnd();

  glColor3f(0,0,0);
  glLineWidth(14);
  glBegin(GL_LINE_STRIP);
  glVertex2f(x+7,y-35);
  glVertex2f(x+17,y-55);
  glVertex2f(x+12,y-85);
  glEnd();
//body
  glColor3f(0.0,0.0,1.0);
  draw_circle(0,360,27,40,x,y);
//hat
  float x1 = x;
  float y1 = y+70;
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex2f(x1-33,y1);
  glVertex2f(x1+33,y1);
  glVertex2f(x1+14,y1+17);
  glVertex2f(x1,y1+5);
  glVertex2f(x1-14,y1+17);
  glEnd();

  //gun
  glColor3f(0.2,0.2,0.2);
  glBegin(GL_POLYGON);
  glVertex2f(x+27,y);
  glVertex2f(x+67,y);
  glVertex2f(x+67,y-5);
  glVertex2f(x+47,y-5);
  glVertex2f(x+47,y-10);
  glVertex2f(x+37,y-10);
  glVertex2f(x+37,y-14);
  glVertex2f(x+25,y-14);
  glEnd();

}

void make_right_soldier(float x,float y)
{
  //face
	glEnd();
  glColor3f(0.0,0.0,0.0);
  draw_circle(-90,135,17,20,x,y+60);

  glColor3f(1.0,0.9,0.7);
  draw_circle(135,270,17,20,x,y+60);
//legs
  glColor3f(0,0,0);
  glLineWidth(14);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x+7,y-35);
  glVertex2f(x+17,y-85);
  glEnd();

  glColor3f(0,0,0);
  glLineWidth(14);
  glBegin(GL_LINE_STRIP);
  glVertex2f(x-7,y-35);
  glVertex2f(x-17,y-55);
  glVertex2f(x-12,y-85);
  glEnd();
//body
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
  draw_circle(0,360,27,40,x,y);
//hat
  float x1 = x;
  float y1 = y+70;
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex2f(x1+33,y1);
  glVertex2f(x1-33,y1);
  glVertex2f(x1-14,y1+17);
  glVertex2f(x1,y1+5);
  glVertex2f(x1+14,y1+17);
  glEnd();

  //gun
  glColor3f(0.2,0.2,0.2);
  glBegin(GL_POLYGON);
  glVertex2f(x-27,y);
  glVertex2f(x-67,y);
  glVertex2f(x-67,y-5);
  glVertex2f(x-47,y-5);
  glVertex2f(x-47,y-10);
  glVertex2f(x-37,y-10);
  glVertex2f(x-37,y-14);
  glVertex2f(x-25,y-14);
  glEnd();

}

void bullet_left(float x,float y)
{
	float bulletx1= x-62;
  float bulletx2= x-66;
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
  glVertex2f(bulletx1,y);
  glVertex2f(bulletx1,y-5);
  glVertex2f(bulletx2,y-5);
  glVertex2f(bulletx2,y);
  glEnd();
}
void bullet_right(float x,float y)
{
	float bulletx1= x+62;
  float bulletx2= x+66;
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
  glVertex2f(bulletx1,y);
  glVertex2f(bulletx1,y-5);
  glVertex2f(bulletx2,y-5);
  glVertex2f(bulletx2,y);
  glEnd();
}
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}


void make_castle3()
{
  glColor3f(0.4,0.4,0.4);
  draw_quad(-12.5,-20,-10,20,13,20,15.5,-20);

  draw_quad(-10,20,-12,25,15,25,13,20);

  draw_quad(-12,25,-12,30,15,30,15,25);

  for(int i=0;i<5;i++)
	{
    draw_quad(-12 + i*6 , 30,-12 + i*6 , 35,-9 + i*6, 35,-9 + i*6, 30);
	}

  draw_quad(50,-20,50,5,70,5,70,-20);
  draw_quad(48,5,48,10,72,10,72,5);
  for(int i=0;i<6;i++)
	{
    draw_quad(48 + i*4 , 10,48 + i*4 , 12,50 + i*4, 12,50 + i*4, 10);
	}

  glColor3f(0.2,0.2,0.2);
  draw_quad(13,20,50,5,50,-20,13,-20);


}

void make_women(float x,float y,col color)
{
	// int d1,d2,d3;
	// d3 = color*10;
	// d2 = (color/10)%10;
	// d1 = (color/100)%10;
  //hair
  glColor3f(0,0,0);
  draw_circle(45,270,17,20,x,y+60);
  //bun
  draw_circle(0,360,9,11,x-18,y+50);
  //face
  glColor3f(1.0,0.9,0.7);
  draw_circle(-90,45,17,20,x,y+60);
  //upperbody
  glColor3f(color[0],color[1],color[2]);
  draw_circle(0,360,22,25,x,y+15);
  //lower body
  draw_circle(-45,225,30,35,x,y-35);
  //arm
  glColor3f(1.0,0.9,0.7);
  glBegin(GL_POLYGON);
  glVertex2f(x+20,y+22);
  glVertex2f(x+80,y+30);
  glVertex2f(x+20,y+16);
  glEnd();

  //stick
  glLineWidth(5);
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+70,y+80);
  glVertex2f(x+70,y-60);
  glEnd();

  //hand
  glBegin(GL_POLYGON);
  glColor3f(1.0,0.9,0.7);
  glVertex2f(x+65,y+27);
  glVertex2f(x+78,y+35);
  glVertex2f(x+78,y+25);
  glEnd();

}

void make_flame(float x,float y)
{
  glColor3f(1.0,0.5,0.0);
  draw_circle(-80,0,50,50,x,y);
  draw_circle(90,170,50,50,x+52,y-50);
  draw_circle(210,270,50,50,x-50,y);
  draw_circle(210,300,50,50,x-50,y);
  draw_circle(130,230,50,50,x-20,y);
  draw_circle(80,200,50,50,x+20,y);

  glBegin(GL_POLYGON);
  glColor3f(1.0,0.0,0.0);
  glVertex2f(x+15,y-50);
  glColor3f(1.0,0.5,0.0);
  glVertex2f(x+50,y+2);
  glColor3f(1.0,1.0,0.0);
  glVertex2f(x-5,y-30);
  glColor3f(1.0,0.5,0.0);
  glVertex2f(x+28,y+51);
  glColor3f(1.0,1.0,0.0);
  glVertex2f(x-30,y-20);
  glColor3f(1.0,0.5,0.0);
  glVertex2f(x-53,y+41);
  glColor3f(1.0,1.0,0.0);
  glVertex2f(x-57,y-40);
  glColor3f(1.0,0.0,0.0);
  glVertex2f(x-57,y-50);
  glEnd();
  glColor3f(0.0,1.0,1.0);
  draw_circle(120,220,40,40,x+50,y+15);
  draw_circle(130,300,20,20,x-37,y+27);

}
void make_smoke(float x,float y)
{
  glColor3f(0.2,0.2,0.2);
  draw_circle(0,360,15,15,x,y);
  draw_circle(0,360,15,15,x-10,y+10);
  draw_circle(0,360,15,15,x+10,y+12);
  draw_circle(0,360,15,15,x+13,y-14);

}

void display3() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();

  glColor3f(0.0,1.0,1.0);
  draw_quad(350,250,350,500,700,500,700,250);
for(int i=0;i<3;i++)
{
  glPushMatrix();
  glTranslated(570- 13*(frameNumber % 700)/100.0,440+ 50*(frameNumber % 500)/300.0,0);
  glScaled(1,1,1);
  make_smoke(0,0);
  glPopMatrix();

  glPushMatrix();
  glTranslated(500- 13*(frameNumber % 700)/250.0,460 + 50*(frameNumber % 500)/500.0,0);
  glScaled(0.5,0.4,1);
  make_smoke(0,0);
  glPopMatrix();

  glPushMatrix();
  glTranslated(520- 13*(frameNumber % 700)/70.0,420+ 50*(frameNumber % 500)/400.0,0);
  glScaled(0.6,0.5,1);
  make_smoke(0,0);
  glPopMatrix();
}
  glPushMatrix();
  glTranslated(670,400,0);
  glScaled(1,1,1);
  make_flame(0,0);
  glPopMatrix();

  glPushMatrix();
  glTranslated(420,330,0);
	glScaled(4,4,1);
	make_castle3();
	glPopMatrix();

  glColor3f(0.2,1.0,0.2);
  draw_quad(0,0,0,250,700,250,700,0);

  col color[3][8] = {{{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,0,0},{0,1,1}},
  {{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,0,0},{0,1,1},{1,0,0}},
  {{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,0,0},{0,1,1},{1,0,0},{0,1,0}}};

	// int num,d1,d2,d3,random;
	// for(int i=0;i<7;i++)
	// {
	// d1= rand()%2;
	// d2= rand()%2;
	// d3= rand()%2;
	// num = d1*100+d2*10+d3;
	// color[i] = num;
	// }
  for(int i=0;i<3;i++)
  for(int j=8;j>0;j--){
    make_women(-45 + i*40+j*50, 60 - i*30+j*30,color[i][j-1]);
   }

  for(int i=0;i<3;i++){
	 for(int j=8;j>0;j--){
	  glPushMatrix();
	  glTranslated(0 + i*40+j*50+13*(frameNumber % 300) / 20.0,-100 - i*30+j*30 + 13*(frameNumber % 200) / 20.0, 0);
	  make_women(0,0,color[i][j-1]);
	  glPopMatrix();
	   //make_women(250 + i*40+j*50, 20 - i*30+j*30,color[0],color[1],color[2]);
	 }
	a=0;
  }



  glColor3f(0.6,0.6,0.7);
  draw_quad(0,250,0,500,350,500,350,250);
  create_partiton3();
  for(int i=0;i<3;i++)
  {
      make_left_soldier(0+i*30,385-i*15);

      make_right_soldier(260+i*30,385-i*15);
			glPushMatrix();
			glTranslated(0+i*30+13*(frameNumber % 150) / 10.0,385-i*15, 0);
			bullet_right(0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(260+i*30-13*(frameNumber % 150) / 10.0,385-i*15, 0);
			bullet_left(0,0);
			glPopMatrix();
  }


	glutSwapBuffers();
  glFlush();
}
/*-----------------------------------frame3 over---------------------------------*/



void deadFace(int x, int y){
  //head - skin
  glColor3f(0.9,0.75,0.69);
  makeVerticalOval(25,1.4,x,y);
  glColor3f(0.2,0.2,0.2);
  if(ay4<370){
    glBegin(GL_LINES);
    glVertex2f(x-5,y+5);
    glVertex2f(x-10,y+10);
    glVertex2f(x-10,y+5);
    glVertex2f(x-5,y+10);
    glVertex2f(x+5,y+5);
    glVertex2f(x+10,y+10);
    glVertex2f(x+10,y+5);
    glVertex2f(x+5,y+10);
    glEnd();
  }else{
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(x-7.5,y+7.5);
    glVertex2f(x+7.5,y+7.5);
    glEnd();
  }
  glPointSize(1.0);
  glBegin(GL_POINTS);
  int radius = 8;
  for (int i = 0; i < 90; ++i){
    glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
  }
  for (int i = 270; i < 360; ++i){
    glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
  }
  glEnd();
}

void sadFace(int x, int y){
  //head - skin
  glColor3f(0.9,0.75,0.69);
  makeVerticalOval(25,1.6,x,y);
  glColor3f(0.2,0.2,0.2);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2f(x-7.5,y+7.5);
  glVertex2f(x+7.5,y+7.5);
  glEnd();
  glPointSize(1.0);
  glBegin(GL_POINTS);
  int radius = 8;
  for (int i = 0; i < 90; ++i){
    glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
  }
  for (int i = 270; i < 360; ++i){
    glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
  }
  glEnd();
}
void robespierr(int x, int y){
      glColor3f(0.7,0.16,0.15);
      glLineWidth(1.0);
      glBegin(GL_POLYGON);
      glVertex2f(x-6,y-20);
      // glVertex2f(x-6,y-30);
      glVertex2f(x-25,y-35);
      glVertex2f(x-25,y-75);
      glVertex2f(x+25,y-75);
      glVertex2f(x+25,y-35);
      // glVertex2f(x+6,y-30);
      glVertex2f(x+6,y-20);
      glEnd();
      //hair color
      glColor3f(0.7,0.7,0.7);
      makeVerticalOval(15,2.0,x-15,y);
      makeVerticalOval(15,2.0,x+15,y);
      makeHorizontalOval(10,2.0,x-15,y-10);
      makeHorizontalOval(10,2.0,x+15,y-10);
      //head - skin
      glColor3f(1,0.9,0.9);
      makeVerticalOval(25,1.6,x,y);
      // hair over head
      glColor3f(0.7,0.7,0.7);
      makeHorizontalOval(20,2.0,x,y+18);
      // smile
      glColor3f(0.2,0.2,0.2);
      glPointSize(1.0);
      int radius = 8;
      glBegin(GL_LINE_LOOP);
      // glVertex2f(x, y-10);
      for (int i = 90; i < 270; ++i){
        glVertex2f(radius*sin(i*deg2grad)+x, (radius/1.5)*cos(i*deg2grad)+y-10);
      }
      glEnd();
      if(blink == 0){
        // making eyes
        glColor3f(0,0,0);
        glPointSize(4.0);
        glBegin(GL_POINTS);
        glVertex2f(x-5,y+5);
        glVertex2f(x+5,y+5);
        glEnd();
      }
      changeBlink();
}

void robespierrDead(int x, int y){
      glColor3f(0.7,0.16,0.15);
      glLineWidth(1.0);
      //hair color
      glColor3f(0.7,0.7,0.7);
      makeVerticalOval(15,2.0,x-15,y);
      makeVerticalOval(15,2.0,x+15,y);
      makeHorizontalOval(10,2.0,x-15,y-10);
      makeHorizontalOval(10,2.0,x+15,y-10);
      //head - skin
      glColor3f(1,0.9,0.9);
      makeVerticalOval(25,1.6,x,y);
      // hair over head
      glColor3f(0.7,0.7,0.7);
      makeHorizontalOval(20,2.0,x,y+18);
      // sad
      glColor3f(0.2,0.2,0.2);
      glPointSize(1.0);
      glBegin(GL_POINTS);
      int radius = 8;
      for (int i = 0; i < 70; ++i){
        glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
      }
      for (int i = 300; i < 360; ++i){
        glVertex2f((radius)*sin(i*deg2grad)+x, radius*cos(i*deg2grad)+y-12);
      }
      glEnd();
      if(ay4<370){
        glBegin(GL_LINES);
        glVertex2f(x-5,y+5);
        glVertex2f(x-10,y+10);
        glVertex2f(x-10,y+5);
        glVertex2f(x-5,y+10);
        glVertex2f(x+5,y+5);
        glVertex2f(x+10,y+10);
        glVertex2f(x+10,y+5);
        glVertex2f(x+5,y+10);
        glEnd();
      }else{
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f(x-7.5,y+7.5);
        glVertex2f(x+7.5,y+7.5);
        glEnd();
      }
}

void happyPeople(int x, int y){
  glColor3f(0.26,0.73,0.99);
  glLineWidth(1.0);
  makeHorizontalOval(25,2.0,x,y-35);
  glBegin(GL_POLYGON);
  glVertex2f(x-6,y-25);
  // glVertex2f(x-6,y-30);
  glVertex2f(x-25,y-35);
  glVertex2f(x-25,y-75);
  glVertex2f(x+25,y-75);
  glVertex2f(x+25,y-35);
  // glVertex2f(x+6,y-30);
  glVertex2f(x+6,y-20);
  glEnd();
  //head - skin
  glColor3f(0.9,0.75,0.69);
  makeVerticalOval(25,1.6,x,y);
  // smile
  glColor3f(0.2,0.2,0.2);
  glPointSize(1.0);
  int radius = 8;
  glBegin(GL_LINE_LOOP);
  // glVertex2f(x, y-10);
  for (int i = 90; i < 270; ++i){
    glVertex2f(radius*sin(i*deg2grad)+x, (radius/1.5)*cos(i*deg2grad)+y-10);
  }
  glEnd();
  if(blink == 0){
    // making eyes
    glColor3f(0,0,0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(x-5,y+5);
    glVertex2f(x+5,y+5);
    glEnd();
  }
  changeBlink();
}
void display4(void){


		glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3,0.3,0.4);
    createClouds(23,cloudx,470);
    createClouds(21,cloudx*2,490);
    createClouds(23,cloudx*2+100,480);
    createClouds(27,cloudx*3+150,480);
    createClouds(23,cloudx*2+200,480);

    glColor3f(0,0,0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
    // the divide
    glVertex2f(0,250);
    glVertex2f(500,250);
    glEnd();
    // ---- Upper half ----
    // Guillotine
    glColor3f(0.9,0.5,0.2);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(300,275);
    glVertex2f(400,275);
    glVertex2f(310,275);
    glVertex2f(310,490);
    glVertex2f(390,275);
    glVertex2f(390,480);
    glEnd();
    glColor3f(0.33,0.24,0.19);
    glBegin(GL_POLYGON);
    glVertex2f(310,275);
    glVertex2f(390,275);
    glVertex2f(390,325);
    int radius = 20;
    for (int i = 90; i < 270; ++i){
        glVertex2f(radius*sin(i*deg2grad)+350, (radius/1.5)*cos(i*deg2grad)+325);
    }
    glVertex2f(310,325);
    glEnd();
    // blade
    glColor3f(0.78,0.78,0.78);
    glBegin(GL_POLYGON);
    glVertex2f(ax4-40,ay4);
    glVertex2f(ax4+40,ay4);
    glVertex2f(ax4+40,ay4-50);
    glVertex2f(ax4-40,ay4-40);
    glEnd();

    deadFace(350,330);
    sadFace(420,390);
    sadFace(460,390);
    sadFace(500,390);
    robespierr(75,400);


    glLineWidth(1.0);
    makeText("Maximilien Robespierre", 10, 270);


    // ---- Lower half ----
    // Guillotine
    glColor3f(0.9,0.5,0.2);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(350,25);
    glVertex2f(450,25);
    glVertex2f(360,25);
    glVertex2f(360,240);
    glVertex2f(440,25);
    glVertex2f(440,230);
    glEnd();
    glColor3f(0.33,0.24,0.19);
    glBegin(GL_POLYGON);
    glVertex2f(360,25);
    glVertex2f(440,25);
    glVertex2f(440,75);
    for (int i = 90; i < 270; ++i){
        glVertex2f(radius*sin(i*deg2grad)+400, (radius/1.5)*cos(i*deg2grad)+75);
    }
    glVertex2f(360,75);
    glEnd();
    // blade
    ay4-=250;
    ax4+=50;
    glColor3f(0.78,0.78,0.78);
    glBegin(GL_POLYGON);
    glVertex2f(ax4-40,ay4);
    glVertex2f(ax4+40,ay4);
    glVertex2f(ax4+40,ay4-50);
    glVertex2f(ax4-40,ay4-40);
    glEnd();
    ay4+=250;
    ax4-=50;
    robespierrDead(400,80);
    happyPeople(40,150);
    happyPeople(100,150);
    happyPeople(160,150);
    glLineWidth(1.0);
    makeText("Reign of terror(1793-1794)", 10, 200);

    glFlush();
}



/*----------------------------------Frame 4 over----------------------------------*/

void makeText(char* text, int x, int y,float scale){
  glColor3f(0,0,0);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(1/scale, 1/scale, 1/scale);
  for (char* p = text; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}

void draw_quad_outline(float vx1,float vy1, float vx2,float vy2, float vx3,float vy3, float vx4,float vy4)
{
	glBegin(GL_POLYGON);
	glVertex2f(vx1,vy1);
	glVertex2f(vx2,vy2);
	glVertex2f(vx3,vy3);
	glVertex2f(vx4,vy4);
	glEnd();
  glColor3f(0.2,0.2,0.2);
  glLineWidth(1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(vx1,vy1);
  glVertex2f(vx2,vy2);
  glVertex2f(vx3,vy3);
  glVertex2f(vx4,vy4);
  glEnd();
}
void draw_left_people(float x,float y){

  //arm
  glColor3f(1.0,0.9,0.7);
  glBegin(GL_POLYGON);
  y+=dy5;
  x+=dx5;
  glVertex2f(x+20,y+22);
  glVertex2f(x+80,y+30);
  glVertex2f(x+20,y+16);
  glEnd();

  //stick
  glLineWidth(5);
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+80,y+110);
  glVertex2f(x+70,y);
  glEnd();

  //hand
  glBegin(GL_POLYGON);
  glColor3f(1.0,0.9,0.7);
  glVertex2f(x+65,y+27);
  glVertex2f(x+78,y+35);
  glVertex2f(x+78,y+25);
  glEnd();

  //banner
  glColor3f(0.11,0.64,0.34);
  draw_quad_outline(x+10,y+90,x+150,y+80,x+154,y+120,x+14,y+130);

  glLineWidth(1.0);
  makeText("Vive la France",x+20,y+100,7.5);

  y-=dy5;
  x-=dx5;

  //hair
  glColor3f(0,0,0);
  draw_circle(0,360,18,22,x,y+62);
  //face
  glColor3f(1.0,0.9,0.7);
  draw_circle(0,360,17,20,x,y+60);
  //smile
  glColor3f(0.2,0.2,0.2);
  glPointSize(1.0);
  int radius = 8;
  glBegin(GL_LINE_LOOP);
  // glVertex2f(x, y-10);
  for (int i = 90; i < 270; ++i){
    glVertex2f(radius*sin(i*DEG2RAD)+x, (radius/1.5)*cos(i*DEG2RAD)+y+55);
  }
  glEnd();
  //eyes
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2f(x-7,y+65);
  glVertex2f(x+7,y+65);
  glEnd();
  //pant
  glColor3f(0,0,0);
  draw_circle(0,360,10,40,x-7,y-55);
  draw_circle(0,360,10,40,x+7,y-55);
  //upperbody
  glColor3f(0.26,0.73,0.99);
  draw_circle(0,360,20,40,x,y);

}

void draw_right_people(float x,float y){


  //arm
  glColor3f(1.0,0.9,0.7);
  glBegin(GL_POLYGON);
  y+=dy5;
  x-=dx5;

  glVertex2f(x-20,y+22);
  glVertex2f(x-80,y+30);
  glVertex2f(x-20,y+16);

  glEnd();

  //stick
  glLineWidth(5);
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glVertex2f(x-80,y+110);
  glVertex2f(x-70,y);
  glEnd();

  //hand
  glBegin(GL_POLYGON);
  glColor3f(1.0,0.9,0.7);
  glVertex2f(x-65,y+27);
  glVertex2f(x-78,y+35);
  glVertex2f(x-78,y+25);
  glEnd();

  //banner
  glColor3f(1,0.29,0.26);
  draw_quad_outline(x-10,y+90,x-150,y+80,x-154,y+120,x-14,y+130);

  glLineWidth(1.0);

  makeText("Vive la France",x-140,y+100,7.5);
  y-=dy5;
  x+=dx5;

  //hair
  glColor3f(0,0,0);
  draw_circle(0,360,18,22,x,y+62);
  //face
  glColor3f(1.0,0.9,0.7);
  draw_circle(0,360,17,20,x,y+60);
  //smile
  glColor3f(0.2,0.2,0.2);
  glPointSize(1.0);
  int radius = 8;
  glBegin(GL_LINE_LOOP);
  // glVertex2f(x, y-10);
  for (int i = 90; i < 270; ++i){
    glVertex2f(radius*sin(i*DEG2RAD)+x, (radius/1.5)*cos(i*DEG2RAD)+y+55);
  }
  glEnd();
  //eyes
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2f(x-7,y+65);
  glVertex2f(x+7,y+65);
  glEnd();
  //pant
  glColor3f(0,0,0);
  draw_circle(0,360,10,40,x-7,y-55);
  draw_circle(0,360,10,40,x+7,y-55);
  //upperbody
  glColor3f(0.26,0.73,0.99);
  draw_circle(0,360,20,40,x,y);
}

void draw_napoleon(float x,float y)
{

  //stand

  glColor3f(0.5,1.0,0.5);
  draw_quad(x-50,y-220,x-70,y-260,x+70,y-260,x+50,y-220);
  draw_circle(180,360,70,20,x,y-260);
  glColor3f(0.5,1.0,0.3);
  draw_circle(0,360,50,20,x,y-220);


  //face
    glColor3f(1.0,0.9,0.7);
    draw_circle(0,360,22,27,x,y);
    //hat
    glColor3f(0.0,0.0,1.0);
    draw_quad(x-50,y+12,x-46,y+17,x+46,y+15,x+50,y+10);
    glColor3f(1.0,1.0,0.0);
    draw_circle(-7,182,40,40,x,y+19);

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x-52,y+12);
    glVertex2f(x-48,y+17);
    glVertex2f(x,y+19);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+52,y+12);
    glVertex2f(x+48,y+17);
    glVertex2f(x,y+19);
    glEnd();

    glLineWidth(1);

    glColor3f(0.0,0.0,1.0);
    draw_circle(-9,187,36,36,x,y+19);

    //pant
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(x-53,y-120);
    glVertex2f(x-29,y-220);
    glVertex2f(x-23,y-220);
    glVertex2f(x+10,y-140);
    glVertex2f(x+23,y-220);
    glVertex2f(x+29,y-220);
    glVertex2f(x+53,y-120);
    glEnd();

    //upperbody
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(x,y-27);
    glVertex2f(x-50,y-30);
    glVertex2f(x-52,y-120);
    glVertex2f(x-26,y-140);
    glVertex2f(x,y-120);
    glVertex2f(x+26,y-140);
    glVertex2f(x+52,y-120);
    glVertex2f(x+50,y-30);
    glEnd();

    //arms
    glColor3f(0,0,1.0);
    draw_circle(0,360,8,56,x-53,y-85);
    draw_circle(0,360,8,56,x+53,y-85);

    //shoes
    glColor3f(0,0,0);
    draw_circle(0,360,15,8,x-26,y-220);
    draw_circle(0,360,15,8,x+26,y-220);




}


void display5(){
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1,colorSun,0);
  makeHorizontalOval(60,1,650,470);

  // clouds
  glColor3f(0.54,0.85,0.98);
  createClouds(23,cloudx,470);
  createClouds(21,cloudx*2,490);
  createClouds(23,cloudx*2+100,480);
  createClouds(27,cloudx*3+150,480);
  createClouds(23,cloudx*2+200,480);

  // horizon
  glColor3f(0.62,0.84,0.57);

  makeHorizontalOval(700,2.0,350,0);
  draw_left_people(20,300);
  draw_right_people(680,300);
  draw_left_people(20+120,300);
  draw_right_people(680-120,300);
  draw_napoleon(350,400);
  makeText("Napoleon Bonaparte",200,90,4);
  makeText("1st Reign: 18 May 1804 to 11 April 1814",100,60,6.5);
  makeText("2nd Reign: 20 March 1815 – 22 June 1815",100,30,6.5);
  glFlush();
}
/*-----------------------------------frame4 over---------------------------------*/
void display_last() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();
  glColor3f(0,0,0);
  draw_quad(0,0,0,500,700,500,700,0);
  glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(70, 220, 0);
	const char *text = "The End";
	glScalef(1,1,1);
	for (const char* p = text; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
	//output(300, 250, "The End");

  glFlush();
}
/*-----------------------------------frame last over-----------------------------*/
void keys(unsigned char key,int x,int y)
{
	if(key=='c') ++current_frame;
	ay4=450;
}
void init() {
	glClearColor(1,1,1,1);
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,700,0,500);
	glMatrixMode(GL_MODELVIEW);
}
void init2() {
	glClearColor(.91,.981,1,1);
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

void animate(){

  cloudx += 0.05;
  float c = 1;
  if(incx){
    dy5+=c;
    dx5+=c;
  }
  else{
    dy5-=c;
    dx5-=c;
  }
  if(dx5>5){
    incx=0;
  }else if(dx5<-5){
    incx=1;
  }

  if(inc)
    colorSun += 0.003;
  else
    colorSun -= 0.003;

  // sway the 'inc' variable - acts like a boolean
  if(colorSun < 0.6){
    inc = 1;
  }else if(colorSun > 0.8){
    inc = 0;
  }

  if(ay4>360){
    ay4-=0.6;
  }
  glutPostRedisplay();
}
void display_frames()
{
	switch(current_frame) {
	    case 0 : display0();
	            break;
		case 1 : display1();
			  	break;
		case 2 :
				init2();
				glutIdleFunc(animate);
				display2();
				break;
		case 3 :
				init();
				display3();
				break;
	    case 4 :
	    		init2();
	    		display4();
				break;
	    case 5 :
			    dy=0;
			    dx=0;
	    		init();
	    		display5();
				break;
		default : display_last();
	}
}


int main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(700,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("French Revolution");

  init();

  glutDisplayFunc(display_frames);
  glutKeyboardFunc(keys);
  glutTimerFunc(200,doFrame,0);
  glutMainLoop();
  return 0;
}
