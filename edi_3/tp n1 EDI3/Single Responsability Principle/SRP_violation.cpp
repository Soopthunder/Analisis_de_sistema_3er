#include <iostream>

class IEmail{
public:
	virtual void setTransmitter(std::string transmitter)=0;
	virtual void setReceiver(std::string receiver)=0;
	virtual void setContent(std::string content)=0;
};

class Email:public IEmail{
public:
	Email();
	void setTransmitter(std::string transmitter);
	void setReceiver(std::string receiver);
	void setContent(std::string content);
	~Email();
};

Email::Email(){
	std::cout<<"I'm creating an email."<<std::endl;
}

void Email::setTransmitter(std::string transmitter){
	std::cout<<"I'm setting the transmitter."<<std::endl;
}

void Email::setReceiver(std::string receiver){
	std::cout<<"I'm setting the receiver."<<std::endl;
}

void Email::setContent(std::string content){
	std::cout<<"I'm setting the content."<<std::endl;
}

Email::~Email(){
	std::cout<<"I'm destroying an email."<<std::endl;
}

int main(){
	IEmail* e = new Email();
	e->setTransmitter("Diego");
	e->setReceiver("EDI III");
	e->setContent("Este es el contenido.");
	delete e;
	return 0;
}
