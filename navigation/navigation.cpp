
#include <math.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <stdlib.h>

static float angle = 0.0, ratio; //각도, 시야걱
static float x = 0.0f, y = 2.75f, z = 5.0f; //카메라 위치
static float lx = 0.0f, ly = 0.0f, lz = -1.0f; //시선방향 
static GLint display_list;

void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;

    ratio = 1.0f * w / h;
    // 초기화
    glMatrixMode(GL_PROJECTION); //투영좌표계 적용
    glLoadIdentity();

    // 뷰포트를 창 전체크기로 설정합니다. 
    glViewport(0, 0, w, h);


    gluPerspective(45, ratio, 1, 1000); // 절단 공간을 설정
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f); // 카메라 시점 설정 
}

void drawBuilding()
{
    glTranslatef(5.0f, 1.0f, -3.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.54902f, 0.0f);
    glVertex3f(-0.7f, 3.0f, 1.0f); // { Front }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Front }
    glVertex3f(0.7f, -1.0f, 1.0f); // { Front }
    glVertex3f(0.7f, 3.0f, 1.0f); // { Front }

    glVertex3f(0.7f, 3.0f, 1.0f); // { Right }
    glVertex3f(0.7f, -1.0f, 1.0f); // { Right }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Right }
    glVertex3f(0.7f, 3.0f, -1.0f); // { Right }

    glVertex3f(0.7f, 3.0f, -1.0f); // { Back }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Back }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Back }
    glVertex3f(-0.7f, 3.0f, -1.0f); // { Back }

    glVertex3f(-0.7f, 3.0f, -1.0f); // { Left }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Left }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Left }
    glVertex3f(-0.7f, 3.0f, 1.0f); // { Left }

    glVertex3f(-0.7f, 3.0f, 1.0f); // { Top }
    glVertex3f(0.7f, 3.0f, 1.0f); // { Top }
    glVertex3f(0.7f, 3.0f, -1.0f); // { Top }
    glVertex3f(-0.7f, 3.0f, -1.0f); // { Top }

    glVertex3f(0.7f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Bottom }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Bottom }
    glEnd();

    glTranslatef(-11.0f, 0.0f, -11.0f);
    glBegin(GL_QUADS);
    glColor3f(0.827451f, 0.827451f, 0.82745f);
    glVertex3f(-0.7f, 3.0f, 1.0f); // { Front }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Front }
    glVertex3f(0.7f, -1.0f, 1.0f); // { Front }
    glVertex3f(0.7f, 3.0f, 1.0f); // { Front }

    glVertex3f(0.7f, 3.0f, 1.0f); // { Right }
    glVertex3f(0.7f, -1.0f, 1.0f); // { Right }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Right }
    glVertex3f(0.7f, 3.0f, -1.0f); // { Right }

    glVertex3f(0.7f, 3.0f, -1.0f); // { Back }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Back }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Back }
    glVertex3f(-0.7f, 3.0f, -1.0f); // { Back }

    glVertex3f(-0.7f, 3.0f, -1.0f); // { Left }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Left }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Left }
    glVertex3f(-0.7f, 3.0f, 1.0f); // { Left }

    glVertex3f(-0.7f, 3.0f, 1.0f); // { Top }
    glVertex3f(0.7f, 3.0f, 1.0f); // { Top }
    glVertex3f(0.7f, 3.0f, -1.0f); // { Top }
    glVertex3f(-0.7f, 3.0f, -1.0f); // { Top }

    glVertex3f(0.7f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-0.7f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-0.7f, -1.0f, -1.0f); // { Bottom }
    glVertex3f(0.7f, -1.0f, -1.0f); // { Bottom }
    glEnd();

    glTranslatef(3.0f, 0.0f, -5.0f); //공대
    glBegin(GL_QUADS);
    glColor3f(0.282353f, 0.239216f, 0.545098f);
    glVertex3f(-1.0f, 3.0f, 1.0f); // { Front }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Front }
    glVertex3f(1.0f, -1.0f, 1.0f); // { Front }
    glVertex3f(1.0f, 3.0f, 1.0f); // { Front }

    glVertex3f(1.0f, 3.0f, 1.0f); // { Right }
    glVertex3f(1.0f, -1.0f, 1.0f); // { Right }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Right }
    glVertex3f(1.0f, 3.0f, -1.0f); // { Right }

    glVertex3f(1.0f, 3.0f, -1.0f); // { Back }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Back }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Back }
    glVertex3f(-1.0f, 3.0f, -1.0f); // { Back }

    glVertex3f(-1.0f, 3.0f, -1.0f); // { Left }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Left }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Left }
    glVertex3f(-1.0f, 3.0f, 1.0f); // { Left }

    glVertex3f(-1.0f, 3.0f, 1.0f); // { Top }
    glVertex3f(1.0f, 3.0f, 1.0f); // { Top }
    glVertex3f(1.0f, 3.0f, -1.0f); // { Top }
    glVertex3f(-1.0f, 3.0f, -1.0f); // { Top }

    glVertex3f(1.0f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Bottom }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Bottom }
    glEnd();

    glTranslatef(6.0f, 0.0f, -4.0f); //도서관
    glBegin(GL_QUADS);
    glColor3f(0.690196f, 0.188235f, 0.376471);
    glVertex3f(-1.0f, 3.0f, 1.0f); // { Front }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Front }
    glVertex3f(1.0f, -1.0f, 1.0f); // { Front }
    glVertex3f(1.0f, 3.0f, 1.0f); // { Front }

    glVertex3f(1.0f, 3.0f, 1.0f); // { Right }
    glVertex3f(1.0f, -1.0f, 1.0f); // { Right }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Right }
    glVertex3f(1.0f, 3.0f, -1.0f); // { Right }

    glVertex3f(1.0f, 3.0f, -1.0f); // { Back }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Back }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Back }
    glVertex3f(-1.0f, 3.0f, -1.0f); // { Back }

    glVertex3f(-1.0f, 3.0f, -1.0f); // { Left }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Left }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Left }
    glVertex3f(-1.0f, 3.0f, 1.0f); // { Left }

    glVertex3f(-1.0f, 3.0f, 1.0f); // { Top }
    glVertex3f(1.0f, 3.0f, 1.0f); // { Top }
    glVertex3f(1.0f, 3.0f, -1.0f); // { Top }
    glVertex3f(-1.0f, 3.0f, -1.0f); // { Top }

    glVertex3f(1.0f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-1.0f, -1.0f, 1.0f); // { Bottom }
    glVertex3f(-1.0f, -1.0f, -1.0f); // { Bottom }
    glVertex3f(1.0f, -1.0f, -1.0f); // { Bottom }
    glEnd();
}

