#include <iostream>
#include <string.h>

//parte en c#
class IForma
{
public:
	virtual int GetTipo() = 0;
};

class Rectangulo : public IForma
{
public:
	int GetTipo(){
	
	return 1  ;
	}
};

class Circulo : public IForma
{
public:
	int GetTipo() {
	
	return 2;
}
};

class EditorGrafico{
public:
	EditorGrafico(){
		std::cout<<"constructor"<<std::endl;
	}
	~EditorGrafico(){
	std::cout<<"destructor"<<std::endl;
	}
void DibujarForma(IForma *forma)
{
	switch( forma -> GetTipo() ) {
            case 1:
              DibujaUnRectangulo( ( Rectangulo* ) forma ) ;
              break ;
            case 2:
              DibujaUnCirculo( ( Circulo* ) forma ) ;
              break ;
        }
}

private:
	void DibujaUnCirculo(Circulo *circulo){
		std::cout<<"dibujar circulo"<<std::endl;
	}

	void DibujaUnRectangulo(Rectangulo *rectangulo){
		std::cout<<"dibujar Rectangulo"<<std::endl;
	}
} ;


int main(){
	
	EditorGrafico* PAINT = new EditorGrafico() ;
    PAINT -> DibujarForma( new Rectangulo() ) ;
    PAINT -> DibujarForma( new Circulo() ) ;

    delete PAINT;
	
	
}
