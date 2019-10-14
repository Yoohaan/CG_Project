#include <stdio.h>
#include <GL/glut.h>

GLfloat a=-170,b=0,c=20,d=0,e=0;
void road();
void display2();
void display3();
void trees();
int i,j,flag=0;

char name1[100]="4NM16CS136      Shelton Blaze D'Souza";
char name2[100]="4NM16CS137      Shetty Yashas Shashidhar";
char name3[100]="4NM16CS138      Shibani Bhandary";
char proj[50]="AIRPORT SIMULATION";
char s[20]="PRESS S TO START";
char s1[100]="PRESS Q TO EXIT";
char s2[100]="PRESS T TO TAKE-OFF THE PLANE";
char s3[100]="PRESS L TO LAND THE PLANE";

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
    {

        glColor3f(1.0,1.0,1.0);
        glRasterPos3f(175,450,0);
        for(i=0;name1[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,name1[i]);

        glColor3f(1.0,1.0,1.0);
        glRasterPos3f(175,425,0);
        for(i=0;name2[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,name2[i]);

        glColor3f(1.0,1.0,1.0);
        glRasterPos3f(175,400,0);
        for(i=0;name3[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,name3[i]);

        glColor3f(1.0,0.0,0);
        glRasterPos3f(190,310,0);
        for(i=0;proj[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,proj[i]);

        glColor3f(1.0,1.0,1.0);
        glRasterPos3f(200,225,0);
        for(i=0;s[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

        glRasterPos3f(200,200,0);
        for(i=0;s1[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);

        glRasterPos3f(165,125,0);
        for(i=0;s2[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,s2[i]);

        glRasterPos3f(175,100,0);
        for(i=0;s2[i]!='\0';i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,s3[i]);

    }
    else
    {

        road();
        //green
        glBegin(GL_POLYGON);
        glColor3f(0.0,0.7,0.0);
            glVertex2i(-10,200);
            glVertex2i(900,200);
            glVertex2i(900,100);
            glVertex2i(-10,100);
        glEnd();


        //plane construction
        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(0.0,30.0);
        glVertex2f(0.0,55.0);
        glVertex2f(135.0,55.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,0.0,0);
        glBegin(GL_POLYGON);//red lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,30.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,0.0,0);
        glBegin(GL_POLYGON);//red back wing
        glVertex2f(0.0,55.0);
        glVertex2f(0.0,80.0);
        glVertex2f(10.0,80.0);
        glVertex2f(40.0,55.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,0.0,0);
        glBegin(GL_POLYGON);//red left side wing
        glVertex2f(65.0,55.0);
        glVertex2f(50.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(90.0,55.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,0.0,0);
        glBegin(GL_POLYGON);//red rightside wing
        glVertex2f(70.0,40.0);
        glVertex2f(100.0,40.0);
        glVertex2f(80.0,15.0);
        glVertex2f(50.0,15.0);

        glEnd();

        glPopMatrix();

    }
    glFlush();
    glutSwapBuffers();
}


void road()
{
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);//black road
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,100.0);
        glVertex2f(500.0,100.0);
        glVertex2f(500.0,0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,1.0,1.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//white strips on road
        glVertex2f(0.0,40.0);
        glVertex2f(8.0,60.0);
        glVertex2f(58.0,60.0);
        glVertex2f(50.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(100.0,40.0);
        glVertex2f(108.0,60.0);
        glVertex2f(158.0,60.0);
        glVertex2f(150.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(200.0,40.0);
        glVertex2f(208.0,60.0);
        glVertex2f(258.0,60.0);
        glVertex2f(250.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(300.0,40.0);
        glVertex2f(308.0,60.0);
        glVertex2f(358.0,60.0);
        glVertex2f(350.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0, 1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(400.0,40.0);
        glVertex2f(408.0,60.0);
        glVertex2f(458.0,60.0);
        glVertex2f(450.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(500.0,40.0);
        glVertex2f(508.0,60.0);
        glVertex2f(558.0,60.0);
        glVertex2f(550.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(600.0,40.0);
        glVertex2f(608.0,60.0);
        glVertex2f(658.0,60.0);
        glVertex2f(650.0,40.0);
        glEnd();
        glPopMatrix();

}


void display2()
{

        glClear(GL_COLOR_BUFFER_BIT);
        //green
        glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0);
            glVertex2i(-10,300);
            glVertex2i(645,310);
            glVertex2i(940,0);
            glVertex2i(-10,0);
        glEnd();


        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.0,30.0);
        glVertex2f(0.0,55.0);
        glVertex2f(135.0,55.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,30.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.0,55.0);
        glVertex2f(0.0,80.0);
        glVertex2f(10.0,80.0);
        glVertex2f(40.0,55.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(65.0,55.0);
        glVertex2f(50.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(90.0,55.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(d,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(70.0,40.0);
        glVertex2f(100.0,40.0);
        glVertex2f(80.0,15.0);
        glVertex2f(50.0,15.0);
        glEnd();
        glPopMatrix();
}

void display3()
{

        glClear(GL_COLOR_BUFFER_BIT);
        road();

        //brown
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.3,0.0);
            glVertex2i(-10,300);
            glVertex2i(645,310);
            glVertex2i(940,100);
            glVertex2i(-10,100);
        glEnd();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.0,30.0);
        glVertex2f(0.0,55.0);
        glVertex2f(135.0,55.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,30.0);
        glVertex2f(135.0,30.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.0,55.0);
        glVertex2f(0.0,80.0);
        glVertex2f(10.0,80.0);
        glVertex2f(40.0,55.0);
        //glVertex2f(165.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(65.0,55.0);
        glVertex2f(50.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(90.0,55.0);
        //glVertex2f(165.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(e,300.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(70.0,40.0);
        glVertex2f(100.0,40.0);
        glVertex2f(80.0,15.0);
        glVertex2f(50.0,15.0);
        glEnd();
        glPopMatrix();
	
	
        glutSwapBuffers();
}


void myinit()
{
        glClearColor(0.0f,0.0f,1.0f,0.0f);
        glColor3f(1.0,0.0,0.0);
        glPointSize(1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,500.0,0.0,500.0);
}


void keys(unsigned char key,int x,int y)
{
    	if(key=='s'){
		flag=1;
		display();}
	

	if(key=='q') exit(0);


	if(key=='t')
	{
	    	a=-170;
		b=0.0;
		c=20;
		while(a<504 || c<422)
		{
		    if(a>100)
			c+=0.8;//take off at certain angle on y axis
		    a+=0.8;	//Plane position takeoff on x axis
		    b-=0.8;	//Road Strip backward movement

		    if(b<=-100.0) // moving of run way
			b=0.0;//take off at certain angle on y axis
		    display();
		}
	}
	
	
	if(key=='l')
	{
		a=-170;
		b=0.0;
		c=450;
		while(a<504 )
		{
		    if(a<300 && c>20)
			c-=0.8;//take off at certain angle on y axis
		    a+=0.8;	//Plane position takeoff on x axis
		    b-=0.8;	//Road Strip backward mvement

		    if(b<=-100.0) // moving of run way
			b=0.0;//take off at cer0.tain angle on y axis
		    display();
		}
	}display();
}


int main(int argc, char* argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(1000,1000);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Airport Simulation");
        glutDisplayFunc(display);
        myinit();
        glutKeyboardFunc(keys);
        glutMainLoop();
}