GLuint createDL()
{
    GLuint DL;

    // 디스플레이리스트를 생성하고 id 를 반환
    DL = glGenLists(1);

    // 디스플레이리스트를 시작
    glNewList(DL, GL_COMPILE);

    // 렌더링을 수행하는 함수 호출
    drawBuilding();

    // 디스플레이리스트 끝
    glEndList();

    return(DL);
}

void initScene()
{
    glEnable(GL_DEPTH_TEST); //원근 적용
    display_list = createDL();
}

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.529412f, 0.807843f, 0.980392f, 1.0f);
   
    //지형 그리기
    glBegin(GL_QUADS);
    glColor3f(0.133333f, 0.545098f, 0.133333f);
    glVertex3f(-50.0f, 0.0f, -50.0f);
    glVertex3f(-50.0f, 0.0f, 10.0f);
    glVertex3f(50.0f, 0.0f, 10.0f);
    glVertex3f(50.0f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); //도로
    glVertex3f(-1.0f, 0.001f, -40.0f);
    glVertex3f(-1.0f, 0.001f, 10.0f);
    glVertex3f(1.0f, 0.001f, 10.0f);
    glVertex3f(1.0f, 0.001f, -40.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //도로 선
    glVertex3f(-0.1f, 0.01f, -40.0f);
    glVertex3f(-0.1f, 0.01f, 10.0f);
    glVertex3f(0.1f, 0.01f, 10.0f);
    glVertex3f(0.1f, 0.01f, -40.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); //도로
    glVertex3f(0.1f, 0.001f, -4.0f);
    glVertex3f(0.1f, 0.001f, -2.0f);
    glVertex3f(5.0f, 0.001f, -2.0f);
    glVertex3f(5.0f, 0.001f, -4.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //도로 선
    glVertex3f(0.0f, 0.01f, -3.1f);
    glVertex3f(0.0f, 0.01f, -2.9f);
    glVertex3f(5.0f, 0.01f, -2.9f);
    glVertex3f(5.0f, 0.01f, -3.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); //도로
    glVertex3f(-6.0f, 0.001f, -15.0f);
    glVertex3f(-6.0f, 0.001f, -13.0f);
    glVertex3f(-0.1f, 0.001f, -13.0f);
    glVertex3f(-0.1f, 0.001f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //도로 선
    glVertex3f(-6.0f, 0.01f, -14.1f);
    glVertex3f(-6.0f, 0.01f, -13.9f);
    glVertex3f(0.0f, 0.01f, -13.9f);
    glVertex3f(0.0f, 0.01f, -14.1f);
    glEnd();

    double rad = 0.5; //명수당
    glBegin(GL_POLYGON);
    glColor3f(0.0f,	0.0f,	1.0f);
    for (int i = 0; i < 360; i++)
    {
        double angle = i * 3.141592 / 180;
        double x = rad * cos(angle);
        double z = rad * sin(angle);
        glVertex3f(-6 + (8 * x), 0.01f, -34 + (8 * z));
    }
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glCallList(display_list);;
    glPopMatrix();
    glutSwapBuffers();
}

void orientMe_UD(float ang) //인자로 받아온 만큼 시선 위/아래 조절
{
    ly = ang;
    ly = -ang;

    glLoadIdentity();
    gluLookAt(x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}
void orientMe_LR(float ang) //인자로 받아온 만큼 시선 회전
{
    lx = sin(ang);
    lz = -cos(ang);

    glLoadIdentity();
    gluLookAt(x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}
void moveMeFlat(int direction) //인자로 받아온 만큼 앞뒤로 이동
{
    x = x + direction * (lx) * 0.1;
    z = z + direction * (lz) * 0.1;
    glLoadIdentity();
    gluLookAt(x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}

void inputKey(unsigned char KeyPressed, int X, int Y) //조절키
{
    switch (KeyPressed)
    {
    case 'l': //left
        angle -= 0.01f;
        orientMe_LR(angle);
        break;
    case 'r': //right
        angle += 0.01f;
        orientMe_LR(angle);
        break;
    case 'u': //up
        angle -= 0.01f;
        orientMe_UD(angle);
        break;
    case 'd': //down
        angle += 0.01f;
        orientMe_UD(angle);
        break;
    case 'f': //front
        moveMeFlat(1);
        break;
    case 'b': //back
        moveMeFlat(-1);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 360);
    glutCreateWindow("HUFS Navigation");

    initScene();

    glutIdleFunc(renderScene);
    glutDisplayFunc(renderScene);

    glutKeyboardFunc(inputKey);
    glutReshapeFunc(changeSize);

    glutMainLoop();

    return(0);
}
