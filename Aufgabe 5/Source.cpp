#include "Array.h"
#include "TemplateArray.h"
#include "Testklasse.h"
#include <memory>
#include <iostream>

int main()
{
	/*Aufgabe 5.1
	Implementieren Sie eine Klasse Array, die mindestens folgende (und ggf. weitere) Memberfunktionen
	enthalten soll:
		Array(int size), get(int index), set(int index, int value), resize(int size), getsize() 
	*/

	std::unique_ptr<Array> arr(new Array(20)); //declare array with size 20

	//test if constructor works:
	arr->print();

	//filling the array:
	arr->set(0, 5); // set array at position 0 to value 5
	arr->set(1, 3); // set array at position 1 to value 3
	arr->set(2, 9); // set array at position 2 to value 9
	arr->set(3, 12); // set array at position 3 to value 12
	arr->set(4, 6); // set array at position 4 to value 6
	arr->set(5, 2); // set array at position 5 to value 2
	arr->set(6, 7); // set array at position 6 to value 7

	//test if filling the array worked:
	arr->print();

	std::cout << "\n" << arr->get(4) << std::endl; //grab value at position 4 -> should be 6

	arr->resize(25); //resize array to 25
	arr->print(); //print to check if it worked
	std::cout << "\n" << arr->getsize() << std::endl; //also print current arraysize to confirm 

	arr->resize(5); //make array smaller, program should now reconfirm if we actually want to lose value 6
	arr->print();
	std::cout << "\n" << arr->getsize() << std::endl; //also print current arraysize to confirm 


	/*Aufgabe 5.2
	
	Implementieren Sie eine Klasse Template-Array für beliebige Datentypen. 
	Testen Sie Ihre TemplateKlasse mit zwei primitiven Datentypen und einer eigenen Klasse Ihrer Wahl.

	*/
	std::cout << "Aufgabe 5.2: " << std::endl;
	std::cout << "Int-Array:";
	std::cout << std::endl;


	std::unique_ptr<TemplateArray<int>> int_arr(new TemplateArray<int>(20)); //declare int-array with size 20

	//test if constructor works:
	int_arr->print();

	//filling the array:
	int_arr->set(0, 5); // set array at position 0 to value 5
	int_arr->set(1, 3); // set array at position 1 to value 3
	int_arr->set(2, 9); // set array at position 2 to value 9
	int_arr->set(3, 12); // set array at position 3 to value 12
	int_arr->set(4, 6); // set array at position 4 to value 6
	int_arr->set(5, 2); // set array at position 5 to value 2
	int_arr->set(6, 7); // set array at position 6 to value 7

	//test if filling the array worked:
	int_arr->print();

	std::cout << "\n" << int_arr->get(4) << std::endl; //grab value at position 4 -> should be 6

	int_arr->resize(25); //resize array to 25
	int_arr->print(); //print to check if it worked
	std::cout << "\n" << int_arr->getSize() << std::endl; //also print current arraysize to confirm 

	int_arr->resize(5); //make array smaller, program should now reconfirm if we actually want to lose value 6
	int_arr->print();
	std::cout << "\n" << int_arr->getSize() << std::endl; //also print current arraysize to confirm 

	//char-Array:

	std::cout << "Char-Array:";
	std::cout << std::endl;


	std::unique_ptr<TemplateArray<char>> char_arr(new TemplateArray<char>(20)); //declare char-array with size 20

	//test if constructor works:
	char_arr->print();

	//filling the array:
	char_arr->set(0, 'F'); // set array at position 0 to value F
	char_arr->set(1, 'O'); // set array at position 1 to value O
	char_arr->set(2, 'O'); // set array at position 2 to value O
	char_arr->set(3, 'B'); // set array at position 3 to value B
	char_arr->set(4, 'A'); // set array at position 4 to value A
	char_arr->set(5, 'R'); // set array at position 5 to value R
	char_arr->set(6, '!'); // set array at position 6 to value !

	//test if filling the array worked:
	char_arr->print();

	std::cout << "\n" << char_arr->get(4) << std::endl; //grab value at position 4 -> should be A

	char_arr->resize(25); //resize array to 25
	char_arr->print(); //print to check if it worked
	std::cout << "\n" << char_arr->getSize() << std::endl; //also print current arraysize to confirm 

	char_arr->resize(3); //make array smaller, program should now reconfirm if we actually want to lose values
	char_arr->print();
	std::cout << "\n" << char_arr->getSize() << std::endl; //also print current arraysize to confirm 

	//Testklasse-Array

	std::cout << "Testklasse-Array: " << std::endl;

	std::unique_ptr<TemplateArray<Testklasse*>> test_arr(new TemplateArray<Testklasse*>(10)); //declare array with size 10

	//test if constructor works:
	test_arr->print(); //will only show memoryadd, but that's okay for now

	//filling the array:
	test_arr->set(0, new Testklasse("Max")); 
	test_arr->set(1, new Testklasse("Tobi")); 
	test_arr->set(2, new Testklasse("Anna")); 
	test_arr->set(3, new Testklasse("Foo")); 
	test_arr->set(4, new Testklasse("Dumbledore")); 
	test_arr->set(5, new Testklasse("Marvin")); 
	test_arr->set(6, new Testklasse("Snape")); 

	//test if filling the array worked:
	for (int x = 0; x < (test_arr->getSize()); x++)
	{
		if((test_arr->get(x)) != 0)
		std::cout << (test_arr->get(x))->m_name << std::endl; //test if get works
	}

	test_arr->resize(25); //resize array to 25
	test_arr->print(); //print to check if it worked
	std::cout << "\n" << test_arr->getSize() << std::endl; //also print current arraysize to confirm 

	test_arr->resize(3); //make array smaller, program should now reconfirm if we actually want to lose values
	 //print array to confirm
	for (int x = 0; x < (test_arr->getSize()); x++)
	{
		if ((test_arr->get(x)) != 0)
			std::cout << (test_arr->get(x))->m_name << std::endl; //test if get works
	}


}