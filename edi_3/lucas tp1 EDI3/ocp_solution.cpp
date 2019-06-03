//.h file code:

// parte en java.

class Forma
{
public:
	virtual void Dibujar() = 0;

protected:
	void DibujarComun();
};

class Rectangulo : public Forma
{
public:
	virtual void Dibujar(){
		DibujarComun();
	} 
};

class Circulo : public Forma
{
public:
	void Dibujar() {
		DibujarComun();
	}
};

class EditorGrafico
{
public:
	void DibujarForma(Forma *forma);
};


void Forma::DibujarComun()
{
// Parte comun en todos los metodos dibujar para todas las formas...
}

void Rectangulo::Dibujar()
{
	//¿Hay algo comun en todos los metodos dibujar?
	DibujarComun();
	// Dibujar un Rectangulo
}

void Circulo::Dibujar()
{
	//¿Hay algo comun en todos los metodos dibujar?
	DibujarComun();
	//Dibuja un circulo
}

void EditorGrafico::DibujarForma(Forma *forma)
{
	forma->Dibujar();
}

