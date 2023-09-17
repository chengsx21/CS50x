#include "helpers.h"
#include <math.h>

int min(int a, int b) {
    return a > b ? b : a;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = round(1.0 * (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = color;
            image[i][j].rgbtGreen = color;
            image[i][j].rgbtBlue = color;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE new_image = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = new_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float blur_r = 0, blur_g = 0, blur_b = 0;
            int cnt = 0;
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    if (i + row < 0 || i + row > height - 1 || j + col < 0 || j + col > width - 1)
                        continue;
                    cnt++;
                    blur_r += image[i + row][j + col].rgbtRed;
                    blur_g += image[i + row][j + col].rgbtGreen;
                    blur_b += image[i + row][j + col].rgbtBlue;
                }
            }
            new_image[i][j].rgbtRed = round(blur_r / cnt);
            new_image[i][j].rgbtGreen = round(blur_g / cnt);
            new_image[i][j].rgbtBlue = round(blur_b / cnt);
        }
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = new_image[i][j];
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE new_image[height][width];
    double sobelx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    double sobely[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int cnt = -1;
            double rx = 0, ry = 0, gx = 0, gy = 0, bx = 0, by = 0;
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    cnt++;
                    if (i + row < 0 || i + row > height - 1 || j + col < 0 || j + col > width - 1)
                        continue;
                    rx += sobelx[cnt] * image[i + row][j + col].rgbtRed;
                    ry += sobely[cnt] * image[i + row][j + col].rgbtRed;
                    gx += sobelx[cnt] * image[i + row][j + col].rgbtGreen;
                    gy += sobely[cnt] * image[i + row][j + col].rgbtGreen;
                    bx += sobelx[cnt] * image[i + row][j + col].rgbtBlue;
                    by += sobely[cnt] * image[i + row][j + col].rgbtBlue;
                }
            }
            new_image[i][j].rgbtRed = min(round(sqrt(rx * rx + ry * ry)), 255);
            new_image[i][j].rgbtGreen = min(round(sqrt(gx * gx + gy * gy)), 255);
            new_image[i][j].rgbtBlue = min(round(sqrt(bx * bx + by * by)), 255);
        }
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = new_image[i][j];
    return;
}
