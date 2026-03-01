#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Global variables for movement
float a = 0, aa = 0;
float b = 0, bb = 0;
float s = 0, ss = 0;

// Ship and Anchor Logic
float shipX = 0;
float anchorY = 30;
int liftingAnchor = 0;
int shipMoving = 0;

// Bubble system
float bubbleY[20];
float bubbleX[20];
float bubbleSpeed[20];

float grassSway = 0;
float speedFish1 = 2.0f, speedFish2 = 1.8f, speedShark = 2.2f;
int moving = 0, flag3 = 0;
const float pi = 3.14159f;

// ---------------- PROTOTYPES ----------------
void init();
void display();
void update(int value);
void fish1();
void fish2();
void Shark();
void drawStarfish(float x, float y);
void drawJellyfish(float x, float y);
void drawSurfaceShip();
void drawSunkenShip();
void drawBubbles();
void drawRocks();
void drawOrganicGrass();

// ---------------- NEW: STARFISH ----------------
void drawStarfish(float x, float y) {
    glColor3f(1.0, 0.4, 0.2); // Bright orange
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 10; i++) {
        float angle = i * 2.0f * pi / 10.0f;
        float r = (i % 2 == 0) ? 10.0f : 4.0f; // Creates the 5-point star shape
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

// ---------------- NEW: JELLYFISH ----------------
void drawJellyfish(float x, float y) {
    float pulse = sin(grassSway * 2) * 4.0f; // Pulsing effect

    // Tentacles
    glColor4f(0.8, 0.6, 1.0, 0.4); // Transparent light purple
    glBegin(GL_LINES);
    for(int i = -10; i <= 10; i += 5) {
        glVertex2f(x + i, y);
        glVertex2f(x + i + sin(grassSway + i) * 8, y - 25 - pulse);
    }
    glEnd();

    // Body/Bell
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i += 10) {
        float angle = i * pi / 180.0f;
        glVertex2f(x + (18 + pulse) * cos(angle), y + 12 * sin(angle));
    }
    glEnd();
}

// ---------------- RESTORED: ORIGINAL FISH 1 ----------------
void fish1() {
    glColor3f(1.0f, 0.45f, 0.15f);
    glBegin(GL_POLYGON);
    glVertex2f(270+a,350+aa); glVertex2f(300+a,325+aa); glVertex2f(370+a,350+aa); glVertex2f(300+a,375+aa);
    glEnd();
    glColor3f(0.9f,0.3f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(360+a,350+aa); glVertex2f(405+a,370+aa); glVertex2f(395+a,350+aa); glVertex2f(405+a,327+aa);
    glEnd();
    glColor3f(1.0f,0.6f,0.25f);
    glBegin(GL_TRIANGLES);
    glVertex2f(302+a,373+aa); glVertex2f(340+a,409+aa); glVertex2f(320+a,360+aa);
    glEnd();
    glColor3f(1.0f,0.5f,0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(302+a,328+aa); glVertex2f(340+a,300+aa); glVertex2f(320+a,340+aa);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f); glPointSize(6.0); glBegin(GL_POINTS); glVertex2f(280+a,355+aa); glEnd();
    glColor3f(0.0f,0.0f,0.0f); glPointSize(3.0); glBegin(GL_POINTS); glVertex2f(282+a,355+aa); glEnd();
}

// ---------------- RESTORED: ORIGINAL FISH 2 ----------------
void fish2() {
    glColor3f(1.0f,0.0f,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(70+b,145+bb); glColor3ub(rand()%256, rand()%256,0);
    glVertex2f(20+b,120+bb); glVertex2f(30+b,145+bb); glVertex2f(20+b,170+bb);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65+b,145+bb); glVertex2f(125+b,170+bb); glVertex2f(165+b,145+bb); glVertex2f(125+b,120+bb);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand()%256, rand()%256,0); glVertex2f(126+b,168+bb);
    glColor3f(1.0,0.0,0.0); glVertex2f(110+b,155+bb); glVertex2f(85+b,195+bb);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand()%256, rand()%256,0); glVertex2f(126+b,122+bb);
    glColor3f(1.0,0.0,0.0); glVertex2f(110+b,136+bb); glVertex2f(85+b,95+bb);
    glEnd();
    glColor3f(0.0,0.0,0.0); glPointSize(4.0); glBegin(GL_POINTS); glVertex2f(150+b,149+bb); glEnd();
}

// ---------------- RESTORED: ORIGINAL SHARK ----------------
void Shark() {
    float x,y, angle;
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<=320; angle+=4){
        glColor3ub(115,116,117); y =(sin(angle*pi/319.0f)*30); x =angle;
        glVertex2f(x+280+s,y+285+ss);
    }
    glColor3ub(200,200,200); glVertex2f(x+280+s,y+265+ss);
    for(angle=298; angle>=35; angle-=4){
        x=angle; y=-(sin(angle*pi/319.0f)*20);
        glVertex2f(x+280+s,y+265+ss);
    }
    glVertex2f(300+s,265+ss);
    glEnd();
    glColor3ub(115,116,117);
    glBegin(GL_POLYGON);
    glVertex2f(598+s,285.6+ss); glVertex2f(640+s,330+ss);
    glColor3ub(200,200,200); glVertex2f(628+s,275+ss); glVertex2f(640+s,220+ss); glVertex2f(598+s,265+ss);
    glEnd();
    glColor3ub(100,106,107);
    glBegin(GL_TRIANGLES);
    glVertex2f(410+s,313+ss); glVertex2f(460+s,360+ss); glVertex2f(475+s,313+ss);
    glEnd();
    glColor3ub(115,116,117);
    glBegin(GL_TRIANGLES);
    glVertex2f(420+s,260+ss); glVertex2f(450+s,210+ss); glVertex2f(460+s,260+ss);
    glEnd();
    glColor3f(0,0,0); glPointSize(4.0); glBegin(GL_POINTS); glVertex2f(332+s,287+ss); glEnd();
    glColor3f(1.0,1.0,1.0); glPointSize(2.0); glBegin(GL_POINTS); glVertex2f(331.8+s,287+ss); glEnd();
}

