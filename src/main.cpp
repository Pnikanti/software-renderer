#include "gmath.h"
#include "tga.h"
#include <iostream>

const TGAColor red(255, 0, 0, 255);
const TGAColor green(0, 255, 0, 255);
const TGAColor blue(0, 0, 255, 255);
const TGAColor white(255, 255, 255, 255);

const char* outputfile = "output.tga";

void flush(const TGAImage& framebuffer)
{
	framebuffer.write_tga_file(outputfile);
}

void draw(int x1, int x2, int y1, int y2, TGAImage& framebuffer, TGAColor color)
{
	bool inverted = false;
	bool inverted_dst = false;

	if (y2 < y1)
	{
		std::swap(y2, y1);
	}

	// if destination coordinate is less than source -> swap em
	if (x2 < x1)
	{
		std::swap(x2, x1);
		inverted_dst = true;
	}

	int dx = x2 - x1;
	int dy = y2 - y1;

	// if y-axis is longer than x-axis -> swap em
	if (dx < dy)
	{
		std::swap(dx, dy);
		std::swap(x1, y1);
		std::swap(x2, y2);
		inverted = true;
	}

	// Old switcharoo -> because we want to go backwards in "x" or the lengthiest axis.
	if (inverted_dst)
	{
		std::swap(x2, x1);
	}

	int decision = 2 * dy - dx;

	std::cout << "dx: " << dx << ", dy: " << dy << std::endl;

	int x = x1;
	int y = y1;

	for( int i = 0; i <= dx; i++ )
	{
		std::cout << "drawing x: " << x << ", y: " << y << ", decision: " << decision << std::endl;

		if (inverted)
		{
			framebuffer.set(y, x, color);
		}
		else
		{
			framebuffer.set(x, y, color);
		}

		inverted_dst ? x-- : x++;

		if (decision <= 0)
		{
			decision += 2 * dy;
		}
		else
		{
			decision += (2 * dy) - (2 * dx);
			y++;
		}
	}
}

void draw(vec2i a, vec2i b, TGAImage& framebuffer, TGAColor color)
{
	draw(a.x, b.x, a.y, b.y, framebuffer, color);
}

int main()
{
	TGAImage framebuffer(400, 400, TGAImage::RGB);

	// perpendicular line in x-axis
	vec2i A(20, 20);
	vec2i B(100, 20);

	draw(A, B, framebuffer, white);

	// perpendicular line in y-axis
	vec2i C(20, 20);
	vec2i D(20, 100);

	draw(C, D, framebuffer, red);

	// 45 degree angle ( inverted src - dst )
	vec2i E(100, 20);
	vec2i F(20, 100);

	draw(E, F, framebuffer, green);

	// 45 degree angle ( inverted src - dst )
	vec2i Ei(20, 100);
	vec2i Fi(100, 20);

	draw(Ei, Fi, framebuffer, blue);

	// steep slope (non-inverted src - dst)
	vec2i G(150, 20);
	vec2i H(200, 150);

	draw(G, H, framebuffer, red);

	// gentle slope (non-inverted src - dst)
	vec2i I(250, 20);
	vec2i J(350, 30);

	draw(I, J, framebuffer, green);

	flush(framebuffer);
	return 0;
}