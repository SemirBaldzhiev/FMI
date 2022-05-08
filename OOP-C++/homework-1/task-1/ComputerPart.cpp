#include "ComputerPart.h"

#include <cstring>
#include <fstream>



ComputerPart::ComputerPart(Type type, const char* brand, const char* model, const unsigned int yearsWarranty, const double price) {
	
	setType(type);
	setBrand(brand);
	setModel(model);
	setYearsWarranty(yearsWarranty);
	setPrice(price);
}

ComputerPart::ComputerPart() : type(Type::UNKNOWN), yearsWarranty(0), price(0), brand(nullptr), model(nullptr) { }

ComputerPart::ComputerPart(const ComputerPart& other) {
	copy(other);
}

ComputerPart& ComputerPart::operator=(const ComputerPart& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

ComputerPart::~ComputerPart() {
	destroy();
}

const char* ComputerPart::getTypeAsString() const{

	switch (type)
	{
	case Type::UNKNOWN: return "Unknown";
		break;
	case Type::MONITOR: return "Monitor";
		break;
	case Type::COMPUTER: return "Computer";
		break;
	case Type::LAPTOP: return "Laptop";
		break;
	case Type::MOUSE: return "Mouse";
		break; 
	case Type::KEYBOARD: return "Keyboard";
		break;
	case Type::HEADPHONES: return "Headphones";
		break;
	case Type::CAMERA: return "Camera";
		break;
	}
}

const Type ComputerPart::getType() const {
	return type;
}

unsigned int ComputerPart::getYearsWarranty() const {
	return yearsWarranty;
}

double ComputerPart::getPrice() const {
	return price;
}

char* ComputerPart::getBrand() const{
	return brand;
}

char* ComputerPart::getModel() const{
	return model;
}

void ComputerPart::setPrice(const double newPrice) {
	if (newPrice > 0) {
		price = newPrice;
	}

	throw "Invalid price! Price should be greater than zero.";
}

void ComputerPart::setType(const Type type) {
	if (Type::UNKNOWN == type) {
		throw std::exception("Unknown type");
	}

	this->type = type;
}

void ComputerPart::setBrand(const char* brand) {
	if (brand == nullptr || strlen(brand) >= 128) {
		throw std::exception("Invalid brand");
	}

	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

void ComputerPart::setModel(const char* model) {
	if (model == nullptr || strlen(model) >= 128) {
		throw std::exception("Invalid model");
	}

	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void ComputerPart::setYearsWarranty(const unsigned int year) {
	if (year == 0) {
		throw std::exception("Invaliud year");
	}

	yearsWarranty = year;
}

bool ComputerPart::operator==(const ComputerPart& item) {
	return this->brand == item.getBrand() 
		&& this->model == item.getModel() 
		&& this->type == item.getType() 
		&& this->price == item.getPrice()
		&& this->yearsWarranty == item.getYearsWarranty();
}

bool ComputerPart::operator!=(ComputerPart& item) {
	return !(*this == item);
}

void ComputerPart::writePartBin(std::ofstream& out) {
	
	size_t sizeType = strlen(getTypeAsString()) + 1;
	out.write(reinterpret_cast<const char*>(&sizeType), sizeof(sizeType));
	out.write(getTypeAsString(), sizeType);
	
	size_t sizeBrand = strlen(getBrand()) + 1;
	out.write(reinterpret_cast<const char*>(&sizeBrand), sizeof(sizeBrand));
	out.write(getBrand(), sizeBrand);
	
	size_t sizeModel = strlen(getModel()) + 1;
	out.write(reinterpret_cast<const char*>(&sizeModel), sizeof(sizeModel));
	out.write(getModel(), sizeModel);

	out.write(reinterpret_cast<const char*>(&yearsWarranty), sizeof(yearsWarranty));
	out.write(reinterpret_cast<const char*>(&price), sizeof(price));
}

void ComputerPart::copy(const ComputerPart& other) {
	type = other.type;
	yearsWarranty = other.yearsWarranty;
	price = other.price;

	brand = new char[strlen(other.brand) + 1];
	strcpy_s(brand, strlen(other.brand) + 1, other.brand);

	model = new char[strlen(other.model) + 1];
	strcpy_s(model, strlen(other.model) + 1, other.model);
}

void ComputerPart::destroy() {
	delete[] brand;
	delete[] model;
}
