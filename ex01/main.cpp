#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	{
		std::cout << "--- Test 1: Un formulario que se firma." << std::endl;
		Form formA("Formulario para ser jarredios", 1, 1);
		Bureaucrat juanan("Juanan", 1);
		juanan.signForm(formA);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "--- Test 2: Un formulario con grado inválido." << std::endl;
		try {
			Form formA("Formulario para ser jarredios", -1, 1);
			Bureaucrat juanan("Juanan", 1);
			juanan.signForm(formA);
		}
		catch (std::exception &e) { std::cout << "No se ha podido crear el formulario. Motivo: " << e.what() << std::endl;}
		try {
			Form formA("Formulario para ser jarredios", 160, 1);
			Bureaucrat juanan("Juanan", 1);
			juanan.signForm(formA);
		}
		catch (std::exception &e) { std::cout << "No se ha podido crear el formulario. Motivo: " << e.what() << std::endl;}
		try {
			Form formA("Formulario para ser jarredios", 1, -1);
			Bureaucrat juanan("Juanan", 1);
			juanan.signForm(formA);
		}
		catch (std::exception &e) { std::cout << "No se ha podido crear el formulario. Motivo: " << e.what() << std::endl;}
		try {
			Form formA("Formulario para ser jarredios", 1, 170);
			Bureaucrat juanan("Juanan", 1);
			juanan.signForm(formA);
		}
		catch (std::exception &e) { std::cout << "No se ha podido crear el formulario. Motivo: " << e.what() << std::endl;}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "--- Test 3: Burocrata que no puede firmar un documento." << std::endl;
		try {
			Form f("declaracion de la renta", 2, 2);
			Bureaucrat rajoy("m.rajoy", 3);
			Bureaucrat jarredon("jarredon", 1);
			rajoy.signForm(f);
		}
		catch (std::exception &e) { std::cout << "No se ha podido crear el formulario. Motivo: " << e.what() << std::endl;}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return (0);
}