// ---------------- GRASS & ENVIRONMENT ----------------
void drawOrganicGrass() {
    for (int i = 0; i < 1200; i += 7) {
        float h = 45.0f + (float)(i % 70);
        float w = 1.2f + (float)(i % 4);
        float sway = sin(grassSway + (i * 0.1f)) * 12.0f;

        if ((i / 7) % 8 != 0) {
            if (i % 2 == 0) glColor3f(0.01, 0.12, 0.01);
            else glColor3f(0.03, 0.18, 0.03);

            glBegin(GL_QUAD_STRIP);
                glVertex2f(i - w, 30); glVertex2f(i + w, 30);
                glVertex2f(i - w + sway*0.4, 30 + h*0.5); glVertex2f(i + w + sway*0.4, 30 + h*0.5);
                glVertex2f(i + sway, 30 + h); glVertex2f(i + sway + 1, 30 + h);
            glEnd();
        }
    }
}

void drawRocks() {
    glColor3f(0.12, 0.12, 0.12);
    glBegin(GL_POLYGON); glVertex2f(120, 30); glVertex2f(150, 60); glVertex2f(210, 70); glVertex2f(250, 30); glEnd();
    glBegin(GL_POLYGON); glVertex2f(880, 30); glVertex2f(920, 85); glVertex2f(1000, 95); glVertex2f(1060, 30); glEnd();
}

void drawBubbles() {
    for (int i = 0; i < 20; i++) {
        glColor4f(1.0, 1.0, 1.0, 0.3);
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 10; j++) {
            float theta = 2.0f * pi * j / 10.0f;
            glVertex2f(bubbleX[i] + 4.0f * cos(theta), bubbleY[i] + 4.0f * sin(theta));
        }
        glEnd();
    }
}

void drawSurfaceShip() {
    glPushMatrix();
    glTranslatef(shipX, 0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(400, 600); glVertex2f(850, 600); glVertex2f(800, 530); glVertex2f(450, 530);
    glEnd();
    glColor3f(0.15, 0.15, 0.15);
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(500, 530); glVertex2f(500, anchorY);
    glEnd();
    glPushMatrix();
    glTranslatef(500, anchorY, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(-18, 18); glVertex2f(0, 0); glVertex2f(18, 18); glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawSunkenShip() {
    glPushMatrix();
    glTranslatef(100, 30, 0);
    glColor3f(0.08, 0.05, 0.02);
    glBegin(GL_POLYGON);
        glVertex2f(0, 90); glVertex2f(380, 70); glVertex2f(320, 0); glVertex2f(60, 0);
    glEnd();
    glLineWidth(6);
    glBegin(GL_LINES);
        glVertex2f(120, 90); glVertex2f(80, 240); glVertex2f(280, 80); glVertex2f(310, 190);
    glEnd();
    glPopMatrix();
}

// ---------------- DISPLAY LOOP ----------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Ocean Gradient
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.3, 0.5); glVertex2f(0, 600); glVertex2f(1200, 600);
    glColor3f(0.0, 0.01, 0.05); glVertex2f(1200, 0); glVertex2f(0, 0);
    glEnd();

    drawSunkenShip();
    drawSurfaceShip();

    // Sand Bed
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.25, 0.15); glVertex2f(0, 30); glVertex2f(1200, 30);
    glColor3f(0.1, 0.08, 0.02); glVertex2f(1200, 0); glVertex2f(0, 0);
    glEnd();

    drawRocks();

    // Scattered Starfish
    drawStarfish(350, 18);
    drawStarfish(720, 12);
    drawStarfish(1050, 20);
    drawStarfish(150, 22);

    drawOrganicGrass();

    if (flag3) {
        drawBubbles();
        // Floating Jellyfish
        drawJellyfish(200, 400 + sin(grassSway) * 20);
        drawJellyfish(900, 250 + cos(grassSway) * 30);

        fish1(); fish2(); Shark();
    } else {
        glColor3f(1,1,1); glRasterPos2f(450,300);
        char* m = "P: START | L: LIFT ANCHOR";
        while(*m) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *m++);
    }
    glutSwapBuffers();
}

void update(int value) {
    if (moving) {
        grassSway += 0.05f;
        a -= speedFish1; if (a < -450) a = 1250;
        b += speedFish2; if (b > 1250) b = -250;
        s -= speedShark; if (s < -650) s = 1300;

        for (int i = 0; i < 20; i++) {
            bubbleY[i] += bubbleSpeed[i];
            if (bubbleY[i] > 600) { bubbleY[i] = -10; bubbleX[i] = rand() % 1200; }
        }

        if (liftingAnchor && anchorY < 530) anchorY += 2.0f;
        else if (liftingAnchor && anchorY >= 530) shipMoving = 1;
        if (shipMoving) { shipX -= 1.5f; if (shipX < -900) shipX = 1300; }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluOrtho2D(0, 1200, 0, 600);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        bubbleX[i] = rand() % 1200;
        bubbleY[i] = rand() % 600;
        bubbleSpeed[i] = 1.0f + (rand() % 20) / 10.0f;
    }
}

void key(unsigned char k, int x, int y) {
    if (k == 'p' || k == 'P') { flag3 = 1; moving = 1; }
    if (k == 'l' || k == 'L') liftingAnchor = 1;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Lush Sea with Jellyfish and Starfish");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
