#ifndef Frak1H
#define Frak1H
//---------------------------------------------------------------------------
class Punkt
{
	public:
    		Punkt( float x = 0, float y = 0 );

            Punkt Set( float x, float y );
			float X;
    		float Y;
};

class DrehKoord
{
	public:
    		DrehKoord();

            Punkt Transform( Punkt P );
            void XDreh( float r, float psi );
            void YDreh( float r, float psi );
            void Verschieb( float x, float y );
            void Drehung( float r, float psi );
            void Reset();

    private:
            float r1, r2, phi, theta;
            float xs, ys;
            float A11, A12, A21, A22;
            float Det;

            void MakeA();
};


class Trafo
{
	public:
    		Trafo();

            void Transform( DrehKoord *D );
            void Reset();

            float r, rx, phi, psi, xs, ys;
};

extern Trafo *GlobalTrafo;











#endif
