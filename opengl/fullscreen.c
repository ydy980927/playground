#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 90, angle=0.0;

//draw the cubes, they make a fancy shape from above :P
void cube (void) {
   // float i;
    //for (i=0;i<50;i++)
   // {
        glTranslated(1, 0, 1);
        glPushMatrix();
        glutSolidCube(.5); //draw the cube
        glPopMatrix();
  //  }
}

void init (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
    
}

void camera (void) {
    glRotatef(xrot,1.0,0.0,0.0); 
    glRotatef(yrot,0.0,1.0,0.0); 
    glTranslated(-xpos,-ypos,-zpos); 
}

void display (void) 
{
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    //clear the color buffer and the depth buffer
    glLoadIdentity();  
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
    //camera position, x,y,z, looking at x,y,z, Up Positions of the camera
    camera();
    cube(); //call the cube drawing function
    glutSwapBuffers(); //swap the buffers
    angle++; //increase the angle
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection
    
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
    
}

void keyboard (unsigned char key, int x, int y) {
    if (key=='q')
    {
        xrot += 1;
        if (xrot >360) xrot -= 360;
    }
    
    if (key=='z')
    {
        xrot -= 1;
        if (xrot < -360) xrot += 360;
    }
    
    if (key=='w')
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f); 
        xpos += (float)sin(yrotrad) ;
        zpos -= (float)cos(yrotrad) ;
        ypos -= (float)sin(xrotrad) ;
    }
    
    if (key=='s')
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f); 
        xpos -= (float)sin(yrotrad);
        zpos += (float)cos(yrotrad) ;
        ypos += (float)sin(xrotrad);
    }
    
    if (key=='d')
    {
        yrot += 1;
        if (yrot >360) yrot -= 360;
    }
    
    if (key=='a')
    {
        yrot -= 1;
        if (yrot < -360)yrot += 360;
    }
    if (key==27)
    {
        glutLeaveGameMode(); //set the resolution how it was
        exit(0); //quit the program
    }
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
    glutGameModeString( "1920x1080:32@60" ); //the settings  for fullscreen mode
    glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
    init (); //call the init function
    glutDisplayFunc (display); //use the display function to draw everything
    glutIdleFunc (display); //update any variables in display,display can be changed to anyhing, as long as you move the variables to be updated, in this case, angle++;
    glutReshapeFunc (reshape); //reshape the window accordingly
    
    glutKeyboardFunc (keyboard); //check the keyboard
    glutMainLoop (); //call the main loop
    return 0;
}