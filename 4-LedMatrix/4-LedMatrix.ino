// Tutorial for controlling the LED Matrix in the R4 board
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() 
{
  Serial.begin(9600);
  // Initialize the LED Matrix
  matrix.begin();
}

// Create a frame buffer to store the image
uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Create a drawing by setting the pixels in the frame buffer
void heart1() {
  clearmatrix();
  frame[1][1] = 1;
  frame[2][1] = 1;
  frame[3][1] = 1;
  frame[0][2] = 1;
  frame[4][2] = 1;
  frame[0][3] = 1;
  frame[5][3] = 1;
  frame[1][4] = 1;
  frame[6][4] = 1;
  frame[2][5] = 1;
  frame[7][5] = 1;
  frame[1][6] = 1;
  frame[6][6] = 1;
  frame[0][7] = 1;
  frame[5][7] = 1;
  frame[0][8] = 1;
  frame[4][8] = 1;
  frame[1][9] = 1;
  frame[2][9] = 1;
  frame[3][9] = 1;
}

void heart2() {
  clearmatrix();
  frame[3][2] = 1;
  frame[4][2] = 1;
  frame[2][3] = 1;
  frame[5][3] = 1;
  frame[2][4] = 1;
  frame[6][4] = 1;
  frame[3][5] = 1;
  frame[7][5] = 1;
  frame[2][6] = 1;
  frame[6][6] = 1;
  frame[2][7] = 1;
  frame[5][7] = 1;
  frame[3][8] = 1;
  frame[4][8] = 1;
}

void circle1() {
  clearmatrix();
  frame[3][5] = 1;
  frame[4][5] = 1;
  frame[3][6] = 1;
  frame[4][6] = 1;
}

void circle2() {
  clearmatrix();
  frame[3][4] = 1;
  frame[4][4] = 1;
  frame[2][5] = 1;
  frame[5][5] = 1;
  frame[2][6] = 1;
  frame[5][6] = 1;
  frame[3][7] = 1;
  frame[4][7] = 1;
}

void circle3() {
  clearmatrix();
  frame[2][3] = 1;
  frame[3][3] = 1;
  frame[4][3] = 1;
  frame[5][3] = 1;
  frame[1][4] = 1;
  frame[6][4] = 1;
  frame[1][5] = 1;
  frame[6][5] = 1;
  frame[1][6] = 1;
  frame[6][6] = 1;
  frame[1][7] = 1;
  frame[6][7] = 1;
  frame[2][8] = 1;
  frame[3][8] = 1;
  frame[4][8] = 1;
  frame[5][8] = 1;
}

void circle4() {
  clearmatrix();
  frame[2][2] = 1;
  frame[3][2] = 1;
  frame[4][2] = 1;
  frame[5][2] = 1;
  frame[1][3] = 1;
  frame[6][3] = 1;
  frame[0][4] = 1;
  frame[7][4] = 1;
  frame[0][5] = 1;
  frame[7][5] = 1;
  frame[0][6] = 1;
  frame[7][6] = 1;
  frame[0][7] = 1;
  frame[7][7] = 1;
  frame[1][8] = 1;
  frame[6][8] = 1;
  frame[2][9] = 1;
  frame[3][9] = 1;
  frame[4][9] = 1;
  frame[5][9] = 1;
}

void circle5() {
  clearmatrix();
  frame[2][1] = 1;
  frame[3][1] = 1;
  frame[4][1] = 1;
  frame[5][1] = 1;
  frame[0][2] = 1;
  frame[1][2] = 1;
  frame[6][2] = 1;
  frame[7][2] = 1;
  frame[0][3] = 1;
  frame[7][3] = 1;
  frame[0][8] = 1;
  frame[7][8] = 1;
  frame[0][9] = 1;
  frame[1][9] = 1;
  frame[6][9] = 1;
  frame[7][9] = 1;
  frame[2][10] = 1;
  frame[3][10] = 1;
  frame[4][10] = 1;
  frame[5][10] = 1;
}

void circle6() {
  clearmatrix();
  frame[2][0] = 1;
  frame[3][0] = 1;
  frame[4][0] = 1;
  frame[5][0] = 1;
  frame[0][1] = 1;
  frame[1][1] = 1;
  frame[6][1] = 1;
  frame[7][1] = 1;
  frame[0][10] = 1;
  frame[1][10] = 1;
  frame[6][10] = 1;
  frame[7][10] = 1;
  frame[2][11] = 1;
  frame[3][11] = 1;
  frame[4][11] = 1;
  frame[5][11] = 1;
}

// Clear the frame buffer each time before drawing a new image
void clearmatrix() {
  for(int i = 0; i<12; i++) {
    for(int j = 0; j<8; j++) {
      frame[j][i] = 0;
    }
  }
}


typedef void (*CircleFunction)();

CircleFunction circleFunctions[] = {circle1, circle2, circle3, circle4, circle5, circle6, clearmatrix};

void loop() {
  // Create a heart shape
  heart1();
  // Load the shape and show it on the LED Matrix
  matrix.renderBitmap(frame, 8, 12);
  // Wait for before showing the next shape
  delay(150);
  // Create another heart shape
  heart2();
  // Load the shape and show it on the LED Matrix
  matrix.renderBitmap(frame, 8, 12);
  delay(150);
}