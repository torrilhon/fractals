#include <vcl\vcl.h>

#include "math.h"
#pragma hdrstop

#include "Frak1.h"
//---------------------------------------------------------------------------

Punkt::Punkt( float x, float y )
{
	Set( x, y );
};

Punkt Punkt::Set( float x, float y )
{
	X = x;
    Y = y;
    return( *this );
};


Trafo::Trafo()
{
	Reset();
};

void Trafo::Reset()
{
	r = 1;
    phi = 0;
    rx = 1;
    psi = 0;
    xs = 0;
    ys = 0;
};

void Trafo::Transform( DrehKoord *D )
{
	D->Verschieb( xs, ys );
    D->Drehung( r, phi );
    D->XDreh( rx, psi );
};





DrehKoord::DrehKoord()
{
	Reset();
};

void DrehKoord::MakeA()
{
	A11 = r1*cos(phi);
    A12 = r1*sin(phi);
    A21 = -r2*sin(theta);
    A22 = r2*cos(theta);
};

Punkt DrehKoord::Transform( Punkt P )
{
	Punkt P2;

    P2.X = (A11*P.X+A21*P.Y) + xs;
    P2.Y = (A12*P.X+A22*P.Y) + ys;
    return( P2 );
};

void DrehKoord::Drehung( float r, float psi )
{
    r1 = r1*r;
    r2 = r2*r;
    phi = phi+psi;
    theta = theta+psi;
    MakeA();
};

void DrehKoord::XDreh( float r, float psi )
{
	psi = 2*acos((A11*A21+A12*A22)/(r1*r2))/M_PI*psi;

    r1 = r1*r;
    phi = phi+psi;
    MakeA();
};

void DrehKoord::YDreh( float r, float psi )
{
    A21 = -A11*r*sin(psi)+A21*r*cos(psi);
    A22 = -A12*r*sin(psi)+A22*r*cos(psi);

	r2 = sqrt( A22*A22+A21*A21 );
    theta = atan( -A21/A22 );
};

void DrehKoord::Verschieb( float x, float y )
{
	Punkt P = Transform( Punkt( x, y ) );
	xs = P.X;
    ys = P.Y;
};

void DrehKoord::Reset()
{
	r1 = 1;
    r2 = 1;
    phi = 0;
    theta = 0;
    xs = 0;
    ys = 0;

    MakeA();
};

