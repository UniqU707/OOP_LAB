#pragma warning(disable:6386)
#include <figure/figure.h>
#include <cmath>
#include <stdexcept>

using namespace figure;
using namespace std;

FigureList::FigureList() :_figures(nullptr), _size(0) {};

FigureList::FigureList(FigureList& figures):_size(figures._size),_figures(new FigurePtr[figures._size]) {
	for (int i = 0; i < _size; ++i)
		_figures[i] = new Figure(*figures._figures[i]);
}

void FigureList::swap(FigureList& another) {
	std::swap(_figures, another._figures);
	std::swap(_size, another._size);
}
FigureList& FigureList:: operator=(FigureList& another) {
	swap(another);
	return *this;
}

FigureList::~FigureList() {
	clear();
}

FigurePtr FigureList::get_figure_by_index(int i)const {
	if (i < 0 || i>_size) 
		throw std::runtime_error("Index out of range.");

	return _figures[i];
}

int FigureList::get_size()const { return _size; }


FigurePtr FigureList::operator[](int ind) const {
	if (ind < 0 || ind >= _size)
		throw std::runtime_error("Index out of range.");

	return _figures[ind];
}

FigurePtr& FigureList::operator[](int ind) {
	if (ind < 0 || ind >= _size) 
		throw std::runtime_error("Index out of range.");

	return _figures[ind];
}

void FigureList::add(Figure& fig) {
	auto figures = new FigurePtr[_size + 1];

	for (int i = 0; i < _size; ++i)
		figures[i] = _figures[i];

	figures[_size] = new Figure(fig);
	delete _figures;
	_figures = figures;
	++_size;
}

void FigureList::insert(int ind, Figure fig) {
	if (ind < 0 || ind >= _size)
		throw std::runtime_error("Index out of range.");

	auto figures = new FigurePtr[_size + 1];

	for (int i = 0; i < _size; ++i)
		figures[i] = _figures[i];

	for (int i = _size; i > ind; --i)
		figures[i] = figures[i - 1];
	figures[ind] = new Figure(fig);

	delete[] _figures;
	_figures = figures;
	++_size;
}

void FigureList::remove(int ind) {
	if (_size <= 0) 
		throw std::runtime_error("FigureList is empty.");
	delete _figures[ind];
	for (int i = ind; i < _size - 1; ++i)
		_figures[i] = _figures[i + 1];
	--_size;
}

void FigureList::clear() {
	if (_figures == nullptr)
		return;
	for (int i = 0; i < _size; ++i)
		delete _figures[i];
	_size = 0;
	delete[] _figures;
	_figures = nullptr;
}

int FigureList::figure_max_volume()const {
	if (_size == 0)
		return -1;
	int ind = 0;
	float max_volume = (*_figures[0]).figure_volume();
	for (int i = 1; i < _size; ++i) {
		float cur_volume = (*_figures[i]).figure_volume();
		if (cur_volume > max_volume) {
			ind = i;
			max_volume = cur_volume;
		}
	}
	return ind;
}
