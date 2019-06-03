/*

public interface ICorreoElectronico
{
    void SetEmisor(String emisor);
    void SetReceptor(String receptor);
    void SetContenido(String contenido);
}

public class CorreoElectronico : ICorreoElectronico
{
    public void SetEmisor(String emisor)
    {
    }
    public void SetReceptor(String receptor)
    {
    }
    public void SetContenido(String contenido)
    {
    }
}

// de aca para abajo en lenguaje de c++

*/

#include <iostream>
#include <string.h>

struct ICorreoElectronico
{
public:
	virtual void SetEmisor(std::string emisor) = 0;
	virtual void SetReceptor(std::string receptor) = 0;
	virtual void SetContenido(std::string contenido) = 0;
	virtual ~ICorreoElectronico(){};
};

class CorreoElectronico : public ICorreoElectronico
{
public:
//Me aparecio el primer error "string has not been declared" , se debe a que me falto el std .
//creo el constructor de la clase correo electronico y heredo de ICorreoElectronico , sus metodos.
	CorreoElectronico(){
	std::cout<<"Creando correo electronico"<<std::endl;
	}
//Asi como creé su constructor tambien creo su destructor
	~CorreoElectronico(){
		std::cout<<"DELETE correo electronico"<<std::endl;
	}
//error n3 no encuentra el emisor , por que no puse el THIS. "cannot be overloaded" 
	void SetEmisor(std::string emisor)
	{
	this -> emisor = emisor;
	std::cout<<"set Emisor"<<std::endl;
	}

	void SetReceptor(std::string receptor)
	{
		this -> receptor = receptor;
	std::cout<<"set Reseptor"<<std::endl;
	}

	void SetContenido(std::string contenido)
	{
		this -> contenido = contenido;
	std::cout<<"set contenido"<<std::endl;
	}
	private:
	std::string emisor;
	std::string receptor;
	std::string contenido;
};

int main(){
	ICorreoElectronico* Mensaje = new CorreoElectronico();
	Mensaje->SetEmisor("Hola don Pepito");
	Mensaje->SetReceptor("Hola don Jose");
	Mensaje->SetContenido("Paso usted por casa?");
	//AL HABER CREADO EL DESTRUCTOR ME PERMITE ELIMINAR LA MEMORIA DE LAS FUNCIONES Y CLASES.
	delete Mensaje;
	
	
	return 0 ;
}

