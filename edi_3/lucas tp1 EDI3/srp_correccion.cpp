#include <iostream>
#include <string.h>
/* parte en c#
interface ICorreoElectronico
{
    void SetEmisor(String emisor);
    void SetReceptor(String receptor);
    void SetContenido(Icontenido content);+
}

interface Icontenido
{
    String GetContenidoSerializado(); // para serializar el contenido
}

class CorreoElectronico : ICorreoElectronico
{
    public void SetEmisor(String Sender){}
    public void SetReceptor(String receiver){}
    public void SetContenido(IContenido content){}
}

// parte en c++*/



struct IContenido
{
public:
	~IContenido(){std::cout<<"create destructor"<<std::endl;}
	 virtual std::string GetContenidoSerializado() = 0; // para serializar el contenido
};	

class ICorreoElectronico
{
public:
	virtual ~ICorreoElectronico(){}
	virtual void SetEmisor(std::string Sender) = 0;
	virtual void SetReceptor(std::string receiver) = 0;
	virtual void SetContenido(IContenido *content) = 0;
	
};


class CorreoElectronico : public ICorreoElectronico
{
public:
CorreoElectronico(){
	
	std::cout<<"creando el constructor (correo)"<<std::endl;
}

~CorreoElectronico(){

	std::cout<<"creando el destructor(free memory destroy mail)";

}
void SetEmisor(std::string Sender)
{
	this->Sender=Sender;
	std::cout<<"Emisor:"<<Sender<<std::endl;
}

void SetReceptor(std::string receiver)
{
		std::cout<<"reseptor:"<<receiver<<std::endl;
}

void SetContenido(IContenido *content)
{
	this->content = content;
	std::cout<<"content: "<<content->GetContenidoSerializado()<<std::endl;
}

	

private:
	std::string Sender;
	std::string receiver;
	IContenido *content;

};

class Contenido : public IContenido {
public:
 
 Contenido(std::string msj){
 	
 	this-> msj= msj;
 }
 
 ~Contenido(){}
 
 std::string GetContenidoSerializado()
 {
 	return msj;
 }
	private:
   std::string msj;
};

int main () {
ICorreoElectronico* MENSAJE = new CorreoElectronico() ;

    MENSAJE -> SetEmisor( "JOSE" ) ;
    MENSAJE -> SetReceptor( "PEPITO" ) ;
    MENSAJE -> SetContenido( new Contenido( "HOLA DON PEPITO , HOLA DON JOSE , USTED PASO POR CASA?" ) ) ;

    delete MENSAJE ;



return 0;
}
